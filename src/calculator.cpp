#include <iostream>
#include <cmath>

using namespace std;

long factorial(int n){
    if(n<=1) return 1;
    return n*factorial(n-1);
}

int main(){

    int choice;

    while(true){

        cout<<"\nScientific Calculator\n";
        cout<<"1 Square Root\n";
        cout<<"2 Factorial\n";
        cout<<"3 Natural Log\n";
        cout<<"4 Power\n";
        cout<<"5 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            double x;
            cout<<"Enter number: ";
            cin>>x;
            cout<<"Result: "<<sqrt(x)<<endl;
        }

        else if(choice==2){
            int n;
            cout<<"Enter number: ";
            cin>>n;
            cout<<"Result: "<<factorial(n)<<endl;
        }

        else if(choice==3){
            double x;
            cout<<"Enter number: ";
            cin>>x;
            cout<<"Result: "<<log(x)<<endl;
        }

        else if(choice==4){
            double a,b;
            cout<<"Enter base: ";
            cin>>a;
            cout<<"Enter power: ";
            cin>>b;
            cout<<"Result: "<<pow(a,b)<<endl;
        }

        else if(choice==5)
            break;

        else
            cout<<"Invalid\n";
    }
}
//test
//test
//test2
//test3
//test3
