#include<iostream>
#include<string>
#include<sstream>
#include "account.h"

using namespace std;

    Account::Account(){
        
    }
    Account::Account(string site,string name,string pass){
        this->site=site;
        this->username=name;
        this->password=pass;
    }
    string Account::toFileString(){
        string acc;
        acc=site+"|"+username+"|"+password;
        return acc;

    }
    Account Account::StringToAccount(string line){
        string site,username,password;
        stringstream ss(line);
        getline(ss, site, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');
        Account acc=Account(site, username, password);
        
        return acc;
    }
    void Account::print() const{

        cout<<"site: "<<site<<endl;
        cout<<"username: "<<username<<endl;
        cout<<"password: "<<password<<endl;
    }
    string Account::getSite(){
        return site;
    }
