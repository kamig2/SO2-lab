//
// Created by grons on 14.03.2025.
//

#ifndef PROJECT1_DININGPHILOSOPHERS_H
#define PROJECT1_DININGPHILOSOPHERS_H

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class DiningPhilosophers {
private:
    vector<mutex> forks;  // Tablica mutexów reprezentujących widelce
    int numPhilosophers; // Liczba filozofów
    static std::mutex printMutex; // Mutex do synchronizacji wypisywania do konsoli

public:
    DiningPhilosophers(int numPhilosophers);  // Konstruktor przyjmujący liczbę filozofów
    void pickUpForks(int i);  // Podnoszenie widelców
    void putDownForks(int i);  // Odstawianie widelców
    static void printSync(int i, const string &message);
};

#endif //PROJECT1_DININGPHILOSOPHERS_H
