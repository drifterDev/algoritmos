#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            cin >> perm[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (perm[i] != i + 1) {
                ans++;
                while (i < n && perm[i] != i + 1) {
                    ++i;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
