#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Account{
    string site;
    string username;
    string password;

    public:
    Account(){
        
    }
    Account(string site,string name,string pass){
        this->site=site;
        this->username=name;
        this->password=pass;
    }
    string toFileString(){
        string acc;
        acc=site+"|"+username+"|"+password;
        return acc;

    }
    Account StringToAccount(string line){
        string site,username,password;
        stringstream ss(line);
        getline(ss, site, '|');
        getline(ss, username, '|');
        getline(ss, password, '|');
        Account acc=Account(site, username, password);
        
        return acc;
    }
    void print(){

        cout<<"site: "<<site<<endl;
        cout<<"username: "<<username<<endl;
        cout<<"password: "<<password<<endl;
    }
    string getSite(){
        return site;
    }

};