//
// Created by grons on 14.03.2025.
//

#include "DiningPhilosophers.h"

DiningPhilosophers::DiningPhilosophers() {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        forks[i] = false;  // Wszystkie widelce są początkowo dostępne
    }
}

