#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>

#define MQ_KEY   0x1234

typedef struct msg{
long type;
int num1, num2, sum;
} msg_t;

int main(){
int mqid, ret, s;
mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
if(mqid < 0){
perror("msgget() failed");
_exit(1);
}

ret = fork();
if(ret ==0){
msg_t m1;
m1.type =1;
printf("sender: enter two numbers:");
scanf("%d %d", &m1.num1, &m1.num2);
ret = msgsnd(mqid, &m1, (sizeof(m1.num1)+ sizeof(m1.num2)),0);
printf("sender: message received:%d %d\n", ret);
}
else
{
msg_t m2;
printf("receiver: waiting for the message...\n");
ret = msgrcv(mqid, &m2, (sizeof(m2.num1)+sizeof(m2.num2)), 1, 0);
printf("receiver: message received: %d %d %d\m", ret, m2.num1, m2.num2);
m2.num1=(m2.num1+m2.num2);
ret = msgsnd(mqid, &m2, sizeof(m2.num1), 0);
printf("receiver: message sent: %d\n", ret);
wait(&s);
msgctl(mqid, IPC_RMID, NULL);
}
return 0;
}
