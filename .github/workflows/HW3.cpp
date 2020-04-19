- name: Setup C++
  uses: Trass3r/setup-cpp@v1
// Samantha start code from here 
//******************************************************************************
// Team #3 CSCI/CMPE 1370 Spring2020 Homework # 3
// Kevin De La Garza 
// Samantha Garza
// This program is a calculator that can add and subtract rational numbers.
// the user can implement any kind of fractions, and our algorythm will get it done efficiently
// through the use of functions and string values with applying all the basics we have learned in class.
//including eliuds algorythm for reduction.
//******************************************************************************
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;
void showMenu()
{
    cout << "Rational Numbers Calculator" << endl;
    cout << endl;
    cout <<"(A) ddition" <<endl;
    cout <<"(S) ubtraction" << endl;
    cout <<"(Q) uit" << endl;
    cout << endl;
}
void displayRational (int num, int den)
{
    char dummy = '/';
    if(den = 1)
    {
        cout << "the result is: " << num << endl; 
    }
    else if (num = 0)
    {
        cout << "The result is 0"<< endl;
    }
    else
    {
        cout << "the result is: " << num << dummy << den <<endl;
    }
    

}
void reduced(int *num,int *den)
{
    int anum, aden;
    int R = anum % aden;
    while( R != 0)
    {
        anum = aden;
        aden = R;
        R = anum % aden;
    }
    int gcf = aden;
    *num = anum / gcf;
    *den = aden / gcf;
}
void addRational(int *anum, int *aden, int num1, int den1, int num2, int den2)
{
    *anum = (num1 * den2) + (num2 * den1);
    *aden = (den1 * den2);
}
void subRational(int *anum, int *aden, int num1, int den1, int num2, int den2)
{
    *anum = (num1 * den2) - (num2 * den1);
    *aden = (den1 * den2);
}
void getRational(int *num, int *den)
{
    string str;
    string numstr,denstr;
    cout << "Please Enter a fraction (n/d): "; 
    getline(cin,str);
    stringstream str_stream(str);
    getline(str_stream,numstr,'/');
    getline(str_stream,denstr,'/');
   *num = stoi(numstr);
    *den = stoi(denstr);
    
}
void add()
{
    system("CLS");
    int num,den;
    int num1,den1,num2,den2,anum,aden;
     cout << "Addition of Rational Numbers" << endl;
    while(true)
    {
        cout << endl;
        getRational(&num1, &den1);
        getRational(&num2, &den2);
        addRational(&anum,&aden, num1, den1,num2,den2);
        reduced(&anum,&aden);
        displayRational(num,den);
        char user = '\0';
        cout << "Do you want to do more additions? (Y/N): ";
        cin >> user;
        cin.ignore();
        if(user == ('N' || 'n'))
        {
            break;
        }
        else 
        {
            showMenu();
        }
    }
}
void sub()
{
    system("CLS");
    int num,den;
    int num1,den1,num2,den2,anum,aden;
    cout << "Subtraction of Rational Numbers" << endl;
    while(true)
    {
        getRational(&num1, &den1);
        getRational(&num2, &den2);
        subRational(&anum,&aden, num1, den1,num2,den2);
        reduced(&anum,&den);
        displayRational(num,den);
        char user = '\0';
        cout << "Do you want to do more additions? (Y/N): ";
        cin >> user;
        cin.ignore();
        if(user = 'N')
        {
            break;
        }
        else
        {
            showMenu();
        }
        
    }
}
int main()
{
    char op;
    int num,den;
    int num1,den1,num2,den2,anum,aden;
    showMenu();
    cout <<"Enter your option: ";
    cin >> op;
    if(op == 'S')
    {
        sub();
    }
    else if (op == 'A')
    {
        add();
    }
    else if(op =='Q')
    {
        system("CLS");
        cout << "thank you!" << endl;
        
    }
    else
    {
        cout << "Please enter options: A ,S ,or Q"<< endl;
    }
    return 0;
}
