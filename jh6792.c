#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/*while(1){
 printf(“lab1> “);
 fgets()  get the input from the user. You can use a different API if you want.
 printf(“Parent Process %d\n”, getpid());
 if (the string entered by the user is a built-in command)
 {
 Check the string and based on it, do the corresponding tasks as stated below.
 If the built-in command is “exit” then ends the whole process using exit(0);
 }
 else
 {
 pid = fork();
 if( pid == 0 )  the created child process
 {
 printf(“Child process %d will execute the command %s\n”, ….);  print process
 ID of the child process and the string entered by the user.
 execve()  use the string entered by the user to transform the child process to
 the new process.
 if execution of the child process reaches this point, it means execve failed. In that
 case, print “Command Not Found!\n” and exits.
 }
 }
wait till the child process finishes
} */

int main(){
	while(1){
		printf("lab1> ");
		char str[20];
		fgets(str, 20, stdin);
		int prid = strcmp(str,"printid\n");
		int ex = strcmp(str, "exit\n");
		int gr = strcmp(str, "greet\n"); 
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