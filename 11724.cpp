#include <iostream>

using namespace std;

int n, m, a, b;
int arr[1005];
int buf[1005];
int indx;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    if (arr[a] == 0 && arr[b] == 0)
    {
      indx++;
      arr[a] = arr[b] = indx;
    }
    else if (arr[a] != 0 && arr[b] == 0)
      arr[b] = arr[a];
    else if (arr[a] == 0 && arr[b] != 0)
      arr[a] = arr[b];
    else if (arr[a] != 0 && arr[b] != 0 && arr[a] != arr[b])
    {
      int temp = arr[b];
      for (int j = 1; j <= n; j++)
        if (arr[j] == temp)
          arr[j] = arr[a];
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (arr[i] == 0)
    {
      indx++;
      arr[i] = indx;
    }
  }
  for (int i = 1; i <= n; i++)
    buf[arr[i]] = 1;
  int cnt = 0;
  for (int i = 1; i < 1005; i++)
  {
    if (buf[i])
    {
      cout << "i: " << i << " buf : " << buf[i] << "\n";
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}