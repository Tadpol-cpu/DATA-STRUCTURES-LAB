//TO IMPLEMENT GRAPH ADT WITH THE IMPLEMENTATION FOR PRIM'S ALGORITHM, KRUSKAL'S ALGORITHM, AND DIJKSTRA'S ALGORITHM
#include <cstdio>
using namespace std;

#define MAX 100
#define INF 99999

class GraphAlgo {
private:
    int vertices;
    int graph[MAX][MAX];

public:
    GraphAlgo(int v);
    void addEdge(int u, int v, int w);
    void display();
    void prims();
    void kruskal();
    void dijkstra(int start);
};

int main() {
    int v;
    printf("ENTER NUMBER OF VERTICES (<= %d): ", MAX);
    scanf("%d", &v);

    if (v <= 0 || v > MAX) {
        printf("INVALID NUMBER OF VERTICES.\n");
        return 1;
    }

    GraphAlgo g(v);
    int choice, u, w, cost, src;

    do {
        printf("GRAPH ALGORITHMS MENU :\n");
        printf("1. ADD EDGE\n2. DISPLAY\n3. PRIM'S ALGORITHM\n4. KRUSKAL'S ALGORITHM\n5. DIJKSTRA'S ALGORITHM\n6. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER EDGE (U V WEIGHT): ");
                scanf("%d %d %d", &u, &w, &cost);
                g.addEdge(u, w, cost);
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.prims();
                break;
            case 4:
                g.kruskal();
                break;
            case 5:
                printf("ENTER SOURCE VERTEX: ");
                scanf("%d", &src);
                g.dijkstra(src);
                break;
            case 6:
                printf("SUCCESSFULLY EXITED :) \n");
                break;
            default:
                printf("INVALID CHOICE!\n");
        }
    } while (choice != 6);

    return 0;
}

// CONSTRUCTOR
GraphAlgo::GraphAlgo(int v) {
    vertices = v;
    for (int i = 0; i < vertices; ++i)
        for (int j = 0; j < vertices; ++j)
            graph[i][j] = 0;
}

// ADD EDGE
void GraphAlgo::addEdge(int u, int v, int w) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices || w <= 0) {
        printf("INVALID INPUT!\n");
        return;
    }
    graph[u][v] = w;
    graph[v][u] = w;
    printf("EDGE ADDED BETWEEN %d AND %d WITH WEIGHT %d.\n", u, v, w);
}

// DISPLAY GRAPH
void GraphAlgo::display() {
    printf("\nADJACENCY MATRIX:\n   ");
    for (int i = 0; i < vertices; ++i)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < vertices; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < vertices; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// PRIM'S ALGORITHM
void GraphAlgo::prims() {
    int selected[MAX], no_edge = 0;
    int x, y;
    for (int i = 0; i < vertices; ++i)
        selected[i] = 0;

    selected[0] = 1;
    printf("\nPRIM'S MST EDGES:\n");

    while (no_edge < vertices - 1) {
        int min = INF;
        x = y = 0;

        for (int i = 0; i < vertices; ++i) {
            if (selected[i]) {
                for (int j = 0; j < vertices; ++j) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = 1;
        no_edge++;
    }
}

// KRUSKAL'S ALGORITHM HELPERS
int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[yset] = xset;
}

// KRUSKAL'S ALGORITHM
void GraphAlgo::kruskal() {
    int parent[MAX];
    int mincost = 0;
    int edge_count = 0;

    for (int i = 0; i < vertices; ++i)
        parent[i] = i;

    printf("\nKRUSKAL'S MST EDGES:\n");

    while (edge_count < vertices - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (find(parent, i) != find(parent, j) && graph[i][j]) {
                    if (graph[i][j] < min) {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            unionSet(parent, a, b);
            printf("%d - %d : %d\n", a, b, graph[a][b]);
            mincost += graph[a][b];
            edge_count++;
        }
    }

    printf("TOTAL COST: %d\n", mincost);
}

// DIJKSTRA'S ALGORITHM
void GraphAlgo::dijkstra(int start) {
    if (start < 0 || start >= vertices) {
        printf("INVALID SOURCE VERTEX.\n");
        return;
    }

    int dist[MAX], visited[MAX];
    for (int i = 0; i < vertices; ++i) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int min = INF, u = -1;
        for (int i = 0; i < vertices; ++i)
            if (!visited[i] && dist[i] <= min)
                min = dist[i], u = i;

        visited[u] = 1;

        for (int v = 0; v < vertices; ++v)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nSHORTEST DISTANCES FROM VERTEX %d:\n", start);
    for (int i = 0; i < vertices; ++i)
        printf("TO %d: %d\n", i, dist[i]);
}
