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

int n, h, t, s, ans;
priority_queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		cin >> s;
		q.push(s);
	}
	if (q.top() == 1 && h == 1) {
		cout << "NO" << endl << 1 << endl;
		return 0;
	}
	if (q.top() < h) {
		cout << "YES" << endl << ans << endl;
		return 0;
	}
	while (t--) {
		int cur = q.top();
		if (cur < h) {
			cout << "YES" << endl << ans << endl;
			return 0;
		}
		q.pop();
		cur /= 2;
		ans++;
		q.push(cur);
	}
	(q.top() < h ? cout << "YES" << endl << ans << endl : cout << "NO" << endl << q.top() << endl);
	return 0;
}