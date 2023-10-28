const int sq = 320;

struct qr {
    int l, r, id;
    bool operator < (const qr x) {
        int a = l / sq, b = x.l / sq;
        return a == b ? (a & 1 ? (r > x.r) : (r < x.r)) : a < b;
    }
};

int fq[N], res[N], a[N];
int cur, n, m;
qr q[N];

void add(int i) {
    fq[a[i]]++;
}

void rmv(int i) {
    fq[a[i]]--;
}

//in the  main section --->
sort(q, q + m);
int l = q[0].l, r = q[0].l - 1;
cur = 0;
for (int i = 0; i < m; i++) {
    while (l > q[i].l) add(--l);
    while (r < q[i].r) add(++r);
    while (l < q[i].l) rmv(l++);
    while (r > q[i].r) rmv(r--);
    res[q[i].id] = cur;
}