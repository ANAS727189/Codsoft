#include<iostream>
using namespace std;


int main() {
    int a, b;
    char c;
    cout<<"Enter the numbers and the operation to perform : "<<endl;
    cin>>a>>b;
    cin>>c;

    switch(c) {
        case '+':
                cout<<a +b<<endl;
                break;

        case '-':
                cout<<a-b<<endl;
                break;

        case '*':
                cout<<a*b<<endl;
                break;

        case '/':
               if(b != 0)
                cout<<a/b<<endl;
               else cout<<"Number divided by 0 is undefined "<<endl;
                break;
    }
    cout<<"Game ended by bye ! "<<endl;
}