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

int n, k, m;
double tmp, x, y;
vector<double> v;

double dist(int x, int y) { return sqrt(pow(x, 2) + pow(y, 2)); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			tmp = max(tmp, dist(x, y));
		}
		v.push_back(tmp);
		tmp = 0;
	}
	sort(v.begin(), v.end());
	cout << fixed << setprecision(2) << pow(v[k - 1], 2) << endl;
	return 0;
}
