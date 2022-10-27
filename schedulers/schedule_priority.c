#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

typedef struct node Node;
Node *taskList;
Node *head;
int id = 0;

Task* pickNext()
{
    Node *temp = head->next;
    Task *tempTask = head->task;

    while (temp != NULL) { //Chooses next task based on it's priority
        if(temp->task->priority > tempTask->priority) { 
            tempTask = temp->task;
        }
        temp = temp->next;
    }

    return tempTask;
}

// add a task to the list 
void add(char *name, int priority, int burst)
{
    Task *newTask = (Task*) malloc(sizeof(Task));
    newTask->tid = id;
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    insert(&head, newTask);
    id++;
}

void schedule()
{
    Task *taskToPick;
    while (head != NULL) { //Loops through tasks in a list
        taskToPick = pickNext();

        run(taskToPick, taskToPick->burst);
        delete(&head, taskToPick);
    }
}
