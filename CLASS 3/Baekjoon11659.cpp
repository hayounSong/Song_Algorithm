#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int num;
    int que;

    cin >> num >> que;
    long long list[num + 1];
    int calc = 0;
    list[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        long long a;
        cin >> a;
        list[i] = list[i - 1] + a;
    }

    for (int i = 0; i < que; i++)
    {

        int start, end;
        cin >> start >> end;
        int ans = list[end] - list[start - 1];
        cout << ans << '\n';
    }
    return 0;
}