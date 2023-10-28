struct Dinic {
	struct Edge {
		int u, v;
		ll cap, flow = 0;
		Edge() {}
		Edge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
	};
	int N;
	vector<Edge> edge;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N) : N(N), edge(0), g(N), d(N), pt(N) {}
	void addEdge(int u, int v, ll cap) {
		if (u == v) return;
		edge.PB({u, v, cap});
		g[u].PB(edge.size() - 1);
		edge.PB({v, u, 0});
		g[v].PB(edge.size() - 1);
	}
	bool bfs(int s, int t) {
		queue<int> q({s});
		fill(d.begin(), d.end(), N + 1);
		d[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t) break;
			for (int k : g[u]) {
				Edge &e = edge[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] +1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[t] != N + 1;
	}
	ll dfs(int u, int T, ll flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); i++) {
			Edge &e = edge[g[u][i]];
			Edge &oe = edge[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = dfs(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int s, int t) {
		ll total = 0;
		while (bfs(s, t)) {
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = dfs(s, t)) {
				total += flow;
			}
		}
		return total;
	}
};
