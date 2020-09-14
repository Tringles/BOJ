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

int n, k, p1, p2, l, chk, ans;
int a[105][105], visit[105][105];
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
char c;
queue<PI> tail;
queue <pair<int, PII>> q;
vector<pair<int, char>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> p1 >> p2;
		a[p1][p2] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> p1 >> c;
		v.push_back({ p1,c });
	}
	v.push_back({ INF,c });
	tail.push({ 1,1 });
	q.push({ 1,{1,{0,0}} });
	visit[1][1] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second.first;
		int dir = q.front().second.second.first;
		int cnt = q.front().second.second.second;
		q.pop();
		if (v[chk].first == cnt) {
			if (v[chk].second == 'D')dir = (dir + 1) % 4;
			else dir = (dir + 4 - 1) % 4;
			chk++;
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny<1 || nx<1 || ny>n || nx>n || visit[ny][nx]) {
			ans = cnt + 1;
			break;
		}
		if (a[ny][nx]) {
			q.push({ ny,{nx,{dir,cnt + 1}} });
			a[ny][nx] = 0;
			visit[ny][nx] = true;
			tail.push({ ny,nx });
		}
		else {
			q.push({ ny,{nx,{dir,cnt + 1}} });
			tail.push({ ny,nx });
			auto cur = tail.front();
			tail.pop();
			visit[cur.first][cur.second] = 0;
			visit[ny][nx] = true;
		}
	}
	cout << ans << endl;
	return 0;
}