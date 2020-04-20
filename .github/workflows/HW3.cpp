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
void addition();
void subtraction();
void disRat(int,int );

//this function shows the menu, where everything begins.
// we decided we didnt want to input here but to be used as a frame in some sort to just display the option
void showMenu(){
    cout << "Rational Numbers Calculator" << endl;
    cout << "(A)dditon" << endl;
    cout << "(S)ubtraction" << endl;
    cout << "(Q)uit" << endl;
    cout << "Enter your option: " << endl;
}

//this functions gets the rational of both fractions
void getRat(int *num1, int *den1, int *num2,int *den2){
    bool start = true;
    string input1, input2;
    string numstr1,denstr1;
    string numstr2,denstr2;

    while(start){
        cout << "Please enter a function (n/d): "; 
        cin >>input1;
        stringstream str_stream(input1);
        getline(str_stream,numstr1,'/');
        getline(str_stream,denstr1,'/');
        *num1 = stoi(numstr1);
        *den1 = stoi(denstr1);
        cout << "Please enter a function (n/d): "; 
        cin >>input2;
        stringstream inp_stream(input2);
        getline(inp_stream,numstr2,'/');
        getline(inp_stream,denstr2,'/');
        *num2 = stoi(numstr2);
        *den2 = stoi(denstr2);
        if (den1==0 || den2 == 0){
            cout << "Try again" << endl;
            start=true;
        }
        else if(den1!=0 || den2 !=0){
            start=false;
        }
    }
}


// finding  return value : GCF
int reduce(int anum,int aden)
{
   if (aden == 0) 
      return anum; 
   return reduce(aden, anum % aden);  
} 
// we then applied reduce in the function of add
// we then got the reduction in terms of our own, not in eliud's format
void addRat(int anum,int aden, int num1, int den1,int num2,int den2)
{
    anum = ((num1*den2)+(num2*den1));
    aden = (den1*den2);
     int gcf = reduce(anum,aden); 
     anum = anum / gcf;
     aden = aden / gcf;
    disRat(anum,aden);

}
void subRat(int anum, int aden, int num1, int den1, int num2, int den2)
{
    anum = ((num1*den2)-(num2*den1));
    aden = (den1*den2);
    int gcf = reduce(anum,aden); 
    anum = anum / gcf;
    aden = aden / gcf;
    disRat(anum,aden);
}

void disRat(int anum, int aden)
{
    if (aden  > 1){
        cout << "The result is: "<< anum << "/"<< aden << endl;
    }
    else
    {
        cout << "The result is: " << anum << endl;
    }
    
}   
void quit(){
    system("CLS");
    cout << "Thank you bye bye!!" << endl;
}
int main()
{
    char op;
    int num,den;
    int num1,den1,num2,den2,anum,aden;
    showMenu();
    cin >> op;
    if(op == 'S')
    {
        subtraction();
    }
    else if (op == 'A')
    {
        addition();
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
void addition()
{
    //you can use Dr. Kim's reference code as a starting point to
    //in his rough code, he uses 6 int variables
   system("CLS");
    int num1,den1,num2,den2,anum,aden;
     cout << "Addition of Rational Numbers" << endl;
    while(true)
    {
        cout << endl;
        getRat(&num1, &den1, &num2, &den2); 
        addRat(anum,aden, num1, den1,num2,den2); 
        char user = '\0';
        cout << "Do you want to do more additions? (Y/N): ";
        cin >> user;
        cin.ignore();
        if(user == 'N')
        {
            quit();
            break;
        }
        else 
        {
            addition();
        }
    }
}

//your subtraction and addition functions should look fairly similar since they do
//basically the same job
void subtraction()
{
//you need to use the same number of integer variables as the addition function
    system("CLS");
    int num1,den1,num2,den2,anum,aden;
    cout << "Subtraction of Rational Numbers" << endl;
    while(true){
        getRat(&num1, &den1,&num2,&den2);
        subRat(anum,aden, num1, den1,num2,den2);
        char user = '\0';
        cout << "Do you want to do more additions? (Y/N): ";
        cin >> user;
        cin.ignore();
        if(user = 'N')
        {
            break;
            quit();
        }
        else
        {
            subtraction();
        }
        
    }
}
