#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

string str;
int ans, n;
bool check[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> s;
		cin >> str;
		s.push(str[0]);
		for (int j = 1; j < str.size(); j++) {
			char c = s.top();
			if(c==str[j])s.push(str[j]);
			else {
				if (check[str[j] - 'a']) {
					ans--;
					break;
				}
				check[s.top() - 'a'] = true;
				while (!s.empty())s.pop();
				s.push(str[j]);
			}
		}
		ans++;
		memset(check, 0, sizeof(check));
	}
	cout << ans << endl;
	return 0;
}