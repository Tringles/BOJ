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

int n, m[100005], l[100005], r[100005];
stack<int> s;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0;i < n;i++)cin >> m[i];
	cin >> str;
	for (int i = 0;i < n;i++) {
		if (s.empty()) {
			s.push(m[i]);
		}
		else {
			l[i] = s.size();
			if (s.top() <= m[i])
				while (!s.empty() && s.top() < m[i])s.pop();
			s.push(m[i]);
		}
	}
	while (!s.empty())s.pop();
	for (int i = n - 1;i >= 0;i--) {
		if (s.empty()) {
			s.push(m[i]);
		}
		else {
			r[i] = s.size();
			if (s.top() <= m[i])
				while (!s.empty() && s.top() < m[i])s.pop();
			s.push(m[i]);
		}
	}
	for (int i = 0;i < str.size();i++) {
		if (str[i] == 'L')cout << l[i] << ' ';
		else cout << r[i] << ' ';
	}
	cout << endl;
	return 0;
}