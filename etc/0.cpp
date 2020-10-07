#include <iostream>

using namespace std;

char len[12][6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> len[i][j];
        }
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%c ", len[i][j]);
        }
        printf("\n");
    }

    return 0;
}