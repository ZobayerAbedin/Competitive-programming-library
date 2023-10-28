ll Fact[N], iFact[N], inv[N];

void preComb(int n) {
	Fact[0] = iFact[0] = 1;
	inv[1] = 1;
	for (int i = 2; i < n; i++) {
		inv[i] = mod - (mod / i) * inv[mod%i] % mod;
	}
	for (int i = 1; i < n; i++) {
		Fact[i] = Fact[i - 1] * i % mod;
		iFact[i] = iFact[i - 1] * inv[i] % mod;
	}
}

ll nCr(ll n, ll r) {
	if(n < r || r < 0) return 0;
	return Fact[n] * iFact[r] % mod * iFact[n - r] % mod;
}
