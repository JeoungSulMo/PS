#include <iostream>
#include <string>
using namespace std;

int n;
string arr[55];
char buf[55];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int len = arr[0].length();
    for (int i = 0; i < len; i++)
    {
        char temp = arr[0][i];
        buf[i] = temp;
        for (int j = 1; j < n; j++)
        {
            if (arr[j][i] != temp)
                buf[i] = '?';
        }
    }
    cout << buf;
    return 0;
}