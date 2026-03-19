#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

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
    void setUsername(std::string newUsername);
    void setPassword(std::string newPassword);

    std::string getSite();


};

#endif
