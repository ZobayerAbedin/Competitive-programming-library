
const ll mod=1e9+7;

ll bM(ll n,ll p){
	if(p==0) return 1ll;
	if(p%2==0){
		ll ret=bM(n,p/2);
		return (ret*ret)%mod;
	}
	return (n*bM(n,p-1))%mod;;
}