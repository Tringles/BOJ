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
string str;
map<string, int> h;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (!h[str])h[str]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (h[str])v.push_back(str);
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (auto& i : v)cout << i << endl;
	return 0;
}
