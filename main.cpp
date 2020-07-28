#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <filesystem>

#include "argparser.h"

typedef argparser::__type Type;

std::vector <Type> args_types = {
    Type("-ta", "--typical-argument", "Some typical argument"),
    Type("-ata", "--another-typical-argument", "Another typical argument"),
    Type("-siva", "--some-integer-value-argument", "Some argument with an integer value"),
    Type("-eba", "--example-of-binary-argument", "An example of a binary argument", true)
};

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);

    argparser::argparser parser;

    for(int i = 0; i < args_types.size(); ++i) {
        parser.addArgHandler(args_types[i]);
    }

    parser.parse_args(argc, argv);

    std::cerr << "Args: " << std::endl;
    for(auto el: parser.args) {
        std::cerr << el.first << ": " << el.second << std::endl;
    } std::cerr << std::endl << "---------" << std::endl << std::endl;

    try {
        std::string typical_argument = parser.handle_argument("--typical-argument");
        std::string another_typical_argument = parser.handle_argument("--another-typical-argument", "Some default value");
        std::string binary_argument = parser.handle_argument("--example-of-binary-argument");
        int integer_value = std::stoi(parser.handle_argument("--some-integer-value-argument")); 

        std::cerr << "Typical argument: " << typical_argument << std::endl;
        std::cerr << "Another typical argument: " << another_typical_argument << std::endl;
        std::cerr << "Binary argument: " << binary_argument << std::endl;
        std::cerr << "Integer: " << integer_value << std::endl;
    } catch(std::string e) {
        std::cerr << e << std::endl;
        return 0;
    }

    return 0;
}