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

char f[202][202];
int n, m, Visit[202][202], key[26], check[202][202];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
queue<PI> q, vq, kq[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> f[i][j];
			if (f[i][j] == '@') {
				q.push({ i,j });
				vq.push({ i,j });
				Visit[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;
			if (f[ny][nx] != '#' && !Visit[ny][nx]) {
				if ('A' <= f[ny][nx] && f[ny][nx] <= 'Z')
					if (!key[f[ny][nx] - 'A']) {
						kq[f[ny][nx] - 'A'].push({ ny,nx });
						continue;
					}
				Visit[ny][nx] = true;
				q.push({ ny,nx });
				if (!check[ny][nx]) {
					vq.push({ ny,nx });
					check[ny][nx] = true;
				}
				if ('a' <= f[ny][nx] && f[ny][nx] <= 'z') {
					key[f[ny][nx] - 'a']++;
					while (!kq[f[ny][nx] - 'a'].empty()) {
						int ky = kq[f[ny][nx] - 'a'].front().first;
						int kx = kq[f[ny][nx] - 'a'].front().second;
						kq[f[ny][nx] - 'a'].pop();
						q.push({ ky,kx });
						if (!check[ky][kx]) {
							vq.push({ ky,kx });
							check[ky][kx] = true;
						}
						Visit[ky][kx] = true;
					}
				}
				if (f[ny][nx] == '!') {
					cout << vq.size() << endl;
					while (!vq.empty()) {
						int ansy = vq.front().first;
						int ansx = vq.front().second;
						vq.pop();
						cout << ansy + 1 << ' ' << ansx + 1 << endl;
					}
					return 0;
				}
			}
		}
	}
	return 0;
}
