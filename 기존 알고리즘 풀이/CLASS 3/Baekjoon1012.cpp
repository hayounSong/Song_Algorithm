#include <iostream>
using namespace std;

int field[51][51] = {0};
int visited[51][51] = {0};
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int garo, sero;
void dfs(int a, int b)
{
    visited[a][b] = 1;

    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i];
        int y = b + dy[i];

        if (x >= 0 && x < garo && y >= 0 && y < sero)
        {
            if (field[x][y] == 1)
            {
                if (visited[x][y] == 0)
                {
                    dfs(x, y);
                }
            }
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int iad = 0; iad < N; iad++)
    {
        ans = 0;

        cin >> garo;

        cin >> sero;
        int n;
        cin >> n;

        for (int i = 0; i < garo; i++)
        {
            for (int j = 0; j < sero; j++)
            {
                field[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            field[a][b] = 1;
        }

        for (int i = 0; i < garo; i++)
        {
            for (int j = 0; j < sero; j++)
            {
                if (visited[i][j] == 0 && field[i][j] == 1)
                {

                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
}