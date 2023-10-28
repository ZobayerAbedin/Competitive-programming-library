const int N = 1e6 + 7;
string s;
int z[N];

void zFunc(string const & s) {
    int l, r;
    l = r = z[0] = 0;
    int n = s.size();

    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
}