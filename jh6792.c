#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){
	while(1){
		printf("lab1> ");
		char str[20];
		fgets(str, 20, stdin);
		str[strlen(str)-1] = NULL;
		int prid = strcmp(str,"printid");
		int ex = strcmp(str, "exit");
		int gr = strcmp(str, "greet"); 
		if(gr == 0)
			printf("Hello\n");
		else if(prid == 0)
			printf("The ID of the current process is %d\n", getpid());
		else if(ex == 0)
			return 0;
		else{
			pid_t pid = fork();
			if(pid==0){
				printf("Child process %d will execute the command %s\n", getpid(), str);
				char bin[20];	strcpy(bin, "/bin/");
				strcat(bin, str);
				char *progname[] = {str, NULL};
				execve(bin, progname, NULL);
				printf("Command Not Found!\n");
				exit(pid);
			}
		}
		wait(NULL);
	}
}
