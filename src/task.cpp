#include "task.h"

Task::Task(const std::string& desc, int prio) {
    description = desc;
    priorite = prio;
}

int Task::getPriorite() const {
    return priorite;
}

std::string Task::getDescription() const {
    return description;
}




