#include <iostream>
#include <vector>
using namespace std;

bool is_safe(int row, int col, vector<vector<int>> &box, int n)
{
    int a, b;
    a = row;
    b = col;

    while (b >= 0)
    {
        if (box[a][b] == 1)
        {
            return false;
        }
        b--;
    }

    a = row;
    b = col;

    while (a >= 0 && b >= 0)
    {
        if (box[a][b] == 1)
        {
            return false;
        }
        a--;
        b--;
    }

    a = row;
    b = col;

    while (a < n && b >= 0)
    {
        if (box[a][b] == 1)
        {
            return false;
        }
        a++;
        b--;
    }

    return true;
}

void N_queen(int col, int n, vector<vector<int>> &box)
{
    if (col == 8)
    {
        int ans[n] = {0};
        cout<<"\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<box[i][j]<<" ";
                if(box[i][j] == 1)
                {
                    ans[i] = j+1;
                }
            }
            cout<<"\n";
        }

        cout<<"\n\nYou can place a queen at each row of column !!!! \n| ";
        for(int i = 0; i < n; i++)
        {
            cout<<ans[i]<<" | ";
        }
        exit(0);
    }
    for (int row = 0; row < n; row++)
    {
        if (is_safe(row, col, box, n))
        {
            box[row][col] = 1;
            // cout << "places at : " << row << col << endl;
            N_queen(col + 1, n, box);
            box[row][col] = 0;
        }
    }
}

int main()
{
    int n = 8;
    vector<vector<int>> box(n, vector<int>(n));
    N_queen(0, n, box);
    return 0;
}

/*
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
