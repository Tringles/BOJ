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

int n, m, bit[1005], ans;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'T')bit[i] += pow(2, m - j - 1);
		}
	}
	for (int i = 0; i < (1 << m); i++) {
		int cnt = INF;
		for (int j = 0; j < n; j++) {
			int tmp = i ^ bit[j];
			int cur = 0;
			while (tmp) {
				if (tmp % 2)cur++;
				tmp /= 2;
			}
			cnt = min(cnt, cur);
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
