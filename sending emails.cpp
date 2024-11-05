#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct A {
    int d, p;
    A(int d, int p) : d(d), p(p) {}
};

int m(int N, vector<vector<A>>& g, int S, int T) {
    vector<int> d(N, INT_MAX);
    d[S] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fp;
    fp.push({0, S});

    while (!fp.empty()) {
        int x = fp.top().first;
        int u = fp.top().second;
        fp.pop();

        if (x > d[u]) continue;

        for (const A& e : g[u]) {
            int v = e.d;
            int w = e.p;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                fp.push({d[v], v});
            }
        }
    }

    return d[T];
}

int main() {
    int Q;
    cin >> Q;

    for (int n = 1; n <= Q; ++n) {
        int N, M, S, T;
        cin >> N >> M >> S >> T;
        
        vector<vector<A>> g(N);

        for (int i = 0; i < M; ++i) {
            int u, v, l;
            cin >> u >> v >> l;
            g[u].emplace_back(v, l);
            g[v].emplace_back(u, l);
        }

        int r = m(N, g, S, T);

        if (r == INT_MAX) {
            cout << "Caso #" << n << ": unreachable" << endl;
        } else {
            cout << "Caso #" << n << ": " << r << endl;
        }

    }
    return 0;
}
