#include <iostream>

using namespace std;

int n;
int dpA[1000005];

inline int mmin(int a, int b) { return a > b ? b : a; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    dpA[1] = 0;
    for (int i = 2; i < n + 1; i++)
    {
        dpA[i] = dpA[i - 1] + 1;
        if (i % 2 == 0)
            (dpA[i] = mmin(dpA[i], dpA[i / 2] + 1));
        if (i % 3 == 0)
            (dpA[i] = mmin(dpA[i], dpA[i / 3] + 1));
    }
    cout << dpA[n];

    return 0;
}