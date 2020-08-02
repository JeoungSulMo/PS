#include <iostream>

using namespace std;

int n, mmax, bufMax;
int arr[505][505];
int visited[505][505];
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};

inline bool safe(int a, int b) { return a < n && a >= 0 && b < n && b >= 0; }
inline int bigger(int a, int b) { return a > b ? a : b; }
int dfs(int x, int y)
{
    if (visited[x][y] >= 1)
        return visited[x][y] + 1;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + tx[i];
        int b = y + ty[i];
        if (safe(a, b) && arr[a][b] > arr[x][y])
            cnt = bigger(cnt, dfs(a, b));
    }
    visited[x][y] = cnt;
    return cnt + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dfs(i, j);
            mmax = bigger(mmax, visited[i][j]);
        }

    cout << mmax;
    return 0;
}