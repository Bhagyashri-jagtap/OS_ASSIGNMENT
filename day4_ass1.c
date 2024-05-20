#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
		int ret2, err2, s2,fd;
		printf("parent started!\n");
		ret2 = fork();
		if(ret2 == 0)
		{
		
			fd = open("in.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
//	   	    fd = open("in.txt", O_RDONLY);
			dup2(fd,1); // copy fd on stdout
			close(fd);

	   		err2 = execlp("wc", "wc", NULL);
			if(err2 < 0)
			{
				perror("exec() failed to execute wc cmd");
				_exit(2);
	  		}
		}
		else
			waitpid(ret2, &s2, 0);
		printf("parent completed!\n");	
   		return 0;
}
