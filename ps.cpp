#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, s[100001], a[100001], d[100001], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> s[i];
	for (int i = 1; i <= n; i++) {
		if (s[i] >= s[i - 1])a[i] = a[i - 1] + 1;
		else a[i] = 1;
		ans = max(ans, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] <= s[i - 1])d[i] = d[i - 1] + 1;
		else d[i] = 1;
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
	return 0;
}