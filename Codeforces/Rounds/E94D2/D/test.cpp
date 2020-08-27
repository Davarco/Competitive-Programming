#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ipair;
typedef vector<int> vi;
typedef long long ll ;
#define fo(i, n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i=a; i<(b); i++)
#define pb emplace_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define debug(x) cout << #x << "  " << x << endl;   
#define mem(x,y) memset(x,y,sizeof(x))
#define endl '\n'
#define all(x) x.begin(), x.end()


void solve() {
    int n;  cin >> n;
    int ar[n];
    fo(i, n)    cin >> ar[i];
    int dp[n+1][n+1], prefix[n+1][n+1];
    fo(i, n) {
        int tmp = 0;
        for(int j=n-1;j>=0;j--) {
            dp[i][j] = tmp;
            if(ar[i] == ar[j])
                tmp++;
        }
    }
    mem(prefix, 0);
    fo(i, n) {
        fo(j, n) {
            prefix[i+1][j] = dp[i][j] + prefix[i][j];
        }
    }
    ll ans = 0;
    fo(i, n) {
        for(int j=i+1;j<n-1;j++) {
            if(ar[i] == ar[j])  {
                ans += prefix[j][j] - prefix[i+1][j];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while(t--) {
        solve();   
    }
}


