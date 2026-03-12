#ifndef STORAGE_H
#define STORAGE_H

#include<unordered_map>
#include"account.h"



class Storage{
private:
std::unordered_map<std::string, Account> psd;

public:
Storage();

void loadFromFile();

void saveToFile();

void addAccount(Account acc);

void deleteAccount(std::string site);

void updateAccount(std::string site,int choice);
    


void searchAccount(std::string site);

void viewAllAccount();

};
#endif // STORAGE_H
