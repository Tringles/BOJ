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

int tmp = 1, ans;
string str;
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			tmp *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() == '[') {
				cout << 0 << endl;
				return 0;
			}
			else {
				if (str[i - 1] == '(')
					ans += tmp;
				tmp /= 2;
				s.pop();
			}
		}
		else {
			if (s.empty() || s.top() == '(') {
				cout << 0 << endl;
				return 0;
			}
			else {
				if (str[i - 1] == '[')
					ans += tmp;
				tmp /= 3;
				s.pop();
			}
		}
	}
	cout << (s.empty() ? ans : 0) << endl;
	return 0;
}