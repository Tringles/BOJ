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

int n, p1, p2;
vector<int> v;
vector<PI> p;
stack<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	v.push_back(-INF);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p1 >> p2;
		p.push_back({ p1,p2 });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++) {
		if (v.back() < p[i].second) {
			v.push_back(p[i].second);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), p[i].second);
			*it = p[i].second;
		}
	}
	cout << n-v.size() + 1 << endl;
	return 0;
}