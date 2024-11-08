#include <iostream>
#include <string>
#include <fstream>
#include "Encrypt.h"
#include "Options.h"

std::string readFile(const std::string& filename);
void writeFile(const std::string& filename, const std::string& data);

int main(int argc, char *argv[])
{
    Options options = parse(argc, argv);

    if (!options.valid) {
        return 1;
    }

    try {
        std::string data = readFile(options.inputFile);
        std::string modifiedText;

        if (options.mode == "encrypt") {
            // ENCRYPT
            modifiedText = encrypt(data, options.shift);
        }
        else {
            // DECRYPT
            modifiedText = decrypt(data, options.shift);
        }
        writeFile(options.outputFile, modifiedText);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

std::string readFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    return content;
}

void writeFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file.");
    }
    file << data;
    file.close();
    std::cout << "Wrote to " << filename << std::endl;
}