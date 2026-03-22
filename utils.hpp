#ifndef UTILS
#define UTILS_HPP

#include <string>

std::string GeneratePassword();
std::string getHiddenPassword();
std::string xorEncryptDecrypt(std::string data,std::string key);


#endif