#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, t, g;
int visit[100000];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t >> g;
	visit[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visit[cur] > t + 1)break;
		if (cur + 1 < 100000 && !visit[cur + 1]) {
			visit[cur + 1] = visit[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 < 100000) {
			int next = cur * 2;
			for (int i = 10000; i >= 1; i /= 10) {
				if (next / i) {
					next -= i;
					break;
				}
			}
			if (!visit[next]) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
	if (visit[g] > t + 1 || !visit[g])cout << "ANG" << endl;
	else cout << visit[g] - 1 << endl;
	return 0;
}