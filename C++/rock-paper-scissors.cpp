// Rock, Paper, Scissors using IF/ELSE statements!

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int user,bot;
    char repeat = 'y';
    srand(time(NULL));
    bot=rand()%3+1;
    
    while(repeat == 'y'){
        cout<<"\n\nPick one:"<<endl;
        cout<<"1. Rock\n";
        cout<<"2. Paper\n";
        cout<<"3. Scissors\n";
        cout<<"Enter your choice: ";
        cin>>user;

        if(user==1){
            cout<<"You: Rock!"<<endl;
            if(bot==1){
                cout<<"Bot: Rock! \n"<<"Tie!";
            }
            else if(bot==2){
                cout<<"Bot: Paper! \n"<<"You Lose!";
            }
            else{
                cout<<"Bot: Scissors! \n"<<"You Win!";
            }
        }

        else if(user==2){
            cout<<"You: Paper!"<<endl;
            if(bot==1){
                cout<<"Bot: Rock! \n"<<"You Win!";
            }
            else if(bot==2){
                cout<<"Bot: Paper! \n"<<"Tie!";
            }
            else{
                cout<<"Bot: Scissors! \n"<<"You Lose!";
            }
        }

        else if(user==3){
            cout<<"You: Scissors!"<<endl;
            if(bot==1){
                cout<<"Bot: Rock! \n"<<"You Lose!";
            }

            else if(bot==2){
                cout<<"Bot: Paper! \n"<<"You Win!";
            }
            else{
                cout<<"Bot: Scissors! \n"<<"Tie!";
            }
        }

        else{
            cout<<"Error!"<<endl;
        }

        cout<<"\n\nDo you wanna play again? (y/n): ";
        cin>>repeat;
    }
}