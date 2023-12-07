#include "password.hpp"
#include <fstream>
#include <limits>
#include <time.h>

using std::cin,std::cout,std::ofstream,std::ifstream;


password::password()        //constructor that checks if the pass.txt file is empty. 
{
    ifstream inputFile("pass.txt");
    if (!inputFile.is_open()) 
        {
            cout << "Error opening the file for reading!\n";
            return;
        }
    inputFile >> fileContent;
    inputFile.close();
    if (fileContent.empty()) {registerp();} //File is empty, its a registration process
    else {loginp();}                        // File is not empty, it's a login process
    
}


password::~password() {}


void password::clearscreen()   //clears old data from the screen.
{
  #ifdef _WIN32     //checks if the program is running from a Windows operating system.
    system("cls");  //if it does, it runs this command, which clears old data from the screen (runs only on windows).
  #else
    system("clear");  //if it is running from unix or macOS, it runs this command that does the same thing.
  #endif
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
            cout << "Invalid Input, try again.\n";
            cin >> g;
        }
    clearscreen();
    if(g == "2")
        {
            int i;
            cout << "Enter the length of the password: [1-21]\n";
            cin >> password_length;
            while((password_length <= 0 || password_length > 21) || cin.fail()) //password length must be a number in from 1 to 21
                {
                    cin.clear();       
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid Input, try again.\n";
                    cin >> password_length;
                }
            srand(time(NULL));
            for(i=0;i<password_length;i++)      //picks a random array from num[],blet[],slet[] and adds a random element in pass[] array.
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
            cout << "\n";
        }
    else
        {
            cout << "Choose a password: \n";
            cin >> pass;
            clearscreen();
            cout << "Password Generated!\n";
        }
        ofstream outputFile("pass.txt");        //then adds the pass[] in the file.
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
    clearscreen();
    string a,userInput;
    cout << "1. Log in \n" << "2. Reset password\n";
    cin >> a;
    while(a != "1" && a != "2")
    {
        cout << "Invalid Input, try again.\n";
        cin >> a;
    }
    clearscreen();
    if(a == "1")        //checks if the input from user is the password inside the file.
    {
          int pl = 3;
          cout << "Give password: \n";          
          cin >> userInput;
          while((userInput != fileContent) && (pl >= 0))
            {
                clearscreen();
                        if(pl == 1)
                            {
                                cout << "last try:\n";
                            }
                        else
                            {
                                cout << "Invalid login. " << pl <<" tries remaining\n";
                            }
                        if(pl==0){cout << "you entered wrong password 3 times.\n"; break;}
                        pl--;
                        cin >> userInput;
            }
            clearscreen();
            if(userInput == fileContent) {cout << "Welcome!\n";}
            return;
    }
    else
    {                       
            ofstream outFile("pass.txt");       //opens the file and clears it.
            if (!outFile.is_open()) {cout << "Error opening file.\n";}
            outFile.seekp(0, std::ios::beg);
            outFile << ""; 
            registerp();
    }
}