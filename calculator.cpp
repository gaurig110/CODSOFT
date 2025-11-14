#include <iostream>
#include <limits>
#include <string>
using namespace std;

/*function for input validation so user only inputs a number. 
Ex- stills works if accidentally user inputs an alphabet.
In that case, it would clear the fail state and ignore the wrong input*/
float valid(const string &message) 
{
    float input;
    cout << message;
    while (true) 
    {
        if (cin >> input) 
        {
            return input;
        } 
        else 
        {
            cout << "Invalid input. Please enter again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

//main function : ASCII art to show a calculator, input and output based upon operator entered
int main()
{
    float a,b;
    int choice=1;
    char c;
    cout<<" _____________________\n|  _________________  |\n| |              0. | |\n| |_________________| |\n|  ___ ___ ___   ___  |\n| ";
    cout<<"| 7 | 8 | 9 | | + | |\n| |___|___|___| |___| |\n| | 4 | 5 | 6 | | - | |\n| |___|___|___| |___| |\n| | 1 | 2 | 3 | | * | |\n| ";
    cout<<"|___|___|___| |___| |\n| | . | 0 | = | | / | |\n| |___|___|___| |___| |\n|_____________________|\n\n";
    cout<<"--- WELCOME TO NumCalc ---\n\n";
    do
    {
        a=valid("Enter first number : ");
        b=valid("Enter second number : ");
        cout<<"Enter an operation to perform (+, -, /, *) : ";
        cin>>c;
        if(c=='+')
        {
            cout<<a<<" + "<<b<<" = "<<a+b<<endl;
        }
        else if(c=='-')
        {
            cout<<a<<" - "<<b<<" = "<<a-b<<endl;
        }
        else if(c=='*')
        {
            cout<<a<<" * "<<b<<" = "<<a*b<<endl;
        }
        else if(c=='/')
        {
            if(b!=0)
            cout<<a<<" / "<<b<<" = "<<a/b<<endl;
            else
            cout<<"Invalid Denominator."<<endl;
        }
        else
        {
            cout<<"Invalid operator."<<endl;
        }
        cout<<"Enter 1 to continue or 0 to exit. ";
        cin>>choice;
        cout<<endl;
    } while (choice);
    return 0;
}