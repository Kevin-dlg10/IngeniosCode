- name: Setup C++
  uses: Trass3r/setup-cpp@v1
// Samantha start code from here 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;
void showMenu();
void add();
void sub();
//void addRational();

int main()
{
    char op;
    showMenu();
    if( op = ('A' || 'a'))
    {
        add();
    }
    else if(op = ('S' || 's'))
    {
        sub();
    }
    else if(op = ('Q'||'q'))
    {
        cout << "thank you!" << endl;
    }
    else
    {
        cout << "Please enter options: A ,S ,or Q"<< endl;
    }

    return 0;
}
void showMenu()
{
    char op;
    cout << "Rational Numbers Calculator" << endl;
    cout << endl;
    cout <<"(A) ddition" <<endl;
    cout <<"(S) ubtraction" << endl;
    cout <<"(Q) uit" << endl;
    cout << endl;
    cout <<"Enter your option: ";
    cin >> op;
}
void getRational(int *num, int *den)
{
    string numstr,denstr,str;
    cout << "Please Enter a fraction (n/d): ";
    getline(cin,str);
    stringstream s_stream1(str);
    getline (s_stream1,numstr,'/');
    getline (s_stream1,denstr,'/');
    *num = stoi(numstr);
    *den = stoi(denstr);
    cout << *num << *den << endl;
    
}
void add()
{
    system("CLS");
    int num1,den1,num2,den2,anum,aden;
    while(true)
    {
        cout << "Addition of Rational Numbers" << endl;
        
        cout << endl;
        getRational(&num1, &den1);
        getRational(&num2, &den2);
    }
}
void sub()
{
    system("CLS");
    int num1,den1,num2,den2,anum,aden;
    while(true)
    {
        cout << "Subtraction of Rational Numbers" << endl;
        cout << endl;
        getRational(&num1, &den1);
        getRational(&num2, &den2);
    }
}
