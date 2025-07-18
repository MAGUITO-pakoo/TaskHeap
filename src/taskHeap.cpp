#include "taskHeap.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void TaskHeap::heapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap[index].getPriorite() < heap[parent].getPriorite()) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void TaskHeap::heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

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
    if (task.getPriorite() < 0)
        throw invalid_argument("Priorité négative non autorisée.");

    heap.push_back(task);
    heapifyUp(heap.size() - 1);
}

Task TaskHeap::extractMin() {
    if (isEmpty())
        throw runtime_error("Impossible d'extraire : tas vide.");

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
    cout << "Tâches dans le tas :\n";
    for (const auto& task : heap) {
        cout << "- " << task.getDescription() << " (Priorité : " << task.getPriorite() << ")\n";
    }
}

Task* TaskHeap::searchTask(const std::string& description) {
    for (auto& task : heap) {
        if (task.getDescription() == description)
            return &task;
    }
    return nullptr;
}

