#include <iostream>
#include <vector>

using namespace std;

struct Wrmh {
    int d, p, t;
    Wrmh(int d, int p, int t) : d(d), p(p), t(t) {}
};

bool TNC(vector<Wrmh>& w, int N) {
    vector<int> d(N, 0);

    for (int i = 0; i < N; ++i) {
        for (const Wrmh& wrmh : w) {
            int u = wrmh.d;
            int v = wrmh.p;
            int t = wrmh.t;

            if (d[u] + t < d[v]) {
                d[v] = d[u] + t;
            }
        }
    }

    for (const Wrmh& wrmh : w) {
        int u = wrmh.d;
        int v = wrmh.p;
        int t = wrmh.t;

        if (d[u] + t < d[v]) {
            return true;
        }
    }

    return false;
}

int main() {
    int C;
    cin >> C;

    for (int cNum = 1; cNum <= C; ++cNum) {
        int N, M;
        cin >> N >> M;

        vector<Wrmh> w;

        for (int i = 0; i < M; ++i) {
            int X, Y, T;
            cin >> X >> Y >> T;
            w.emplace_back(X, Y, T);
        }

        bool ePos = TNC(w, N);

        if (ePos) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }

    return 0;
}
