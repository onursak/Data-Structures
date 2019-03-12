#define linkedlist

typedef struct lst_node_s {
	int data;
	struct lst_node_s* next;
}lst_node;

int Insert(int value);
int Search(int value);
int Delete(int value);
void printList();
