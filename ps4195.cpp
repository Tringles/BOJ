#include<bits/stdc++.h>
#include<unordered_map>
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

int t, n, p[100001];
string p1, p2;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) cout << -p[x] << endl;
	else {
		p[x] += p[y];
		p[y] = x;
		cout << -p[x] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt = 0;
		memset(p, -1, sizeof(p));
		unordered_map<string, int> frnd;
		for (int i = 0; i < n; i++) {
			cin >> p1 >> p2;
			if (!frnd[p1])frnd[p1] = ++cnt;
			if (!frnd[p2])frnd[p2] = ++cnt;
			merge(frnd[p1], frnd[p2]);
		}
	}
	return 0;
}
