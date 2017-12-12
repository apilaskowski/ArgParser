//
// Created by Artur Laskowski on 10/11/2017.
//

#ifndef __ARGPARSER_H
#define __ARGPARSER_H

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <tuple>

namespace argparser {

    struct __type {
        std::string short_name;
        std::string long_name;
        std::string description;

        __type(std::string s, std::string l, std::string d) 
            : short_name(s), long_name(l), description(d) {}
    };

    class argparser {
    private:
        std::vector<__type> args_types;
    public:
        argparser();
        virtual ~argparser();

        bool parse_args(int, char *[]);
        std::unordered_map<std::string, std::string> args;

        void show_usage(std::string);

        void addArgHandler(__type);
    };

}

#endif //__ARGPARSER_H
