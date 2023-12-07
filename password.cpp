#include "password.hpp"
#include <fstream>
#include <limits>
#include <time.h>
using std::cin,std::cout;
password::password()
{
    std::ifstream inputFile("pass.txt");
    if (!inputFile.is_open()) 
        {
            cout << "Error opening the file for reading!\n";
            return;
        }
    inputFile >> fileContent;
    inputFile.close();
    if (fileContent.empty()) {registerp();}
    else {loginp();}                        // File is not empty, it's a login process
    
}
void password::registerp()
{
    string g;
        cout << "Register: \n\n";
        cout << "1.Choose your own password.\n";
        cout << "2.Generate random password.\n";
        cin >> g; 
        while(g != "1" && g != "2")
        {
            cout << "invalid input. Try again.\n";
            cin >> g;
        }
        if(g == "2")
        {
            cout << "Enter the length of the password: \n";
            cin >> password_length;
            while((password_length <= 0 || password_length > 21) || std::cin.fail())
                {
                    cin.clear();       
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid Input, try again." << "\n";
                    cin >> password_length;
                }
            srand(time(NULL));
            for(i=0;i<password_length;i++)
                {
                    array = rand() % 3;
                    switch(array)
                        {
                            case 0:
                                pass[i] =  num[rand() % 10];
                                break;
                            case 1:
                                pass[i] = blet[rand() % 26];
                                break;
                            case 2:
                                pass[i] = slet[rand() % 26];
                                break;
                        }
                }
            pass[password_length] = '\0';
            cout << "Password generated: ";
            for(i=0;i<password_length;i++) {cout << pass[i];}
        }
        else
        {
            cout << "Choose a password: \n";
            cin >> pass;
        }
        std::ofstream outputFile("pass.txt");
        if (!outputFile.is_open()) 
        {
            cout << "Error opening the file for writing!\n";
            return;
        }
        outputFile << pass;     // Write the password to the file
        outputFile.close();
}
void password::loginp()
{ 
    int pl = 3;
    string a;
    string userInput;
    cout << "1. Log in \n" << "2. Reset password\n";
    cin >> a;
    while(a != "1" && a != "2")
    {
        cout << "invalid input. Try again\n";
        cin >> a;
    }
    if(a == "1")
    {
          cout << "Give password: \n";
          cin >> userInput;
          while((userInput != fileContent) && (pl >= 0))
            {
                        if(pl == 1)
                            {
                                cout << "last try:\n";
                            }
                        else
                            {
                                cout << "Invalid login. " << pl <<" tries remaining\n";
                            }
                        if(pl==0){cout << "you entered wrong password 3 times."; break;}
                        pl--;
                        cin >> userInput;
            }
            if(userInput == fileContent) {cout << "Welcome!\n";}
                return;
    }
    else
    {
            std::ofstream outFile("pass.txt");
            if (!outFile.is_open()) {cout << "Error opening file.\n";}
            outFile.seekp(0, std::ios::beg);
            outFile << ""; 
            registerp();
    }
}

password::~password() {}
