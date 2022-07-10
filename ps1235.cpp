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
string id[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> id[i];

	for (int i = 1;i <= id[0].size();i++) {
		map<string, int> m;
		int flag = true;
		for (int j = 0;j < n;j++) {
			string s = id[j].substr(id[0].size() - i, i);
			m[s]++;
			if (m[s] > 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}