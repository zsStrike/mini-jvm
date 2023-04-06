#include <iostream>
#include "boost/program_options.hpp"
#include "boost/program_options/variables_map.hpp"

namespace bpo = boost::program_options;

int main(int argc, const char** argv) {
    std::string classpath;
    std::vector<std::string> mainclass;

    bpo::options_description desc("Allowed options:");
    desc.add_options()
        ("help,h", "display help message.")
        ("version,v", "display version message.")
        ("classpath,c", bpo::value<std::string>(&classpath), "classpath.")
        ("mainclass", bpo::value<std::vector<std::string>>(&mainclass), "class and args")
    ;
    bpo::positional_options_description pdes;
    pdes.add("mainclass", -1);
    bpo::variables_map vmap;
    bpo::store(bpo::command_line_parser(argc, argv).options(desc).positional(pdes).run(), vmap);
    bpo::notify(vmap);

    if (vmap.count("help") == 1) {
        std::cout << desc << std::endl;
    } else if (vmap.count("version") == 1) {
        std::cout << "version is 1.0" << std::endl;
    } else {
        std::cout << "mini-jvm: 1.0 started." << std::endl;
        std::cout << "classpath: " << classpath << std::endl;
        for (auto& arg : mainclass) {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}