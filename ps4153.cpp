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

int a[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while(1){
        cin >> a[0] >> a[1] >> a[2];
        if(!a[0] && !a[1] && !a[2])break;
        sort(a, a + 3);
        if((a[0] * a[0] + a[1] * a[1]) == a[2] * a[2])
            cout << "right" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}
