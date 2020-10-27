#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int MAX_VERTEX = 20005;
const int MAX_EDGE = 300001;
const int INF = 0x7fffffff;
int min_weight[20005];
int start_vertex, vertaxN, edgeN;

struct node
{
    int to, val;
    node(int a, int b)
    {
        to = a;
        val = b;
    }
};
bool operator<(node newN, node oldN)
{
    return newN.val < oldN.val;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<node> V[MAX_VERTEX];
    priority_queue<node> PQ;
    cin >> vertaxN >> edgeN;
    cin >> start_vertex;
    int u, v, w;
    for (int i = 0; i < edgeN; i++)
    {
        cin >> u >> v >> w;
        V[u].push_back(node(v, w));
    }
    for (int i = 1; i <= vertaxN; i++)
        min_weight[i] = INF;

    min_weight[start_vertex] = 0;
    PQ.push(node(start_vertex, 0));
    while (!PQ.empty())
    {
        int currentNode = PQ.top().to;
        int currentValue = -PQ.top().val;
        PQ.pop();

        if (min_weight[currentNode] < currentValue)
            continue;

        for (int i = 0; i < V[currentNode].size(); i++)
        {
            int dest = V[currentNode][i].to;
            int nextValue = currentValue + V[currentNode][i].val;
            if (min_weight[dest] > nextValue)
            {
                min_weight[dest] = nextValue;
                PQ.push(node(dest, -nextValue));
            }
        }
    }
    for (int i = 1; i <= vertaxN; i++)
    {
        if (min_weight[i] == INF)
            cout << "INF\n";
        else
            cout << min_weight[i] << "\n";
    }

    return 0;
}