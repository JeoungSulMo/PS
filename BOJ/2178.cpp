#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct pos
{
    int x, y;
    int cnt;
};

int n, m, min_cnt = 1000000;
int arr[105][105];
int visit[105][105];
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};
inline bool safe(int a, int b) { return a < n && a >= 0 && b < m && b >= 0; }
void bfs()
{
    queue<pos> Q;
    Q.push({0, 0, 1});
    visit[0][0] = 1;
    while (!Q.empty())
    {
        pos cur = Q.front();
        Q.pop();
        if (min_cnt < cur.cnt + (n - cur.x) + (m - cur.y))
            continue;

        if (cur.x == n - 1 && cur.y == m - 1)
        {
            min_cnt = min_cnt > cur.cnt ? cur.cnt : min_cnt;
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int a = cur.x + tx[i];
            int b = cur.y + ty[i];
            if (safe(a, b) && arr[a][b] == 1 && visit[a][b] == 0)
            {
                Q.push({a, b, cur.cnt + 1});
                visit[a][b] = cur.cnt + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string buf;
        cin >> buf;
        for (int j = 0; j < m; j++)
            arr[i][j] = buf[j] - '0';
    }

    bfs();
    cout << min_cnt;
    return 0;
}
