#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

lst_node* head = NULL;

int Search(int value){
	lst_node* traveler = head;   //creating traveler variable to avoid updating global head node
	while(traveler != NULL){
		if(traveler->data == value){   //the value is found
			return 1;
		}
		else{
			traveler = traveler->next;  //the value is not found look for other nodes
			continue;
		}
	}
	return 0;
};

int Insert(int value){
	//if the linked list is empty, then create a new node at the head
	if(head==NULL){
		lst_node* new_node = (lst_node*)malloc(sizeof(lst_node));
		new_node -> data = value;
		new_node -> next = NULL;
		head=new_node;
		return 1;
	}
	lst_node* traveler = head;   //creating traveler variable to avoid updating global head node
	if(Search(value)){    //if item is already in the list there is no operation to avoid duplicated items
		return 0;
	}
	//if value less than head value then update head
	if (value < head -> data){
		lst_node* temp = (lst_node*)malloc(sizeof(lst_node));
		temp -> data = value;
		temp -> next = head;
		head = temp;		
		return 1;
	}
	//if there is only item in the linked list
	if(value > traveler -> data && traveler->next == NULL){
		lst_node* temp = (lst_node*)malloc(sizeof(lst_node));
		temp -> data = value;
		temp -> next = NULL;
		traveler -> next = temp;	
		return 1;	
	}
	//travel the linked list due to determine where to insert the value
	while(1){
		if(value > traveler->data){
			if(traveler->next != NULL && value > traveler->next->data){
				traveler = traveler -> next;
				continue;
			}
			if(traveler->next != NULL && value < traveler->next->data){
				break;
			}
			if(traveler->next == NULL){
				break;
			}
		}
		else{
			break;
		}
	}
	//if we insert the data to the end of the linked list
	if(traveler->next == NULL){
		lst_node* temp = (lst_node*)malloc(sizeof(lst_node));
		temp -> data = value;
		temp -> next = NULL;
		traveler -> next = temp;	
		return 1;
	}
	//if we insert the data to mid of the linked list
	else{
		lst_node* temp = (lst_node*)malloc(sizeof(lst_node));
		temp -> data = value;
		temp -> next = traveler -> next;
		traveler -> next = temp;
		return 1;
	}
	return 0;

}

void printList(){
	lst_node* traveler = head;
	while(traveler != NULL){
		printf("%d ", traveler->data);
		traveler = traveler->next;
	}
    printf("\n");
		
}


int Delete(int value){
	if(head == NULL){   //if the list is empty there is no element to delete return 0
		return 0;
	}
	
	else if(!Search(value)){   //for controlling item which we want to delete in the list or not return 0
		return 0;
	}
	else{  //the item is in the list
		if(value == head->data && head->next==NULL){  //if there is only one item in the list
			free(head);
			head=NULL;
			return 1;
		}
		lst_node* traveler = head; //creating traveler variable to avoid updating global head node
		while(1){
			//if value is at the head
			if (value == head->data){ 
				lst_node* temp = (lst_node*)malloc(sizeof(lst_node));
				temp = head->next;
				free(head);
				head=temp;
				return 1;
			}
			//if value is not at the head, travel other nodes
			if(value != traveler->next->data){
				traveler=traveler->next;
				continue;
			}
			else{
				break;
			}
			
		}
		//if the item is located at last node
		if(traveler->next->next == NULL){
			free(traveler->next);
			traveler->next = NULL;
			return 1;
			
		}	
		//if the item is located at mid nodes
		else{
			lst_node* temp = (lst_node*)malloc(sizeof(lst_node));
			temp = traveler->next->next;
			free(traveler->next);
			traveler -> next = temp;
			return 1;
		}
		}
		
	return 0;	
}
