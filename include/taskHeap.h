#ifndef TASKHEAP_H
#define TASKHEAP_H

#include <vector>
#include "task.h"

class TaskHeap {
private:
    std::vector<Task> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void addTask(const Task& task);
    Task extractMin();
    bool isEmpty() const;
    void displayTasks() const;
    Task* searchTask(const std::string& description);
};

#endif


