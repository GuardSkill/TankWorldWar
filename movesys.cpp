#include "tank.h"
void GetCommand(CMD *cmd)
{
	cmd->key1=NULL;
	cmd->key2=NULL;
	if(GetAsyncKeyState(VK_ESCAPE) & 0x8000) {exit(0);}
	if(GetAsyncKeyState(65) & 0x8000) cmd->key1=LEFT;
	if(GetAsyncKeyState(87) & 0x8000) cmd->key1=UP;
	if(GetAsyncKeyState(83) & 0x8000) cmd->key1=DOWN;
	if(GetAsyncKeyState(68) & 0x8000) cmd->key1=RIGHT;
	if(GetAsyncKeyState(74) & 0x8000) cmd->skill1=20;
	if(GetAsyncKeyState(75) & 0x8000) cmd->skill2=20;
	if(GetAsyncKeyState(76) & 0x8000) cmd->skill3=20;
	if(GetAsyncKeyState(VK_LEFT) & 0x8000) cmd->key2=LEFT2;
	if(GetAsyncKeyState(VK_UP) & 0x8000) cmd->key2=UP2;
	if(GetAsyncKeyState(VK_DOWN) & 0x8000) cmd->key2=DOWN2;
	if(GetAsyncKeyState(VK_RIGHT) & 0x8000) cmd->key2=RIGHT2;
	if(GetAsyncKeyState('1') & 0x8000) cmd->skill4=20;
	if(GetAsyncKeyState('2') & 0x8000) cmd->skill5=20;
	if(GetAsyncKeyState('3') & 0x8000) cmd->skill6=20;                    //技能处于开启，变量20
	if(GetAsyncKeyState(80) & 0x8000) 
	{
		outtextxy(0,0,"Pause...");
		system("pause");
	}
}
void tankmove(CMD *cmd,PLAY *p1,PLAY *p2,IMAGE direction[][2],int a[][16])
{
	switch(cmd->key1)
	{
	case UP:
		p1->y-=1;
		if(p1->y<0||a[p1->y][p1->x]!=0) p1->y+=1;
		else
		{
			a[p1->y+1][p1->x]=0;
			a[p1->y][p1->x]=1;
		}
		p1->tank=&direction[0][1];
		p1->tank0=&direction[0][0];
		break;
	case LEFT:
		p1->x-=1;
		if(p1->x<0||a[p1->y][p1->x]!=0) p1->x+=1;
		else
		{
			a[p1->y][p1->x+1]=0;
			a[p1->y][p1->x]=1;
		}
		p1->tank=&direction[1][1];
		p1->tank0=&direction[1][0];
		break;
	case DOWN:
		p1->y+=1;
		if(p1->y>=12||a[p1->y][p1->x]!=0) p1->y-=1;
		else
		{
			a[p1->y-1][p1->x]=0;
			a[p1->y][p1->x]=1;
		}
		p1->tank=&direction[2][1];
		p1->tank0=&direction[2][0];
		break;
	case RIGHT:
		p1->x+=1;
		if(p1->x>=16||a[p1->y][p1->x]!=0) p1->x-=1;
		else
		{
			a[p1->y][p1->x-1]=0;
			a[p1->y][p1->x]=1;
		}
		p1->tank=&direction[3][1];
		p1->tank0=&direction[3][0];
		break;
	}
	if(p2->c!='d')
	{
		switch(cmd->key2)
		{
		case UP:
		p2->y-=1;
		if(p2->y<0||a[p2->y][p2->x]!=0) p2->y+=1;
		else
		{
			a[p2->y+1][p2->x]=0;
			a[p2->y][p2->x]=1;
		}
		p2->tank=&direction[0][1];
		p2->tank0=&direction[0][0];
		break;
	    case LEFT:
		p2->x-=1;
		if(p2->x<0||a[p2->y][p2->x]!=0) p2->x+=1;
		else
		{
			a[p2->y][p2->x+1]=0;
			a[p2->y][p2->x]=1;
		}
		p2->tank=&direction[1][1];
		p2->tank0=&direction[1][0];
		break;
	    case DOWN:
		p2->y+=1;
		if(p2->y>=12||a[p2->y][p2->x]!=0) p2->y-=1;
		else
		{
			a[p2->y-1][p2->x]=0;
			a[p2->y][p2->x]=1;
		}
		p2->tank=&direction[2][1];
		p2->tank0=&direction[2][0];
		break;
	    case RIGHT:
		p2->x+=1;
		if(p2->x>=16||a[p2->y][p2->x]!=0) p2->x-=1;
		else
		{
			a[p2->y][p2->x-1]=0;
			a[p2->y][p2->x]=1;
		}
		p2->tank=&direction[3][1];
		p2->tank0=&direction[3][0];
		break;
		}
	}
}
	
