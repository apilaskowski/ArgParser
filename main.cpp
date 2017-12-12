#include "argparser.h"

#include <vector>

typedef argparser::__type Type;

std::vector <Type>  args_types = {
        Type("-sfp",    "--sam-file-path",                  "Set path to sam file with input data;"),
        Type("-fifp",   "--fasta-input-file-path",          "Set path to input fasta file with contigs;"),
        Type("-fofp",   "--fasta-output-file-path",         "Set path to output fasta file with contigs.")
};

int main(int argc, char * argv []) {
    argparser::argparser parser;

    for(int i = 0; i < args_types.size(); ++i) {
        parser.addArgHandler(args_types[i]);
    }

    if(!parser.parse_args(argc, argv)) {
        std::cout << "Sth went wrong!" << std::endl;
        return 1;
    } else {
        std::cout << "Parsing OK!" << std::endl;
    }

    std::string fifp = parser.args["-fifp"];
    std::string sfp = parser.args["-sfp"];
    std::string fofp = parser.args["-fofp"];

    std::cout << fifp << ", " << fofp << ", " << sfp << std::endl;
    return 0;
}