#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef struct node
{
  ll a = 0, b = 0, c = 0;
} node;
int n;
node dp[50];

node fibo(int a)
{
  if (dp[a].c != 0)
    return dp[a];
  if (a == 0)
  {
    dp[a].a = 1;
    dp[a].c = 1;
    return dp[a];
  }
  else if (a == 1)
  {
    dp[a].b = 1;
    dp[a].c = 1;
    return dp[a];
  }
  dp[a].a = fibo(a - 2).a + fibo(a - 1).a;
  dp[a].b = fibo(a - 2).b + fibo(a - 1).b;
  dp[a].c = fibo(a - 2).c + fibo(a - 1).c;
  return dp[a];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while (n--)
  {
    int t;
    cin >> t;
    fibo(t);
    cout << dp[t].a << " " << dp[t].b << '\n';
  }

  return 0;
}