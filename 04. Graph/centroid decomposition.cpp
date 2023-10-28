struct cD {
	vector<vector<int> > g;
	vector<int> pr, sub;
	vector<bool> vis;

	cD(vector<int> g[], int n) {
		this->g.resize(n + 2, vector<int>() );
		for (int i = 1; i <= n; i++) {
			this->g[i].insert(this->g[i].end(),g[i].begin(), g[i].end());
		}
		pr = vector<int> (n + 1, -1);
		sub = vector<int> (n + 1, 0);
		vis = vector<bool> (n + 1, 0);
		bld(1, -1);
	}

	void bld(int u, int pp) {
		int c = findC(u, -1, findS(u));
		pr[c] = pp;
		vis[c] = 1;

		for (int v : g[c]) {
			if(!vis[v]) bld(v, c);
		}
	}

	int findS(int u, int pp = -1) {
		if(vis[u]) return 0;
		sub[u] = 1;
		for (int v : g[u]) {
			if (v != pp) sub[u] += findS(v, u);;
		}
		return sub[u];
	}

	int findC(int u, int pp, int n) {
		for (int v : g[u])
			if (v != pp and !vis[v] and sub[v] > n/2) return findC(v, u, n);
		return u;
	}

	int operator[](int i) {
		return pr[i];
	}
};