word_dict = {
    "1second": "time",
    "2seconds": "time",
    "5seconds": "time",
    "unlimited": "time",
    "left": "move",
    "right": "move",
    "forwards": "move",
    "backwards": "move",
    "light": "weight",
    "medium": "weight",
    "heavy": "weight",
    "recognise": "action",
    "eat": "action", 
    "see": "action",
    "lift": "action",
    "roomA": "room",
    "roomB": "room",
    "kitchen": "room",
    "bedroom": "room",
    "car": "object",
    "bus": "object",
    "apple": "object",
    "boat": "object"
}


instructions = str.split(input("Please enter the instructions: ")) # Split the instructions inputted on whitespace and convert to a list of values.
type_list = []

# determines the type of instructions inputted.
for instruction in instructions:
    type = word_dict[instruction]
    type_list.append(type)

correct_forms = [['time', 'action', 'object'], 
                ['action', 'room', 'object'], 
                ['time', 'move'], 
                ['time', 'move', 'time', 'move'], 
                ['object', 'weight', 'action']]

for form in correct_forms:
    counter = 1
    incorrect_positions = []
    for i in range(len(form)):
        if type_list[i] == list[i]:
            counter = counter + 1
            if counter == len(form):
                print("correct")
                break
        else:
            incorrect_positions.append(i)


# def Get_corrections():
#     for list in form:

