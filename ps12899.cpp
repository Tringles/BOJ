#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int seg[2000004 * 4], q, p1, p2;

int update(int pos, int val, int node, int x, int y) {
    if (pos < x || pos > y) return seg[node];
    if (x == y) return seg[node] += val;
    int mid = (x + y) >> 1;
    return seg[node] = update(pos, val, node * 2, x, mid) +
                       update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int val, int node, int x, int y) {
    int mid = (x + y) >> 1;
    if (x == y) return x;
    if (seg[node * 2] >= val)
        return query(val, node * 2, x, mid);
    else
        return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> q;
    while (q--) {
        cin >> p1 >> p2;
        if (p1 == 1)
            update(p2, 1, 1, 1, 2000000);
        else {
            int cur = query(p2, 1, 1, 2000000);
            cout << cur << endl;
            update(cur, -1, 1, 1, 2000000);
        }
    }
    return 0;
}
