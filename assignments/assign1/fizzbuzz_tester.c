#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

/*
    Instructions for use:
    Place the tester in the same folder as the fizzbuzz program, which should be
    appropriately labeled as "fizzbuzz.c" and as the fizzbuzz_solution.txt file. 
    Compile and run this program.
*/
int main() {
    char * fizzbuzz_program = "fizzbuzz.c";
    char * fizzbuzz_solution = "fizzbuzz_solution.txt";
    int pipefd[2];
    pipe(pipefd);   //Create pipe on pipefd for sending data back to parent.
    
    if (fork()) {   //Fork the process
        dup2(pipefd[0],0);	//Replace stdin with write side of the pipe 
		close(pipefd[1]);   //Close the out side of pipe
		FILE * solution = fopen(fizzbuzz_solution, "r");
		char buf[64]; //A 64-char buffer should be more than enough.
		char sol_buf[64]; 
		int i=0;
		while (scanf("%64s", &buf) > 0 && fscanf(solution, "%64s", &sol_buf) > 0) {
		    assert(strcmp(buf, sol_buf) == 0);
		}
		fclose(solution);
		printf("Test passed!\n");
    } else {
        printf("Compiling %s...\n", fizzbuzz_program);
        execl("gcc", fizzbuzz_program, "-o", "temp");
        printf("Running the program and analyzing input...\n");
        dup2(pipefd[1],1);  //Replace stdout with out side of the pipe 
		close(pipefd[0]);   //Close the write side of the pipe.
        execl("temp", 0);
    }
    
	if (remove("temp") != 0)
	    fprintf(stderr, "Error deleting temporary test program file.\n");

}