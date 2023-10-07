#include <iostream>
#include <queue>
using namespace std;
char al[31][31] = {'.'};
int num[5001] = {0};
int R, C = 0;
int direcx[4] = {0, 0, 1, -1};
int direcy[4] = {1, -1, 0, 0};
int visited[21][21] = {0};
int maxa = 1;
int ans = 1;
void bfs(int sx, int sy)
{
    for (int i = 0; i < 4; i++)
    {
        int dx = sx + direcx[i];
        int dy = sy + direcy[i];

        if (dx < 0 || dy < 0 || dx >= R || dy >= C)
        {
            continue;
        }
        if (num[al[dx][dy]] <= 0 && visited[dx][dy] == 0)
        {
            // cout << dx << " " << dy << "s";
            visited[dx][dy]++;
            num[al[dx][dy]]++;
            maxa++;
            if (maxa > ans)
            {
                ans = maxa;
            }
            bfs(dx, dy);
            visited[dx][dy] = 0;
            num[al[dx][dy]]--;
            maxa--;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        char c[10001];
        cin >> c;
        for (int j = 0; j < C; j++)
        {
            al[i][j] = c[j];
        }
    }
    visited[0][0] = 1;
    num[al[0][0]]++;
    bfs(0, 0);
    cout << ans;
}