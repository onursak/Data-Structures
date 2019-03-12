#define taskqueue

typedef struct tsk_node_s {
	int task_num; //starting from 0
	int task_type; // insert:0, delete:1, search:2
	int value;
	struct tsk_node_s* next;
}tsk_node;

void Task_queue(int n); //generate n random tasks for the task queue
void Task_enqueue(int task_num, int task_type, int value);
int Task_dequeue(int* task_num_p, int* task_type_p, int* value_p); 
