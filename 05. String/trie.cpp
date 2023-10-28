int node[N][10],isW[N],vis[N];


int n,it=0;
cin>>n;
memset(node,0,sizeof(node));
memset(isW,0,sizeof(isW));
memset(vis,0,sizeof(vis));
bool ok=1;
for(int i=0;i<n;i++){
	ll x;
	cin>>x;
	string s=to_string(x);
	vector<int> a;
	for(int j=0;j<s.size();j++){
		a.PB(s[j]-'0');
	}
	int nw=0
	for(int j=0;j<a.size();j++){
		if(node[nw][a[j]]==0){
			node[nw][a[j]]=++it;
		}
		nw=node[nw][a[j]];
		if(j==a.size()-1) isW[nw]++;
		else vis[nw]=1;
		if(vis[nw] && isW[nw]) ok=0;
		if(isW[nw]>=2) ok=0;
	}
}