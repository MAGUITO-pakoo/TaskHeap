#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string description;
    int priorite;

public:
    Task(const std::string& desc, int prio);
    int getPriorite() const;
    std::string getDescription() const;
};

#endif
 


