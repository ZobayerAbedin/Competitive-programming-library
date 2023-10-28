
// mod and k must be coprime and k is > 200(prime preferable)
// backup prime = 300007159, 999999017, 1000000289, 1000007117,1000000007
struct rH {
    const ll k = 239;
    ll mod[2] = {1000000289, 1000007117};
    string  s;
    int n;
    vector<vector<ll> > pw, vl;
    rH(){}
    rH(string s): s(s), n(s.size()) {
        pw.resize(2, vector<ll> (n + 2, 1) );
        vl.resize(2, vector<ll> (n + 2, 0) );
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                vl[i][j + 1] = (vl[i][j] * k % mod[i] + s[j]) % mod[i];
                // if(i == 1) dbg(j, vl[i][j + 1]);
                pw[i][j + 1] = (pw[i][j] * k) % mod[i];
            }
        }
    }
    void operator = (const rH &hs) {
        pw.clear();
        vl.clear();
        pw = hs.pw;
        vl = hs.vl;
        s = hs.s;
        n = hs.n;
    }
    ll h0(int i, int l) {
        return vl[i][l];
    }
    pll h(int l, int r) {
        //if(l > r || r >= n) return {0ll, 0ll};
        ll tmp = (h0(0, r + 1) - (h0(0, l) * pw[0][r + 1 - l]) % mod[0] + mod[0]) % mod[0];
        ll tmp1 = (h0(1, r + 1) - (h0(1, l) * pw[1][r + 1 - l]) % mod[1] + mod[1]) % mod[1];
        return {tmp, tmp1};
    }
};

// single hash
struct rH {
    const ll k = 239, mod = 1000000289;
    string s;
    int n;
    vector<ll> pw, vl;
    rH(){}
    rH(string s): s(s), n(s.size()), pw(n + 1), vl(n + 1) {
        pw[0] = 1, vl[0] = 0;
        for (int i = 0; i < n; i++) {
            vl[i + 1] = (vl[i] * k % mod + s[i] ) % mod;
            pw[i + 1] = (pw[i] * k) % mod;
        }
    }
    void operator = (const rH &hs) {
        pw.clear();
        vl.clear();
        pw = hs.pw;
        vl = hs.vl;
        s = hs.s;
        n = hs.n;
    }
    ll h(int l) {
        return vl[l];
    }
    ll h(int l, int r) {
        return (h(r + 1) - (h(l) * pw[r + 1 - l]) % mod + mod) % mod;
    }
};

// rH hs(s);
// hs.h(l, r)