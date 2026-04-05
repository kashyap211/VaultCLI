#ifndef STORAGE_HPP
#define STORAGE_HPP

#include<unordered_map>
#include"account.hpp"



class Storage{
private:
std::unordered_map<std::string, Account> psd;


public:
std::string key;
Storage(std::string key);

void loadFromFile();

void saveToFile();

void addAccount(Account acc);

void deleteAccount(std::string site);

void updateAccount(std::string site,int choice);
    


void searchAccount(std::string site);

void PartialSearchAccount(std::string keyword);


void viewAllAccount();

};
#endif // STORAGE_H
