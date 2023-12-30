#include<bits/stdc++.h>
using namespace std;
string s,ss;
double x;
int r=-1,t;
void runcommand(string command){
	r=system(command.c_str());
}
int main(int cnt,char **str){
	if(cnt<=3){
		cout<<"没有指定参数。";
		return 0;
	}
	s=str[1];
	ss=str[2];
	x=atoi(str[3]);
	t=clock();
	thread thr(runcommand,s);
	thr.detach();
	while(r==-1)
		if(clock()-t>x*1.2){
			runcommand(ss);
			return 123321;
		}
	return r;
}
