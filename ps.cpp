#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m;
int visit[100001], path[100001];
queue<int> q;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	visit[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == m)break;
		int next[] = { cur + 1,cur - 1,cur * 2 };
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (next[i] < 0 || next[i]>100000)continue;
			if (!visit[next[i]]) {
				visit[next[i]] = visit[cur] + 1;
				path[next[i]] = cur;
				q.push(next[i]);
			}
		}
	}
	cout << visit[m] - 1 << endl;
	for (int i = m; i != n; i = path[i])s.push(i);
	s.push(n);
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
	return 0;
}