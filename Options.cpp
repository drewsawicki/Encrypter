#include "Options.h"
#include <getopt.h>
#include <iostream>
#include <cstdlib>

Options parseOptions(int argc, char* argv[])
{
    Options options;
    options.key = 0;
    options.valid = ture;

    const struct option longOptions[] = {
        {"mode", required_argument, nullptr, 'm'},
        {"input", required_argument, nullptr, 'i'},
        {"output", required_argument, nullptr, 'o'},
        {"key", required_argument, nullptr, 'k'},
        {nullptr, 0, nullptr, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "m:i:o:k:", longOptions, nullptr)) != -1) {
        switch (opt) {
            case 'm':
                options.mode = optarg;
                break;
            case 'i':
                options.inputFile = optarg;
                break;
            case 'o':
                options.outputFile = optarg;
                break;
            case 'k':
                options.key = optarg;
                break;
            case '?':
                options.valid = false;
                break;
        }
    }

    if (options.mode.empty() || options.inputFile.empty() || options.outputFile.empty() || options.key.empty()) {
        options.valid = false;
        std::cerr << "Missing required options. Usage:\n"
                  << "  --mode <encrypt|decrypt> --input <input_file> --output <output_file> --key <key>\n";
    }

    return options;
}