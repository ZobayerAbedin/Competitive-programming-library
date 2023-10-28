#include<bits/stdc++.h>
using namespace std;

#define dbg(args...) \
{ \
    cerr << "Line("<< __LINE__ << ")";\
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr<< *it << " = " << a;
    cerr<<(++it == istream_iterator<string> () ? "\n" : ", ");
    err(it, args...);
}

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define I ios::sync_with_stdio(false); cin.tie(0);
#define Q int tt; cin>>tt ; for(int qq=1; qq <= tt; qq++)

#define ff first
#define ss second
#define sz(x) int((x).size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PB push_back
#define V vector


int main(){
    I
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif

    return 0;
}