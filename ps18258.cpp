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

int n, k;
queue<int> q;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> str;
		if (str[0] == 's')cout << q.size() << endl;
		else if (str == "push") {
			cin >> k;
			q.push(k);
		}
		else if (str == "pop") {
			if (q.empty())cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "empty") cout << q.empty() << endl;
		else if (str == "front") {
			if (q.empty())cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else {
			if (q.empty())cout << -1 << endl;
			else cout << q.back() << endl;
		}
	}
	return 0;
}
