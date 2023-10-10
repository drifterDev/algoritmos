#include <iostream>
#include <vector>
#define ll long long
#define vl vector<ll>
#define ln "\n"
using namespace std;

struct nodeSt {
    nodeSt *left, *right;
    ll l, r, val;

    nodeSt(vl &v, ll lef, ll rig) : l(lef), r(rig) {
        ll m = (l + r) / 2;

        if (l != r) {
            left = new nodeSt(v, lef, m);
            right = new nodeSt(v, m + 1, rig);
            val = oper(left->val, right->val);
        } else {
            val = v[l];
        }
    }

    ll get(ll i, ll j) {
        if (l >= i && r <= j) {
            return val;
        }
        if (l > j || r < i) {
            return 0;
        }

        return oper(left->get(i, j), right->get(i, j));
    }

    void actl(ll k, ll u) {
        if (l > k || r < k) return;
        if (l == k && r == k) {
            val = u;
            return;
        }

        left->actl(k, u);
        right->actl(k, u);

        val = oper(left->val, right->val);
    }

    ll oper(ll n1, ll n2) {
        return n1 + n2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vl vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    nodeSt st(vals, 0, n - 1);

    for (int i = 0; i < q; i++) {
        ll n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if (n1 == 1) {
            n2--;
            st.actl(n2, n3);
        } else {
            n2--;
            n3--;
            cout << st.get(n2, n3) << ln;
        }
    }

    return 0;
}