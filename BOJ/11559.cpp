#include <iostream>
#include <queue>

using namespace std;

char arr[12][6];

typedef struct point
{
    int x, y;
} point;

int tx[4] = {0, 0, 1, -1};
int ty[4] = {1, -1, 0, 0};

bool safe(int a, int b) { return (a >= 0 && a < 12 && b >= 0 && b < 6); }

int bfs(int x, int y, char c)
{
    int count = 1;
    queue<point> Q;
    arr[x][y] = 'H';
    Q.push((point){x, y});
    while (!Q.empty())
    {
        point cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = cur.x + tx[i];
            int b = cur.y + ty[i];
            if (safe(a, b) && arr[a][b] == c)
            {
                arr[a][b] = 'H';
                count++;
                Q.push((point){a, b});
            }
        }
    }
    if (count < 4)
    {
        arr[x][y] = c;
        Q.push((point){x, y});
        while (!Q.empty())
        {
            point cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int a = cur.x + tx[i];
                int b = cur.y + ty[i];
                if (safe(a, b) && arr[a][b] == 'H')
                {
                    arr[a][b] = c;
                    Q.push((point){a, b});
                }
            }
        }
        return 0;
    }
    else
    {
        arr[x][y] = '.';
        Q.push((point){x, y});
        while (!Q.empty())
        {
            point cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int a = cur.x + tx[i];
                int b = cur.y + ty[i];
                if (safe(a, b) && arr[a][b] == 'H')
                {
                    arr[a][b] = '.';
                    Q.push((point){a, b});
                }
            }
        }
        return 1;
    }
}

void renew()
{
    queue<char> Q2;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 11; j >= 0; j--)
        {
            if (arr[j][i] != '.')
                Q2.push(arr[j][i]);
        }
        for (int j = 0; j < 12; j++)
            arr[j][i] = '.';

        int len = Q2.size();
        for (int j = 0; j < len; j++)
        {
            arr[11 - j][i] = Q2.front();
            Q2.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            cin >> arr[i][j];

    int answer = 0;
    int popcnt = 1;
    while (popcnt != 0)
    {
        popcnt = 0;
        for (int i = 11; i >= 0; i--)
            for (int j = 0; j < 6; j++)
            {
                if (arr[i][j] != '.')
                    popcnt += bfs(i, j, arr[i][j]);
            }
        if (popcnt != 0)
        {
            answer++;
            renew();
        }
    }
    cout << answer;
    return 0;
}