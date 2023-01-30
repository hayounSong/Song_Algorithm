#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string a;

    cin >> a;
    int minus = 0;
    int result = 0;
    string num = "";
    for (int i = 0; i <= a.size(); i++)
    {
        if (a[i] == '-')
        {
            if (minus == 1)
            {
                result = result - stoi(num);
                num = "";
            }
            else if (minus == 0)
            {
                result = result + stoi(num);
                num = "";
            }
            minus = 1;
        }
        else if (a[i] == '+' || i == a.size())
        {
            if (minus == 1)
            {
                result = result - stoi(num);
                num = "";
            }
            else if (minus == 0)
            {
                result = result + stoi(num);
                num = "";
            }
        }
        else
        {
            num = num + a[i];
        }
    }

    cout << result;
}