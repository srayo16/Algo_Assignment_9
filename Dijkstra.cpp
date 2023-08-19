#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 10;
vector<pii> arr[N];
bool visited[N];
int level[N];
vector<int> dist(N, INF);

void dijkstra(int source)
{

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (pii vPair : arr[u])
        {
            int v = vPair.first;
            int w = vPair.second;

            if ((dist[v] > dist[u] + w) && !visited[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v, w});
        arr[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node: " << i << ": ";
        cout << dist[i] << endl;
    }

    return 0;
}