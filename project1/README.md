[Powrót](../README.md)
# Problem Jedzących Filozofów

Problem **"Jedzących Filozofów"** to klasyczny problem synchronizacji w systemach wielowątkowych, który ilustruje wyzwania związane z blokowaniem współdzielonych zasobów. Filozofowie siedzą przy stole i naprzemiennie myślą, jedzą i oczekują na dostęp do widelców. Aby jeść, filozofowie potrzebują dwóch widelców, ale widelec może być używany tylko przez jednego filozofa w tym samym czasie. Celem jest zapobieganie zakleszczeniom i zapewnienie, że filozofowie będą mogli jeść, myśleć i zwracać widelce w sposób zsynchronizowany.

## Uruchamianie programu

Aby uruchomić program, należy podać liczbę filozofów jako argument.  
Liczba filozofów musi być większa niż 1.

## Opis rozwiązania

Program implementuje rozwiązanie problemu **Jedzących Filozofów** przy pomocy mutexów do synchronizacji wątków. Program używa wielowątkowości w C++ do symulacji filozofów, którzy naprzemiennie myślą, jedzą i czekają na dostęp do widelców.

### Wątki:
- **Wątek filozofa**: Każdy filozof jest reprezentowany przez osobny wątek. Każdy wątek:
  - Wypisuje na konsolę, że filozof myśli.
  - Czeka na dostęp do widelców.
  - Je przez określony czas, a potem zwraca widelce.
  - Współdzieli zasoby, takie jak widelce, z innymi wątkami (filozofami).

### Sekcje krytyczne:

- **Podnoszenie widelców (pickUpForks)**:
  - Jest to sekcja krytyczna, gdzie filozof próbuje podnieść dwa widelce.
  - Aby uniknąć zakleszczenia, każdy filozof próbuje podnieść widelce w określonej kolejności.
  - **Mutexy** są używane do blokowania dostępu do widelców. Jeśli filozof nie może podnieść obu widelców, czeka i ponawia próbę.

- **Zwracanie widelców (putDownForks)**:
  - Po skończeniu jedzenia filozof zwraca widelce, uwalniając je z mutexów.
  - Zwrócenie widelców odbywa się w sposób zsynchronizowany, aby inni filozofowie mogli je wykorzystać.

- **Synchronizacja wypisywania**:
  - Funkcja `printSync` jest odpowiedzialna za synchronizację dostępu do konsoli. Zabezpiecza to przed zlewaniem się komunikatów, gdy wiele filozofów chce wypisać swoje stany jednocześnie.

### Rozwiązanie sekcji krytycznych:
- **Mutexy**: Używamy mutexów do synchronizacji dostępu do widelców. Gdy filozof chce je podnieść, najpierw sprawdza, czy są one dostępne, a jeśli tak, blokuje je (mutex). Kiedy kończy jedzenie, zwraca widelce, odblokowując mutexy.

- **Czekanie i yield**: Jeśli filozof nie może podnieść obu widelców, czeka (yield), co pozwala innym filozofom na wykonanie ich operacji.

