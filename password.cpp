#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <limits>
using std::cin,std::cout,std::string,std::cerr;

int main()
{
    int i,password_length,array;
    string ans;
    char num[] = {'0','1','2','3','4','5','6','7','8','9'}; 
    char blet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char slet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char pass[20];

    std::ifstream inputFile("pass.txt");
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening the file for reading!\n";
        return 1;
    }
    string fileContent;
    inputFile >> fileContent;
    inputFile.close();
    if (fileContent.empty()) 
    {
        string g;
        cout << "Register: \n";
        cout << "You can choose your own password, or generate one:\n";
        cout << "1. To choose your own.\n";
        cout << "2. To generate one.\n";
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
            cerr << "Error opening the file for writing!\n";
            return 1;
        }
        outputFile << pass;     // Write the password to the file
        outputFile.close();
    }
    else // File is not empty, it's a login process
    { 
        int pl = 3;
        string userInput;
        cout << "Log in: \n";
        cin >> userInput;
        while(userInput != fileContent)
        {
           if(pl == 0)
           {
            break;
           }
           cout << "Invalid login. " << pl <<" tries remaining\n";
           pl--;
           cin >> userInput;
        }
        cout << "You have entered wrong password 3 times.\n";
    }
            
} 

    
        
