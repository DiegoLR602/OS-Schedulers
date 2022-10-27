
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *temp;
int quantum = 10;


Task* pickNext()
{
    return (temp->task);

}
void add(char *name, int priority, int burst){

  Task *newTask;
  newTask = (Task*)malloc(sizeof(Task));
  (*newTask).priority = priority;
  (*newTask).burst = burst;
  (*newTask).name = name;

  insert(&temp, newTask);

}


void schedule(){
  int newBurst;
  Task *taskToPick;

    while (temp != NULL) {
          taskToPick = pickNext();
          run(taskToPick, quantum);

            if(taskToPick->burst > quantum){ //Chooses next task to pick based on quantum
              if(temp->next == temp){
                break;
              }
              newBurst = taskToPick->burst - quantum;
              taskToPick->burst = newBurst; //Selects next burst for task in list
              insert(&temp->next, taskToPick);
              delete(&temp, taskToPick);

            }


          else{
            delete(&temp, taskToPick);
          }



    }

}
