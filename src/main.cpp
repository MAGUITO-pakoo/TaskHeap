#include <iostream>
#include "taskHeap.h"
using namespace std;

int main() {
    TaskHeap monTas;

    try {
        monTas.addTask(Task("Boir du lait", 3));
        monTas.addTask(Task("Manger pour avoir de forces", 1));
        monTas.addTask(Task("Remettre ce projet", 2));
        monTas.addTask(Task("Reviser", 4));
        monTas.addTask(Task("Faire le sport", 5));

        monTas.displayTasks();

        cout << "\nExtraction de la tâche prioritaire : "
             << monTas.extractMin().getDescription() << endl;

        monTas.displayTasks();

        // Test de recherche
        Task* trouvée = monTas.searchTask("Appeler maman");
        if (trouvée != nullptr)
            cout << "\nTâche trouvée : " << trouvée->getDescription() << endl;
        else
            cout << "\nTâche non trouvée.\n";

        // Test d'erreur : extraction d'un tas vide
        while (!monTas.isEmpty())
            monTas.extractMin();
        monTas.extractMin(); 
    } catch (exception& e) {
        cout << "\nErreur : " << e.what() << endl;
    }

    try {
        // Test d'erreur : priorité négative
        monTas.addTask(Task("Tâche impossible", -1));
    } catch (exception& e) {
        cout << "\nErreur : " << e.what() << endl;
    }

    return 0;
}


