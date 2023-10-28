class SparseTable
{
public:
	int n;
	vector<vector<ll>> table;
	int limit;
	vector<int> lg;
	SparseTable(int _n) {
		n = _n;
		limit = __lg(n) + 2;
		lg.assign(n + 5, 0);
		table.assign(n + 5, vector<ll>(limit));
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i / 2] + 1;
		}
	}
	virtual int merge(ll u, ll v) = 0;
	void build(const vector<int> &a) {
		for (int i = 0; i < n; i++) {
			table[i][0] = a[i];
		}
		for (int j = 1; j < limit; j++) {
			for (int i = 0; i + (1<<j) <= n; i++) {
				table[i][j] = merge(table[i][j - 1], table[i + (1<<(j - 1))][j - 1]);
			}
		}
	}
	int query(int l, int r) {
		int len = lg[r - l + 1];
		int ans = merge(table[l][len], table[r - (1<<len) + 1][len]);
		return ans;
	}
};

class LCM : public SparseTable
{
public:
	LCM(int n) : SparseTable(n) {};
	int merge(ll u, ll v) {
		ll ret = min((ll)1e8, u * v / __gcd(u, v));
		return ret;
	}
};