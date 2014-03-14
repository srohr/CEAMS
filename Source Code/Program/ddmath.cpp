#include "ddmath.h"
#include <sstream>
#include <random>
#include <vector>

using namespace std;

int GetPoints(string fn, int var)
{
    int i = 0;
    int ret;
    int v1, v2;

    if (fn.size() == 5)
    {
        v1 = fn[0]; // [] _ _ _ _
        v2 = fn[4]; // _ _ _ _ []
        ret = (v1 + var)*v2;
    }
    else if (fn.size() == 3)
    {
        v1 = fn[0]; // [] _ _
        ret = v1 + var;
    }
    else
        return 0; //We may want to eventually support functions of various forms. I don't care to right now.

    return ret;
}

vector<int> test()
{
    vector<int> sean;
    sean.push_back(5);
    return sean;
}

int Roll(int n, int d)
{
    int ret = 0;

    for (int i = 0; i < n; i++)
        ret += rand()%d + 1; //This isn't as random as we can make it.

    return ret;
}

int Roll(string s)
{
    stringstream ss;
    ss << s;

    int n;
    int x;
    char garbage;
    char op;
    int mod = 0;
    int ret;

    ss >> n >> garbage >> x;

    ret = Roll (n, x);

    if (ss.rdbuf()->in_avail() > 0)
    {
        ss >> op >> mod;

        if (op == 'x' || op == '*')
            ret *= mod;
        else if (op == '//')
            ret /= mod;
        else if (op == '+')
            ret += mod;
        else if (op == '-')
            ret -= mod;
    }

    return ret;
}
