#include <iostream>
#include <queue>

using namespace std;

int n, m, s;
int arr[1005][1005];
int dfs_ch[1005];
int bfs_ch[1005];

void dfs(int start)
{
    cout << start << " ";
    dfs_ch[start] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr[start][i] && !dfs_ch[i])
            dfs(i);
    }
}

void bfs(int start)
{
    queue<int> Q;
    Q.push(start);
    bfs_ch[start] = 1;
    cout << start << " ";
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (arr[cur][i] && !bfs_ch[i])
            {
                Q.push(i);
                bfs_ch[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    cin >> s;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfs(s);
    cout << endl;
    bfs(s);
    return 0;
}