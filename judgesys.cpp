#include "tank.h"
int judgeplayer()
{
	char c;
	while(1)
	{
		c=getch();
		if(c=='1') 
		{
			return 1;
		}
		else if(c=='2') 
		{
			return 2;
		}
		else {}
	}
}
void ifcreatenewenemy(ENE *E,int a[][16])
{
	int x,y;
	if(E->live==0&&E->life>=0) 
	{
		while(1){
			x=rand()%16;
			y=rand()%2;
			if(a[y][x]==0)
			{
				E->x=x;
				E->y=y;
				E->live=1;
				break;
			}
		}
	}

}

void createenemy(ENE *E1,ENE *E2,ENE *E3,ENE *E4,int a[][16])
{
	ifcreatenewenemy(E1,a);
	ifcreatenewenemy(E2,a);
	ifcreatenewenemy(E3,a);
	ifcreatenewenemy(E4,a);

}
void createtank(PLAY *p1,PLAY *p2,int a[][16])
{
	if(p1->live==0&&p1->life>=0) {
		p1->x=0;
		p1->y=11;
		p1->live=1;
		a[p1->y][p1->x]=1;
	}
	if(p2->live==0&&p2->life>=0) {
		p2->x=15;
		p2->y=11;
		p2->live=1;
		a[p2->y][p2->x]=1;
	}

}
void ifdeath(PLAY *p1,PLAY *p2,ENE *E1,ENE *E2,ENE *E3,ENE *E4,int a[][16])
{
	if(p1->c=='l')
		{
	if(a[p1->y][p1->x]==0) {
		p1->live=0; 
		p1->life--;
		if(p1->life=-1) p1->c='d';
	}
	}
	if(p2->c=='l')
		{
	if(a[p2->y][p2->x]==0) {
		p2->live=0; 
		p2->life--;
		if(p2->life=-1) p2->c='d';
	}
	}
	if(a[E1->y][E1->x]==0) {E1->live=0; E1->life--;}
	if(a[E2->y][E2->x]==0) {E2->live=0; E2->life--;}
	if(a[E3->y][E3->x]==0) {E3->live=0; E3->life--;}
	if(a[E4->y][E4->x]==0) {E4->live=0; E4->life--;}
}
void gameover (PLAY *p1,PLAY *p2,int a[][16],IMAGE *over)
{
	loadimage(over,"res\\1.jpg");
	if(p1->c=='d'&&p2->c=='d'||a[11][7]!=2){putimage(0,0,over);_sleep(4000);exit(0);}
	else{};
}