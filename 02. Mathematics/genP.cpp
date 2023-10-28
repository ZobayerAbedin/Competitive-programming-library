vector<bool> isP;
vector<int> prime;

void genP(int n){
	isP.resize(n+2,0);
	isP[1]=1;
	int sq=sqrt(n);
	for(int i=2;i<=n;i++){
		if(isP[i]==1) continue;
		prime.PB(i);
		for(ll j=i*1ll*i;j<=n;j+=i){
			isP[j]=1;
		}
	}
}