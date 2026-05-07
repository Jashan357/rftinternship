#include<bits/stdc++.h>
using namespace std;

class BANKACCOUNT{
private:
int BALANCE;
int ACC_NUMBER;
string HOLD_NAME;

public:
BANKACCOUNT(string name,int acc_num,int init_balance){
   ACC_NUMBER=acc_num;
    HOLD_NAME= name;
    BALANCE=init_balance;
}

void Deposit(int dep_amnt){    //setter
   BALANCE+=dep_amnt;
}

void Withdraw(int req_amount){
   if(BALANCE>=req_amount){
     BALANCE=BALANCE-req_amount;
    cout<<"amount withdrawl successful ,this remaining balance is:"<<BALANCE;
   }
   else{
    cout<<"Transaction not possible";
   }
}

void DISPLAY_BALANCE(){
    cout<<"current balance:"<<BALANCE;
}


};

int main(){
string name;
int acc_num;
int init_balance;

cout<<"enter name:";
getline(cin,name);

cout<<"account no. :-\n";
cin>>acc_num;

cout<<"enter initial balance:";
cin>>init_balance;

BANKACCOUNT b(name,acc_num,init_balance);

int choice;
int amount;
do{
    cout<<"......../MENU/......"<<endl;
    cout<<"1.deposit amount"<<endl;
    cout<<"2.display balance"<<endl;
    cout<<"3.withdraw money"<<endl;
    cout<<"4. EXIT"<<endl;

    cout<<"enter from 1-4\n";
cin>>choice;
    switch(choice){
        case 1: cout<<"enter amount to be deposit:";
                cin>>amount;
                b.Deposit(amount);
                break;

        case 2: b.DISPLAY_BALANCE();
                    break;

        case 3: cout<<"enter amount to be withdrawl:";
                cin>>amount;
                b.Withdraw(amount);
                break;

        case 4: cout<<"EXIT";
                break;

          default:cout<<"INVALID INPUT";
    }
    
}
while(choice!=4);

return 0;
}