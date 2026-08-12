#include <iostream>
using namespace std;

void displayBoard(char board[3][3])
{
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | "
             << board[i][1] << " | "
             << board[i][2] << endl;

        if (i < 2)
        {
            cout << "---|---|---" << endl;
        }
    }
}

void playerMove(char board[3][3], char currentPlayer)
{
    int position;

    while (true)
    {
        cout << "\nPlayer " << currentPlayer
             << ", enter your position (1-9): ";

        cin >> position;

        if (position < 1 || position > 9)
        {
            cout << "Invalid position! Please choose 1-9." << endl;
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Position already occupied! Choose another position."
                 << endl;
            continue;
        }

        board[row][col] = currentPlayer;
        break;
    }
}

bool checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

char switchPlayer(char currentPlayer)
{
    if (currentPlayer == 'X')
    {
        return 'O';
    }
    else
    {
        return 'X';
    }
}

void resetBoard(char board[3][3])
{
    char value = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value;
            value++;
        }
    }
}

int main()
{
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y')
    {
        cout << "\n==========================" << endl;
        cout << "      TIC TAC TOE" << endl;
        cout << "==========================" << endl;

        char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver)
        {
            displayBoard(board);

            playerMove(board, currentPlayer);

            if (checkWin(board, currentPlayer))
            {
                displayBoard(board);

                cout << "\nPlayer " << currentPlayer << " wins!" << endl;

                gameOver = true;
            }
            else if (checkDraw(board))
            {
                displayBoard(board);

                cout << "\nGame is a draw!" << endl;

                gameOver = true;
            }
            else
            {
                currentPlayer = switchPlayer(currentPlayer);
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
    }

    cout << "\nThank you for playing!" << endl;

    return 0;
}
