#written by divyam
print("Enter 'x' for exit.")
print("enter 1 to generate 2 to check")
p=input()
if p== 'x':
    exit();
elif int(p)==1:
	print("Enter the interval (starting and ending number): ")
	start = int(input())
	end = int(input())
	for num in range(start, end+1):
		tot = 0;
		temp = num
		while temp != 0:
			dig = temp % 10
			tot += dig ** 3
			temp //= 10;
		if num == tot:
			print(num)
elif int(p)==2:
	num = int(input("Enter a number: "))
	sum = 0
	temp = num
	while temp > 0:
	   digit = temp % 10
	   sum += digit ** 3
	   temp //= 10
	if num == sum:
   		print(num,"is an Armstrong number")
	else:
   		print(num,"is not an Armstrong number")
else:
	exit()
