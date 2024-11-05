#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    
    while (cin >> N && N != 0) {
        vector<int> col(N);
        
        for (int i = 0; i < N; i++) {
            cin >> col[i];
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (col[i] > col[j]) {
                    swap(col[i], col[j]);
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            cout << col[i];
            if (i < N - 1) {
                cout << " ";
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
