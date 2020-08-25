#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, f[500001], p;
vector<int> v, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++)cin >> f[i];
	for (int i = 0; i < m; i++) {
		s.push_back(upper_bound(v.begin(), v.end(), f[i]) - lower_bound(v.begin(), v.end(), f[i]));
	}
	for (auto& i : s)cout << i << ' ';
	cout << endl;
	return 0;
}