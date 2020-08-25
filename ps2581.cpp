#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

vector<int> v;
bool prime[10001];
int n, m, ans, ma = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(prime + 2, 1, sizeof(prime));
	for (int i = 2; i <= 10000; i++) {
		for (int j = i * 2; j <= 10000; j += i)
			prime[j] = false;
	}
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (prime[i]) {
			ans += i;
			ma = min(ma, i);
		}
	}
	if (ans)	cout << ans << endl << ma << endl;
	else cout << -1 << endl;
	return 0;
}
