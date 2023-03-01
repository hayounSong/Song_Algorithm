#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int T;
int A, B;
string visited[20001];

int D(int num)
{

    num = num * 2;

    return num % 10000;
}

int S(int num)
{

    num = num - 1;
    if (num < 0)
    {
        num = 9999;
    }
    return num;
}

int L(int num)
{

    num = (num % 1000) * 10 + num / 1000;
    return num;
}
int R(int num)
{
    num = (num % 10) * 1000 + num / 10;
    return num;
}

void bfs(int start, int end)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> q;
    visited[start] = "X";
    q.push(start);

    while (!q.empty())
    {
        int front = q.front();

        if (front == end)
        {
            return;
        }
        q.pop();

        int d = D(front);

        if (visited[d].size() == 0)
        {
            q.push(d);
            visited[d] = visited[front] + "D";
        }

        d = S(front);

        if (visited[d].size() == 0)
        {
            q.push(d);
            visited[d] = visited[front] + "S";
        }

        d = L(front);

        if (visited[d].size() == 0)
        {
            q.push(d);
            visited[d] = visited[front] + "L";
        }
        d = R(front);

        if (visited[d].size() == 0)
        {
            q.push(d);
            visited[d] = visited[front] + "R";
        }
    }
}
int main()
{
    cin >> T;

    for (int dd = 0; dd < T; dd++)
    {
        fill(visited, visited + 10001, "");
        cin >> A >> B;

        bfs(A, B);
        for (int i = 1; i < visited[B].size(); i++)
        {
            cout << visited[B][i];
        }
        cout << "\n";
    }
}
