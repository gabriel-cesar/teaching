#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[]) {
 	int pid; //process identifier
    int i;
    char usage_cpu[100]; //command of cpu usage
    char usage_mem[100]; //command of memory usage
    char kill[100]; //command used to kill the process

	pid = fork(); //process replication
 	if (pid < 0) { //if fork doesn't work
		perror ("Erro: Fork failed.");
		exit (-1); //terminates the process with error code -1
	}

	else if(pid > 0){ //if I'm the father process
        //this 3 sprintf functions format the used commands
        sprintf(usage_cpu, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");  //script to result CPU
        sprintf(usage_mem, "%s%d%s", "pmap -x ", pid, " | grep total | awk '{print $4}'");  //script to result RAM
        sprintf(kill, "%s%d", "kill -9 ", pid);

        for(i = 0; i <= 10; i++) {
        	printf("Time: %ds\n", i);
            printf("CPU usage(%%)\n");
            
            system(usage_cpu); //running the cpu usage command
            printf("MEM usage(kbps)\n");
            
            system(usage_mem); //running the memory usage command
            printf("------\n");
            
            sleep(1); //waits one second
        }

        system(kill); //running the killing command
	}

	else { //else I'm the son process
		if(strcmp(argv[1], "ucp") == 0) {
		    for( ; ; ){
		    	usleep(100);
		    }
		}
 
        if(strcmp(argv[1], "ucp-mem") == 0) {
            for ( ; ; ){
                malloc(sizeof(100000));
                usleep(100);
            }
		}
	}

	perror ("Erro") ; //execve didn't work
 	printf ("Finished!\n") ;
	exit(0) ; //terminates the process with success (code 0) */
 }