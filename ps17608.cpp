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
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, p1;i < n;i++) {
		cin >> p1;
		if (s.empty()) {
			s.push(p1);
		}
		else {
			if (s.top() <= p1) {
				while (!s.empty() && s.top() <= p1)s.pop();
				s.push(p1);
			}
			else {
				s.push(p1);
			}
		}
	}
	cout << s.size() << endl;
	return 0;
}