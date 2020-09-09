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

int n, m, cnt = 1;
stack<int> s;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		q.push(m);
	}
	while (!q.empty()) {
		int cur = q.front();
		if (cur == cnt) {
			cnt++;
			q.pop();
		}
		else {
			if (!s.empty() && s.top() == cnt) {
				s.pop();
				cnt++;
			}
			else {
				s.push(cur);
				q.pop();
			}
		}
	}
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (cur != cnt) {
			cout << "Sad" << endl;
			return 0;
		}
		cnt++;
	}
	cout << "Nice" << endl;
	return 0;
}
