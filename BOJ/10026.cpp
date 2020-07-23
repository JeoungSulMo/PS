#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, cnt0, cnt1;
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};
struct pos
{
  int x, y;
};
char arr[105][105];
int visit[2][105][105];

inline bool safe(int a, int b) { return a < n && a >= 0 && b < n && b >= 0; }

void bfs(int x, int y, char color)
{
  queue<pos> Q;
  Q.push({x, y});
  cnt0++;
  visit[0][x][y] = cnt0;
  while (!Q.empty())
  {
    pos cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++)
    {
      int a = cur.x + tx[i];
      int b = cur.y + ty[i];
      if (safe(a, b) && arr[a][b] == color && visit[0][a][b] == 0)
      {
        Q.push({a, b});
        visit[0][a][b] = cnt0;
      }
    }
  }
}
void bfs1(int x, int y, char color)
{
  queue<pos> Q;
  Q.push({x, y});
  cnt1++;
  visit[1][x][y] = cnt1;
  if (color == 'B')
  {
    while (!Q.empty())
    {
      pos cur = Q.front();
      Q.pop();
      for (int i = 0; i < 4; i++)
      {
        int a = cur.x + tx[i];
        int b = cur.y + ty[i];
        if (safe(a, b) && arr[a][b] == color && visit[1][a][b] == 0)
        {
          Q.push({a, b});
          visit[1][a][b] = cnt1;
        }
      }
    }
  }
  else
  {
    while (!Q.empty())
    {
      pos cur = Q.front();
      Q.pop();
      for (int i = 0; i < 4; i++)
      {
        int a = cur.x + tx[i];
        int b = cur.y + ty[i];
        if (safe(a, b) && (arr[a][b] == 'R' || arr[a][b] == 'G') && visit[1][a][b] == 0)
        {
          Q.push({a, b});
          visit[1][a][b] = cnt1;
        }
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
  for (int i = 0; i < n; i++)
  {
    string buf;
    cin >> buf;
    for (int j = 0; j < n; j++)
      arr[i][j] = buf[j];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (visit[0][i][j] == 0)
        bfs(i, j, arr[i][j]);
      if (visit[1][i][j] == 0)
        bfs1(i, j, arr[i][j]);
    }
  }

  cout << cnt0 << " " << cnt1;
  return 0;
}