//
// Created by Artur Laskowski on 10/11/2017.
//

#include "argparser.h"


typedef int64_t lint;

argparser::argparser::argparser() {}
argparser::argparser::~argparser() {}

std::string fill_space(int shrt_size, int full_size) {
    std::string res = "";
    for(int i = 40 - shrt_size - full_size - 1; i--;) {
        res += ' ';
    }
    return res;
}

void argparser::argparser::show_usage(std::string name) {
    std::cerr << "Usage: " << name << " <option(s)>\n"
              << "Options:\n"
              << "    -h,--help";
    for(int i = 40 - 9; i--;) {
        std::cerr << " ";
    }
    std::cerr << "Show this help message;\n";
    for(int i = 0; i < this->args_types.size(); ++i) {
        std::string shrt, full, desc;
        shrt = this->args_types[i].short_name;
        full = this->args_types[i].long_name;
        desc = this->args_types[i].description;

        std::cerr << "    " << shrt << "," << full << fill_space(shrt.size(), full.size()) << desc << "\n";
    }
}

bool argparser::argparser::parse_args(int argc, char* argv[]) {
    for(int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        bool arg_found = false;
        for(int j = 0; j < this->args_types.size(); ++j) {
            std::string shrt, full;
            shrt = this->args_types[j].short_name;
            full = this->args_types[j].long_name;
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
                return false;
            }
            std::cerr << "Unrecognized option: " << arg << std::endl;
            show_usage(argv[0]);
            return false;
        }
    }
    return true;
}

void argparser::argparser::addArgHandler(__type t) {
    args_types.push_back(t);
}
