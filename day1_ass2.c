#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
int hii, bye, child1, child2, child3, child4, s3, s2, s1, waitt;

child1 = fork();
if(child1 ==0){
child2 = fork();
if(child2 ==0){
child3 = fork();
if(child4 ==0){
int count = 5;
while(count !=0)
{
printf("count: %d\n", count);
count--;
}
_exit(0);

waitt = waitpid(child4, &s3, 0);
}
_exit(0);

waitt = waitpid(child3, &s2, 0);
}
_exit(0);

waitt = waitpid(child2, &s2, 0);
_exit(0);
}
else{
hii = waitpid(child1, &s1, 0);
printf("exit: %d\n", hii);
}
}

