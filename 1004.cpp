#include <iostream>

using namespace std;
typedef struct planet
{
  int x, y, r;
} planet;
int n, k;
planet s, e;
planet arr[50];
int cnt;
inline int pow(int a) { return a * a; }

int process()
{
  cnt = 0;
  for (int i = 0; i < k; i++)
  {
    int s_r = pow(s.x - arr[i].x) + pow(s.y - arr[i].y);
    int e_r = pow(e.x - arr[i].x) + pow(e.y - arr[i].y);
    int r2 = pow(arr[i].r);
    if (s_r > r2 && e_r > r2 || s_r < r2 && e_r < r2)
      continue;
    if (s_r < r2)
      cnt++;
    if (e_r < r2)
      cnt++;
    ;
  }
  return cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while (n--)
  {
    cin >> s.x >> s.y >> e.x >> e.y;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
      cin >> arr[i].x >> arr[i].y >> arr[i].r;
    }
    cout << process();
    cout << "\n";
  }

  return 0;
}