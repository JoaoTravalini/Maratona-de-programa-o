#include <iostream>
#include <cstring>
#include <queue>

#define INF 0x3F3F3F3F
#define MAX 101 

using namespace std;

int mat[MAX][MAX];

int bfs(int rGraph[MAX][MAX], int s, int t, int anterior[MAX])
{
    int u, v;
    int visited[MAX];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    anterior[s] = -1;

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (v = 0; v < MAX; v++)
        {
            if (visited[v] == 0 && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    anterior[v] = u;
                    return 1;
                }
                q.push(v);
                anterior[v] = u;
                visited[v] = 1;
            }
        }
    }

    return 0;
}

int maxflow(int graph[MAX][MAX], int s, int t)
{
    int u, v;
    int anterior[MAX];
    int fluxoMax = 0;
    int bot;
    int rGraph[MAX][MAX];

    for (u = 0; u < MAX; u++)
        for (v = 0; v < MAX; v++)
            rGraph[u][v] = graph[u][v];

    while (bfs(rGraph, s, t, anterior))
    {
        bot = INF;
        for (v = t; v != s; v = anterior[v])
        {
            u = anterior[v];
            bot = min(bot, rGraph[u][v]);
        }

        for (v = t; v != s; v = anterior[v])
        {
            u = anterior[v];
            rGraph[u][v] -= bot;
            rGraph[v][u] += bot;
        }

        fluxoMax += bot;
    }

    return fluxoMax;
}

int main()
{
    int N, s, t, c, u, v, b;

    int k = 0;

    while (cin >> N)
    {

        if (N == 0)
        {
            break;
        }

        memset(mat, 0, sizeof(mat));

        cin >> s >> t >> c;

        while (c--)
        {
            cin >> u >> v >> b;
            mat[u][v] += b;
            mat[v][u] += b;
        }

        printf("Rede %d\n", k++);
        printf("%d\n\n", maxflow(mat, s, t));
    }

    return 0;
}