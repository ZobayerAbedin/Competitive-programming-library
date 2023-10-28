// 1D BIT
int bit[N];

void upd(int i, int vl) {
    for (; i < N; i += i & (-i)) {
        bit[i] += vl;
    }
}

int pfx(int i) {
    int tot = 0;
    for (; i > 0; i -= i & (-i)) {
        tot += bit[i];
    }
    return tot;
}

// 2D BIT

int bit[N][N];

void upd(int i, int j, int vl) {
    for (; i < N; i += i & (-i)) {
        for (; j < N; j += j & (-j)) {
            bit[i][j] += vl;
        }
    }
}

int pfx(int i, int j) {
    int tot = 0;
    for (; i > 0; i -= i & (-i)) {
        for (; j > 0; j -= j & (-j)) {
            tot += bit[i][j];
        }
    }
    return tot;
}