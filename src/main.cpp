#include <boost/format/format_fwd.hpp>
#include <iostream>
#include "boost/program_options.hpp"
#include "boost/program_options/variables_map.hpp"
#include "boost/format.hpp"
#include <boost/algorithm/string.hpp>
#include "./classpath/Classpath.h"
#include "./log/log.h"
#include <iomanip>

namespace bpo = boost::program_options;

void startJVM(bpo::variables_map vmap) {
    auto jreOption = vmap["Xjre"].as<std::string>();
    auto cpOption = vmap["classpath"].as<std::string>();
    Classpath cp{};
    LOG_INFO("jreOption=%1%, cpOption=%2%", jreOption, cpOption);
    cp.parse(jreOption, cpOption);
    LOG_INFO("jreOption=%1%, cpOption=%2%", jreOption, cpOption);
    auto className = vmap["mainclass"].as<std::string>();
    LOG_INFO("jreOption=%1%, cpOption=%2%, mainClass=%3%", jreOption, cpOption, className);
    boost::replace_all(className, ".", "/");
    LOG_INFO("jreOption=%1%, cpOption=%2%, mainClass=%3%", jreOption, cpOption, className);
    auto classData = cp.readClass(className);
    if (classData == nullptr) {
        LOG_INFO("could not find the class: %1%", className);
    } 
    for (auto& b : *classData) {
        std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)b << " ";
    }
    std::cout << std::endl;
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