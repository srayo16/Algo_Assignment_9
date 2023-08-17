#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> arr[N];
int parent[N];
bool visited[N];
int level[N];

void bfs(int r)
{
    queue<int> q;
    q.push(r);
    visited[r] = true;
    level[r] = 0;
    parent[r] = -1;

    while (!q.empty()) // O(n);
    {
        int u = q.front();
        q.pop();

        for (int v : arr[u]) // O(m)
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
    }
}

// BFS = O(n+m)

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int s, d;
    cin >> s >> d;

    bfs(s);

    // for (int i = 1; i <= m; i++)
    // {
    //     cout << level[i] << endl;
    // }

    cout << "Shortest Distance is: " << level[d] << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Parent of " << i << " : " << parent[i] << endl;
    }

    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int i : path)
    {
        cout << i << " -> ";
    }

    cout << endl;

    return 0;
}