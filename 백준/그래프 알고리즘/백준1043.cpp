#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int people[51] = {0};
vector<int> party[51];
vector<int> partici[51];
vector<int> who;
int checked[51] = {0};

void bfs(int start)
{
    queue<int> q;
    checked[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < partici[now].size(); i++)
        {

            int nextparty = partici[now][i];
            for (int j = 0; j < party[nextparty].size(); j++)
            {

                int nextperson = party[nextparty][j];
                if (checked[nextperson] == 0 && people[nextperson] == 0)
                {

                    checked[nextperson] = 1;
                    people[nextperson] = 1;
                    q.push(nextperson);
                }
            }
        }
    }
}

int main()
{

    int N, M;
    cin >> N >> M;

    int tru;
    cin >> tru;

    for (int i = 0; i < tru; i++)
    {
        int a;
        cin >> a;
        people[a] = 1;
        who.push_back(a);
    }

    for (int i = 0; i < M; i++)
    {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            int a;
            cin >> a;
            party[i].push_back(a);
            partici[a].push_back(i);
        }
    }

    for (int i = 0; i < who.size(); i++)
    {
        bfs(who[i]);
    }
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int lie = 0;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (people[party[i][j]] == 1)
            {

                lie = 1;
                break;
            }
        }
        if (lie == 0)
        {

            ans++;
        }
    }
    cout << ans;
}