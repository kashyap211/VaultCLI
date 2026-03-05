#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
public:
    string site;
    string username;
    string password;

    Account();
    Account(string s, string u, string p);

    string toFileString();     
    static Account fromLine(string line);  
};

#endif
