#include "utils.h"
#include<iostream>
#include <cstdlib>


std::string GeneratePassword(){
     std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*?";
        int length=12;
        std::string password="";
        for(int i=0;i<length;i++){
            int randomIndex=rand()%characters.length();
            password=password+characters[randomIndex];
        }
        return password;
    }
