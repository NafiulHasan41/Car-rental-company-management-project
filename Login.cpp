#include<iostream>
#include<string>
#include<map>
using namespace std;
//make a class to store id or match id,password
class login{
    map<int ,string> m;         //create map to hold id and password in one object 
    public:
   // bool flag;                   //to check id and password are valid or not
    void setid_and_password(int a,string b);    //to set id and password if not set
    bool checkid_and_password(int a,string b);  //to check check id password    
    //friend void check(); 
};
void login::setid_and_password(int a,string b)
{
    m[a]=b;
}
bool login::checkid_and_password(int a,string b)
{
    if(m[a]==b)
    {
        return true;
    }
    else
    {
        return false;
        //cout<<"\t\tThe ID and PASSWORD does not match\t\t"<<endl;
    }
}

