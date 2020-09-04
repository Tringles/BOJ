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

int n, m, x, y, p[105], cnt;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	p[y] = x;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		for (int j = x + 1; j <= y; j++)
			merge(x, j);
	}
	for (int i = 1; i <= n; i++)if (p[i] == -1)cnt++;
	cout << cnt << endl;
	return 0;
}