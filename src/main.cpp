#include <boost/format/format_fwd.hpp>
#include <iostream>
#include "boost/program_options.hpp"
#include "boost/program_options/variables_map.hpp"
#include "boost/format.hpp"
#include <boost/algorithm/string.hpp>
#include "./classpath/Classpath.h"
#include "./log/log.h"
#include "classfile/ClassFile.h"
#include <iomanip>
#include <memory>
#include "./rtda/Frame.h"

namespace bpo = boost::program_options;

shared<ClassFile> loadClass(string& className, Classpath& cp) {
    auto buffer = cp.readClass(className);
    auto cf = std::make_shared<ClassFile>();
    cf->parse(buffer);
    return cf;
}

void testLocalVars(shared<LocalVars> vars) {
    vars->setInt(0, 100);
    vars->setInt(1, -100);
    vars->setLong(2, 2997924580);
    vars->setLong(4, -2997924580);
    vars->setFloat(6, 3.1415926);
    vars->setDouble(7, 2.71828182845);
    vars->setRef(9, nullptr);
    LOG_INFO("%1%", vars->getInt(0));
    LOG_INFO("%1%", vars->getInt(1));
    LOG_INFO("%1%", vars->getLong(2));
    LOG_INFO("%1%", vars->getLong(4));
    LOG_INFO("%f", vars->getFloat(6));
    LOG_INFO("%f", vars->getDouble(7));
    LOG_INFO("%1%", vars->getRef(9));
}

void testOperandStack(shared<OperandStack> ops) {
    ops->pushInt(100);
    ops->pushInt(-100);
    ops->pushLong(2997924580);
    ops->pushLong(-2997924580);
    ops->pushFloat(3.1415926);
    ops->pushDouble(2.71828182845);
    ops->pushRef(nullptr);
    LOG_INFO("%1%", ops->popRef());
    LOG_INFO("%1%", ops->popDouble());
    LOG_INFO("%1%", ops->popFloat());
    LOG_INFO("%1%", ops->popLong());
    LOG_INFO("%1%", ops->popLong());
    LOG_INFO("%1%", ops->popInt());
    LOG_INFO("%1%", ops->popInt());
}

void testFrame(shared<Frame> frame) {
    testLocalVars(frame->localVars);
    testOperandStack(frame->operandStack);
}

void startJVM(bpo::variables_map vmap) {
    auto jreOption = vmap["Xjre"].as<std::string>();
    auto cpOption = vmap["classpath"].as<std::string>();
    Classpath cp{};
    cp.parse(jreOption, cpOption);
    auto className = vmap["mainclass"].as<std::string>();
    boost::replace_all(className, ".", "/");
    LOG_INFO("jreOption=%1%, cpOption=%2%, mainClass=%3%", jreOption, cpOption, className);
    auto cf = loadClass(className, cp);
    std::cout << *cf << std::endl;
    testFrame(frame::newFrame(100, 100));
}

int main(int argc, const char** argv) {

    std::string classpath;
    std::vector<std::string> mainclass;
    std::string jrepath;

    bpo::options_description desc("Allowed options:");
    desc.add_options()
        ("help,h", "display help message.")
        ("version,v", "display version message.")
        ("classpath,c", bpo::value<std::string>()->default_value("."), "classpath.")
        ("mainclass", bpo::value<std::string>(), "main class")
        ("args", bpo::value<std::vector<std::string>>(), "args")
        ("Xjre", bpo::value<std::string>(&jrepath), "path to jre")
    ;
    bpo::positional_options_description pdes;
    pdes.add("args", -1);

    bpo::variables_map vmap;
    bpo::store(bpo::command_line_parser(argc, argv).options(desc).positional(pdes).run(), vmap);
    bpo::notify(vmap);

    if (vmap.count("help") == 1) {
        std::cout << desc << std::endl;
    } else if (vmap.count("version") == 1) {
        std::cout << "version is 1.0" << std::endl;
    } else {
        LOG_INFO("jreOption=%1%", jrepath);
        startJVM(vmap);
    }
    
    return 0;
}