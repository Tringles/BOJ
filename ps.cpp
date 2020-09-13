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

string a, b;
stack<PI> s;
bool chk[1000005], flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	if (b.size() == 1) {
		for (int i = 0; i < a.size(); i++)
			if (a[i] == b[0])chk[i] = true;
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[0])
				s.push({ i,0 });
			else {
				if (!s.empty()) {
					int cur = s.top().second;
					if (a[i] == b[cur + 1]) {
						s.push({ i,cur + 1 });
						if (cur + 1 == b.size() - 1) {
							for (int j = 0; j < b.size(); j++) {
								int idx = s.top().first;
								chk[idx] = true;
								s.pop();
							}
						}
					}
					else while (!s.empty())s.pop();
				}
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (!chk[i]) {
			cout << a[i];
			flag = true;
		}
	}
	if (!flag)cout << "FRULA";
	cout << endl;
	return 0;
}