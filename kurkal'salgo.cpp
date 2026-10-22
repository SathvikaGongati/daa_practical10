#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int e = 5, n = 4;

    int a[5] = {0, 0, 0, 1, 2};
    int b[5] = {1, 2, 3, 3, 3};
    int w[5] = {10, 6, 5, 15, 4};

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = i + 1; j < e; j++) {
            if (w[i] > w[j]) {
                swap(w[i], w[j]);
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }

    int parent[4] = {0, 1, 2, 3};
    int cost = 0, count = 0;

    for (int i = 0; i < e; i++) {
        int u = a[i];
        int v = b[i];

        while (parent[u] != u)
            u = parent[u];

        while (parent[v] != v)
            v = parent[v];

        if (u != v) {
            cout << a[i] << " - " << b[i]
                 << " : " << w[i] << endl;

            cost += w[i];
            parent[u] = v;
            count++;

            if (count == n - 1)
                break;
        }
    }

    cout << "Minimum cost = " << cost;

    return 0;
}
