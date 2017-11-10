//
// Created by Artur Laskowski on 10/11/2017.
//

#include "ArgParser.h"


typedef int64_t lint;

ArgParser::ArgParser::ArgParser() {}
ArgParser::ArgParser::~ArgParser() {
    for(auto it = args.begin(); it != args.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

std::string fill_space(int shrt_size, int full_size) {
    std::string res = "";
    for(int i = 40 - shrt_size - full_size - 1; i--;) {
        res += ' ';
    }
    return res;
}

void ArgParser::ArgParser::show_usage(std::string name) {
    std::cerr << "Usage: " << name << " <option(s)>\n"
              << "Options:\n"
              << "    -h,--help";
    for(int i = 40 - 9; i--;) {
        std::cerr << " ";
    }
    std::cerr << "Show this help message;\n";
    for(int i = 0; i < args_types.size(); ++i) {
        std::string shrt, full, desc;
        std::tie(shrt, full, desc) = args_types[i];

        std::cerr << "    " << shrt << "," << full << fill_space(shrt.size(), full.size()) << desc << "\n";
    }
}

void ArgParser::ArgParser::parse_args(int argc, char* argv[]) {
    if(argc < args_types.size() * 2) {
        show_usage(argv[0]);
        return;
    }
    for(int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        bool arg_found = false;
        for(int j = 0; j < args_types.size(); ++j) {
            std::string shrt, full, _;
            std::tie(shrt, full, _) = args_types[j];
            if(arg == shrt || arg == full) {
                if(i + 1 < argc) {
                    args.insert({shrt, argv[++i]});
                    arg_found = true;
                    break;
                }
            }
        }
        if(!arg_found){
            if((arg == "-h") || (arg == "--help")) {
                show_usage(argv[0]);
                return;
            }
            std::cerr << "Unrecognized option: " << arg << std::endl;
            show_usage(argv[0]);
            return;
        }
    }
}

void ArgParser::ArgParser::addArgHandler(std::string shrt, std::string full, std::string desc) {
    std::tuple<std::string, std::string, std::string> t = std::make_tuple(shrt, full, desc);
    args_types.push_back(t);
}