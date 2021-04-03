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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> str;
    int i = 0, left = 0, right = str.size() - 1;
    while(left + i <= right - i){
        if(str[left + i] != str[right - i]){
            cout << 0 << endl;
            return 0;
        }
        i++;
    }
    cout << 1 << endl;
    return 0;
}
