#ifndef _TANK_H
#define _TANK_H
#include <graphics.h>
#include <conio.h>
#include "time.h"
#pragma comment(lib,"Winmm.lib")
typedef struct Command
{
	int key1,key2;
	int skill1,skill2,skill3;
	int skill4,skill5,skill6;
}CMD;
typedef struct Tank
{
	IMAGE *tank;
	IMAGE *tank0;
	int life;
	int live;
	int x,y;
	char c;
}PLAY;
typedef struct enemy
{
	IMAGE *tank;
	IMAGE *tank0;
	int life; 
	int live;
	int x,y;
}ENE;

#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define UP2 1
#define LEFT2 2
#define DOWN2 3
#define RIGHT2 4

void Loadingothers(IMAGE *huang,IMAGE bullet[][2],IMAGE *bullet_rc);
void startimage();  //���뿪ʼ����
void Loadimage0(ENE *E1,ENE *E2,ENE *E3,ENE *E4,IMAGE direction0[][2],IMAGE *enemy_rc);           //ͼƬ���봢��
void Loadimage(PLAY *p1,PLAY *p2,IMAGE *grass,IMAGE direction[][2],IMAGE *tank_rc,IMAGE *home,IMAGE *home0,IMAGE *box,IMAGE *box0);
void createenemy(ENE *E1,ENE *E2,ENE *E3,ENE *E4,int a[][16]);  //��������
void ifcreatenewenemy(ENE *E,int a[][16]);        //�Ƿ��������
void createtank(PLAY *p1,PLAY *p2,int a[][16]);
void enemymove0(ENE *E,int a[][16],IMAGE direction0[][2]);           //�����ƶ�
void drawenemy0(ENE *E);
void enemymove(ENE *E1,ENE *E2,ENE *E3,ENE *E4,int a[][16],IMAGE direction0[][2]); 
void drawenemy(ENE *E1,ENE *E2,ENE *E3,ENE *E4);   //��������
void drawmap(int a[][16],IMAGE *home,IMAGE *home0,IMAGE *box,IMAGE *box0,IMAGE bullet[][2]);           //��ͼ����
void GetCommand(CMD *cmd);                 //��ȡ����
void tankmove(CMD *cmd,PLAY *p1,PLAY *p2,IMAGE direction[][2],int a[][16]);           //����ƶ�	
void skillact(CMD *cmd,PLAY *p1,PLAY *p2,int a[][16],int key1,int key2);
void bulletact(int a[][16]);
void ifdeath(PLAY *p1,PLAY *p2,ENE *E1,ENE *E2,ENE *E3,ENE *E4,int a[][16]);
int judgeplayer();                                 //��������ж� 
void drawplayer(PLAY *p1,PLAY *p2);
void gameover (PLAY *p1,PLAY *p2,int a[][16],IMAGE *over);
        
#endif 