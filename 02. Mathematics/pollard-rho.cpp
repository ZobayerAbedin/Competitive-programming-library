//Complexity for checking prime: klog(n)
//Complexity for prime factorization: O(sqrt(Smallest Prime Factor of n)) = O(n^(1/4))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {
    uniform_int_distribution<ll>uid(l, r);
    return uid(rng);
}

#define pii pair<ll,int>

ll Mul(ll a,ll b,ll Mod){
    ll Ans=0;
    while(b){
        if(b&1) {Ans+=a; if(Ans>=Mod) Ans-=Mod;}
        a+=a; if(a>=Mod) a-=Mod;
        b>>=1;
    }
    return Ans;
}

ll bM(ll n,ll p, ll mod){
    if(p==0) return 1ll;
    if(p%2==0){
        ll ret=bM(n, p/2, mod);
        return (ret*ret)%mod;
    }
    return (n*bM(n, p-1, mod))%mod;
}
//Miller-Rabin
bool witness(ll wit,ll n){
    if(wit>=n) return false;

    int s=0; ll t=n-1;
    while(t%2==0) s++,t/=2;

    wit=bM(wit,t,n);
    if(wit==1 || wit==n-1) return false;
    for(int i=1;i<s;i++){
        wit=Mul(wit,wit,n);
        if(wit==1) return true;
        if(wit==n - 1) return false;
    }
    return true;
}

//Is n prime?
bool miller(ll n){
    if(n==2) return true;
    if(n%2==0 || n<2) return false;
    //n < 4,759,123,141,(~2 ^ 32) it is enough to test =
    vector<ll> chk={2, 7, 61};

    //n < (2^ 64), it is enough to test=
    //vector<ll> chk = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(ll x : chk) {
        if(witness(x, n)) return false;
    }
    return true;
}

// Pollard's Rho
// a must not equal 0 or -2.
// returns a divisor, a proper one when succeeded, equal to n if failed
// in case of failure, change a
ll rho(ll n,ll a) {
    auto f=[&](ll x) {return (Mul(x,x,n)+a)%n; };
    ll x=2,y=2;
    for(int i=1;;i++) {
        x=f(x); y=f(f(y));
        ll d=__gcd(n,abs(x-y));
        if(d!=1) return d;
    }
    return n;
}

ll get_factor(ll n){
    if(n%2==0) return 2;
    if(n%3==0) return 3;
    if(n%5==0) return 5;
    while(true){
        ll a=2+rand(0, 100);
        ll d=rho(n,a);
        if(d!=n) return d;
    }
    return n;
}

void pFct(ll n,vector<ll> &x) {
    if(n==1) return;
    else if(miller(n)) x.push_back(n);
    else{
        ll d=get_factor(n);
        pFct(d,x);
        pFct(n/d,x);
    }
}

vector<ll> pFct(ll n) {vector<ll>x; pFct(n, x); return x;}

vector<pii>Factors;
vector<ll>Divisors;
void findDiv(int pos,ll val){
    if(pos<0) {Divisors.push_back(val); return;}
    ll Now=1;
    for(int i=0;i<=Factors[pos].second;i++){
        findDiv(pos-1,val*Now);
        Now=Now*Factors[pos].first;
    }
}

void findAllDiv(ll n){
    vector<ll>now=pFct(n);
    sort(now.begin(),now.end());

    Factors.clear();
    Divisors.clear();
    int Count=1;
    for(int i=1;i<now.size();i++){
        if(now[i]==now[i-1]) Count++;
        else {Factors.push_back({now[i-1],Count}); Count=1;}
    }
    Factors.push_back({now.back(),Count});
    findDiv(Factors.size()-1,1);
}