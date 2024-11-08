#include "Options.h"
#include <getopt.h>
#include <iostream>
#include <cstdlib>

Options parse(int argc, char* argv[])
{
    Options options;
    opterr = false;
    int option_index = 0;
    int option = 0;
    options.shift = 0;
    options.valid = true;

    const struct option longOptions[] = {
        {"mode", required_argument, nullptr, 'm'},
        {"input", required_argument, nullptr, 'i'},
        {"output", required_argument, nullptr, 'o'},
        {"shift", required_argument, nullptr, 's'},
        {nullptr, 0, nullptr, '\0'}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "m:i:o:s:", longOptions, &option_index)) != -1) {
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
            case 's':
                try {
                    options.shift = std::stoi(optarg); 
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid argument for shift: " << optarg << "\n";
                    options.valid = false;  // Mark as invalid if conversion fails
                } catch (const std::out_of_range& e) {
                    std::cerr << "Shift value out of range: " << optarg << "\n";
                    options.valid = false;  // Mark as invalid if number is too large/small
                }
                break;
            case '?':
                options.valid = false;
                break;
        }
    }

    if (options.inputFile.empty() || options.outputFile.empty()) {
        options.valid = false;
        std::cerr << "Missing required options. Usage:\n"
                  << "  --mode <encrypt|decrypt> --input <input_file> --output <output_file> --shift <shift>\n";
    }

    if (options.mode != "encrypt" && options.mode != "decrypt") {
        options.valid = false;
        std::cerr << "Invalid mode. Usage:\n"
                  << " --mode <encrypt|decrypt>\n";
    }

    if (options.shift == 0) {
        options.valid = false;
        std::cerr << "Must use shift value greater than 0.\n";
    }

    return options;
}