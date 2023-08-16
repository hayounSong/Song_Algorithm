#include <iostream>
#include <queue>
using namespace std;
int qs[100001];
long ps[100001];
int N;
int M;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    deque<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> qs[i];
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (qs[i] == 0)
        {
            q.push_back(a);
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> ps[i];
        if (!q.empty())
        {

            cout << q.back() << " ";

            q.pop_back();

            q.push_front(ps[i]);
        }
        else
        {
            cout << ps[i] << " ";
        }
    }
}