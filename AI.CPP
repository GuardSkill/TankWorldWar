#include "tank.h"
void enemymove0(ENE *E,int a[][16],IMAGE direction0[][2])
{
	int n = rand() % 4;
	int m= rand()%4;
	switch(n)
	{
    case 0: 
		E->y-=1;
		if(E->y<0||a[E->y][E->x]!=0) E->y+=1;
		else {
			a[E->y+1][E->x]=0;
			a[E->y][E->x]=1;
		}
		if(m==0&&E->y!=0)
		{
			if(a[E->y-1][E->x]!=0) 	a[E->y+1][E->x]=0;
			if(a[E->y-1][E->x]==0)  a[E->y+1][E->x]=4;
		}
		E->tank=&direction0[0][1];
		E->tank0=&direction0[0][0];
		break;//表示向上
    case 1: 
		E->y+=1;
		if(E->y>=12||a[E->y][E->x]!=0) E->y-=1;
		else {
			a[E->y-1][E->x]=0;
			a[E->y][E->x]=1;
		}
		if(m==0&&E->y!=11)
		{
			if(a[E->y+1][E->x]!=0) 	a[E->y+1][E->x]=0;
			if(a[E->y+1][E->x]==0)  a[E->y+1][E->x]=6;
		}
		E->tank=&direction0[2][1];
		E->tank0=&direction0[2][0];
		break; //表示向下
    case 2: 
		E->x-=1;
		if(E->x<0||a[E->y][E->x]!=0) E->x+=1;
		else {
			a[E->y][E->x+1]=0;
			a[E->y][E->x]=1;
		}
		if(m==0&&E->x!=0)
		{
			if(a[E->y][E->x-1]!=0) 	a[E->y+1][E->x-1]=0;
			if(a[E->y][E->x-1]==0)  a[E->y+1][E->x-1]=5;
		}
		E->tank=&direction0[1][1];
		E->tank0=&direction0[1][0];
		break;//表示向左
    case 3: 
		E->x+=1;
		if(E->x>=16||a[E->y][E->x]!=0) E->x-=1;
		else {
			a[E->y][E->x-1]=0;
			a[E->y][E->x]=1;
		}
		if(m==0&&E->x!=15)
		{
			if(a[E->y][E->x+1]!=0) 	a[E->y+1][E->x+1]=0;
			if(a[E->y][E->x+1]==0)  a[E->y+1][E->x+1]=7;
		}
		E->tank=&direction0[3][1];
		E->tank0=&direction0[3][0];
		break;//表示向右
	}
}
void enemymove(ENE *E1,ENE *E2,ENE *E3,ENE *E4,int a[][16],IMAGE direction0[][2]){
	enemymove0(E1,a,direction0);
	enemymove0(E2,a,direction0);
	enemymove0(E3,a,direction0);
	enemymove0(E4,a,direction0);
}