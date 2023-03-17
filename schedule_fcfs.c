#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

struct node *head;
int fcfs_tid = 0;

void add(char *name, int priority, int burst){
    Task *newTask = malloc(sizeof(Task));
    newTask->name = name;
    newTask->tid = fcfs_tid;
    newTask->priority = priority;
    newTask->burst = burst;
    insert(&head, newTask);
    ++fcfs_tid;
}

void schedule(){
    if(head == NULL){
        printf("Error: Nothing to schedule.\n");
    }
    else{
        //A node for getting the last node of the linkedlist
        struct node *lastNode;
        while(head != NULL){
            lastNode = head;
            //Makes the node be the last node of the linkedlist 
            while(lastNode->next != NULL){
                lastNode = lastNode->next;
            }
            run(lastNode->task, lastNode->task->burst);
            delete(&head, lastNode->task);
        }   
    }
}
