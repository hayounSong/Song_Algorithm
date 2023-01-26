#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int direcx[4] = {0, 1, -1, 0};
int direcy[4] = {1, 0, 0, -1};
string in[101];
int num[101][101];
int visited[101][101];

int main()
{

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string imsi;
        cin >> imsi;
        for (int j = 1; j <= M; j++)
        {
            num[i][j] = imsi[j - 1] - '0';
        }
    }

    queue<pair<int, int>> q;

    q.push(make_pair(1, 1));
    visited[1][1] = 1;

    while (!q.empty())
    {

        pair<int, int> front;
        front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int px = front.first + direcy[i];
            int py = front.second + direcx[i];

            if (px > 0 && px <= N && py > 0 && py <= M)
            {

                if (visited[px][py] == 0 && num[px][py] == 1)
                {
                    if (px == N && py == M)
                    {

                        cout << visited[front.first][front.second] + 1;
                        return 0;
                    }
                    // cout << px << " ";
                    q.push(make_pair(px, py));
                    visited[px][py] = visited[front.first][front.second] + 1;
                }
            }
        }
    };
}