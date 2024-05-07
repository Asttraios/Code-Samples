from collections import deque
import random

def user_decision(page_number):
    
    data_string=[]

    for _ in range(page_number):
        user_input=input()
        data_string.append(user_input)
    return data_string

def generator(pages_number):                                               #generator danych losowych
    data_string = [random.randint(0, 5) for _ in range(pages_number)]    #losowy czas przyjscia - po jakim czasie proces jest gotowy do wykonywania, jest juz w kolejce gotowosci
    return data_string


def FIFO(page_list, frame_capacity):
    
    frame = deque()
    hit = 0
    fault = 0

    for i in range(len(page_list)):
        if page_list[i] in frame:
            hit+=1
        else:
            fault+=1
            if len(frame)==frame_capacity:
                frame.popleft()
                frame.append(data_string[i])
            else:
                frame.append(data_string[i])
    return hit, fault 


frame_size = 3

page_quantity = int(input("Number of pages: "))

#data_string = user_decision(page_quantity)
data_string = generator(page_quantity)

hit_number, fault_number = FIFO(data_string, frame_size)

print("Number of hits: ", hit_number)
print("Number of faults: ", fault_number)

