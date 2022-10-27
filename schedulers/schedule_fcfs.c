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
    return (head->task); // picks first task in list
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
    while (head != NULL) { //Iterates through tasks in list
        taskToPick = pickNext();

        run(taskToPick, taskToPick->burst);
        delete(&head, taskToPick);
    }
}
