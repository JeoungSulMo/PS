#include <iostream>
#include <queue>

using namespace std;

int n,
    se;
int arr[105][105];
int buf[105][105];

void bfs()
{
  for (int i = 0; i < n; i++)
  {
    queue<int> Q;
    Q.push(i);
    while (!Q.empty())
    {
      int cur = Q.front();
      Q.pop();
      for (int j = 0; j < n; j++)
      {
        if (arr[cur][j] == 1 && buf[i][j] == 0)
        {
          buf[i][j] = 1;
          Q.push(j);
        }
      }
    }
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  bfs();

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