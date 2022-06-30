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

int rc[105][105], cnt;

int rotate(vector<int> q) {
	cnt = 0;
	int ret = INF;
	int y1 = q[0], x1 = q[1], y2 = q[2], x2 = q[3];

	vector<int> v;
	for (int i = x1;i <= x2;i++) {
		ret = min(ret, rc[y1][i]);
		v.push_back(rc[y1][i]);
	}
	for (int i = y1 + 1;i <= y2;i++) {
		ret = min(ret, rc[i][x2]);
		v.push_back(rc[i][x2]);
	}
	for (int i = x2 - 1;i >= x1;i--) {
		ret = min(ret, rc[y2][i]);
		v.push_back(rc[y2][i]);
	}
	for (int i = y2 - 1;i > y1;i--) {
		ret = min(ret, rc[i][x1]);
		v.push_back(rc[i][x1]);
	}

	for (int i = x1 + 1;i <= x2;i++)
		rc[y1][i] = v[cnt++];
	for (int i = y1 + 1;i <= y2;i++)
		rc[i][x2] = v[cnt++];
	for (int i = x2 - 1;i >= x1;i--)
		rc[y2][i] = v[cnt++];
	for (int i = y2 - 1;i >= y1;i--) {
		rc[i][x1] = v[cnt++];
	}

	return ret;
}

vector<int> solution(int r, int c, vector<vector<int>> queries) {
	vector<int> ans;

	for (int i = 1;i <= r;i++) {
		for (int j = 1;j <= c;j++) {
			rc[i][j] = ++cnt;
		}
	}

	for (auto q : queries) {
		ans.push_back(rotate(q));
	}

	return ans;
}

int main() {
	solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
}