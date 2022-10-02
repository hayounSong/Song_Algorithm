#include <iostream>

using namespace std;

struct matrix
{
    unsigned long long list[2][2];
};

matrix fibosum(struct matrix g, struct matrix x)
{

    struct matrix a;

    a.list[0][0] = (g.list[0][0] * x.list[0][0]) % 1000000007 + (g.list[0][1] * x.list[1][0]) % 1000000007;
    a.list[0][1] = (g.list[0][0] * x.list[0][1]) % 1000000007 + (g.list[0][1] * x.list[1][1]) % 1000000007;
    a.list[1][0] = (g.list[1][0] * x.list[0][0]) % 1000000007 + (g.list[1][1] * x.list[1][0]) % 1000000007;
    a.list[1][1] = (g.list[1][0] * x.list[0][1]) % 1000000007 + (g.list[1][1] * x.list[1][1]) % 1000000007;

    return a;
}

matrix fibo(int n)
{

    if (n == 1)
    {
        struct matrix a;
        a.list[0][0] = 1;
        a.list[0][1] = 1;
        a.list[1][0] = 1;
        a.list[1][1] = 0;
        return a;
    }
    else
    {
        if (n % 2 == 0)
        {
            struct matrix a = fibo(n / 2);
            return fibosum(a, a);
        }
        if (n % 2 == 1)
        {
            struct matrix a = fibo(n / 2);
            struct matrix b = fibosum(a, a);
            struct matrix c;
            c.list[0][0] = 1;
            c.list[0][1] = 1;
            c.list[1][0] = 1;
            c.list[1][1] = 0;
            return fibosum(c, b);
        }
    }
}

int main()
{

    unsigned long long a;
    cin >> a;
    if (a == 0)
    {
        cout << 0 % 1000000007;
    }
    else
    {
        cout << fibo(a).list[0][1] % 1000000007;
    }
}
// #include <iostream>
// #include <vector>
// using namespace std;

// typedef vector<vector<long long>> matrix;
// const long long mod = 1000000007;

// long long n;

// matrix operator*(matrix &a, matrix &b)
// {
//     matrix c(2, vector<long long>(2));

//     for (int i = 0; i < 2; i++)
//         for (int j = 0; j < 2; j++)
//         {
//             for (int k = 0; k < 2; k++)
//                 c[i][j] += a[i][k] * b[k][j];

//             c[i][j] %= mod;
//         }
//     return c;
// }

// int main()
// {
//     cin >> n;

//     matrix ans = {{1, 0}, {0, 1}};
//     matrix a = {{1, 1}, {1, 0}};

//     while (n > 0)
//     {
//         if (n % 2 == 1)
//             ans = ans * a;
//         a = a * a;
//         n /= 2;
//     }

//     cout << ans[0][1] << '\n';
// }