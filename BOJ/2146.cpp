#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct pos
{
  int x, y, count;
};
int n, indx, minn = 10000;
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};
int arr[105][105];
int buf[105][105];
queue<pos> Q;

inline bool safe(int a, int b) { return a < n && a >= 0 && b < n && b >= 0; }
void cleanBuf()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      buf[i][j] = arr[i][j];
}
void dfs(int x, int y)
{
  arr[x][y] = indx;
  for (int i = 0; i < 4; i++)
  {
    int a = x + tx[i];
    int b = y + ty[i];
    if (safe(a, b) && arr[a][b] == 1)
      dfs(a, b);
  }
}
void bfs2(int x, int y)
{
  Q.push({x, y, 0});
  while (!Q.empty())
  {
    pos cur = Q.front();
    Q.pop();
    bool trig = false;
    for (int i = 0; i < 4; i++)
    {
      int a = cur.x + tx[i];
      int b = cur.y + ty[i];
      if (safe(a, b) && arr[a][b] != arr[x][y] && arr[a][b] != 0)
      {
        minn = minn > cur.count ? cur.count : minn;
        trig = true;
      }
    }
    if (trig)
    {
      while (!Q.empty())
      {
        Q.pop();
      }
      break;
    }
    for (int i = 0; i < 4; i++)
    {
      int a = cur.x + tx[i];
      int b = cur.y + ty[i];
      if (safe(a, b) && buf[a][b] == 0)
      {
        buf[a][b] = cur.count + 1;
        Q.push({a, b, cur.count + 1});
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
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == 1)
      {
        indx--;
        dfs(i, j);
      }
    }
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] != 0)
      {
        for (int k = 0; k < 4; k++)
        {
          int a = i + tx[k];
          int b = j + ty[k];
          if (safe(a, b) && arr[a][b] == 0)
          {
            cleanBuf();
            bfs2(i, j);
            break;
          }
        }
      }
    }
  cout << minn;
  return 0;
}
