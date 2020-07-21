#include <iostream>

using namespace std;
int n, m, num, cx, cy, d1, d2;

inline bool safe(int a, int b, int sx, int sy, int ex, int ey) { return a >= sx && a < ex && b >= sy && b < ey; }
void dfs(int a, int b, int sx, int sy, int ex, int ey, int *cnt)
{
    if (a + 1 == ex && b + 1 == ey)
    {
        *cnt += 1;
        return;
    }
    if (safe(a + 1, b, sx, sy, ex, ey))
        dfs(a + 1, b, sx, sy, ex, ey, cnt);
    if (safe(a, b + 1, sx, sy, ex, ey))
        dfs(a, b + 1, sx, sy, ex, ey, cnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> num;
    int indx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            indx++;
            if (indx == num)
            {
                cx = i;
                cy = j;
            }
        }
    dfs(0, 0, 0, 0, cx + 1, cy + 1, &d1);
    dfs(cx, cy, cx, cy, n, m, &d2);

    cout << d1 * d2;
    return 0;
}