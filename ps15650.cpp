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

int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (i <= m)v.push_back(1);
		else v.push_back(0);
	}
	do {
		for (int i = 0; i < n; i++)
			if (v[i])cout << i + 1 << ' ';
		cout << endl;
	} while (prev_permutation(v.begin(), v.end()));
	return 0;
}
