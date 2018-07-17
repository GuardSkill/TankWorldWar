#include "tank.h"
void Loadingothers(IMAGE *huang,IMAGE bullet[][2],IMAGE *bullet_rc){
	int i;
	loadimage(huang, "res\\huang.jpg");
	loadimage(bullet_rc,"res\\tank\\bullet.jpg");
	SetWorkingImage(bullet_rc);
	for(i=0;i<4;i++)
	{
		getimage(&bullet[i][1],40*i,0,40,40);		//存每个面向的图片
		getimage(&bullet[i][0],40*i,40,40,40);          //掩码图  
	}
	SetWorkingImage(NULL);
}
void startimage(){
	IMAGE logo,login;
	mciSendString("open res\\RPG.wav alias BackMusic", NULL, 0, NULL); // 打开音乐
	mciSendString("setaudio BackMusic volume to 300",NULL,0,NULL);		//设置音量大小
	mciSendString("play BackMusic", NULL, 0, NULL);
	loadimage(&logo, "res\\logo.jpg");
	putimage(0,0,&logo);
	_sleep(3000);
	mciSendString("stop BackMusic", NULL, 0, NULL);
	mciSendString("close BackMusic", NULL, 0, NULL);
	loadimage(&login, "res\\login.jpg");
	putimage(0,0,&login);	
}
void Loadimage0(ENE *E1,ENE *E2,ENE *E3,ENE *E4,IMAGE direction0[][2],IMAGE *enemy_rc)
{
	int i;
	loadimage(enemy_rc,"res\\tank\\enemy.jpg");
	SetWorkingImage(enemy_rc);
	for(i=0;i<4;i++)
	{
		getimage(&direction0[i][1],40*i,0,40,40);		//存每个面向的图片
		getimage(&direction0[i][0],40*i,40,40,40);          //掩码图  
	}
	SetWorkingImage(NULL);
	E1->tank=&direction0[3][1];
	E1->tank0=&direction0[3][0];
	E2->tank=&direction0[3][1];
	E2->tank0=&direction0[3][0];
	E3->tank=&direction0[3][1];
    E3->tank0=&direction0[3][0];
	E4->tank=&direction0[3][1];
	E4->tank0=&direction0[3][0];         //初始化坦克方向//初始化坦克方向

}
void Loadimage(PLAY *p1,PLAY *p2,IMAGE *grass,IMAGE direction[][2],IMAGE *tank_rc,IMAGE *home,IMAGE *home0,IMAGE *box,IMAGE *box0)
{
	int i;
	loadimage(home, "res\\home.jpg");
	loadimage(home0, "res\\home0.jpg");
	loadimage(box, "res\\box.jpg");
	loadimage(box0, "res\\box0.jpg");
	loadimage(grass, "res\\littlegrass.jpg");
	loadimage(tank_rc,"res\\tank\\tank.jpg");			//获取图片
	SetWorkingImage(tank_rc);
	for(i=0;i<4;i++)
	{
		getimage(&direction[i][1],40*i,0,40,40);		//存每个面向的图片
		getimage(&direction[i][0],40*i,40,40,40);          //掩码图  
	}
	SetWorkingImage(NULL);
	p1->tank=&direction[0][1];
	p1->tank0=&direction[0][0];
	p2->tank=&direction[0][1];
	p2->tank0=&direction[0][0];         //初始化坦克方向
}
void drawmap(int a[][16],IMAGE *home,IMAGE *home0,IMAGE *box,IMAGE *box0,IMAGE bullet[][2]){
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<12;j++)
			if(a[j][i]==3) 
			{	
				putimage(i*40,j*40,box0,SRCAND);                   //输出图片
		        putimage(i*40,j*40,box,SRCINVERT);
			}
			else if(a[j][i]==2)
			{
				putimage(i*40,j*40,home0,SRCAND);    
				putimage(i*40,j*40,home,SRCINVERT);//输出图片
			}
			else if(a[j][i]==4)
			{
				putimage(i*40,j*40,&bullet[0][0],SRCAND);                   //输出图片
		        putimage(i*40,j*40,&bullet[0][1],SRCINVERT);
			}
			else if(5==a[j][i])
			{
				putimage(i*40,j*40,&bullet[1][0],SRCAND);                   //输出图片
		        putimage(i*40,j*40,&bullet[1][1],SRCINVERT);
			}
			else if(6==a[j][i])
			{
				putimage(i*40,j*40,&bullet[2][0],SRCAND);                   //输出图片
		        putimage(i*40,j*40,&bullet[2][1],SRCINVERT);
			}
			else if(7==a[j][i])
			{
				putimage(i*40,j*40,&bullet[3][0],SRCAND);                   //输出图片
		        putimage(i*40,j*40,&bullet[3][1],SRCINVERT);
			}
	}

}


void drawplayer(PLAY *p1,PLAY *p2)
{
	if(p1->c=='l')
	{
	if(p1->life>=0)
	{
		putimage(p1->x*40, p1->y*40,p1->tank0,SRCAND);                   //输出图片
		putimage(p1->x*40,p1->y*40,p1->tank,SRCINVERT);
	}
	}
	if(p2->c=='l')
		{
	if(p2->live>=0)
	{
		putimage(p2->x*40, p2->y*40,p2->tank0,SRCAND);                   //输出图片
		putimage(p2->x*40,p2->y*40,p2->tank,SRCINVERT);
	}
	}
	
}
void drawenemy0(ENE *E)
{
	if(E->life>=0&&E->live==1)
	{
		putimage(E->x*40, E->y*40,E->tank0,SRCAND);                   //输出图片
		putimage(E->x*40,E->y*40,E->tank,SRCINVERT);
	}
}
void drawenemy(ENE *E1,ENE *E2,ENE *E3,ENE *E4)
{
	drawenemy0(E1);
	drawenemy0(E2);
	drawenemy0(E3);
	drawenemy0(E4);
}
