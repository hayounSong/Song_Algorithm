#include <iostream>
using namespace std;

int N, M;
int sd;
int room[101][101];
int direcx[4] = {-1, 0, 1, 0};
int direcy[4] = {0, 1, 0, -1};
int main()
{
    int cx, cy;
    cin >> N >> M;
    cin >> cx >> cy;
    cin >> sd;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }
    int cd = sd;
    int ans = 0;
    while (true)
    {

        if (room[cx][cy] == 0)
        {
            // cout << cx << " " << cy;
            // cout << endl;
            room[cx][cy] = 2;
            ans++;
            continue;
        }
        int chec = 0;
        for (int i = 0; i < 4; i++)
        {
            int px = cx + direcx[i];
            int py = cy + direcy[i];

            if (px < 0 || py < 0 || px >= N || py >= M)
            {

                continue;
            }
            else if (room[px][py] == 0)
            {

                chec = 1;
                break;
            }
        }

        if (chec == 0)
        {
            int px = cx - direcx[cd];
            int py = cy - direcy[cd];
            // cout << cd;
            if (px < 0 || py < 0 || px >= N || py >= M)
            {
                // ans++;
                break;
            }
            else if (room[px][py] == 1)
            {
                // ans++;
                break;
            }
            else
            {
                cx = px;
                cy = py;
            }
            // ans++;

            continue;
        }
        else if (chec == 1)
        {

            for (int g = 0; g < 4; g++)
            {
                cd = cd - 1;

                if (cd < 0)
                {
                    cd = cd + 4;
                }
                int px = cx + direcx[cd];
                int py = cy + direcy[cd];

                if (px < 0 || py < 0 || px >= N || py >= M)
                {
                    continue;
                }
                else if (room[px][py] == 0)
                {
                    // cout << cd << endl;
                    cx = px;
                    cy = py;

                    break;
                }
            }
            // continue;
        }
    }
    cout << ans;
}