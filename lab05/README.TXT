Gdyby po uruchomieniu zmieniły się kolorki terminala, wpisujemy polecenie
"reset" do przywrócenia standardowych ustawień terminala.

W kodzie jest gdzieś błąd powodujący crash przy niektórych sytuacjach przy wpisaniu "quit". Nie mam siły szukać.
Plusik, jak ktoś znajdzie.

CEL: najpierw zadanie początkowe (implementacja zegarów Lamporta) potem główne (implementacja detekcji stanu globalnego)

Kompilacja:

1. make clear; make (make clear usuwa poprzednie pliki wykonywalne i obiektowe)

Zadaniem początkowym do wykonania jest wprowadzenie zegarów Lamporta:

1. Dodać zmienną globalną reprezentującą zegar skalarny Lamporta ("globalną" w sensie języka C; faktycznie jest to zegar lokalny
                                                                   dla każdego procesu)

2. Zmodyfikować makra println (w main.h), by wyświetlały zegar Lamporta 

3. Zwiększanie zegara przy sendPacket (w init.c) oraz max(bieżący, pakiet)+1 przy odbieraniu (w wątku komunikacyjnym comFunc w main.c)

4. MPI_Send oraz MPI_Recv są wywoływane przez różne wątki, więc dostępy do zmiennej
    reprezentującej zegar lamporta należy chronić muteksem (np. nowym albo już istniejącym)

Modyfikowanie typu pakietu:

1. w main.h szukamy struct packet_t i dodajemy pole np. int nowe_pole; zwiększamy FIELDNO

2. w init.c szukamy funkcji inicjuj i tam zamieniamy dodajemy typ pola do MPI_Datatype typy[3] = {MPI_INT, MPI_INT, MPI_INT), wyliczamy offset dla nowego pola

3. make clear; make

Drugim zadaniem jest implementacja algorytmu detekcji spójnego stanu globalnego. Może być chamski stop-record-resume albo 
jeden z dwóch poznanych na wykładzie (Lamporta lub Lai-Yanga)

Można wpisywać polecania z klawiatury. Ich spis można sobie obejrzeć w kodzie monitor.c
w szczególności, "state" powoduje, że monitor wysyła do wszystkich prośbę o podanie bieżącego stanu
