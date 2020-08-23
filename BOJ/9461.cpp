#include <iostream>

using namespace std;

typedef long long ll;
int t, n;
ll dpA[105];

ll dp(int a)
{
    if (dpA[a] != 0)
        return dpA[a];
    else if (1 <= a && a <= 3)
        return dpA[a] = 1;
    else if (a == 4 || a == 5)
        return dpA[a] = 2;
    else
        return dpA[a] = dp(a - 5) + dp(a - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    dp(100);
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dpA[n] << '\n';
    }

    return 0;
}