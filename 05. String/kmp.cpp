//0-based
int pi[N];

void lps(string const& s){
    int n = s.size();
    for(int i = 1; i < n;i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}

//1-based
int kmp(string const & t, string const & p) {
    int j, cnt;
    j = cnt = 0;
    int n = t.size(), m = p.size();
    for (int i = 0; i < n; i++) {
        while (j != 0 && p[j] != t[i]) j = pi[j];
        if (p[j] == t[i]) j++;
        else j = 0;
        if (j == m) {
            cnt++;
            j = pi[j];
        }
    }
    return cnt;
}