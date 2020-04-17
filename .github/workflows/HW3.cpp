- name: Setup C++
  uses: Trass3r/setup-cpp@v1
// Samantha start code from here 
#include <iostream>
using namespace std;
void showMenu();
int main()
{
    showMenu();
    if( op == 'A' || op == 'a')
    {
        add();
    }
    else if(op == 'S' || op == 's')
    {
        sub();
    }
    else if(op = 'Q'|| op = 'q')
    {
        cout << "thank you!" << endl;
    }
    else
    {
        cout << "please enter options: A ,S ,or Q"
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


