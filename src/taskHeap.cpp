#include "../include/taskHeap.h"
#include <iostream>
using namespace std;

void TaskHeap::heapifyUp(int index) {
    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (heap[index].getPriorite() < heap[parent].getPriorite()) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void TaskHeap::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap.size() && heap[left].getPriorite() < heap[smallest].getPriorite())
        smallest = left;

    if (right < heap.size() && heap[right].getPriorite() < heap[smallest].getPriorite())
        smallest = right;

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void TaskHeap::addTask(const Task& task) {
    heap.push_back(task);
    heapifyUp(heap.size() - 1);
}

Task TaskHeap::extractMin() {
    if (isEmpty()) {
        cout << "Pas de tâche." << endl;
        return Task("", 0);
    }

    Task minTask = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return minTask;
}

bool TaskHeap::isEmpty() const {
    return heap.empty();
}

void TaskHeap::displayTasks() const {
    cout << "Liste des tâches dans le tas :" << endl;
    for (const auto& task : heap) {
        cout << "- " << task.getDescription() << " (Priorité : " << task.getPriorite() << ")" << endl;
    }
}

