#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>

#define MQ_KEY    0x1234

typedef struct msg
{
	long type;
	int num1;
	int num2;
	int sum;


}msg_t;

int main()
{
	int mqid,ret,s;
	mqid= msgget(MQ_KEY,IPC_CREAT | 0600);
	if(mqid<0)
	{
		perror("msgget()failed");
		_exit(1);
	}

	ret = fork();
	if(ret==0)
	{
		msg_t m1;
		m1.type=1;
		m1.num1=5;
		m1.num2=7;
		ret= msgsnd(mqid,&m1,(sizeof(m1.num1)+sizeof(m1.num2)),0);

	}
	else{
	    msg_t m2;
		printf("receiver: waiting for the msg:\n");
		ret= msgrcv(mqid,&m2,(sizeof(m2.num1)+sizeof(m2.num2)),1,0);
		m2.sum=m2.num1+m2.num2;
		printf("received num1=%d,num2=%d\n",m2.num1,m2.num2);
		printf("received: msg received:%d,%d\n",ret,m2.sum);
		wait(&s);
		msgctl(mqid,IPC_RMID,NULL);
	}
	return 0;
}
