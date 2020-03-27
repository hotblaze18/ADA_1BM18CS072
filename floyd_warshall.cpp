#include<iostream>

#define V 4

using namespace std;

void floydWarshall (int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout<<"\nThe All pairs shortest path matrix is as follows:\n";
    for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                cout<< dist[i][j] << " ";
            }
        cout<<"\n";
        }

}

int main() {

    int graph[5][5] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0}
                    };
    floydWarshall(graph);
    return 0;
}
