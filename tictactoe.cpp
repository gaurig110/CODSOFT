#include <iostream>
#include <cstdlib>
using namespace std;

//play(display,move,check,continue until win/draw)
void play()
{
    char board[3][3] = { {'-','-','-'},{'-','-','-'},{'-','-','-'} },curr = 'X';
    int moves= 0,win=0,i,num,row,col;
    do
    {
        cout<<endl;
        for(i = 0; i < 3; i++) 
        {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
            if (i < 2) 
            {
                cout << "---|---|---\n";
            }
        }
        cout << "\nPlayer " << curr << ", enter (1 - 9) for your move : ";
        cin >> num;
        row = (num - 1) / 3;
        col = (num - 1) % 3;
        if (num < 1 || num > 9 || board[row][col] == 'X' || board[row][col] == 'O') 
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }
        board[row][col] = curr;
        moves++;

        //checking for win(row/col/diagonal)
        for (int i = 0; i < 3; i++) 
        {
            if (board[i][0] == curr && board[i][1] == curr && board[i][2] == curr) 
            {
                win =1;
            }
        }
        if(win==0)
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[0][j] == curr && board[1][j] == curr && board[2][j] == curr) 
                {
                    win =1;
                }
            }
        }
        if(win==0)
        {
            if ((board[0][0] == curr && board[1][1] == curr && board[2][2] == curr) ||
            (board[0][2] == curr && board[1][1] == curr && board[2][0] == curr)) 
            {
                win=1;
            }
        }

        if(win)
        {
            for(i = 0; i < 3; i++) 
            {
                cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
                if (i < 2) 
                {
                    cout << "---|---|---\n";
                }
            }
            cout<<"\nPlayer "<< curr <<" won !!! Congrats !!!";
        }
        else if (moves == 9)
        {
            for(i = 0; i < 3; i++) 
            {
                cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
                if (i < 2) 
                {
                    cout << "---|---|---\n";
                }
            }
            cout << "\nGame is a draw!\n";
            win=1;
        }
        else
        {
            curr = (curr == 'X' ? 'O' : 'X');
        }
    }while (!win);   
}

//instructions
void instruct()
{
    cout<<"--- INSTRUCTIONS ---\nThis is a 2 - player Tic - Tac - Toe game.\n";
    cout << "Players take turns to enter numbers 1 - 9 corresponding to the board positions.\n";
    cout << "First player is X, second player is O.\nGet three of your symbol in a row (horizontal,";
    cout<<" vertical or diagonal) to win.\nIf all cells are filled and no one wins, it' s a draw.\n";
}

//main function : ASCII art to show the game board, input from two players and output(Win/Draw)
int main()
{
    int c;
    cout<<"      |     |     \n   1  |  2  |  3  \n _____|_____|_____\n      |     |     \n   4  |  5  |  6  ";
    cout<<"\n _____|_____|_____\n      |     |     \n   7  |  8  |  9  \n      |     |     \n";
    cout<<"\n--- WELCOME TO TicTacToe ---\n\n";
    do
    {
        cout<<"--- MENU ---\nEnter:-\n1 - Play.\n2 - Read instructions.\n3 - Exit.\nEnter choice : ";
        cin>>c;
        if(c==1)
        {
            play();
        }
        else if(c==2)
        {
            instruct();
        }
        else if(c==3)
        {
            exit(0);
        }
        else
        {
            cout<<"Invalid input.";
        }
        cout<<"\n\nEnter 1 to continue or 0 to exit. ";
        cin>>c;
        cout<<endl;
    } while(c);
    return 0;
}