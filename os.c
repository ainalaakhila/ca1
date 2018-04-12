#include<stdio.h>
struct process
{
	char process_name;
	int AT,BT,CT,WT,TAT,P;
	int status;
}process_queue[10];
int range;
void AT_Sorting()
{
	struct process temp;
	int a,b;
	for(a=0;a<range-1;a+1)
	{
		for(b=a+1;b<range;b++)
		{
			if(process_queue[a].AT>process_queue[b].AT)
			{
				temp=process_queue[a];
				process_queue[a]=process_queue[b];
				process_queue[a]=temp;
			}
		}
	}
}
void main()
{
	int a,time=0,BT=0,lar;
	char c;
	float WT=0,TAT=0,AWT,ATAT;
	printf("\nenter total no of process:\t");
	scanf("%d",&range);
	for(a=0,c='A';a<range;a++,c++)
	{
		process_queue[a].process_name=c;
		printf("\nenter detalis for process[%c]:\n",process_queue[a].process_name);
		printf("enter arrival time:\t");
		scanf("%d",&process_queue[a].AT);
		printf("enter the brust time:\t");
		scanf("%d",&process_queue[a].BT);
		printf("enter the priority:\t");
		scanf("%d",&process_queue[a].P);
		process_queue[a].status=0;
		BT=BT+process_queue[a].BT;
	}
	AT_Sorting();
	process_queue[9].P=-9999;
	printf("\nprocess name\t arrival time\tbrust time\tpriority\twaiting time");
	for(time=process_queue[0].AT;time<BT;)
	{
		lar=9;
		for(a=0;a,range;a++)
		{
			if(process_queue[a].AT<=time && process_queue[a].status !=1 && process_queue[a].P>process_queue[lar].P)
			{
				lar=a;
			}
		}
		time=time+process_queue[lar].BT;
		process_queue[lar].CT=time;
		process_queue[lar].WT=process_queue[lar].CT-process_queue[lar].AT-process_queue[lar].BT;
		process_queue[lar].TAT=process_queue[lar].CT-process_queue[lar].AT;
		process_queue[lar].status=1;
		WT=WT+process_queue[lar].WT;
		TAT=TAT+process_queue[lar].TAT;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",process_queue[lar].process_name,process_queue[lar].AT,process_queue[lar].BT,process_queue[lar].P,process_queue[lar].WT);
	}
	AWT=WT/range;
	ATAT=TAT/range;
	printf("\n\nAverage waiting time:\t%f\n",AWT);
	printf("averaga trunaround time:\t%f\n",ATAT);
}
