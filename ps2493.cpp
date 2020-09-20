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

int n, m[500005], k;
stack<PI> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (s.empty())
			s.push({ k,i });
		else {
			while (!s.empty()) {
				if (s.top().first < k) {
					s.pop();
				}
				else {
					m[i] = s.top().second;
					break;
				}
			}
			s.push({ k,i });
		}
	}
	for (int i = 1; i <= n; i++)cout << m[i] << ' ';
	cout << endl;
	return 0;
}
