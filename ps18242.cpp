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

int n, m;
char t[101][101];
vector<int> h, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cin >> t[i][j];
			if (t[i][j] == '#')cnt++;
		}
		if (cnt)h.push_back(cnt);
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (t[j][i] == '#')cnt++;
		if (cnt)v.push_back(cnt);
	}
	if (h[0] == h[h.size() - 1]) {
		if (v[0] > v[v.size() - 1])cout << "RIGHT" << endl;
		else cout << "LEFT" << endl;
	}
	else if (h[0] > h[h.size() - 1])cout << "DOWN" << endl;
	else cout << "UP" << endl;
	return 0;
}
