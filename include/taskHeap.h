#ifndef TASKHEAP_H
#define TASKHEAP_H

#include <vector>
#include "task.h"

using namespace std;

class TaskHeap {
private:
    vector<Task> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void addTask(const Task& task);
    Task extractMin();
    bool isEmpty() const;
    void displayTasks() const;
};

#endif


