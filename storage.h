#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <unordered_map>
using namespace std;

// Struct to hold account data
struct DATA {
    string username;
    string password;
};

// Storage class to manage accounts
class Storage {
public:
    unordered_map<string, DATA> psd;

    // Constructor
    Storage();

    // Add an account
    void addAccount(const string& site, const string& username, const string& password);

    // Delete an account
    void deleteAccount(const string& site);

    // View an account
    void viewAccount(const string& site);

    // Search an account (safe version)
    void searchAccount(const string& site);
};

#endif // STORAGE_H
