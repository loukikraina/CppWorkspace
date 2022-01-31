#include<conio.h>
#include<stdio.h>

struct process{
	int burst_time;
	int completion_time;
	int start_time;
	char completed;
}p[10];

void main(){
	int a,n,qt,time_taken=0,flag=0,bt[10],k;
	float aw=0,at=0;
	clrscr();
	printf("Enter the total number of process:- ");
	scanf("%d",&n);
	k=n;
	for(a=0;a<n;a++){
		printf("Enter burst time for process %d:-  ",a+1);
		scanf("%d",&p[a].burst_time);
		p[a].completed = 'F';
		p[a].start_time=0;
		bt[a]=p[a].burst_time;
	}
	printf("Enter quantum time for process:-  ");
	scanf("%d",&qt);
	printf("\nThe Gantt's chart:- \n");
	printf("0");
	time_taken=0;
	while(1)
	{
		flag=0;
		for(a=0;a<k;a++)
		{
			
				if(p[a].completed=='F')
				{	

					if(p[a].start_time==0 && a!=0)
						p[a].start_time = time_taken;
					flag++;
					if(p[a].burst_time<qt)
					{
						p[a].completed ='T';
						time_taken += p[a].burst_time;
						p[a].completion_time = time_taken;
					}
					else
					{
						time_taken += qt;
						p[a].burst_time -= qt;
					}

					printf("  Process '%d'  %d",a+1,time_taken);

					
				}
		}	
		if(flag==0)
			break;
	}
	getch();
	printf("\nWaiting time for process:- \n");
	for(a=0;a<n;a++)
	{
		printf("Process '%d'\tWaiting time:- %d\n",a+1,p[a].completion_time-bt[a]);
		aw = aw+p[a].completion_time-bt[a];
	}
	getch();
	printf("\nTurnaround time for process:- \n");

	for(a=0;a<n;a++)
	{
		printf("Process '%d'\tTurnaround time:- %d\n",a+1,p[a].completion_time);
		at = at + p[a].completion_time;
	}
	getch();

	printf("Average waiting time:- %f\n", aw/(float)n);
	printf("Average turnaround time:- %f\n", at/(float)n);



	getch();
}



