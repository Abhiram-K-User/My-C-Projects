#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
char board[3][3];

int i,j;
void board_initialisor()
{
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    board[i][j]=' ';
}

void cheating_checker(int a,int b)
{

    if(board[a][b]!=' ')
    {
        cout<<"Invalid Input";
        exit(0);
    }
}
void win_declare(char inp)
{
    cout<<inp<<" has won!";
    exit(0);
}

bool tie_checker()
{
    int x=9;
    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    {
        if(board[i][j]!=' ')
        x--;
    }
    }
    if(x==0)
    {
        cout<<"The game is a tie";
        exit(0);
    }
    else
    x=9;
    return false;
}
void win_checker(char inp)
{
    int  counter=0;
    //Checks from left to right
    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    {
        if(board[i][j]==inp)
         counter++;
        if( counter==3)
        {
        win_declare('X');
        }
    }
     counter=0;
    }

    //Checks from top to bottom
    for(j=0;j<3;j++)
    {
    for(i=0;i<3;i++)
    {
        if(board[i][j]==inp)
         counter++;
        if( counter==3)
        {
        win_declare(inp);
        }
    }
     counter=0;
    }
    //Checks diagonally
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' ')
    {
        win_declare(inp);
    }
    //...
    else if(board[2][0]==board[1][1]&&board[2][0]==board[0][2]&&board[2][0]!=' ')
    {
        win_declare(inp);
    }

}

void board_printer()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        cout<<"|"<<board[i][j];
        }
        cout<<"|";
        cout<<"\n";
    }
}



int main(void)
{
    int x1,x2,o1,o2;
    board_initialisor();
    board_printer();
    cout<<"X's turn. Enter the co-ordinates"<<"\n";
    cin>>x1>>x2;
    cheating_checker(x1,x2);
    board[x1][x2]='X';
    board_printer();
    for(i=0;i<8;i++)
    {
        cout<<"O's turn,Enter the coordinates"<<"\n";
        cin>>o1>>o2;
        cheating_checker(o1,o2);
        board[o1][o2]='O';
        win_checker('O');
        board_printer();
        cout<<"X's turn. Enter the co-ordinates"<<"\n";
        cin>>x1>>x2;
        cheating_checker(x1,x2);
        board[x1][x2]='X';
        win_checker('X');
        board_printer();
        
    }
    cout<<"The game is a tie.";

}