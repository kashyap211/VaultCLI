#include<iostream>
#include <thread>
#include <chrono>
#include"storage.hpp"
#include"account.hpp"
#include"utils.hpp"
#include <ctime>
#include<fstream>


int main(){
    srand(time(0));
    bool run=true;
    std::string masterPassword;
    
    
    std::ifstream file("master.txt");
    if(!file){
        std::string masterPwd;
        std::cout<<"Enter a master password: ";
        masterPwd=getHiddenPassword();
        std::string hashed=hashPassword(masterPwd);
        std::ofstream fout("master.txt");
        fout<<hashed;
        fout.close();
        masterPassword=masterPwd;
        std::cout << "Master password set!\n";
    }else{
        int counter=3;
        bool auth=false;

        while(counter>0){
            std::cout<<"Enter Your Master Password: ";
            std::string masterPwd;
            masterPwd=getHiddenPassword();
            std::ifstream fin("master.txt");
            std::string pass;
            getline(fin,pass);
            fin.close();
            if(hashPassword(masterPwd)==pass){
                std::cout<<"Access Granted\n";
                auth=true;
                masterPassword=pass;
                break;
            }
            else{
                counter--;
                std::cout<<"Wrong password, You have "<<counter<<"attempts left\n";
                //std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }
        if(!auth){
            std::cout<<"You have many invalid attempts";
            run=false;
            return 0;
        } 
    }
    Storage storage(masterPassword);
    
    while(run){
    std::cout<<"--------- Welcome to password Manager -----------"<<std::endl;

    int choice;
    std::cout <<"1. Add account\n2. View accounts\n3. Search account(O(1))\n4. Partial Search(O(n))\n5. Delete account\n6. Update Account\n7. Exit\n";
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
            std::cout<<"\n1. Enter password manually\n2. Generate password\n"<<std::endl;
            int passChoice;
            std::cin>>passChoice;

            if(passChoice==1){
            std::cout<<"Enter the password"<<std::endl;
            password = getHiddenPassword();
            }
            else if(passChoice==2){
                password=GeneratePassword();
                std::cout<<"Generated password is:"<<password<<std::endl;
            }
            else{
                std::cout<<"Enter valid choice";
            }
        
            Account acc(site,username,password);
            storage.addAccount(acc);
            std::cout<<"Account stored successfully\n";
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
            std::cout<<"Enter the site name"<<std::endl;
            std::cin>>site;
            storage.PartialSearchAccount(site);
        break;
        }
        case 5:{
            std::string site;
            std::cout<<"Enter the site "<<std::endl;
            std::cin>>site;
            storage.deleteAccount(site);
        break;
        }
        case 6:{
            std::string site;
            int choice2;
            std::cout<<"Enter the site name"<<std::endl;
            std::cin>>site;
            std::cout<<"1. Update password\n2. Update Username\n3. Update Both"<<" \n"<<"Enter Your choice"<<std::endl;
            std::cin>>choice2;
            storage.updateAccount(site,choice2);
            break;
        }
        case 7:
            run=false;
        break;

        default:{
        
        std::cout<<"Enter the right choice"<<std::endl;
        
        break;
        }
    }

    }
}
