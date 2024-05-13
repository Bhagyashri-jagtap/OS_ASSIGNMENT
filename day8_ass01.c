#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int ret,i,s;
	for(i=0;i<=5;i++)
	{
		ret = fork();
		if(ret == 0)
		{
		printf("child:%d\n",i);
		printf("hello\n");
			_exit(0);
		}
	}

	for(i=0;i<3;i++)
	{
		waitpid(-1,&s,0);
		printf("child exit:%d\n",WEXITSTATUS(s));
	
	/*	waitpid(ret,&s1,0);
		printf("child exit:%d\n",WEXITSTATUS(s1));

		waitpid(ret,&s2,1);
		printf("child exit:%d\n",WEXITSTATUS(s2));*/
	}

	return 0;

}


