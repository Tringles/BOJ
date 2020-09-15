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

int t, n, m;
bool visit[10001];
queue<pair<int, string>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		visit[n] = true;
		q.push({ n,"" });
		while (!q.empty()) {
			int cur = q.front().first;
			string str = q.front().second;
			q.pop();
			if (cur == m) {
				cout << str << endl;
				break;
			}
			int next = (2 * cur) % 10000;
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next, str + 'D' });
			}
			if (cur == 0)next = 9999;
			else next = cur - 1;
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,str + 'S' });
			}
			if (cur) {
				next = (cur % 1000) * 10 + cur / 1000;
				if (!visit[next]) {
					visit[next] = true;
					q.push({ next,str + 'L' });
				}
				next = (cur / 10) + (cur % 10) * 1000;
				if (!visit[next]) {
					visit[next] = true;
					q.push({ next,str + 'R' });
				}
			}
		}
		while (!q.empty())q.pop();
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}