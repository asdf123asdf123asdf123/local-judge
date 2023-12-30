#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	int x=!system("fc user.out test.out");
	freopen("report","w",stdout);
	cout<<x<<endl;
	if(x)
		cout<<"ถิมห";
	else
		cout<<"aa";
	return 0;
}
