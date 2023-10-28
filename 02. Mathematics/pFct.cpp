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

vector<int> pFct(int n){
	vector<int> res;
	int sq=sqrt(n);
	for(int i=0;prime[i]<=sq;i++){
		if(n%prime[i]==0){
			res.PB(prime[i]);
			while(n%prime[i]==0){
				n/=prime[i];
			}
			sq=sqrt(n);
		}
	}
	if(n!=1) res.PB(n);
	return res;
}