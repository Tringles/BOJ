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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	getline(cin, str);
	for (int i = 0;i < str.size() - 1;i++)
		if ((str[i] == 'd' && str[i + 1] == '2') || ((str[i] == 'D' && str[i + 1] == '2'))) {
			cout << "D2" << endl;
			return 0;
		}
	cout << "unrated" << endl;
	return 0;
}