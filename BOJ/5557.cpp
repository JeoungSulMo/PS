#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
int n, target;
int arr[105];
ll dp[105][21];

ll dfs(int buf, int indx)
{
  if (buf > 20 || buf < 0)
    return 0;
  if (indx == n - 1)
  {
    if (buf == target)
      dp[indx][buf] = 1;
    else
      dp[indx][buf] = 0;
    return dp[indx][buf];
  }

  if (dp[indx][buf] != -1)
    return dp[indx][buf];
  ll var = 0;
  var += dfs(buf + arr[indx + 1], indx + 1);
  var += dfs(buf - arr[indx + 1], indx + 1);
  return dp[indx][buf] = var;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  n--;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> target;
  memset(dp, -1, sizeof(dp));
  cout << dfs(arr[0], 0);

  return 0;
}
