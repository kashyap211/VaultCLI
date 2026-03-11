#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>


class Account{
  private:
    std::string site;
    std::string username;
    std::string password;

    public:
    Account();

    Account(std::string site,std::string name,std::string pass);

    std::string toFileString();

    static Account StringToAccount(std::string line);
    
    void print() const;

    std::string getSite();

};

#endif
