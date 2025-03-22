//
// Created by grons on 14.03.2025.
//

#ifndef PROJECT1_DININGPHILOSOPHERS_H
#define PROJECT1_DININGPHILOSOPHERS_H

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class DiningPhilosophers {
private:
    vector<bool> forks;  // Tablica widelców (true = zajęty, false = dostępny)
    int numPhilosophers; // Liczba filozofów

public:
    DiningPhilosophers(int numPhilosophers);  // Konstruktor przyjmujący liczbę filozofów
    void pickUpForks(int i);  // Podnoszenie widelców
    void putDownForks(int i);  // Odstawianie widelców
};

#endif //PROJECT1_DININGPHILOSOPHERS_H
