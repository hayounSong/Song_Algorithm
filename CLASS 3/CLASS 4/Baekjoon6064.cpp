#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{

    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {

        int M, N;

        cin >> M >> N;
        int x, y;
        cin >> x >> y;
        int count = 1;
        int startx = x;
        int starty = 0;
        int max = M * N / gcd(M, N);
        int ans = 0;
        for (; startx <= max; startx += M)
        {
            starty = startx % N;
            if (starty == 0)
            {
                starty = N;
            }
            if (starty == y)
            {
                ans = 1;
                cout << startx << "\n";
                break;
            }
        }
        if (ans == 0)
        {
            cout << -1 << "\n";
        }
    }
}

// while (true)
// {
// if (x % (N % y) != 0 || (N % y) % x != 0)
// {

//     cout << -1 << endl;
//     break;
// }
// if (y % (M % x) != 0)
// {

//     cout << -1 << endl;
//     break;
// }
//         if (M * N / gcd(M, N) < count)
//         {
//             cout << -1 << endl;
//             break;
//         }
//         startx++;
//         starty++;
//         if (startx > M)
//         {
//             startx = startx - M;
//         }
//         if (starty > N)
//         {
//             starty = starty - N;
//         }
//         if (startx == x && starty == y)
//         {
//             cout << count << endl;
//             break;
//         }
//         count++;
//     }
// }
