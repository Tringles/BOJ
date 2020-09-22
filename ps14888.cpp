#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

struct S { int sum, sub, pd, div; };
int n, s[15], maxans = -INF, minans = INF;
int a, b, c, d;
queue<pair<pair<int, int>, S>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> s[i];
	cin >> a >> b >> c >> d;
	q.push({ {s[0],0},{0,0,0,0} });
	while (!q.empty()) {
		int cur = q.front().first.first;
		int cnt = q.front().first.second;
		S now = q.front().second;
		q.pop();
		if (cnt == n - 1) {
			maxans = max(maxans, cur);
			minans = min(minans, cur);
			continue;
		}
		if (now.sum < a) {
			S push = now;
			push.sum++;
			q.push({ { cur + s[cnt + 1],cnt + 1 }, push });
		}
		if (now.sub < b) {
			S push = now;
			push.sub++;
			q.push({ { cur - s[cnt + 1],cnt + 1 }, push });
		}
		if (now.pd < c) {
			S push = now;
			push.pd++;
			q.push({ { cur * s[cnt + 1],cnt + 1 }, push });
		}
		if (now.div < d) {
			S push = now;
			push.div++;
			q.push({ { cur / s[cnt + 1],cnt + 1 }, push });
		}
	}
	cout << maxans << endl << minans << endl;
	return 0;
}
