#include<bits/stdc++.h>
#include<unordered_map>
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

int n, m;
char c[22][22];
bool start;
queue<char> q;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (!j || start) {
				string tmp;
				for (int k = j; k < m; k++) {
					if (c[i][k] != '#')q.push(c[i][k]);
					else break;
				}
				if (q.size() > 1) {
					while (!q.empty()) {
						tmp += q.front();
						q.pop();
					}
					v.push_back(tmp);
				}
				else while (!q.empty())q.pop();
				start = false;
			}
			if (c[i][j] == '#')start = true;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (!j || start) {
				string tmp;
				for (int k = j; k < n; k++) {
					if (c[k][i] != '#')q.push(c[k][i]);
					else break;
				}
				if (q.size() > 1) {
					while (!q.empty()) {
						tmp += q.front();
						q.pop();
					}
					v.push_back(tmp);
				}
				else while (!q.empty())q.pop();
				start = false;
			}
			if (c[j][i] == '#')start = true;
		}
	}
	sort(v.begin(), v.end());
	cout << v[0] << endl;
	return 0;
}
