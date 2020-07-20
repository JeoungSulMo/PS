#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct pos
{
  int x, y, z;
  int value;
} pos;
int m, n, arr[105][105][105], day, cnt, h;
int tx[6] = {1, -1, 0, 0, 0, 0};
int ty[6] = {0, 0, -1, 1, 0, 0};
int tz[6] = {0, 0, 0, 0, 1, -1};
bool check()
{
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (arr[k][i][j] == 0)
          return false;
  return true;
}

bool safe(int a, int b, int c)
{
  return (a >= 0 && a < n && b >= 0 && b < m && c >= 0 && c < h);
}

void bfs()
{
  queue<pos> Q;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (arr[k][i][j] == 1)
          Q.push({i, j, k});

  while (!Q.empty())
  {
    pos cur = Q.front();
    Q.pop();
    day = arr[cur.z][cur.x][cur.y] - 1;
    cnt = 0;
    for (int i = 0; i < 6; i++)
    {
      int x = cur.x + tx[i];
      int y = cur.y + ty[i];
      int z = cur.z + tz[i];
      if (safe(x, y, z) && arr[z][x][y] == 0)
      {
        Q.push({x, y, z});
        arr[z][x][y] = arr[cur.z][cur.x][cur.y] + 1;
        cnt++;
      }
    }
  }
  if (check())
    cout << day;
  else
    cout << -1;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n >> h;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> arr[k][i][j];
  if (check())
    cout << 0;
  else
    bfs();

  return 0;
}