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
char cmp[] = { 'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U' };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int cnt = 0;
		getline(cin, str);
		if (str.size() == 1 && str[0] == '#')break;
		for (int i = 0;i < str.size();i++)
			for (int j = 0;j < 10;j++)if (str[i] == cmp[j])cnt++;
		cout << cnt << endl;
	}
	return 0;
}