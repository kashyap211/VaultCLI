#include<iostream>
#include"storage.h"
#include"account.h"


int main(){
    Storage storage;
    bool run=true;
    
    while(run){
    std::cout<<"--------- Welcome to password Manager -----------"<<std::endl;
    int choice;
    std::cout <<"1. Add account\n2. View accounts\n3. Search account\n4. Delete account\n5. Exit\n";
    std::cout<<"--------- Enter Your choice ---------------------"<<std::endl;
    std::cout<<std::endl;
    std::cin>>choice;
    
    switch(choice){
        case 1:{
            std::string site,username,password;
            std::cout<<"Enter the name of site"<<std::endl;
            std::cin>>site;
            std::cin.ignore();
            std::cout<<"Enter the name of username"<<std::endl;
            std::getline(std::cin,username);
            std::cout<<"Enter the name of password"<<std::endl;
            std::cin>>password;

            Account acc(site,username,password);
            storage.addAccount(acc);
        break;
        }
        case 2:{
            storage.viewAllAccount();
        break;
        }
        case 3:{
            std::string site;
            std::cout<<"Enter the site name"<<std::endl;
            std::cin>>site;
            storage.searchAccount(site);
        break;
        }
        case 4:{
            std::string site;
            std::cout<<"Enter the site "<<std::endl;
            std::cin>>site;
            storage.deleteAccount(site);
        break;
        }
        case 5:
            run=false;
        break;

        default:{
        
        std::cout<<"Enter the right choice"<<std::endl;
        
        break;
        }
    }

    }
}
