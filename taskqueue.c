#include<stdio.h>
#include<stdlib.h>
#include "taskqueue.h"
#include "linkedlist.h"

tsk_node* front = NULL;
tsk_node* back = NULL;

void Task_queue(int n){
	for(int i=0; i<n; i++){ //creating n tasks
		Task_enqueue(i, rand()%3, rand()%30);  //creating task with random value between 0 and 29 and random list operation and enqueue
	}
	for(int i=0; i<n; i++){   //this loop is to dequeue from task and perform list operations
		int task_num_p, task_type_p, value_p = 0;    //creating these variables for keeping datas of node which is applied dequeue operation   
		Task_dequeue(&task_num_p, &task_type_p, &value_p); //sending addresses into function   
		if(task_type_p == 0){ 
			if(Insert(value_p)==0){    
				printf("task %d-insert %d: %d cannot be inserted\n", task_num_p, value_p, value_p);
			}
			else{
				printf("task %d-insert %d: %d is inserted\n", task_num_p, value_p, value_p);
			}

		}
		if(task_type_p == 1){   
			if(Delete(value_p)==0){    
				printf("task %d-delete %d: %d cannot be deleted\n", task_num_p, value_p, value_p);
			}
			else{
				printf("task %d-delete %d: %d is deleted\n", task_num_p, value_p, value_p);
			}
		}
		if(task_type_p == 2){ 
			if(Search(value_p)==0){
				printf("task %d-search %d: %d is not found\n", task_num_p, value_p, value_p);
			}
			else{
				printf("task %d-search %d: %d is found\n", task_num_p, value_p, value_p);
			}
		}
	}
	printf("Final list:\n");
	printList();  //printing final linked list
};

void Task_enqueue(int task_num, int task_type, int value){
	if(front==NULL){   //if front is NULL the queue is empty, create new node
		front = (tsk_node*)malloc(sizeof(tsk_node));
		front->task_num = task_num;
		front->task_type = task_type;
		front->value = value;
		front->next = NULL;
		back = front;  //back and front points same node for now(1 element in the queue)
		return;     //return and don't execute the rest of code
	}
	//if queue is not empty
	//creating new node located next of back
	back->next = (tsk_node*)malloc(sizeof(tsk_node));
	back->next->task_num = task_num;
	back->next->task_type = task_type;
	back->next->value = value;
	back = back->next;	//updating back
	back->next = NULL;
};

int Task_dequeue(int* task_num_p, int* task_type_p, int* value_p){
	if(front == NULL){  //there is no element to dequeue
		return 0;
	}
	*task_num_p = front->task_num;
	*task_type_p = front->task_type;
	*value_p = front->value;
	tsk_node* temp = (tsk_node*)malloc(sizeof(tsk_node)); //creating temp variable to free old front node
	temp = front; 
	front = front->next; //updating front
	free(temp);
};
