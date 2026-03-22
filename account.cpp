#include<iostream>
#include<string>
#include<sstream>
#include "account.hpp"
#include"utils.hpp"

using namespace std;

    Account::Account(){
        
    }
    Account::Account(std::string site,std::string name,std::string pass){
        this->site=site;
        this->username=name;
        this->password=pass;
    }
    string Account::toFileString(){
        string acc;
        std::string key="mysecretpass";
        std::string encryptedPass= xorEncryptDecrypt(password,key);
        acc=site+"|"+username+"|"+encryptedPass;
        return acc;

    }

    Account Account::StringToAccount(std::string line){
        string site,username,password;
        stringstream ss(line);
        getline(ss, site, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');
        std::string key="mysecretpass";
        std::string orgPassword=xorEncryptDecrypt(password,key);
        Account acc=Account(site, username, orgPassword);
        
        return acc;
    }
    void Account::print() const{

        cout<<"site: "<<site<<endl;
        cout<<"username: "<<username<<endl;
        cout<<"password: "<<password<<endl;
    }

    void Account::setUsername(std::string newUsername){
        this->username=newUsername;
    }

    void Account::setPassword(std::string newPassword){
        this->password=newPassword;
    }

    string Account::getSite(){
        return site;
        
    }
  
