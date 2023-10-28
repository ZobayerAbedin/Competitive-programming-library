using ll = long long;
const ll mod = 1e9 + 7;
const int N = 102;


struct Matrix{
    int row, col;
    ll m[N][N];
    Matrix() {memset(m,0,sizeof(m));}
    void Set(int r,int c) {row = r; col = c;}
    Matrix(int r,int c) {memset(m,0,sizeof(m)); Set(r,c);}
};

Matrix Multiply(Matrix A,Matrix B){
    Matrix ans(A.row,B.col);

    for(int i=0;i<A.row;i++){
        for(int j=0;j<B.col;j++){
            ans.m[i][j]=0;
            ll sm = 0;
            for(int k=0;k<A.col;k++){
                sm+=(A.m[i][k]*B.m[k][j]);
            }
            ans.m[i][j] = sm;
        }
    }
    return ans;
}

Matrix Power(Matrix mat,ll p){
    Matrix tmp(mat.row , mat.col);
    Matrix ans(mat.row , mat.col);

    int n = ans.row;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans.m[i][j]=0;
            tmp.m[i][j]=mat.m[i][j];
        }
        ans.m[i][i]=1;
    }

    while(p){
        if(p&1) ans=Multiply(ans,tmp);
        tmp=Multiply(tmp,tmp);
        p=p/2;
    }
    return ans;
}