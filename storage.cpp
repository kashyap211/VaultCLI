#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct DATA{
	string username;
	string password;
};
class Storage{
    public:
	unordered_map<string,DATA>psd;
	
	//psd["google.com"]={"hun2@gmail.com","chulia"};
    Storage(){}
	
	
    void addAccount(const string& site, const string& username, const string& password){
        psd[site]={username,password};
    }

    void deleteAccount(const string& site){
		psd.erase(site);
	}
	
	void viewAccount(const string& site){
		
		DATA n=psd.at(site);
		cout<<site<<"->"<<endl;
        cout<<"username: "<<n.username<<endl;
        cout<<" password: "<<n.password<<endl;
    }
    void searchAccount(const string& site){
        auto it=psd.find(site);
        if(it!=psd.end()){
            cout<<"Account found for site: "<<site<<endl;
            cout<<"username: "<<it->second.username<<endl;
            cout<<"password: "<<it->second.password<<endl;      
        }else{
            cout<<"No account found for site: "<<site<<endl;
        }
    }

};

