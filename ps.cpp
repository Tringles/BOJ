#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, s, ans;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.push_back(-INF);
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (v.back() < s) {
			v.push_back(s);
			ans++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), s);
			*it = s;
		}
	}
	cout << n - ans << endl;
	return 0;
}