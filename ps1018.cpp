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

int n, m, ans = INF;
char c[55][55], det[2];

int chk(int y, int x) {
	int cnt[2] = { 0, };
	for (int i = y;i < 8 + y;i++) {
		for (int j = x;j < 8 + x;j++) {
			if (det[(i + j) % 2] != c[i][j])cnt[0]++;
			else cnt[1]++;
		}
	}
	return min(cnt[0], cnt[1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++)cin >> c[i];
	det[0] = 'W', det[1] = 'B';
	for (int i = 0;i <= n - 8;i++)
		for (int j = 0;j <= m - 8;j++)
			ans = min(ans, chk(i, j));
	cout << ans << endl;
	return 0;
}