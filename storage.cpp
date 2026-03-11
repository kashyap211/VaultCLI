#include<iostream>
#include<fstream>
#include<unordered_map>
#include "storage.h"

using namespace std;


Storage::Storage(){

    loadFromFile();
}

void Storage::loadFromFile(){
    string st1;
    ifstream sin("pwd.txt");
    if(!sin){
        cout<<"File cannot be opened"<<endl;
        return ;
    }
    while(getline(sin,st1)){
        Account acc= Account::StringToAccount(st1);
        psd[acc.getSite()]=acc;
    }
    
    sin.close();
}
void Storage::saveToFile(){
    string st2;
    ofstream sout("pwd.txt");
    if(!sout){
        cout<<"File cannot be opened"<<endl;
        return;
    }
        for(auto &acc:psd){
            st2=acc.second.toFileString();
            sout<<st2<<endl;
        }
    sout.close();
}

void Storage::addAccount(Account acc){
    psd[acc.getSite()]=acc;
    saveToFile();
}

void Storage::deleteAccount(string site){
    if(psd.find(site)!=psd.end()){
    psd.erase(site);
    saveToFile();
    }
    else{
        cout<<"Account not found"<<endl;
    }
}

void Storage::searchAccount(string site){
    auto it=psd.find(site);
    if(it!=psd.end()){
        cout<<"Account Found"<<endl;
        it->second.print();
    }
    else{
        cout<<"Account not found"<<endl;
    }
}
void Storage::viewAllAccount(){
    for(const auto &it:psd){
        it.second.print();
    }
}

