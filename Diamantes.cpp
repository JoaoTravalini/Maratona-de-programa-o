#include <bits/stdc++.h>

using namespace std;

int contarDiamantes(const string& casoTeste) {
    int abertos = 0;
    int count = 0;

    for (char c : casoTeste) {
        if (c == '<') {
            abertos++;
        } else if (c == '>' && abertos > 0) {
            abertos--;
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string casoTeste;
        getline(cin, casoTeste);
        int count = contarDiamantes(casoTeste);
        cout << count << endl;
    }

    return 0;
}
