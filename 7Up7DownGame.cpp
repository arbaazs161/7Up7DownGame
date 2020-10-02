#include<iostream>
#include<ctime>
#include<string>
#include<conio.h>
using namespace std;

class User{
    string username;
    int score = 0,compScore = 0;
    int choice = 0;
    bool result = false;
    public:

    User(string username){
        this->username = username;
    }

    void startGame()
    {
        cout<<"5 Rounds to go..."<<"\n";
        int i=0;
        int *compNum;
        
        while(i < 5)
        {
            cout<<"\n1.   7 UP  | 2.   7   |  3.   7 Down   "<<"\nEnter Choice : ";
            cin>>choice;
            compNum = genNum();
            result = compareResult(choice,compNum[0]);

            if(result == 0){
                compScore++;
            }
            else{
                score++;
            }

            
            cout<<"Computers Number : "<<compNum[1];

            cout<<"\nYour Score : "<<score;
            i++;
        }

        cout<<"\n\nGame Over\n\n";
        if(compScore>score){
            cout<<"You Lose "<<username;
        }
        else{
            cout<<"You Won "<<username;
        }
    }

    int* genNum()
    {
        int *arr = new int[2];
        srand(time(0));
        int num = rand()%15 + 1;
        if(num > 7){
            arr[0] = 1;
            arr[1] = num;
            return arr;
        }
        else if(num == 7){
            arr[0] = 2;
            arr[1] = num;
            return arr;
        }
        else if(num < 7){
            arr[0] = 3;
            arr[1] = num;
            return arr;
        }
        arr[0] = 0;
        arr[1] = num;
        return arr;
    }



    int compareResult(int userNum, int compNum){
        if(userNum == compNum)
        {return 1;}

        return 0;
    }

    
};

void main()
{
    
    string name;
    cout<<"Enter your Name to start : ";
    cin>>name;
    //cout<<name;

    User user(name);
    user.startGame();
    getch();
}