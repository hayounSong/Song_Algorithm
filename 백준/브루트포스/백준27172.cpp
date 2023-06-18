#include <iostream>
#include <vector>
using namespace std;

int N;
int card[10000001];
int score[10000001] = {0};
vector<int> numbers;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
        card[a] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = numbers[i] * 2; j < 1000001; j += numbers[i])
        {
            if (card[j] == 1 && j % numbers[i] == 0)
            {
                score[j]--;
                score[numbers[i]]++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << score[numbers[i]] << " ";
    }
}