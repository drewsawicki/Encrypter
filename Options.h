#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

struct Options {
    std::string mode;
    std::string inputFile;
    std::string outputFile;
    int shift;
    bool valid;
};

Options parse(int argc, char* argv[]);

#endif