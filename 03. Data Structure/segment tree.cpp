const int NTR = 0;
int tr[4 * N], op[4 * N];

int mrg(int x, int y) {
    return x + y;
}

void prpg(int i, int l, int r) {
    if (l == r || op[i] == NTR) return;
    int iL = 2 * i, iR = 2 * i + 1;
    op[iL] = op[iR] = op[i];
    tr[iL] = tr[iR] = op[i];
    op[i] = NTR;
}

void bld(int i, int l, int r) {
    if (l == r) {
        tr[i] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    bld(2 * i, l, mid);
    bld(2 * i + 1, mid + 1, r);
    tr[i] = mrg(tr[2 * i], tr[2 * i + 1]);
}
//point upd-->
void upd(int i, int l, int r, int id, int vl) {
    prpg(i, l, r);
    if (l > id || r < id) return;
    if (l == r) {
        tr[i] = vl;
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * i, l, mid, id, vl);
    upd(2 * i + 1, mid + 1, r, id, vl);
    tr[i] = mrg(tr[2 * i], tr[2 * i + 1]);
}

void updR(int i, int l, int r, int lx, int rx, int vl) {
    prpg(i, l, r);
    if (l > rx || r < lx) return;
    if (l >= lx && r <= rx) {
        op[i] = tr[i] = vl;
        return;
    }
    int mid = (l + r) / 2;
    updR(2 * i, l, mid, lx, rx, vl);
    updR(2 * i + 1, mid + 1, r, lx, rx, vl);
    tr[i] = mrg(tr[2 * i], tr[2 * i + 1]);
}

int qry(int i, int l, int r, int lx, int rx) {
    prpg(i, l, r);
    if (l > rx || r < lx) return NTR;
    if (l >= lx && r <= rx) return tr[i];
    int mid = (l + r) / 2;
    int vl1 = qry(2 * i, l, mid, lx, rx);
    int vl2 = qry(2 * i + 1, mid + 1, r, lx, rx);
    return mrg(vl1, vl2);
}