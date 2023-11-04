#include<bits/stdc++.h>
#include<windows.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=r;i>=l;i--)
using namespace std;

bool win11=1;//请输入是否为 win11
string goexe="-std=c++14 -O2 -Wall -Wl,-stack=1000000000";//请输入编译选项
int sum=10/*测试点数量*/,maxms=1000/*时间上限*/;
bool mk=0;//是否将数据保存至不同文件中
bool rt1=0,rt2=0,rt3=0,rt4=0,rt5=0;//是否在 RE,WA,TLE,AC,UKE 时直接结束 

/*
以上为参数
-----------------------------
以下为变量
*/

string checker/*判断评测状态*/,a;
double point=0/*分数*/;
int casesum=0/*测试点编号*/,ms/*运行时间*/;
int kind[1000000],tim[1000000]/*测试点状态*/;

inline void mkexe(string s)//run exe
{
	a=s+" "+goexe;
	system(a.c_str());
}

inline void ptpoint(double x,double y)//print point
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
	
	int ans=x;
	if(x+0.5>=ans+1)ans++;
	
	if(x<y*0.3)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	else if(x<y*0.6)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a);
	
	cout<<left<<setw(2);
	cout<<ans<<right;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
}

inline void init()//init judge
{
	system("title Local Judge 1.7.3");
	//change name
	
	if(!win11)system("mode con cols=40 lines=25");
	//change size (win11 无法正常进行)
	
	system("taskkill /f /im std.exe");
	system("taskkill /f /im rand.exe");
	system("taskkill /f /im user.exe");
	system("taskkill /f /im fc_judge.exe");
	system("cls");
	//ready judge
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	cout<<"Local Judge 1.7.3"<<endl;
	Sleep(500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0d);
	cout<<"preparing for the judge..."<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
	
	mkexe("g++ -o std std.cpp");
	mkexe("g++ -o user user.cpp");
	mkexe("g++ -o rand rand.cpp");
	mkexe("g++ -o fc_judge fc_judge.cpp");
	//mk exe
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
	
	ofstream rdti;
	rdti.open("time.text");
	rdti<<maxms;
	rdti.close();
	//ready time

	ofstream rdmk;
	rdmk.open("make.text");
	rdmk<<mk;
	rdmk.close();
	//ready time
	
	system("cls");
}

inline void judge()//judge
{
	cout<<"----------------------------------------";
	if(win11)cout<<endl;
	cout<<"Subtask 1:"<<endl;
	
	rep(casesum,1,sum)
	{
		cout<<"# "<<setw(ceil(log10(sum))+1)<<casesum<<" | ";
		
		ofstream rdcs;
		rdcs.open("case.text");
		rdcs<<casesum;
		rdcs.close();
		//ready case
		
		ms=system("fc_judge.exe");
		//get judge
		
		double cspoint=0;
		if(ms==50000000)kind[casesum]=0;//RE
		else if(ms==998244353)kind[casesum]=4;//UKE
		else if(ms==-50000000)kind[casesum]=1,tim[casesum]=0;//WA but 0ms
		else if(abs(ms)>=maxms)kind[casesum]=2,tim[casesum]=ms;//TLE
		else if(ms<0)kind[casesum]=1,tim[casesum]=-1*ms;//WA
		else kind[casesum]=3,tim[casesum]=ms,cspoint=100.0/sum;//AC
		point+=cspoint;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
		cout<<setw(4);
		if(kind[casesum]==0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0d);
			cout<<"RE";
			if(rt1)return;
		}
		if(kind[casesum]==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
			cout<<"WA";
			if(rt2)return;
		}
		if(kind[casesum]==2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
			cout<<"TLE";
			if(rt3)return;
		}
		if(kind[casesum]==3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a);
			cout<<"AC";
			if(rt4)return;
		}
		if(kind[casesum]==4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
			cout<<"UKE";
			if(rt5)return;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY );
		//print type

		cout<<" | ";
		cout<<setw(ceil(log10(maxms))+2)<<left;
		if(tim[casesum]>=0)cout<<tim[casesum]<<"ms";
		else cout<<-1*tim[casesum]<<"ms";
		//print ms
		
		cout<<right;
		cout<<" | ";
		ptpoint(cspoint,100.0/sum),cout<<" points"<<endl;
		//print point
		
		Sleep(50);
	}
	
	cout<<"Subtask 1 : ",ptpoint(point,100),cout<<" points"<<endl;
	cout<<"----------------------------------------";
	if(win11)cout<<endl;
	cout<<"total : ",ptpoint(point,100),cout<<" points"<<endl;
	//print point
}

int main()
{
	init(),judge();
	return 0;
}
