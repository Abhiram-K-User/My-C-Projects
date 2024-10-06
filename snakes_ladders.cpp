#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

class snakes
{
    private: 
    int i1,i2,s,dice,counter1,counter2,i;
    string player1,player2;
    char board[100];
    public:
    void initialize()
    {
        srand(time(0)); //Picks the seed for the random number generator based on system time
        for(i=0;i<100;i++)
        board[i]='X';
        //Creating Ladders
        for(i=0;i<7;i++)
        {
            s=rand()%99+1;
            while(board[s]=='L')
            s=rand()%100;
            board[s]='L';
        }
        for(i=0;i<7;i++) //Creating Snakes
        {
        s=rand()%90+10;
        while(board[s]=='S'||board[s]=='L')
        s=rand()%90+10; //Chooses a random number between 0 and 99
        board[s]='S';
        }
    }

    void print()
    {
        for(i=0;i<100;i++)
        {
            if(i%10==0)
            {
                cout<<"\n";
            }
            cout<<board[i]<<"\t";
        }
        cout<<"\n";
    }
    void game()
    {
        srand(time(0));
        i1=0,counter1=0,counter2=0,i2=0;
        //Name Creation
        cout<<"Enter the name of player 1"<<"\n";
        cin>>player1;
        cout<<"Enter the name of player 2"<<"\n";
        cin>>player2;
        
        while(i1<=100&&i2<=100)
        {
        //Dice Roll 1
        cout<<player1<<"'s Turn"<<"\n";
        counter1++;
        dice=rand()%6+1;
        cout<<"Rolled a "<<dice<<"!"<<"\n";
        i1=i1+dice;
        if(i1>99)
        break;
        cout<<"The player "<<player1<<" is at position "<<i1<<"\n";
        //....
        while(board[i1]=='S')
        {
        cout<<"Uh oh!"<<player1<<" was attacked by a snake!"<<"\n";
        i1=i1-9;
        cout<<"The player "<<player1<<" is at position "<<i1<<"\n";
        }
        while(board[i1]=='L')
        {
            cout<<player1<<" climbed a Ladder!"<<"\n";
            if(i1+10>=100)
            break;
            else
            i1=i1+10;
            cout<<"The player "<<player1<<" is at position "<<i1<<"\n";
        }
        //Dice Roll 2
        cout<<player2<<"'s turn"<<"\n";
        counter2++;
        dice=rand()%6+1;
        i2=i2+dice;
        cout<<"Rolled a "<<dice<<"!"<<"\n";
        if(i2>99)
        break;
        cout<<"The player "<<player2<<" is at position "<<i2<<"\n";
        //...
        while(board[i2]=='S')
        {
        cout<<"Uh oh! "<<player2<<" was attacked by a snake!"<<"\n";
        i2=i2-9;
        cout<<"The player "<<player2<<" is at position "<<i2<<"\n";
        }
        while(board[i2]=='L')
        {
            cout<<player2<<" climbed a Ladder!"<<"\n";
            if(i2+10>=100)
            break;
            else
            i2=i2+10;
            cout<<"The player "<<player2<<" is at position "<<i2<<"\n";
        }
        }
        // Win Declaration
        if(i1>=100)
        cout<<"The player "<<player1<<" has won in "<<counter1<<" dice rolls"<<"\n";
        else if(i2>=100)
        cout<<"The player "<<player2<<" has won in "<<counter2<<" dice rolls"<<"\n";
        else
        cout<<"ERROR! WINNER NOT DETECTED!"<<"\n";
    }
};
int main(void)
{
    snakes ob1;
    ob1.initialize();
    ob1.print();
    ob1.game();
}
