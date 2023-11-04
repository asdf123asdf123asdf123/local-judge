#include<bits/stdc++.h>
#include<windows.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
bool pd=0;/*双线程*/
bool re=0/*判断有没有RE*/;
int t1,t2,t3;/*运行时间*/
int ti,cs,mk;
inline void Function1()//user
{
	if(!mk)re=system("user.exe <test.in> user.out");
	else
	{
		string s="user.exe <test"+to_string(cs)+".in> user"+to_string(cs)+".out";
		re=system(s.c_str());
	}
	pd=1;
}
inline void Function2()//rand
{
	if(!mk)system("rand.exe > test.in");
	else
	{
		string s="rand.exe > test"+to_string(cs)+".in";
		re=system(s.c_str());
	}
	pd=1;
}
inline void Function3()//std
{
	if(!mk)system("std.exe <test.in> test.out");
	else
	{
		string s="std.exe <test"+to_string(cs)+".in> test"+to_string(cs)+".out";
		re=system(s.c_str());
	}
	pd=1;
}
inline int judge()
{
	ifstream rdti;
	rdti.open("time.text");
	rdti>>ti;
	rdti.close();
	//ready time
	
	ifstream rdcs;
	rdcs.open("case.text");
	rdcs>>cs;
	rdcs.close();
	//ready case
	
	ifstream rdmk;
	rdmk.open("make.text");
	rdmk>>mk;
	rdmk.close();
	//ready make
	
	t3=clock();
	{
		pd=0;
		thread Thread(Function2);
		Thread.detach();
		while(!pd)if(clock()-t3>5000)
		{
			system("taskkill /f /im rand.exe");
			return 998244353;
		}
	}
	//make
	
	t3=clock();
	{
		pd=0;
		thread Thread(Function3);
		Thread.detach();
		while(!pd)if(clock()-t3>5000)
		{
			system("taskkill /f /im std.exe");
			return 998244353;
		}
	}
	//std
	
	t1=clock();
	{
		pd=0;
		thread Thread(Function1);
		Thread.detach();
		while(!pd)if(clock()-t1>ti+200)
		{
			system("taskkill /f /im user.exe");
			return clock()-t1;
		}
	}
	t2=clock();
	//user
	
	if(re)return 50000000;
	string s="fc user.out test.out";
	if(mk)s="fc user"+to_string(cs)+".out test"+to_string(cs)+".out";
	if(system(s.c_str()))return (-1ll*(t2-t1)==0?-50000000:-1ll*(t2-t1));
	else return 1ll*(t2-t1);
	//exit the value
}
int main()
{
	freopen("rub.out","w",stdout);
	return judge();
}
