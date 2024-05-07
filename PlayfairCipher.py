
import numpy as np

    

def ReadyWord():                    #funkcja przygotowujaca klucz do wrzucenia do macierzy
   
   plain2 =""                       #klucz ktory zostanie wrzucony do macierzy, na poczatku jest to pusty string

    
   plain = input("Enter an encrypting key: ")    #wprowadzenie przez uzytkownika klucza
   plain = str(plain)                               #zamiana na stringa na wszelki wypadek
   plain = plain.replace(" ", "")                   #usuniecie wszelkich spacji, zespawanie slow
   plain = plain.replace("j", "i")                  #wedlug schematu szyfru Playfaira powinno sie zastapic litery j na i
    
            
   for i in range (len(plain)):                     #petla przepisujaca pierwotny klucz do nowej zmiennej, tak aby zadna litera sie nie powtarzala
        if plain[i] not in plain2:
            plain2+=plain[i]      
   
   
   return plain2
               
   


def WordEnter():
    
    alphabet = "abcdefghiklmnopqrstuvwxyz"
    count = 0                       #licznik kontrolujacy czy nie przekroczono dlugosci wprowadzonego slowa
    matrix = []
    new_row=[]
    new_alphabet=""
    plain = ReadyWord()

    
    for i in range (5):             #stworzenie pustej macierzy 5x5
        for j in range (5):
            new_row.append('')
        matrix.append(new_row)      #dodanie wiersza (tablicy) do macierzy
        new_row=[]                  #nowy wiersz, uzupelniany pustymi stringami ""

    
    for i in range (len(alphabet)):
        if(alphabet[i] not in plain):
            new_alphabet+=str(alphabet[i])
            
    
    matrix_content = plain+new_alphabet

    
    for i in range (5):             # 5 wierszy macierzy      
       for j in range (5):          # 5-elementowy wiersz
            matrix[i][j] = matrix_content[count]
            count+=1         
    
    
    return matrix

    
    

def MessageReady():
    
    temp_matrix = WordEnter()
    temp_matrix=np.array(temp_matrix)
    secret_message=input("Write down your secret message: ")
    
    secret_message = secret_message.replace(" ", "")
    secret_message = secret_message.replace("j", "i")
    if(len(secret_message)%2!=0):
        secret_message=secret_message+"x"
    
    message_to_receive=""

    for i in range (0, len(secret_message), 2):
        pair1=secret_message[i]
        pair2=secret_message[i+1]
        
        
        positionPair1 = np.where(temp_matrix == pair1)
        positionPair2 = np.where(temp_matrix == pair2)

        
        if(positionPair1[1] == positionPair2[1]):   #czy litery sa w tej samej kolumnie?
            pair1 = temp_matrix[(positionPair1[0]+1) % 5, (positionPair1[1]) % 5].astype(str).item()
            pair2 = temp_matrix[(positionPair2[0]+1) % 5, (positionPair2[1]) % 5].astype(str).item()
        elif(positionPair1[0] == positionPair2[0]):
            pair1 = temp_matrix[(positionPair1[0]) % 5, (positionPair1[1]+1) % 5].astype(str).item()
            pair2 = temp_matrix[(positionPair2[0]) % 5, (positionPair2[1]+1) % 5].astype(str).item()
        else:
            pair1 = temp_matrix[(positionPair1[0]) % 5, (positionPair2[1]) % 5].astype(str).item()
            pair2 = temp_matrix[(positionPair2[0]) % 5, (positionPair1[1]) % 5].astype(str).item()
        
        
        message_to_receive+=pair1 +pair2
        
    return message_to_receive
    
if __name__ == "__main__":
    MessageReady()   
