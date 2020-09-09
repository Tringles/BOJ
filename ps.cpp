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

int t, n, m, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		queue<PI> q;
		priority_queue<int> pq;
		int cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			pq.push(s);
			q.push({ i,s });
		}
		while (true) {
			int max = pq.top();
			auto cur = q.front();
			q.pop();
			if (max != cur.second)q.push(cur);
			else {
				pq.pop();
				cnt++;
				if (cur.first == m) {
					cout << cnt << endl;
					break;
				}
			}
		}
	}
	return 0;
}