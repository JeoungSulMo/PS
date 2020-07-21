#include <iostream>
#include <queue>
using namespace std;

int s, b;
int visit[100100];
struct node
{
  int a;
  int cnt;
};

inline bool safe(int a) { return a >= 0 && a <= 100100; }
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s >> b;
  if (s > b)
    cout << s - b;
  else if (s == b)
    cout << 0;
  else
  {
    queue<node> Q;
    Q.push({s, 0});
    visit[s] = -1;
    while (!Q.empty())
    {
      node cur = Q.front();
      Q.pop();
      if (visit[b] != 0)
      {
        cout << visit[b];
        return 0;
      }
      if (safe(cur.a - 1) && visit[cur.a - 1] == 0)
      {
        Q.push({cur.a - 1, cur.cnt + 1});
        visit[cur.a - 1] = cur.cnt + 1;
      }
      if (safe(cur.a + 1) && visit[cur.a + 1] == 0)
      {
        Q.push({cur.a + 1, cur.cnt + 1});
        visit[cur.a + 1] = cur.cnt + 1;
      }
      if (safe(cur.a * 2) && visit[cur.a * 2] == 0)
      {
        Q.push({cur.a * 2, cur.cnt + 1});
        visit[cur.a * 2] = cur.cnt + 1;
      }
    }
  }
  return 0;
}