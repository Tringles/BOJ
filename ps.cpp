#include<bits/stdc++.h>
#include<unordered_map>
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

int t, n;
string op, str;
deque<int> v;
queue<char> q;
bool flag, fb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> op >> n;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '[')continue;
			else if (str[i] == ',' || str[i] == ']') {
				int tmp = 0;
				if (!q.empty()) {
					while (!q.empty()) {
						int cur = q.front() - '0';
						q.pop();
						tmp *= 10;
						tmp += cur;
					}
					v.push_back(tmp);
				}
			}
			else q.push(str[i]);
		}
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'R')fb = !fb;
			else {
				if (v.empty()) {
					cout << "error" << endl;
					flag = true;
					break;
				}
				else {
					if (fb)v.pop_back();
					else v.pop_front();
				}
			}
		}
		if (!flag) {
			cout << '[';
			if (fb) {
				for (int i = v.size() - 1; i >= 0; i--) {
					cout << v[i];
					if (i != 0)cout << ',';
				}
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					cout << v[i];
					if (i != v.size() - 1)cout << ',';
				}
			}
			cout << ']' << endl;
		}
		v.clear();
		flag = fb = false;
	}
	return 0;
}