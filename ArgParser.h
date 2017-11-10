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

namespace ArgParser {

    class ArgParser {
    private:
        std::vector<std::tuple<std::string, std::string, std::string>> args_types;
        void show_usage(std::string);

    public:
        ArgParser();
        virtual ~ArgParser();

        void parse_args(int, char *[]);
        std::unordered_map<std::string, std::string> args;

        void addArgHandler(std::string, std::string, std::string);
    };

}

#endif //__ARGPARSER_H
