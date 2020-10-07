#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

ll n, k, w;
vector<ll> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	for (int i = 1; i < n; i++) {
		if (v[i - 1] < v[i])
			w = (w / v[i - 1]) * v[i] + w % v[i - 1];
	}
	cout << w << endl;
	return 0;
}