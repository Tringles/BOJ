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

string str;
stack<char> s;
bool check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1) {
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.')break;
		check = true;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[')s.push(str[i]);
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(')s.pop();
				else {
					check = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[')s.pop();
				else {
					check = false;
					break;
				}
			}
		}
		if (check && s.empty())cout << "yes" << endl;
		else cout << "no" << endl;
		while (!s.empty())s.pop();
	}
	return 0;
}