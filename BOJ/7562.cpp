#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, I;
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int map[305][305];
struct pos
{
  int x, y;
  int cnt = 0;
};
inline bool safe(int a, int b) { return a >= 0 && b >= 0 && a < I && b < I; }
pos s, e;
void bfs()
{
  queue<pos> Q;
  Q.push({s.x, s.y, 0});
  map[s.x][s.y] = 1;
  while (!Q.empty())
  {
    pos cur = Q.front();
    Q.pop();
    for (int i = 0; i < 8; i++)
    {
      int a = cur.x + dx[i];
      int b = cur.y + dy[i];
      if (a == e.x && b == e.y)
      {
        while (!Q.empty())
        {
          Q.pop();
        }
        cout << cur.cnt + 1 << '\n';
        return;
      }
      if (safe(a, b) && map[a][b] == 0)
      {
        Q.push({a, b, cur.cnt + 1});
        map[a][b] = 1;
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
    cin >> I;
    cin >> s.x >> s.y;
    cin >> e.x >> e.y;
    if (s.x == e.x && s.y == e.y)
      cout << 0 << '\n';
    else
      bfs();
    for (int j = 0; j < I; j++)
    {
      for (int k = 0; k < I; k++)
        map[j][k] = 0;
    }
  }

  return 0;
}