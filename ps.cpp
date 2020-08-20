#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<string.h>
#include<stack>
#include<set>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF 2e9
#define LINF 2e14
#define MOD 1000000007

int n, a, b;

int gcd(int x, int y) {
	if (y == 0)return x;
	else return gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
	return 0;
}