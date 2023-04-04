#include <iostream>
#include <vector>
using namespace std;

int N;
int S[21][21];
int chec[21];
int mins = 999999;
int checksum()
{
    vector<int> no1;
    vector<int> no2;
    for (int i = 1; i <= N; i++)
    {
        if (chec[i] == 0)
        {
            no2.push_back(i);
        }
        else
        {
            no1.push_back(i);
        }
    }

    int no1count = 0;
    for (int i = 0; i < no1.size(); i++)
    {
        for (int j = i + 1; j < no1.size(); j++)
        {
            int si = no1[i];
            int sj = no1[j];
            no1count = no1count + S[si][sj];
            no1count = no1count + S[sj][si];
        }
    }
    int no2count = 0;
    for (int i = 0; i < no2.size(); i++)
    {
        for (int j = i + 1; j < no2.size(); j++)
        {
            int si = no2[i];
            int sj = no2[j];
            no2count = no2count + S[si][sj];
            no2count = no2count + S[sj][si];
        }
    }
    return abs(no1count - no2count);
}

void contro(int ccount, int max)
{
    if (ccount == N / 2)
    {
        int ch = checksum();
        if (ch < mins)
        {
            mins = ch;
        }
        return;
    }
    else
    {
        chec[max] = 1;
        for (int i = max + 1; i <= N; i++)
        {
            contro(ccount + 1, i);
        }
        if (ccount + 1 == N / 2)
        {
            int ch = checksum();
            if (ch < mins)
            {
                mins = ch;
            }
        }
        chec[max] = 0;
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> S[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        contro(0, i);
    }
    cout << mins;
}