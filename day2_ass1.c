#include<stdio.h>
#include<signal.h>
int main()
{

int pid,signum, ret;
printf("To terminate process.\n");
printf("enter PID SIGNUM:");
scanf("%d %d", &pid, &signum);
ret = kill(pid, signum);
if(ret  == 0)
printf("given process terminated successfully..\n");
else printf("termination failed");
return 0;
}
