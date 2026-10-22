#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 4, e = 5;

    int edges[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Sort edges by weight
    sort(edges, edges + e, [](int a[], int b[]) {
        return a[2] < b[2];
    });

    int parent[4] = {0, 1, 2, 3};
    int cost = 0, count = 0;

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        while (parent[u] != u)
            u = parent[u];

        while (parent[v] != v)
            v = parent[v];

        if (u != v) {
            cout << edges[i][0] << " - "
                 << edges[i][1] << " : "
                 << w << endl;

            cost += w;
            parent[u] = v;
            count++;

            if (count == n - 1)
                break;
        }
    }

    cout << "Minimum cost = " << cost;

    return 0;
}
