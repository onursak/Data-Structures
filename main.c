#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
#include "taskqueue.h"

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	srand(time(NULL)); //for seeding rand function with time to avoid getting same numbers for every execution
	Task_queue(n);
    
}
