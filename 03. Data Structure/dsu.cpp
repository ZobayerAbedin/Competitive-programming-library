int id[N];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        id[i] = i;
    }
}
int rt(int x) {
    while (id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
bool un(int x, int y) {
    x = rt(x), y = rt(y);
    if (x == y) return 0;
    id[y] = x;
    return 1;
}