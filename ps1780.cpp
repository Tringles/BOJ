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

int n, mp[2222][2222], cnt[3];

// 9
/*
0~3, 0~3 | 0~3, 3~6 | 0~3, 6~9
3~6, 0~3 | 3~6, 3~6 | 3~9, 6~9
6~9, 0~3 | 6~9, 3~6 | 6~9, 6~9
*/

void func(int y1, int x1, int y2, int x2) {
	bool flag = false;
	int det = mp[y1][x1];
	for (int i = y1;i < y2;i++)for (int j = x1;j < x2;j++) {
		if (det != mp[i][j]) {
			int ky = (y2 - y1) / 3;
			int kx = (x2 - x1) / 3;
			func(y1, x1, y1 + ky, x1 + kx);
			func(y1, x1 + kx, y1 + ky, x1 + (2 * kx));
			func(y1, x1 + (2 * kx), y1 + ky, x1 + (3 * kx));
			func(y1 + ky, x1, y1 + (2 * ky), x1 + kx);
			func(y1 + ky, x1 + kx, y1 + (2 * ky), x1 + (2 * kx));
			func(y1 + ky, x1 + (2 * kx), y1 + (2 * ky), x1 + (3 * kx));
			func(y1 + (2 * ky), x1, y1 + (3 * ky), x1 + kx);
			func(y1 + (2 * ky), x1 + kx, y1 + (3 * ky), x1 + (2 * kx));
			func(y1 + (2 * ky), x1 + (2 * kx), y1 + (3 * ky), x1 + (3 * kx));
			return;
		}
	}
	cnt[det + 1]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++)for (int j = 0;j < n;j++)cin >> mp[i][j];
	func(0, 0, n, n);
	for (auto i : cnt)cout << i << endl;
	return 0;
}