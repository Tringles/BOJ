#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, s[505], w[505], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)cin >> s[i];
	for (int i = 1; i < m - 1; i++) {
		int lo = s[i], hi = s[i];
		for (int j = 0; j < i; j++)
			lo = max(lo, s[j]);
		for (int j = i + 1; j < m; j++)
			hi = max(hi, s[j]);
		ans += min(hi, lo) - s[i];
	}
	cout << ans << endl;
    return 0;
}
