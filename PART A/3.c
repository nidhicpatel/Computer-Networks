#include<stdio.h>
#define infinity 999
struct node {
int dist[20];
int from[20];
}rt[10];

int main()
{
int i,j,k,nodes,count=0,costmat[20][20];
printf("enter no of nodes:");
scanf("%d",&nodes);
printf("enter cost matrix:\n");
for(i=0;i<nodes;i++)
{
	for(j=0;j<nodes;j++)
	{
	scanf("%d",&costmat[i][j]);
	costmat[i][i]=0;
	rt[i].dist[j]=costmat[i][j];
	rt[i].from[j]=j;
	}
}

do
{
count=0;
for(i=0;i<nodes;i++)
for(j=0;j<nodes;j++)
for(k=0;k<nodes;k++)
if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
{
rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
rt[i].from[j]=k;
count++;
}
}while(count!=0);
for(i=0;i<nodes;i++)
{
printf("Router %d\t\n",i+1);
for(j=0;j<nodes;j++)
printf("Node %d\t via %d\t Distance %d\t\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
}
printf("\n\n");
}
