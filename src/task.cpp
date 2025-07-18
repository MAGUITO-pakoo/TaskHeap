#include "../include/task.h"

Task::Task(string desc, int prio) {
    description = desc;
    priorite = prio;
}

int Task::getPriorite() const {
    return priorite;
}

string Task::getDescription() const {
    return description;
}




