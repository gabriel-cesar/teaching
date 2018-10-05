#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc, char *argv[], char *envp[]) {
 	int pid; //process identifier
    int i; //counter for loop
    char usage_cpu[100]; //command of cpu usage
    char usage_mem[100]; //command of memory usage
    char kill[100]; //command used to kill the process

	pid = fork(); //
 	if (pid < 0) { //if fork doesn't work
		perror ("Erro: Fork failed.");
		exit (-1); //terminates the process with error code -1
	}

	else if(pid > 0){ //if I'm the father process
        sprintf(usage_cpu, "%s%d%s", "ps -p ", pid, " -o pcpu | sed 1d | tr -d ' '");  //script to result CPU
        sprintf(usage_mem, "%s%d%s", "pmap -x ", pid, " | grep total | awk '{print $4}'");  //script to result RAM
        sprintf(kill, "%s%d", "kill -9 ", pid); //script to kill the process

        if(strcmp(argv[1], "ucp") == 0){
            for(i = 0; i <= 10; i++){
                system("clear");
                printf("------ Process with intense CPU usage ------\n");
                printf("Time: %ds\n", i); //time counter

                printf("CPU usage(%%)\n");
                system(usage_cpu); //running the cpu usage command
    
                printf("MEM usage(kB)\n");
                system(usage_mem); //running the memory usage command

                sleep(1); //waits one second
            }
        }

        else if(strcmp(argv[1], "ucp-mem") == 0){
            for(i = 0; i <= 10; i++) {
                system("clear");
                printf("------ Process with intense CPU and memory usage ------\n");
                printf("Time: %ds\n", i);//time counter

                printf("CPU usage(%%)\n");
                system(usage_cpu); //running the cpu usage command

                printf("MEM usage(kbps)\n");
                system(usage_mem); //running the memory usage command

                sleep(1); //waits one second
            }   
        }

        else {
            printf("The arguments are invalid, please try with 'ucp' or 'ucp-mem'\n"); //if the arguments are difent than 'ucp' or 'ucp-mem'
        }

        system(kill); //killing command
	}

	else { //else I'm the son process
        if(strcmp(argv[1], "ucp") == 0) {
            for( ; ; ){
		    }
            
            perror ("Erro: "); //execve didn't work
            printf ("Finished!\n"); 
            exit(0); //terminates the process with success code 0
    	}
 
        if(strcmp(argv[1], "ucp-mem") == 0) {
            clock_t start_t, end_t, elapsed_t; //
            
            start_t = clock(); // Start of the clock
            for(;;){
                end_t = clock(); // End of clock
                elapsed_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // calculation of elapsed time

                if (elapsed_t <= 10.0000){ // If time is smaller than ten seconds
                    malloc(10 * sizeof(int));
                }
            }

            perror ("Erro: ") ; //execve didn't work
            printf ("Finished!\n");
            exit(0); //terminates the process with success code 0
		}

        else{
            printf("Erro: "); //execve didn't work
            printf ("Finished!\n");
            exit(0); //terminates the process with success code 0
        }
	}
}