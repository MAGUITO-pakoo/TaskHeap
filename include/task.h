#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
    string description;
    int priorite;

public:
    Task(string desc, int prio);
    int getPriorite() const;
    string getDescription() const;
};

#endif
 


