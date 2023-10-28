int node[N][2], it = 0, cnt[N];

cin >> ch >> x;
if (ch == '+') {
    int nw = 0;
    for (int i = 30; i >= 0; i--) {
        if (node[nw][(x >> i) & 1] == 0) {
            node[nw][(x >> i) & 1] = ++it;
        }
        nw = node[nw][(x >> i) & 1];
        cnt[nw]++;

    }
} 
else if (ch == '-') {
    int nw = 0;
    for (int i = 30; i >= 0; i--) {
        nw = node[nw][(x >> i) & 1];
        cnt[nw]--;
    }
} s
else {
    int res = 0, nw = 0;
    for (int i = 30; i >= 0; i--) {
        int tmp = node[nw][((x >> i) & 1) ^ 1];
        if (cnt[tmp] > 0) res += (1 << i);
        else {
            tmp = node[nw][!(((x >> i) & 1) ^ 1)];
        }
        nw = tmp;

        cout << max(res, x) << endl;
}