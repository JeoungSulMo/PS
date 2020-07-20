#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct pos
{
  int x, y;
  int value;
} pos;
int m, n, arr[1005][1005], day, cnt;
int tx[4] = {1, -1, 0, 0};
int ty[4] = {0, 0, -1, 1};
bool check()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (arr[i][j] == 0)
        return false;
  return true;
}

bool safe(int a, int b)
{
  return (a >= 0 && a < n && b >= 0 && b < m);
}

void bfs()
{
  queue<pos> Q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      if (arr[i][j] == 1)
        Q.push({i, j});
  }

  while (!Q.empty())
  {
    pos cur = Q.front();
    Q.pop();
    day = arr[cur.x][cur.y] - 1;
    cnt = 0;
    for (int i = 0; i < 4; i++)
    {
      int x = cur.x + tx[i];
      int y = cur.y + ty[i];
      if (safe(x, y) && arr[x][y] == 0)
      {
        Q.push({x, y});
        arr[x][y] = arr[cur.x][cur.y] + 1;
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

  cin >> m >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  if (check())
    cout << 0;
  else
    bfs();

  return 0;
}