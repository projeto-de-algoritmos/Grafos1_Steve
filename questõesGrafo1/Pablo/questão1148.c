#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 600
#define INF 0x3f3f3f3f

int adj[MAXSIZE][MAXSIZE];

void bfs(int, int, int);

int main(int argc, char **argv)
{

    int u, v, w;
    int n, m, i, j, t;

    while (scanf("%d %d", &n, &m), n || m)
    {

        for (i = 0; i <= n; ++i)
            for (j = 0; j <= n; ++j)
                adj[i][j] = INF;

        for (i = 0; i < m; ++i)
        {

            scanf("%d %d %d", &u, &v, &w);

            if (adj[v][u] != INF)
                adj[u][v] = adj[v][u] = 0;
            else
                adj[u][v] = w;

        }

        scanf("%d", &t);
        while (t--)
        {

            scanf("%d %d", &u, &v);
            bfs(n, u, v);

        }

        printf("\n");

    }

    return 0;

}

void bfs(int n, int src, int dest)
{

    int i, j;
    int vis[n + 1];
    int dist[n + 1];

    memset(vis, false, sizeof(vis));

    for (i = 0; i <= n; ++i)
        dist[i] = INF;

    dist[src] = 0;

    bool found = false;

    while (!found)
    {

        int v = -1;
        for (i = 1; i <= n; ++i)
            if (!vis[i] && (v == -1 || dist[i] < dist[v]))
                v = i;

        if (v == -1 || dist[v] == INF)
            break;

        vis[v] = true;
        if (v == dest)
        {
            found = true;
            break;
        }

        for (i = 1; i <= n; ++i)
            if (adj[v][i] != INF && dist[v] + adj[v][i] < dist[i])
                dist[i] = dist[v] + adj[v][i];

    }

    if (dist[dest] < INF)
        printf("%d\n", dist[dest]);
    else
        puts("Nao e possivel entregar a carta");

} 
