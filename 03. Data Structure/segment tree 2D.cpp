const int NTR = 0;
int n, m;
int tr[4 * N][4 * N];
int a[N][N];

int mrg(int x, int y) {
    return x + y;
}

void bldY(int i, int lx, int rx, int j, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) tr[i][j] = a[lx][ly];
        else tr[i][j] = mrg(tr[2 * i][j], tr[2 * i + 1][j]);
        return;
    }
    int mid = (ly + ry) / 2;
    bldY(i, lx, rx, 2 * j, ly, mid);
    bldY(i, lx, rx, 2 * j + 1, mid + 1, ry);
    tr[i][j] = mrg(tr[i][2 * j], tr[i][2 * j + 1]);

}

void bldX(int i, int lx, int rx) {
    if (lx != rx) {
        int mid = (lx + rx) / 2;
        bldX(2 * i, lx, mid);
        bldX(2 * i + 1, mid + 1, rx);
    }
    bldY(i, lx, rx, 1, 1, m);
}

void updY(int i, int lx, int rx, int j, int ly, int ry, int y, int vl) {
    if (ly == ry) {
        if (lx == rx) tr[i][j] = vl;
        else tr[i][j] = mrg(tr[2 * i][j], tr[2 * i + 1][j]);
        return;
    }
    int mid = (ly + ry) / 2;
    if (y <= mid) updY(i, lx, rx, 2 * j, ly, mid, y, vl);
    else updY(2 * i + 1, lx, rx, 2 * j + 1, mid + 1, ry, y, vl);
}

void updX(int i, int lx, int rx, int x, int y, int vl) {
    if (lx != rx) {
        int mid = (lx + rx) / 2;
        if (x <= mid) updX(2 * i, lx, mid, x, y, vl);
        else updX(2 * i + 1, mid + 1, rx, x, y, vl);
    }
    updY(i, lx, rx, 1, 1, m, y, vl);
}

int qryY(int i, int j, int ly, int ry, int y1, int y2) {
    if (ly > y2 || ry < y1) return NTR;
    if (ly >= y1 && ry <= y2) return tr[i][j];

    int mid = (ly + ry) / 2;
    return mrg(qryY(i, 2 * j, ly, mid, y1, y2), qryY(i, 2 * j + 1, mid + 1, ry, y1, y2));
}

int qryX(int i, int lx, int rx, int x1, int x2, int y1, int y2) {
    if (lx > x2 || rx < x1) return NTR;
    if (lx >= x1 && rx <= x2) return qryY(i, 1, 1, m, y1, y2);

    int mid = (lx + rx) / 2;
    return mrg(qryX(2 * i, lx, mid, x1, x2, y1, y2), qryX(2 * i + 1, mid + 1, rx, x1, x2, y1, y2));
}