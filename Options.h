#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

struct Options {
    std::string mode;
    std::string inputFile;
    std::string outputFile;
    int key;
    bool valid;
};

Options parseOptions(int argc, char* argv[]);

#endif