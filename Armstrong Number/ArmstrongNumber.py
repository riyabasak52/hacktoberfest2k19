number, new_number  = input("Enter a number to check if it is an Armstrong Number: "), 0
for i in number:
    new_number += int(i) ** 3
if number == new_number:
    print("The number is an Armstrong number")
else:
    print("It is not an Armstrong Number")