//
// Created by grons on 14.03.2025.
//

#include "DiningPhilosophers.h"
#include <algorithm>

std::mutex DiningPhilosophers::printMutex;

DiningPhilosophers::DiningPhilosophers(int numPhilosophers) {
    this->numPhilosophers = numPhilosophers;
    forks = vector<mutex>(numPhilosophers); // Inicjalizacja wektora mutexów
}

// Funkcja próbująca podnieść widelec
void DiningPhilosophers::pickUpForks(int i) {
    int first = min(i, (i + 1) % numPhilosophers);
    int second = max(i, (i + 1) % numPhilosophers);

    // Aby uniknąć zakleszczeń, najpierw próbujemy zablokować mniejszy numer widelca
    lock(forks[first], forks[second]);  // Blokowanie mutexów

}

// Funkcja zwracająca widelce
void DiningPhilosophers::putDownForks(int i) {
    int first = min(i, (i + 1) % numPhilosophers);
    int second = max(i, (i + 1) % numPhilosophers);

    forks[first].unlock();
    forks[second].unlock();
}

void DiningPhilosophers::printSync(int i, const string &message) {
    // Zablokowanie mutexu przed wypisaniem do konsoli
    std::lock_guard<std::mutex> lock(printMutex);

    // Wypisujemy komunikat
    cout << "Philosopher " << i << " " << message << endl;
}


