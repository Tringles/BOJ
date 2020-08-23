#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, dp[301][301], mine[301][301];

int wook(int y, int x) {
	if (y == n || x == m)return 0;
	int& ret = dp[y][x];
	if (ret)return ret;
	if (y < n)ret = max(ret, wook(y + 1, x) + mine[y][x]);
	if (x < m)ret = max(ret, wook(y, x + 1) + mine[y][x]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mine[i][j];
	cout << wook(0, 0) << endl;
	return 0;
}
