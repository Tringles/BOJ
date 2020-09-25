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

int n, visit[1000005], cnt;
queue<int> q;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!cur)continue;
		if (cur == 1) break;
		if (!(cur % 3)) {
			if (!visit[cur / 3]) {
				visit[cur / 3] = cur;
				q.push(cur / 3);
			}
		}
		if (!(cur % 2)) {
			if (!visit[cur / 2]) {
				visit[cur / 2] = cur;
				q.push(cur / 2);
			}
		}
		if (!visit[cur - 1]) {
			visit[cur - 1] = cur;
			q.push(cur - 1);
		}
	}
	int x = 1;
	s.push(x);
	while (x != n) {
		if (visit[x])x = visit[x];
		s.push(x);
		cnt++;
	}
	cout << cnt << endl;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		cout << cur << ' ';
	}
	cout << endl;
	return 0;
}
