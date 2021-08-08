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

int mp[9][9];
vector<PI> v;

bool check(int y, int x, int idx) {
	for (int i = 0;i < 9;i++)
		if (mp[y][i] == idx || mp[i][x] == idx)return false;
	for (int i = (y / 3) * 3;i < (y / 3) * 3 + 3;i++)
		for (int j = (x / 3) * 3;j < (x / 3) * 3 + 3;j++)
			if (mp[i][j] == idx)return false;
	return true;
}

bool dfs(int cur) {
	if (cur == v.size())return true;
	int y = v[cur].first;
	int x = v[cur].second;
	for (int i = 1;i <= 9;i++) {
		if (check(y, x, i)) {
			mp[y][x] = i;
			if (dfs(cur + 1))return true;
			mp[y][x] = 0;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> mp[i][j];
			if (!mp[i][j])v.push_back({ i,j });
		}
	}
	dfs(0);
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++)cout << mp[i][j] << ' ';
		cout << endl;
	}
	return 0;
}