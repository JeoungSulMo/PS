#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > q;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (!q.empty())
            {
                cout << q.top() << "\n";
                q.pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            q.push(arr[i]);
        }
    }

    return 0;
}