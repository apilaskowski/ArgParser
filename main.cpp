#include "ArgParser.h"

std::string args_types [][3] = {
        {"-nsd",    "--number-of-standard-deviations",  "Number of standard deviations, which wile exceeded define pair-end as a suspect;"},
        {"-nco",    "--number-of-outsiders",            "Number of consecutive outsiders that will cause program to break contig;"},
        {"-sfp",    "--sam-file-path",                  "Set path to sam file with input data;"},
        {"-fifp",   "--fasta-input-file-path",          "Set path to input fasta file with contigs;"},
        {"-fofp",   "--fasta-output-file-path",         "Set path to output fasta file with contigs."}
};

int main(int argc, char * argv []) {
    ArgParser::ArgParser parser;

    for(int i = 0; i < (sizeof(args_types)/sizeof(*args_types)); ++i) {
        parser.addArgHandler(args_types[i][0], args_types[i][1], args_types[i][2]);
    }

    parser.parse_args(argc, argv);

    int nco = std::stoi(parser.args["-nco"]);
    std::string sfp = parser.args["-sfp"];
    double nsd = std::stod(parser.args["-nsd"]);

    std::cout << nco << ", " << nsd << ", " << sfp << std::endl;
    return 0;
}