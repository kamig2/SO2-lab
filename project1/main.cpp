#include "DiningPhilosophers.h"
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void philosopher(DiningPhilosophers &table, int id) {
    while (true) {
        table.printSync(id, "is thinking.");
        this_thread::sleep_for(chrono::milliseconds(1000));

        table.printSync(id, "is hungry.");
        table.pickUpForks(id);

        table.printSync(id, "is eating.");
        this_thread::sleep_for(chrono::milliseconds(1000));

        table.putDownForks(id);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <number_of_philosophers>" << endl;
        return 1;
    }

    // Wczytujemy liczbę filozofów z argumentu wiersza poleceń
    int numPhilosophers = stoi(argv[1]);

    DiningPhilosophers table(numPhilosophers);  // Tworzymy stół z odpowiednią liczbą filozofów
    vector<thread> philosophers;

    for (int i = 0; i < numPhilosophers; i++) {
        philosophers.emplace_back(philosopher, ref(table), i);  // Tworzymy wątki dla filozofów
    }

    for (auto &philo : philosophers) {
        philo.join();  // Czekamy na zakończenie wątków
    }

    return 0;
}

