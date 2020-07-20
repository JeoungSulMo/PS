#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n, cnt;
int arr[30][30];
int buf[10000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct pos
{
  int x, y;
};
inline bool safe(int a, int b) { return a >= 0 && a < n && b < n && b >= 0; }

void bfs()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (arr[i][j] == -1)
      {
        buf[cnt]++;
        cnt++;
        queue<pos> Q;
        Q.push({i, j});
        arr[i][j] = cnt;
        while (!Q.empty())
        {
          pos cur = Q.front();
          Q.pop();
          for (int k = 0; k < 4; k++)
          {
            int a = cur.x + dx[k];
            int b = cur.y + dy[k];
            if (safe(a, b) && arr[a][b] == -1)
            {
              Q.push({a, b});
              arr[a][b] = cnt;
              buf[cnt - 1]++;
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
      arr[i][j] = buf[j] - '0' == 1 ? -1 : 0;
  }

  bfs();
  cout << cnt << '\n';
  sort(buf, buf + cnt);
  for (int i = 0; i < cnt; i++)
    cout << buf[i] << '\n';
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}