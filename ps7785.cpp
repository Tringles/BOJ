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

int n;
string a, b;
map<string, int> m;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b == "enter")
			m[a]++;
		else m[a]--;
	}
	for (auto& i : m)
		if (i.second == 1)v.push_back(i.first);
	sort(v.rbegin(), v.rend());
	for (auto& i : v)
		cout << i << endl;
	return 0;
}
