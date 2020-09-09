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

int n, m, k, cur = -INF;
vector<string> sv;
vector<int> v;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str >> k;
		if (cur < k) {
			cur = k;
			sv.push_back(str);
			v.push_back(k);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> k;
		cout << sv[lower_bound(v.begin(), v.end(), k) - v.begin()] << endl;
	}
	return 0;
}