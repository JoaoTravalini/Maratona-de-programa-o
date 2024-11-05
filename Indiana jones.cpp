#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edg {
    int to, w;
};

int main() {
    int N, M;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        vector<vector<Edg>> G(N + 2);
        vector<vector<int>> D(N + 2, vector<int>(N + 2, INF));

        for (int i = 0; i < M; i++) {
            int U, V, L;
            cin >> U >> V >> L;
            G[U].push_back({V, L});
            G[V].push_back({U, L});
            D[U][V] = D[V][U] = L;
        }

        for (int i = 0; i <= N + 1; i++) {
            D[i][i] = 0;
        }

        for (int k = 0; k <= N + 1; k++) {
            for (int i = 0; i <= N + 1; i++) {
                for (int j = 0; j <= N + 1; j++) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }

        cout << D[0][N + 1] << endl;
    }

    return 0;
}
