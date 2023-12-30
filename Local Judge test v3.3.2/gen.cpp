#include<bits/stdc++.h>
#define int unsigned long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
mt19937 rnd,dnr;
inline int mkrd(int x){return ((x<<3)^(x>>7))&(dnr()|(x>>9))&(rnd()|(x>>4));}
inline int random(int x,int y){return mkrd(mkrd(rnd())*mkrd(dnr()))*rnd()*dnr()%(y-x+1)+x;}
signed main()
{
	freopen("case.text","r",stdin);
	int cs;
	cin>>cs;
	rnd.seed(cs*cs*123456789+time(0)),dnr.seed(rnd());
	int n;
	if(cs<=3)n=random(1,1e4);
	else if(cs<=10)n=random(1e5,1e7);
	else n=random(1e10,1e18);
	cout<<n;
    return 0;
}
