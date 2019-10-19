import random
def hangman():
    #opened_file = open('movies.txt','r')
    movie=["The Avengers","Captain America: Civil War","Aquaman","Thor","Madagascar","Ice Age","Real Steel","Joker"]
    #read_file = read(opened_file)
    #movie = list(opened_file)
    turns=10
    guesses=[]
    for i in range(turns,0,-1):
        n=random.randint(0,len(movie)-1)
        letter= input("Enter your guess \n")
        if letter not in guesses:
            guesses.append(letter)
            x=movie[n]
            x.replace(" ","")
            if letter in x:
                x.replace(letter,'')
                print("Correct guess")
                i+=1
                print("Turns left: ",i)
                if x=='':
                    print("Congratulations!!!!")
                    break
        else:
            print("Wrong guess")
            print("Turns left: ",i)
            continue
    return 
        
hangman()
print("While you may or may not have won in the game, you will always be a loser in life")
        

        
