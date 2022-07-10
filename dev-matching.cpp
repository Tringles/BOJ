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

int visited[5][6];
char mp[5][6];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
map<char, pair<int, int>> m;
string tmp1, tmp2;

int tmp1bfs(int cur) {
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	char c = tmp1[cur - 1], next = tmp1[cur];
	int cy = m[c].first, cx = m[c].second;
	visited[cy][cx] = 1;
	q.push({ cy, cx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 0 || ny>4 || nx < 0 || nx>5)continue;
			if (mp[ny][nx] == '\0')continue;
			if (!visited[ny][nx]) {
				if (mp[ny][nx] == next)return visited[y][x];
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}
int tmp2bfs(int cur) {
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	char c = tmp2[cur - 1], next = tmp2[cur];
	int cy = m[c].first, cx = m[c].second;
	visited[cy][cx] = 1;
	q.push({ cy, cx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 0 || ny>4 || nx < 0 || nx>5)continue;
			if (mp[ny][nx] == '\0')continue;
			if (!visited[ny][nx]) {
				if (mp[ny][nx] == next)return visited[y][x];
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int solution(string str) {
	if (str.size() <= 2)return 0;
	int ans = INF, cy = 0, cx = 0;
	for (int i = 0; i < 26; i++) {
		char c = i + 'A';
		mp[cy][cx] = c;
		m[c] = { cy, cx };
		cx++;
		if (cx > 5) {
			cx = 0;
			cy++;
		}
	}
	for (int i = 0; i < pow(2, str.size()); i++) {
		int temp = i;
		tmp1 = "", tmp2 = "";
		for (int j = 0; j < str.size(); j++) {
			int mod = temp % 2;
			temp /= 2;
			if (mod)tmp1 += str[j];
			else tmp2 += str[j];
		}

		int cur = 1, sum = 0;
		for (int j = cur; j < tmp1.size(); j++) {
			sum += tmp1bfs(j);
		}

		cur = 1;
		for (int j = cur; j < tmp2.size(); j++) {
			sum += tmp2bfs(j);
		}
		ans = min(ans, sum);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << solution("HAPPY") << endl;
	return 0;
}