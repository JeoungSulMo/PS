#include <iostream>

using namespace std;

int n, m, buf, answer = 1;
int fix[45];
int dp_arr[45];

int setting(int a)
{
    if (a == 0)
        return dp_arr[0] = 1;
    if (a == 1)
        return dp_arr[1] = 1;
    return dp_arr[a] = setting(a - 2) + setting(a - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> fix[i];
    }
    setting(40);
    if (m == 0)
    {
        answer = dp_arr[n];
    }
    else
    {
        for (int i = 0; i < m + 1; i++)
        {
            if (i == 0 && fix[i] - 1 != 0)
            {
                answer = dp_arr[fix[i] - 1];
            }
            else if (i == m)
            {
                answer *= dp_arr[n - fix[i - 1]];
            }
            else
            {
                answer *= dp_arr[fix[i] - fix[i - 1] - 1];
            }
        }
    }
    cout << answer;

    return 0;
}