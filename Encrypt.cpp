#include "Encrypt.h"
#include <iostream>

std::string encrypt(std::string& text, const int shift)
{
    std::string result = text;
    
    for (char& c : result) {
        // Check if character is an uppercase letter
        if (isupper(c)) {
            c = ((c - 'A' + shift) % 26) + 'A';
        }
        // Check if character is a lowercase letter
        else if (islower(c)) {
            c = ((c - 'a' + shift) % 26) + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }

    return result;
}

std::string decrypt(std::string& text, const int shift)
{
    std::string result = text;
    
    for (char& c : result) {
        // Check if character is an uppercase letter
        if (isupper(c)) {
            c = ((c - 'A' - shift + 26) % 26) + 'A';
        }
        // Check if character is a lowercase letter
        else if (islower(c)) {
            c = ((c - 'a' - shift + 26) % 26) + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }

    return result;
}