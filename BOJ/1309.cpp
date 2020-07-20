#include <iostream>

using namespace std;
typedef long long ll;
int n;
ll DP[100005];

ll dp(int a)
{
    if (DP[a] != 0)
        return DP[a];
    if (a == 0)
        return DP[a] = 3;
    if (a == 1)
        return DP[a] = 7;
    return DP[a] = (dp(a - 2) + 2 * dp(a - 1)) % 9901;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << dp(n - 1);

    return 0;
}