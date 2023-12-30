#include<bits/stdc++.h>
#include<windows.h>
#include<graphics.h>
using namespace std;
int skipcomp,skipped,sum,maxms,casesum,kind[103],tim[103],skips[103],col[7]={0x9D3DCF,0xE74C3C,0x052242,0x52C41A,0x052242};
double wheel,bor[7]={0,0,12.5,0,12.5};
string gplusplus,option,font,checker,stauts[7]={"RE","WA","TLE","AC","UKE"},report[103];
void quick_quit(){
	while(is_run());
	skipped=1;
	closegraph();
}
void skip(){
	while(1)
		if(keystate(key_esc)){
			getch();
			skipped=1;
			system("taskkill /f /im std.exe");
			system("taskkill /f /im gen.exe");
			system("taskkill /f /im user.exe");
			system("taskkill /f /im checker.exe");
			return;
		}
}
void hc(){
	HWND h=GetForegroundWindow();
	ShowWindow(h,SW_HIDE);
}
void mkexe(string s){
	string command="\""+gplusplus+"\" -o "+s+".exe "+s+".cpp "+option;
	system(command.c_str());
}
void output(int casesum){
	if(skips[casesum]){
		setfont(50,0,font.c_str());
		setfillcolor(0x052242);
		bar(((casesum-1)%5+1)*25+((casesum-1)%5)*100,((casesum-1)/5+1)*25+((casesum-1)/5)*100+50+wheel,((casesum-1)%5+1)*25+((casesum-1)%5+1)*100,((casesum-1)/5+1)*25+((casesum-1)/5+1)*100+50+wheel);
		outtextxy(((casesum-1)%5+1)*25+((casesum-1)%5)*100+12.5,((casesum-1)/5+1)*25+((casesum-1)/5)*100+62.5+wheel,"TLE");
		setfont(25,0,font.c_str());
		xyprintf(((casesum-1)%5+1)*25+((casesum-1)%5)*100+7.5,((casesum-1)/5+1)*25+((casesum-1)/5)*100+112.5+wheel,"skipped");
	}
	else{
		setfont(50,0,font.c_str());
		setfillcolor(col[kind[casesum]]);
		bar(((casesum-1)%5+1)*25+((casesum-1)%5)*100,((casesum-1)/5+1)*25+((casesum-1)/5)*100+50+wheel,((casesum-1)%5+1)*25+((casesum-1)%5+1)*100,((casesum-1)/5+1)*25+((casesum-1)/5+1)*100+50+wheel);
		outtextxy(((casesum-1)%5+1)*25+((casesum-1)%5)*100+25-bor[kind[casesum]],((casesum-1)/5+1)*25+((casesum-1)/5)*100+62.5+wheel,stauts[kind[casesum]].c_str());
		setfont(25,0,font.c_str());
		double bd;
		if(tim[casesum])
			bd=(100-(log10(abs(tim[casesum]))+3)*12.5)/2;
		else
			bd=31.25;
		xyprintf(((casesum-1)%5+1)*25+((casesum-1)%5)*100+bd,((casesum-1)/5+1)*25+((casesum-1)/5)*100+112.5+wheel,"%dms",abs(tim[casesum]));
	}
	setfont(15,0,font.c_str());
	xyprintf(((casesum-1)%5+1)*25+((casesum-1)%5)*100,((casesum-1)/5+1)*25+((casesum-1)/5)*100+50+wheel,"#%d",casesum);
}
int ready,judging=1;
void initexe(){
	mkexe("std");
	ready=1;
	mkexe("user");
	ready=2;
	mkexe("gen");
	ready=3;
	mkexe("checker");
	ready=4;
}
void draw(){
	setcolor(0x000000);
	setfont(50,0,font.c_str());
	xyprintf(25,25,"Preparing for the judge...");
	setfont(25,0,font.c_str());
	xyprintf(25,75,"Loding standard code...");
	if(ready>=1){
		xyprintf(25,100,"Loding user's code...");
		if(ready>=2){
			xyprintf(25,125,"Loding generator...");
			if(ready>=3){
				xyprintf(25,150,"Loding checker...");
				if(ready==4){
					setcolor(0x00ff00);
					setfont(50,0,font.c_str());
					xyprintf(25,175,"Ready!");
				}
			}
		}
	}
}
void m_move(){
	mouse_msg m;
	while(judging){
		while(mousemsg())
			m=getmouse();
		if(m.is_wheel()){
			wheel+=m.wheel/5.0;
			wheel=min(wheel,0.0);
			m=mouse_msg();
		}
	}
}
void move_back(){
	int lw=wheel;
	while(casesum<sum){
		if(lw!=wheel){
			cleardevice();
			setcolor(0x34A5E5);
			setfont(50,0,font.c_str());
			xyprintf(25,12.5+wheel,"Judging...");
			setcolor(0xFFFFFF);
			for(int i=1;i<casesum;i++)
				output(i);
			lw=wheel;
		}
		api_sleep(1);
	}
}
void init(){
	ifstream setup("setup.inf");
	if(!setup){
		MessageBox(NULL,"没有配置文件","错误",MB_OK+16);
		exit(-1);
	}
	system("taskkill /f /im std.exe");
	system("taskkill /f /im gen.exe");
	system("taskkill /f /im user.exe");
	system("taskkill /f /im checker.exe");
	getline(setup,gplusplus);
	getline(setup,option);
	getline(setup,font);
	setup>>sum>>maxms;
	if(setup.eof())
		skipcomp=0;
	else{
		setup>>skipcomp;
		skipcomp=!skipcomp;
	}
	if(!skipcomp){
		thread genexe(initexe);
		genexe.detach();
	}
	initgraph(1,1,INIT_NOFORCEEXIT|INIT_RENDERMANUAL);
	setcaption("Local Judge 3.3.2");
	setcolor(0xFFFFFF);
	setbkcolor(0xffffff);
	setbkmode(TRANSPARENT);
	if(skipcomp){
		for(int i=1;i<=640;i++,delay_fps(400)){
			resizewindow(i,1);
			cleardevice();
		}
		for(int i=1;i<=480;i++,delay_fps(400)){
			resizewindow(640,i);
			cleardevice();
		}
	}
	else{
		for(int i=1;i<=640;i++,delay_fps(200)){
			resizewindow(i,1);
			cleardevice();
			draw();
		}
		for(int i=1;i<=480;i++,delay_fps(200)){
			resizewindow(640,i);
			cleardevice();
			draw();
		}
		while(delay_fps(30),ready!=4){
			cleardevice();
			draw();
		}
	}
	setcolor(0xFFFFFF);
	cleardevice();
}
int commander(string command,string backup,int time){
	string need="commander.exe \""+command+"\" \""+backup+"\" "+to_string(time);
	return system(need.c_str());
}
bool startjudge(int testcase){
	int st,en,rp;
	rp=commander("gen.exe > test.in","taskkill /f /im gen.exe",5000);
	if(rp==123321){
		kind[testcase]=4;
		report[testcase]="Generator time limit exceeded.";
		return true;
	}
	if(rp){
		kind[testcase]=4;
		report[testcase]="Generator runtime error.";
		return true;
	}
	rp=commander("std.exe < test.in > test.out","taskkill /f /im std.exe",5000);
	if(rp==123321){
		kind[testcase]=4;
		report[testcase]="Std time limit exceeded.";
		return true;
	}
	if(rp){
		kind[testcase]=4;
		report[testcase]="Std runtime error.";
		return true;
	}
	st=clock();
	rp=commander("user.exe < test.in > user.out","taskkill /f /im user.exe",maxms);
	en=clock();
	tim[testcase]=en-st;
	if(rp==123321){
		kind[testcase]=2;
		report[testcase]="Time limit exceeded.";
		return true;
	}
	if(rp){
		kind[testcase]=0;
		report[testcase]="Runtime error.";
		return true;
	}
	return false;
}
void judge(){
	double point=0;
	int aced=0,used=0;
	thread mouse_move(m_move);
	mouse_move.detach();
	thread move_b(move_back);
	move_b.detach();
	setcolor(0x34A5E5);
	setfont(50,0,font.c_str());
	xyprintf(25,12.5+wheel,"Judging...");
	setcolor(0xFFFFFF);
	for(casesum=1;casesum<=sum;casesum++){
		ofstream testcase("case.text");
		testcase<<casesum;
		testcase.close();
		if(!skipped){
			if(!startjudge(casesum)){
				int rp=commander("checker.exe","taskkill /f /im checker.exe",5000);
				if(rp==123321){
					kind[casesum]=4;
					report[casesum]="Checker time limit exceeded.";
					continue;
				}
				if(rp){
					kind[casesum]=4;
					report[casesum]="Checker runtime error.";
					continue;
				}
				ifstream rep("report");
				rep>>kind[casesum];
				getline(rep,report[casesum]);
				getline(rep,report[casesum]);
				if(kind[casesum]==0)
					kind[casesum]=1;
				else
					kind[casesum]=3;
			}
			string tmp;
			tmp="ren test.in test"+to_string(casesum)+".in";
			system(tmp.c_str());
			tmp="ren test.out test"+to_string(casesum)+".out";
			system(tmp.c_str());
			tmp="ren user.out user"+to_string(casesum)+".out";
			system(tmp.c_str());
		}
		skips[casesum]=skipped;
		if(skips[casesum])
			report[casesum]="Skipped.";
		else{
			used++;
			if(kind[casesum]==3)
				aced++;
		}
		output(casesum);
		if(!skipped)
			Sleep(50);
	}
	point=(double)aced/used*100;
	for(double pts=1;pts<=point&&skipped==0;delay_fps(20),pts+=1){
		cleardevice();
		setcolor(((int)((0x52-0xE7)*pts/100)<<16)+((int)((0xC4-0x4C)*pts/100)<<8)+(int)((0x1A-0x3C)*pts/100)+0xE74C3C);
		setfont(50,0,font.c_str());
		xyprintf(25,12.5+wheel,"total : %d points",(int)(pts+0.5));
		setcolor(0xFFFFFF);
		for(int casesum=1;casesum<=sum;casesum++)
			output(casesum);
	}
	judging=0;
	cleardevice();
	setcolor(((int)((0x52-0xE7)*point/100)<<16)+((int)((0xC4-0x4C)*point/100)<<8)+(int)((0x1A-0x3C)*point/100)+0xE74C3C);
	setfont(50,0,font.c_str());
	xyprintf(25,12.5+wheel,"total : %d points",(int)(point+0.5));
	setcolor(0xFFFFFF);
	for(int casesum=1;casesum<=sum;casesum++)
		output(casesum);
	system("del report");
	system("del case.text");
	if(!skipcomp){
		system("del checker.exe");
		system("del gen.exe");
		system("del std.exe");
		system("del user.exe");
	}
	mouse_msg m;
	int selecting;
	string ss;
	for(;is_run();delay_fps(60)){
		cleardevice();
		selecting=-1;
		while(mousemsg())
			m=getmouse();
		for(int i=1;i<=sum;i++)
			if(m.x>=((i-1)%5+1)*25+((i-1)%5)*100&&m.x<=((i-1)%5+1)*25+((i-1)%5+1)*100&&m.y>=((i-1)/5+1)*25+((i-1)/5)*100+50+wheel&&m.y<=((i-1)/5+1)*25+((i-1)/5+1)*100+50+wheel)
				selecting=i;
		if(m.is_left()&&m.is_down())
			if(selecting!=-1&&skips[selecting]==0){
				ss="start test"+to_string(selecting)+".in";
				system(ss.c_str());
				ss="start test"+to_string(selecting)+".out";
				system(ss.c_str());
				ss="start user"+to_string(selecting)+".out";
				system(ss.c_str());
			}
		if(m.is_wheel()){
			wheel+=m.wheel/5.0;
			wheel=min(wheel,0.0);
			m=mouse_msg();
		}
		setcolor(((int)((0x52-0xE7)*point/100)<<16)+((int)((0xC4-0x4C)*point/100)<<8)+(int)((0x1A-0x3C)*point/100)+0xE74C3C);
		setfont(50,0,font.c_str());
		xyprintf(25,12.5+wheel,"total : %d points",(int)(point+0.5));
		setcolor(0xFFFFFF);
		for(int i=1;i<=sum;i++)
			output(i);
		if(selecting!=-1)
			if(report[selecting].size()){
				double x=report[selecting].size()/2.0;
				setfillcolor(0x000000);
				bar(((selecting-1)%5+3)*25+((selecting-1)%5)*100-(x+1)*12.5,((selecting-1)/5+1)*25+((selecting-1)/5)*100+25+wheel,((selecting-1)%5+3)*25+((selecting-1)%5)*100+(report[selecting].size()-x+1)*12.5,((selecting-1)/5+1)*25+((selecting-1)/5)*100+50+wheel);
				setcolor(0xFFFFFF);
				setfont(25,0,font.c_str());
				outtextxy(((selecting-1)%5+3)*25+((selecting-1)%5)*100-x*12.25,((selecting-1)/5+1)*25+((selecting-1)/5)*100+25+wheel,report[selecting].c_str());
			}
	}
	closegraph();
	for(int i=1;i<=sum;i++){
		ss="del test"+to_string(i)+".in";
		system(ss.c_str());
		ss="del test"+to_string(i)+".out";
		system(ss.c_str());
		ss="del user"+to_string(i)+".out";
		system(ss.c_str());
	}
}
int main(){
	thread quick(quick_quit);
	quick.detach();
	hc();
	init();
	thread skipping(skip);
	skipping.detach();
	judge();
	return 0;
}
