#include<bits/stdc++.h>
#include<unordered_map>
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

int n, m, s, cnt, idx;
deque<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)q.push_back(i);
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (q.front() == s)q.pop_front();
		else {
			idx = 0;
			for (auto& i : q) {
				if (i == s)break;
				else idx++;
			}
			if ((q.size() / 2) < idx) {
				while (q.front() != s) {
					q.push_front(q.back());
					q.pop_back();
					cnt++;
				}
				q.pop_front();
			}
			else {
				while (q.front() != s) {
					q.push_back(q.front());
					q.pop_front();
					cnt++;
				}
				q.pop_front();
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
