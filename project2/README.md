# Prosty Czat TCP w Pythonie (wersja lokalna)

##  Opis projektu

To prosty czat działający lokalnie na jednym komputerze. Komunikacja odbywa się przez protokół TCP z wykorzystaniem gniazd (`socket`) i wątków (`threading`). Serwer obsługuje wielu klientów, umożliwiając im przesyłanie wiadomości tekstowych między sobą.



##  Instrukcja uruchomienia

###  Wymagania

- Python 3.x



### Uruchamianie serwera i klientów

1. **Uruchom serwer** w jednym terminalu:

   ```bash
   python3 server.py
   ```

   Serwer będzie nasłuchiwał na `127.0.0.1` (localhost), czyli tylko lokalnie.

2. **Uruchom klienta** w drugim terminalu (na tym samym komputerze):

   ```bash
   python3 client.py
   ```

3. Można uruchomić wiele klientów w osobnych terminalach, każdy połączy się z serwerem lokalnie.



## Funkcje

- Obsługa wielu klientów (na jednym komputerze)
- Każdy klient wysyła wiadomości, które trafiają do wszystkich pozostałych



##  Obsługa wielu klientów

Serwer tworzy nowy wątek dla każdego podłączającego się klienta, dzięki czemu obsługuje wielu użytkowników jednocześnie.

## Sekcje krytyczne i rozwiązanie
Lista klientów (clients) jest współdzielona między wątkami. Aby zapobiec problemom z jednoczesnym dostępem, została zabezpieczona za pomocą threading.Lock.


##  Uwagi

Wersja ta działa **tylko lokalnie**. Klient i serwer muszą działać na tym samym komputerze.



