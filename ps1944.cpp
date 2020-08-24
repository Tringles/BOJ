#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

string str;
int n, m, cnt = 2, ans, det, mst;
int visit[51][51], key[51][51], p[255];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
priority_queue<P, vector<P>, greater<P>> pq;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	p[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] - '0' == 1)key[i][j] = -1;
			else if (str[j] == 'S')key[i][j] = 1;
			else if (str[j] == 'K')key[i][j] = cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (key[i][j] >= 1) {
				mst = 0;
				visit[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1)continue;
						if (!visit[ny][nx] && key[ny][nx] != -1) {
							visit[ny][nx] = visit[y][x] + 1;
							if (key[ny][nx]) {
								pq.push({ visit[ny][nx] - 1,{key[i][j],key[ny][nx]} });
								mst++;
							}
							q.push({ ny,nx });
						}
					}
				}
				if (mst != m) {
					cout << -1 << endl;
					return 0;
				}
				memset(visit, 0, sizeof(visit));
			}
		}
	}
	while(!pq.empty()) {
		int d = pq.top().first;
		int cur = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		if (merge(cur, next)) {
			ans += d;
			if (++det == m + 1)break;
		}
	}
	cout << ans << endl;
	return 0;
}
