def Generator(Name, ID):

    character_list = [] #List of character in name
    Stud_len = len(ID) #Length of student ID

    counter = 1 #Set counter to 1 to avoid out of range error
    while counter <= Stud_len: #Iterate over the student ID, set column number according to brief
        digit = int(ID[Stud_len-counter])
        if digit >= 2 and digit <= 7:
            columns = digit
            break
        else:
            counter = counter + 1
            columns = 4 #Set columns to 4 if no acceptable int found

    for i in range(0, len(Name)):
        character_list.append(Name[i]) #Take entered string and split to list


    total_length = len(character_list) #Get length of character list

    while total_length % columns != 0: #While remainder of length/columns is not zero add plusses to end of character list
        character_list.append("+")
        total_length = len(character_list)

    counter = 0           
    while counter < total_length: #iterate over the character list, if asterisk or plus, dont change
        for i in range(columns):
            if character_list[counter] == "*" or character_list[counter] == "+":
                character_list.append(character_list[counter])
                counter = counter + 1
            else: #Get ascii value of char, add current column number and get new char, then append to the end of character list
                character = (character_list[counter])
                position = ord(character)-96
                column = i + 1
                asci = position+column+96
                if asci > 122: #If new ascii value is greater than ascii value of z, loop to start of alphabet
                    asci = asci - 26
                new_letter = chr(asci)
                character_list.append(new_letter)
                counter = counter + 1

    total_length = len(character_list) #update length of character list
    counter = 0
    while counter < total_length: #Iterate over every item in character list
        row_string = ""
        for i in range(columns): #Row length is the same as no. of columns
            row_string += character_list[counter] #Add chars to row sting
            counter = counter + 1
        print(row_string) #Print row string after it is the same length as no. of columns

if __name__ == "__main__": #Get full name and student ID, exit if user exits
    print("Type exit to exit")
    while True:
        full_name = input("Enter Full Name: ").replace(" ", "*")
        if full_name == "exit":
            exit()
        Stud_ID = input("Enter Student ID: ")
        if Stud_ID == "exit":
            exit()
        Generator(full_name, Stud_ID) #Call generator for grid output

