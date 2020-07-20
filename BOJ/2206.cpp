#include <iostream>

using namespace std;
int n, m, min_cnt = 2000000;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[1005][1005];
int visit[1005][1005];

inline bool safe(int a, int b)
{
  return a < n && a >= 0 && b < m && b >= 0;
}
void dfs(int cx, int cy, int b, int cnt)
{
  // cout << cx << ", " << cy << " \n";
  visit[cx][cy] = 1;
  // 방문했던 위치의 최소 횟수
  // if (visit[cx][cy] == 0)
  //   visit[cx][cy] = cnt;
  // else if (visit[cx][cy] > cnt)
  //   visit[cx][cy] = cnt;
  // else
  //   return;
  if (min_cnt < cnt + (n - cx) + (m - cy))
    return;
  // 도착시
  if (cx == n - 1 && cy == m - 1)
  {
    min_cnt = min_cnt > cnt ? cnt : min_cnt;
    // cout << min_cnt << endl;
    return;
  }

  // 일반 체크
  for (int i = 0; i < 4; i++)
  {
    int x = cx + dx[i];
    int y = cy + dy[i];
    if (safe(x, y) && visit[x][y] == 0)
    {
      if (b == 0)
      {
        if (arr[x][y] == 1)
          dfs(x, y, b + 1, cnt + 1);
        else
          dfs(x, y, b, cnt + 1);
        visit[x][y] = 0;
      }
      else
      {
        if (arr[x][y] == 0)
        {
          dfs(x, y, b, cnt + 1);
          visit[x][y] = 0;
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

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    string buf;
    cin >> buf;
    for (int j = 0; j < m; j++)
      arr[i][j] = buf[j] - '0';
  }

  dfs(0, 0, 0, 1);
  if (min_cnt == 2000000)
    cout << -1;
  else
  {
    cout << min_cnt;
  }

  return 0;
}
