#include<bits/stdc++.h>
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

int n, q, p1, p2;
ll seg[100000 * 4], sseg[100000 * 4];

ll maxques(ll lo, ll hi, ll node, ll x, ll y) {
    if (lo > y || hi < x) {
        return -1;
    }
    if (lo <= x && hi >= y) {
        return seg[node];
    }
    ll mid = (x + y) >> 1;
    ll left = maxques(lo, hi, node * 2, x, mid);
    ll right = maxques(lo, hi, node * 2 + 1, mid + 1, y);
    return max(left, right);
}
ll minques(ll lo, ll hi, ll node, ll x, ll y) {
    if (lo > y || hi < x) {
        return INF;
    }
    if (lo <= x && hi >= y) {
        return sseg[node];
    }
    ll mid = (x + y) >> 1;
    ll left = minques(lo, hi, node * 2, x, mid);
    ll right = minques(lo, hi, node * 2 + 1, mid + 1, y);
    return min(left, right);
}
ll maxupd(ll pos, ll val, ll node, ll x, ll y) {
    if (x > pos || y < pos) {
        return seg[node];
    }
    if (x == y) {
        return seg[node] = val;
    }
    ll mid = (x + y) >> 1;
    ll left = maxupd(pos, val, node * 2, x, mid);
    ll right = maxupd(pos, val, node * 2 + 1, mid + 1, y);
    return seg[node] = max(left, right);
}
ll minupd(ll pos, ll val, ll node, ll x, ll y) {
    if (x > pos || y < pos) {
        return sseg[node];
    }
    if (x == y) {
        return sseg[node] = val;
    }
    ll mid = (x + y) >> 1;
    ll left = minupd(pos, val, node * 2, x, mid);
    ll right = minupd(pos, val, node * 2 + 1, mid + 1, y);
    return sseg[node] = min(left, right);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p1;
        maxupd(i, p1, 1, 1, n);
        minupd(i, p1, 1, 1, n);
    }
    while (q--) {
        cin >> p1 >> p2;
        cout << maxques(p1, p2, 1, 1, n) - minques(p1, p2, 1, 1, n) << endl;
    }
	return 0;
}