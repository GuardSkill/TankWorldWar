#include "tank.h"
void main()
{
	initgraph(640, 480);
	srand((unsigned)time(NULL));
	startimage();                      //加载开始画面
	CMD cmd;
	int a[12][16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,3,3,3,0,0,0,0,3,3,3,0,0,0,
		0,0,0,3,3,3,0,0,0,0,3,3,3,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		3,3,3,3,3,0,3,3,3,0,0,0,0,0,3,3,
		0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,
		0,0,0,0,3,0,0,3,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,
		0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,
		0,0,0,0,0,0,3,2,3,0,0,0,0,0,0,0,
	};
	PLAY p1,p2;
	ENE E1,E2,E3,E4;
	E1.x=0;
	E1.y=0;
	E1.live=1;
	E1.life=3;
	a[E1.y][E1.x]=1;
	E2.x=7;
	E2.y=0;
	E2.live=1;
	E2.life=3;
	a[E2.y][E2.x]=1;
	E3.x=8;
	E3.y=0;
	E3.live=1;
    E3.life=3;
	a[E3.y][E3.x]=1;
	E4.x=15;
	E4.y=0;
	E4.live=1;
    E4.life=3;
	a[E4.y][E4.x]=1;
	p1.live=0;
	p2.live=-1;  //初始化玩家状态
	p1.life=3; 
	p2.life=3; //初始化玩家生命
	p1.c='l';
	p2.c='l';
	//初始坦克坐标
	int i,j,key1=UP,key2=UP;
	int s=0;             //人数判断旗帜
	IMAGE direction[4][2];
	IMAGE direction0[4][2];
	IMAGE bullet[4][2];
	IMAGE grass,over;
	IMAGE tank_rc,enemy_rc,bullect_rc;
	IMAGE box,box0;
	IMAGE home,home0;
	IMAGE huang;
	Loadingothers(&huang,bullet,&bullect_rc);
	Loadimage0(&E1,&E2,&E3,&E4,direction0,&enemy_rc);
	Loadimage(&p1,&p2,&grass,direction,&tank_rc,&home,&home0,&box,&box0);
	s=judgeplayer();    //判断有几个人
	if(s==2) 			p2.live=0;
	else {
		p2.c='d';
		p2.life=-1;
	}
	while(s==1||s==2){
		createenemy(&E1,&E2,&E3,&E4,a);
		createtank(&p1,&p2,a);
		enemymove(&E1,&E2,&E3,&E4,a,direction0);	                        
		for(i=0;i<16;i++)
		{
			for(j=0;j<2;j++)
			{
				putimage(i*40,j*40,&huang);
			}
			for(j=2;j<12;j++)
				putimage(i*40, j*40,&grass);  //设置画布 
		}
		GetCommand(&cmd);
		if(cmd.key1!=NULL) key1=cmd.key1;
		if(cmd.key2!=NULL) key2=cmd.key2;
		tankmove(&cmd,&p1,&p2,direction,a);
		skillact(&cmd,&p1,&p2,a,key1,key2);
		bulletact(a);
		ifdeath(&p1,&p2,&E1,&E2,&E3,&E4,a);
		drawmap(a,&home,&home0,&box,&box0,bullet);
		drawplayer(&p1,&p2);
		drawenemy(&E1,&E2,&E3,&E4);
		gameover (&p1,&p2,a,&over);
		BeginBatchDraw();
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));         //清除输入信息
		_sleep(400);
		FlushBatchDraw();
	}
	closegraph();
}

//读取图片