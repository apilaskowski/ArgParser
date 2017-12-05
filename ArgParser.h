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

    class argparser {
    private:
        std::vector<std::tuple<std::string, std::string, std::string>> args_types;
    public:
        argparser();
        virtual ~argparser();

        void parse_args(int, char *[]);
        std::unordered_map<std::string, std::string> args;

        void show_usage(std::string);

        void addArgHandler(std::string, std::string, std::string);
    };

}

#endif //__ARGPARSER_H
