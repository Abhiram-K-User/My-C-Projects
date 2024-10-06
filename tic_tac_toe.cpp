#include<iostream>
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

void win_declare(char inp)
{
    cout<<inp<<" has won!";
    exit(0);
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
        if(counter==3)
        {
        win_declare(inp);
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

void input_validator(int &a, int &b, char var)
{
    while(board[a][b]!=' '||a>2||b>2||a<0||b<0)
    {
        cout<<"Invalid Input. Try again!"<<"\n";
        cin>>a>>b;
    }
    board[a][b]=var;
}

int main(void)
{
    int x1,x2,o1,o2,itr;
    board_initialisor();
    board_printer();
    cout<<"X's turn. Enter the co-ordinates"<<"\n";
    cin>>x1>>x2;
    input_validator(x1,x2,'X');
    board_printer();
    for(itr=0;itr<4;itr++)
    {
        cout<<"O's turn,Enter the coordinates"<<"\n";
        cin>>o1>>o2;
        input_validator(o1,o2,'O');
        win_checker('O');
        board_printer();
        //
        cout<<"X's turn, Enter the coordinates"<<"\n";
        cin>>x1>>x2;
        input_validator(x1,x2,'X');
        win_checker('X');
        board_printer();  
    }
    cout<<"The game is a tie.";

}