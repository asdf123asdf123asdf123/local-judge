#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
int n,p=998244353;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n,n%=p,cout<<n*(n+1)/2%p;
	return 0;
}
