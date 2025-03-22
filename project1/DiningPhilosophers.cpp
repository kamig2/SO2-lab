//
// Created by grons on 14.03.2025.
//

#include "DiningPhilosophers.h"
#include <algorithm>

DiningPhilosophers::DiningPhilosophers(int numPhilosophers) {
    this->numPhilosophers = numPhilosophers;
    forks.resize(numPhilosophers, false);  // Inicjalizacja wektora widelców
}

// Funkcja próbująca podnieść widelec
void DiningPhilosophers::pickUpForks(int i) {
    int first = min(i, (i + 1) % numPhilosophers);
    int second = max(i, (i + 1) % numPhilosophers);

    while (true) {
        // Spróbuj podnieść pierwszy widelec, jeśli jest dostępny
        if (!forks[first] && !forks[second]) {
            forks[first] = true;  // Podnosimy pierwszy widelec
            forks[second] = true; // Podnosimy drugi widelec
            return;
        }

        // Jeśli nie udało się podnieść, pozwól innym filozofom na podniesienie swoich widelców
        this_thread::yield();  // Odstępujemy czas innym wątkom
    }
}

// Funkcja zwracająca widelce
void DiningPhilosophers::putDownForks(int i) {
    int first = min(i, (i + 1) % numPhilosophers);
    int second = max(i, (i + 1) % numPhilosophers);

    forks[first] = false;  // Zwracamy pierwszy widelec
    forks[second] = false; // Zwracamy drugi widelec
}

