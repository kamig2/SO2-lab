//
// Created by grons on 14.03.2025.
//

#ifndef PROJECT1_DININGPHILOSOPHERS_H
#define PROJECT1_DININGPHILOSOPHERS_H

#include <iostream>
#include <thread>
#include <vector>

const int NUM_PHILOSOPHERS = 5;
using namespace std;

class DiningPhilosophers {
private:
    bool forks[NUM_PHILOSOPHERS];  // Tablica widelców (true = zajęty, false = dostępny)

public:
    DiningPhilosophers();

};


#endif //PROJECT1_DININGPHILOSOPHERS_H
