#include <iostream>
using std::string;
class password
{
    public:
    password();
    void registerp();
    void loginp();
    ~password();

    private:
    int i,password_length,array;
    string ans,fileContent;
    char num[10] = {'0','1','2','3','4','5','6','7','8','9'}; 
    char blet[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char slet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char pass[20];
    
};