#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, s[1111], ctr = 1, ans;
string str;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	s[0] = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) {
			s[i] = s[i - 1] + 1;
			if (ctr < s[i]) {
				ctr = s[i];
				ans = i;
			}
		}
		else s[i] = 1;
	}
	cout << v[ans] << endl;
	return 0;
}
