#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
int n;
ll sqr(ll a) { return a * a; }

void process()
{
  ll x1, x2, r1, y1, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  ll dist = sqr(x1 - x2) + sqr(y1 - y2);
  ll Rsum = sqr(r1 + r2);
  if (r1 > r2)
    swap(r1, r2);
  ll Rsub = sqr(r2 - r1);

  if (dist < Rsum && dist > Rsub)
    cout << 2;
  else if (dist == Rsum || (dist == Rsub && dist != 0))
    cout << 1;
  else if (dist == 0 && r1 == r2)
    cout << -1;
  else if (dist == 0 && r1 != r2)
    cout << 0;
  else if (dist > Rsum || dist < Rsub)
    cout << 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while (n--)
  {
    process();
    cout << '\n';
  }

  return 0;
}