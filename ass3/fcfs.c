#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
 int n;
 printf("Enter the numbers of processes :");
 scanf("%d",&n);
 
 int at[n],bt[n],wt[n],tat[n],s[n];
 float wtavg=0,tatavg=0;
 
 //srand(time(NULL));
 
 printf(" Enter the arival time and the first CPU burst for each process :\n");
 for(int i=0;i<n;i++)
 {
   printf(" Arival time for the process %d:",i+1);
   scanf("%d",&at[i]);
   printf("First CPU brust for process id %d:",i+1);
   scanf("%d",&bt[i]);
   bt[i]=rand()%10;
 }
 //ct[0]=at[0]+bt[0]+2;
 s[0]=0;
 for(int i=1;i<n;i++)
 {
   s[i]=s[i-1]+bt[i-1];
   //int io_delay=(at[i]>ct[i-1])?at[i]-ct[i-1]:0;
  // ct[i]=ct[i-1]+io_delay+bt[i];
   
 }
 // calculate wating time
 for(int i=0;i<n;i++)
 {
   //int io_delay=(at[i]>ct[i-1])?at[i]-ct[i-1]:0;
   wt[i]=s[i]-at[i];
   wtavg +=wt[i];
   tat[i]=wt[i]+bt[i];
   tatavg +=tat[i];
 }
 wtavg /=n;
 tatavg /=n;
 
 /* printf("\n Gantt Chart:\n");
 for(int i=0;i<n;i++)
 {
  printf("P%d\t",i+1);
   
 }
 printf("\n");
 for(int i=0;i<n;i++)
 {
   printf("%d\t",at[i]);
 }
 printf(" %d\n",ct[n-1]);
 */
 printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
 for(int i=0;i<n;i++)
 {
   printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
   
 }
 printf("\n Average  Wt :  %f\n",wtavg);
 printf("\n Average  TAT :  %f\n",tatavg); return 0;
}

