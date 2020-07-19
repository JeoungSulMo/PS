#include <iostream>
#include <queue>
using namespace std;

typedef struct pos
{
  int x, y;
  int value;
} pos;
int n, h_cnt, max_zone = 1;
int arr[101][101], h_buf[101], height[101];
pos buf[101][101];
int tx[4] = {1, -1, 0, 0};
int ty[4] = {0, 0, 1, -1};

inline bool safe(int a, int b)
{
  return (a < n && a >= 0 && b < n && b >= 0);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
      h_buf[arr[i][j]] = 1;
    }

  for (int i = 0; i < 101; i++)
    if (h_buf[i] == 1)
    {
      height[h_cnt] = i;
      h_cnt++;
    }

  for (int i = 0; i < h_cnt; i++)
  {
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
      {
        buf[j][k].value = arr[j][k] <= height[i] ? -1 : arr[j][k];
        buf[j][k].x = j;
        buf[j][k].y = k;
      }
    int max_buf = 0;
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
      {
        if (buf[j][k].value != 0 && buf[j][k].value != -1)
        {
          queue<pos> Q;
          Q.push(buf[j][k]);
          buf[j][k].value = 0;
          while (!Q.empty())
          {
            pos cur = Q.front();
            Q.pop();
            for (int l = 0; l < 4; l++)
            {
              int a = cur.x + tx[l];
              int b = cur.y + ty[l];
              if (safe(a, b) && buf[a][b].value != 0 && buf[a][b].value != -1)
              {
                buf[a][b].value = 0;
                Q.push({a, b, buf[a][b].value});
              }
            }
          }
          max_buf++;
        }
      }
    if (max_zone < max_buf)
      max_zone = max_buf;
  }
  cout << max_zone;

  return 0;
}