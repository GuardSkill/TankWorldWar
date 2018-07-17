#include "tank.h"
void bulletact(int a[][16])
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<12;j++)
		{
			if(a[j][i]==4)             //向上的子弹处理
			{
				if(j==0) a[j][i]=0;
				else if(a[j-1][i]==0)
				{
					a[j][i]=0;
					a[j-1][i]=4;
				}
			    else if(a[j-1][i]!=0)
				{
					a[j][i]=0;
					a[j-1][i]=0;
				}
			}
			if(a[j][i]==5)                 //向左的子弹处理
			{
				if(i==0) a[j][i]=0;
				else if(a[j][i-1]==0)
				{
					a[j][i]=0;
					a[j][i-1]=5;
				}
			    else if(a[j][i-1]!=0)
				{
					a[j][i]=0;
					a[j][i-1]=0;
				}
			}
			if(a[j][i]==6)          //向下的子弹处理
			{
				if(j==11) a[j][i]=0;
				else if(a[j+1][i]==0)
				{
					a[j][i]=0;
					a[j+1][i]=6;
				}
			    else if(a[j+1][i]!=0)
				{
					a[j][i]=0;
					a[j+1][i]=0;
				}
			}
			if(a[j][i]==7)                 //向右的子弹处理
			{
				if(i==15) a[j][i]=0;
				else if(a[j][i+1]==0)
				{
					a[j][i]=0;
					a[j][i+1]=7;
				}
			    else if(a[j][i+1]!=0)
				{
					a[j][i]=0;
					a[j][i+1]=0;
				}
			}
			
		}
	}
}
void skillact(CMD *cmd,PLAY *p1,PLAY *p2,int a[][16],int key1,int key2)
{
	if(p1->c=='l')
		{	
	if(cmd->skill1==20&&key1==UP) 
		{
			if(p1->y==0) {}
			else if(a[p1->y-1][p1->x]!=0)
			{
				a[p1->y-1][p1->x]=0;
			}
			else if(a[p1->y-1][p1->x]==0)
			{
				a[p1->y-1][p1->x]=4;
			}
			cmd->skill1=0;
		}
		if(cmd->skill1==20&&key1==LEFT)
		{
			if(p1->x==0) {}
			else if(a[p1->y][p1->x-1]!=0)
			{
				a[p1->y][p1->x-1]=0;
			}
			else if(a[p1->y][p1->x-1]==0)
			{
				a[p1->y][p1->x-1]=5;
			}
			cmd->skill1=0;
		}
		if(cmd->skill1==20&&key1==DOWN) 
		{
			if(p1->y==11) {}
			else if(a[p1->y+1][p1->x]!=0)
			{
				a[p1->y+1][p1->x]=0;
			}
			else if(a[p1->y+1][p1->x]==0)
			{
				a[p1->y+1][p1->x]=6;
			}
			cmd->skill1=0;
		}
		if(cmd->skill1==20&&key1==RIGHT)
		{
			if(p1->x==15) {}
			else if(a[p1->y][p1->x+1]!=0)
			{
				a[p1->y][p1->x+1]=0;
			}
			else if(a[p1->y][p1->x+1]==0)
			{
				a[p1->y][p1->x+1]=7;
			}
			cmd->skill1=0;
		} 
}
		if(p2->c=='l')
		{
		if(cmd->skill4==20&&key2==UP)
		{
			if(p2->y==0) {}
			else if(a[p2->y-1][p2->x]!=0)
			{
				a[p2->y-1][p2->x]=0;
			}
			else if(a[p2->y-1][p2->x]==0)
			{
				a[p2->y-1][p2->x]=4;
			}
			cmd->skill4=0;
		}
		if(cmd->skill4==20&&key2==LEFT)
		{
			if(p2->x==0) {}
			else if(a[p2->y][p2->x-1]!=0)
			{
				a[p2->y][p2->x-1]=0;
			}
			else if(a[p2->y][p2->x-1]==0)
			{
				a[p2->y][p2->x-1]=5;
			}
			cmd->skill4=0;
		}
		if(cmd->skill4==20&&key2==DOWN)
		{
			if(p2->y==11) {}
			else if(a[p2->y+1][p2->x]!=0)
			{
				a[p2->y+1][p2->x]=0;
			}
			else if(a[p2->y+1][p2->x]==0)
			{
				a[p2->y+1][p2->x]=6;
			}
			cmd->skill4=0;
		}
		if(cmd->skill4==20&&key2==RIGHT)
		{
			if(p2->x==15) {}
			else if(a[p2->y][p2->x+1]!=0)
			{
				a[p2->y][p2->x+1]=0;
			}
			else if(a[p2->y][p2->x+1]==0)
			{
				a[p2->y][p2->x+1]=7;
			}
			cmd->skill4=0;
		}
		}
}

