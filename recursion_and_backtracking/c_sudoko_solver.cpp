#include <bits/stdc++.h>
using namespace std;
bool solved = false;
void helper(vector<vector<char>> &board, int x, int y, vector<vector<int>> &rowCheck, vector<vector<int>> &colCheck, vector<vector<vector<int>>> &gridCheck)
{
    if (y == 9)
    {
        solved = true;
        return;
    }
    else
    {
        if (board[x][y] == '.')
        {
            for (int i = 1; i < 10; i++)
            {
                if (rowCheck[x][i] == 0)
                {
                    if (colCheck[y][i] == 0)
                    {
                        if (gridCheck[x / 3][y / 3][i] == 0)
                        {
                            board[x][y] = i + '0';
                            rowCheck[x][i] = 1;
                            colCheck[y][i] = 1;
                            gridCheck[x / 3][y / 3][i] = 1;
                            if (x == 8)
                                helper(board, 0, y + 1, rowCheck, colCheck, gridCheck);
                            else
                                helper(board, x + 1, y, rowCheck, colCheck, gridCheck);
                            if (solved)
                                break;
                            board[x][y] = '.';
                            rowCheck[x][i] = 0;
                            colCheck[y][i] = 0;
                            gridCheck[x / 3][y / 3][i] = 0;
                        }
                    }
                }
            }
        }
        else
        {
            if (x == 8)
                helper(board, 0, y + 1, rowCheck, colCheck, gridCheck);
            else
                helper(board, x + 1, y, rowCheck, colCheck, gridCheck);
        }
    }
}
int main()
{
    vector<vector<char>> board(9, vector<char>(9));

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> board[i][j];

    vector<vector<int>> rowCheck(9, vector<int>(10, 0));
    vector<vector<int>> colCheck(9, vector<int>(10, 0));
    vector<vector<vector<int>>> gridCheck(3, vector<vector<int>>(3, vector<int>(10, 0)));
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0';
                rowCheck[i][num] = 1;
                colCheck[j][num] = 1;
                gridCheck[i / 3][j / 3][num] = 1;
            }
        }
    }

    helper(board, 0, 0, rowCheck, colCheck, gridCheck);

    for (const auto &row : board)
    {
        for (const auto &cell : row)
            cout << cell << " ";
        cout << "\n";
    }

    return 0;
}
