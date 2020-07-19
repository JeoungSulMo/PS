#include <iostream>

using namespace std;

int n, se;
int arr[105][105];
int buf[105][105];

void dfs(int s, int e, int cnt)
{
  if (cnt > n)
    return;
  if (s != e)
    buf[s][e] = 1;
  else if (cnt != 0)
  {
    buf[s][e] = 1;
  }
  else
  {
    cnt += 1;
  }
  for (int i = 0; i < n; i++)
  {
    if (arr[e][i] == 1)
      dfs(s, i, cnt);
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
    dfs(i, 0, 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << buf[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}