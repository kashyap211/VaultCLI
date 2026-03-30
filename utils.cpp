#include "utils.hpp"
#include<iostream>
#include <cstdlib>
#include<functional>
#include<string>
#include<conio.h>


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
std::string getHiddenPassword(){
    std::string password="";
    char ch;

    while(true){
        ch=_getch();

        if(ch==13) break;

        if(ch==8){
            if(!password.empty()){
                password.pop_back();
                std::cout<<"\b \b";
            }
        }
        else{
            password +=ch;
            std::cout<<"*";
        }
    }
    std::cout<< std::endl;
    return password;
}

std::string xorEncryptDecrypt(std::string data,std::string key){
    std::string result=data;
    for(int i=0;i<data.length();i++){
        result[i]=data[i] ^ key[i%key.length()];
    }
    return result;
}

std::string hashPassword(std::string password){
    std::hash<std::string>h;
    return std::to_string(h(password));
}
