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

int n, m, k;
vector<vector<string>> v;
string str;

bool cmp(string str1, string str2) {
	if (str1.size() == str2.size())return str1 < str2;
	return str1.size() < str2.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	cin >> k >> str;
	while (k != 0 && str != "0") {
		if (v[k].size() < m) v[k].push_back(str);
		cin >> k >> str;
	}
	for (int i = 1;i <= n;i++)sort(v[i].begin(), v[i].end(), cmp);
	for (int i = 1;i <= n;i += 2)for (auto& j : v[i])cout << i << ' ' << j << endl;
	for (int i = 2;i <= n;i += 2)for (auto& j : v[i])cout << i << ' ' << j << endl;
	return 0;
}