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
map<string, int> m;
vector<string> v;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> str;
		m[str]--;
	}
	for (auto& i : m) {
		if (i.second == 1) {
			cout << i.first << endl;
			break;
		}
	}
	return 0;
}