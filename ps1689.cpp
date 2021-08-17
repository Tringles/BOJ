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

int n, ans = 1;
PI p[1000005];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p, p + n);
	q.push(p[0].second);
	for (int i = 1;i < n;i++) {
		while (!q.empty() && q.top() <= p[i].first)q.pop();
		q.push(p[i].second);
		ans = max(ans, (int)q.size());
	}
	cout << ans << endl;
	return 0;
}