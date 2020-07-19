#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n, k, s, e = 200000000, mid, max_fuel;
typedef struct pos
{
  int x;
  int y;
} pos;
typedef struct node
{
  int indx;
  int cnt;
} node;
pos start_pos = {0, 0};
pos end_pos = {10000, 10000};
pos arr[1005];
int chk[1005];
int dist[1005][1005];

//function
inline int get_dist(pos a, pos b)
{
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
};

bool bfs(int fuel);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // input
  cin >> n >> k;
  arr[0] = start_pos;
  arr[n + 1] = end_pos;
  for (int i = 1; i < n + 1; i++)
    cin >> arr[i].x >> arr[i].y;
  // set distance
  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < n + 2; j++)
      dist[i][j] = get_dist(arr[i], arr[j]);

  while (s <= e)
  {
    mid = (s + e) / 2;
    // false : decrease, true : increase
    if (bfs(mid))
    {
      s = mid + 1;
    }
    else
    {
      e = mid - 1;
    }
  }
  float buf = sqrt(max_fuel);
  buf = buf / 10;
  if (buf - (int)buf > 0)
    cout << (int)(buf + 1);
  else
    cout << (int)buf;
  return 0;
}

bool bfs(int fuel)
{
  bool result = true;
  queue<node> Q;
  fill_n(chk, 1005, -1);
  chk[0] = 0;
  Q.push({0, 0});
  while (!Q.empty())
  {
    node cur = Q.front();
    Q.pop();
    if (cur.cnt == k)
    {
      if (dist[cur.indx][n + 1] < fuel)
      {
        max_fuel = fuel;
        while (!Q.empty())
        {
          Q.pop();
        }
        return false;
      }
      continue;
    }
    for (int i = 1; i <= n + 1; i++)
    {
      if (dist[cur.indx][i] < fuel && chk[i] == -1)
      {
        if (i == n + 1)
        {
          max_fuel = fuel;
          while (!Q.empty())
          {
            Q.pop();
          }
          return false;
        }
        else
        {
          chk[i] = chk[cur.indx] + 1;
          Q.push({i, cur.cnt + 1});
        }
      }
    }
  }

  return true;
}