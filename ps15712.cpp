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

ll t, x, n, m;

ll dpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

ll func(ll r, ll n) {
	if (n == 1)return 1;
	ll ret = func(r, n >> 1) * (1 + dpow(r, n >> 1));
	if (n & 1)ret += dpow(r, n - 1);
	return ret % m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t >> x >> n >> m;
	cout << t * func(x, n) % m << endl;
	return 0;
}