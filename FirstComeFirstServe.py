import random

def generator(process_quantity):                                               #generator danych losowych
    arrival_time = [random.randint(0, 100) for _ in range(process_quantity)]    #losowy czas przyjscia - po jakim czasie proces jest gotowy do wykonywania, jest juz w kolejce gotowosci
    arrival_time.sort()
    burst_times = [random.randint(5, 5) for _ in range(process_quantity)]     #losowy czas wykonania - ilosc czasu jaka potrzebuje dany proces aby zakonczyc swoje wykonanie, od momentu przydzielenia do CPU do momentu zakonczenia
    return arrival_time, burst_times

def FCFS(quantity, arrival_times, burst_time):                         #funkcja wykonujaca algorytm First Come First Serve
    n = quantity                                                      #zmienna pomocnicza n trzymajaca ilosc procesow
    wait_time = [0] * n                                         #waiting time - calkowita ilosc czasu czekania w "kolejce gotowosci", zanim zostanie przydzielony co CPU
    turnaround_time = [0] * n                                   #Turnaround time - calkowity czas jaki uplywa od pojawienia sie procesu w kolejce do momentu zakonczenia jego wykonywania - jego cykl zycia

    time = 0                                                    #biezacy czas symulacji, czas ktory minal - przyjmujemy ze jednostki to takty procesora
    #ready_queue =[]                                             #kolejka gotowosci - tu przetrzymywane sa indeksy procesow
    for i in range(n):
        while(arrival_times[i] > time):                         #jeœli jeszcze zaden proces nie nadszedl to dodaj do czasu trwania symulacji
            time+=1
            
        #ready_queue.append(i)                                   
    
                                                         
        wait_time[i] = time - arrival_times[i]           #czas oczekiwania w kolejce zanim proeces zacznie byc obslugiwany
    
        turnaround_time[i] = wait_time[i] + burst_time[i]           #obliczenie czasu cyklu zycia procesu
        time += burst_time[i]                                       #mija czas potrzebny na wykonanie procesu

    print("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time")       #wyprintowanie po kolei numeru procesu, czas przyjscia, potrzebny czas wykonania, czas oczekiwania w kolejce
    for i in range(n):
        print(f"P{[i+1]}\t\t{arrival_time[i]}\t\t{burst_time[i]}\t\t{wait_time[i]}\t\t{turnaround_time[i]}")

    avg_wait_time = sum(wait_time)/n                            #sredni czas czekania w kolejce 
    avg_turnaround_time = sum(turnaround_time)/n                #sredni czas od momentu pojawienia sie w kolejce do pelnego wykonania procesu
    avg_burst_time = sum(burst_time)/n                          #sredni czas potrzebny do wykonania jednego procesu                      
    
    print("\nAverage Wait Time:", avg_wait_time)                #wyswietlenie srednich czasow
    print("Average Turnaround Time:", avg_turnaround_time)
    print("Avarage Burst Time:", avg_burst_time)
    

# Generuj losowe dane dla x procesów
process_quantity = input("Number of processes: ")                                           #liczba procesow
arrival_time, burst_times = generator(int(process_quantity))         #do zmiennych przypisywane sa wygenerowane losowo czasy przybycia i czasy wykonania

# Wyswietl wygenerowane dane
print("---------RESULT----------")
print("Arrival Times:", arrival_time)
print("Burst Times:", burst_times)

# Wywolaj algorytm FCFS z wygenerowanymi danymi
FCFS(int(process_quantity), arrival_time, burst_times)  #argumenty:ilosc procesow, losowe czasy przybycia, losowe czasy wykonania
