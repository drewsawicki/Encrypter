#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>

std::string encrypt(std::string& text, const int shift);
std::string decrypt(std::string& text, const int shift);


#endif