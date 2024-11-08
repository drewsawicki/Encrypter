# Encrypter - Command Line Encryption & Decryption Tool

This project implements a simple command-line encryption and decryption tool using the Caesar cipher. The program allows you to encrypt or decrypt a text file with customizable parameters such as shift value and file input/output paths.

## Features

- Encrypt and decrypt text files using the **Caesar cipher**
- Command-line interface with customizable input and output file paths.
- Adjustable shift value for Caesar cipher encryption/decryption.

## Installation

To use this project, you need to have a C++ compiler installed (such as `g++`). Follow the steps below to get started:

1. Clone the repository to your local machine:

    ```bash
   git clone https://github.com/yourusername/Encrypter.git
   ```

2. Navigate to the project directory:
    ```bash
    cd Encrypter
    ```

3. Compile the program
    ```bash
    g++ -o encrypter main.cpp options.cpp encrypt.cpp -std=c++11
    ```

This will generate an executable file called "encrypter".

## Command Line Usage

The program accepts the following command-line options:
```bash
    --mode <encrypt|decrypt>   # Mode of operation: 'encrypt' or 'decrypt'
    --input <input_file>       # Path to the input file
    --output <output_file>     # Path to save the result
    --shift <shift_value>      # Shift value for the Caesar cipher (integer)
```

## File Formats
 * The input and output files are text files (.txt)
 * Non-alphabetic characters are preserved during encryption/decryption
