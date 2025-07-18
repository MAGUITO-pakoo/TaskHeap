#include "../include/taskHeap.h"
#include <iostream>
using namespace std;

int main() {
    TaskHeap monTas;

    monTas.addTask(Task("Faire les courses", 4));
    monTas.addTask(Task("Rendre le projet", 1));
    monTas.addTask(Task("Réviser pour l'examen", 2));
    monTas.addTask(Task("Manger pour etre en forme", 3));
    monTas.addTask(Task("faire du sport", 5));
    cout << "Tâches triées par priorité :" << endl;
    monTas.displayTasks();

    cout << endl << "Traitement des tâches (du plus prioritaire au moins prioritaire) :" << endl;
    while (!monTas.isEmpty()) {
        Task tache = monTas.extractMin();
        cout << "-> " << tache.getDescription() << " (Priorité : " << tache.getPriorite() << ")" << endl;
    }

    return 0;
}


