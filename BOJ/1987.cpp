#include <iostream>
#include <string>
using namespace std;

int R, C, cnt, max_cnt;
int tx[4] = {0, 1, 0, -1};
int ty[4] = {1, 0, -1, 0};
char arr[21][21];
int visit[100];
inline bool safe(int a, int b) { return a < R && a >= 0 && b < C && b >= 0; }
void dfs(int x, int y)
{
  cnt++;
  visit[(int)arr[x][y]] = 1;
  for (int i = 0; i < 4; i++)
  {
    int a = x + tx[i];
    int b = y + ty[i];
    if (safe(a, b) && !visit[(int)arr[a][b]])
    {
      dfs(a, b);
      visit[(int)arr[a][b]] = 0;
      cnt--;
    }
  }
  max_cnt = max_cnt < cnt ? cnt : max_cnt;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> R >> C;
  for (int i = 0; i < R; i++)
  {
    string buf;
    cin >> buf;
    for (int j = 0; j < C; j++)
      arr[i][j] = buf[j];
  }
  dfs(0, 0);
  cout << max_cnt;
  return 0;
}