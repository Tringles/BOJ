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

int cnt;
string str;
map<string, int> m;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(4);
	while (getline(cin, str)) {
		m[str]++;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	cout << v[0] << ' ' << (double)100 * (m[v[0]]) / v.size() << endl;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1])continue;
		cout << v[i] << ' ' << (double)100 * (m[v[i]]) / v.size() << endl;
	}
	return 0;
}