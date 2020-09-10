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

int n, k;
unordered_map<string, int> m;
vector<pair<int, string>> v;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		m[str] = i;
		v.push_back({ i,str });
	}
	for (int i = 0; i < k; i++) {
		cin >> str;
		if ('A' <= str[0] && str[0] <= 'Z') {
			cout << m[str] << endl;
		}
		else cout << v[stoi(str) - 1].second << endl;
	}
	return 0;
}