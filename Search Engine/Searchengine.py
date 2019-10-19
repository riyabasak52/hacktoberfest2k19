from bs4 import BeautifulSoup
import urllib.request
def websites():#defining function to access the website link of mentioned word
    fp=open("web.txt","r")
    a=fp.read().split("\n")
    urls=[]
    for i in a:
        urls.append("https://www."+i)
        #print(url)
    fp.close()
    return urls

word=input("Enter the search word")#word inputted here
#word=words.split()
density={}
c=[]
def webaccess():#defining a function to access the website
    t=""
    url=[]
    rank={}
    url=websites()
    for i in url:
        print(i)
        req=urllib.request.Request(i)
        t=(urllib.request.urlopen(req)).read().decode('utf-8')
        soup=BeautifulSoup(t,"html.parser")
        for script in soup(["script","style"]):
            script.extract()
        text=soup.get_text()
        #print(text)
        #lines=(line.strip() for line in text.splitlines())
        temp=text.split()
        #print(temp)
        for x in word:
            count=0
            for y in temp:
                if y not in density:
                    count=count+1
                    density.update({y:count})
                    #print("Not Found ",y,count)
                else:
                    count=density[y]
                    count=count+1
                    density.update({y:count})
                    #print("Found ",y,count)
                    
        if word in density:
            print(density[word])
            for i in range(0,len(url)):
                rank.update({url[i]:(density[word]/len(text)*100)})
            sorted_by_value = sorted(rank.items(), key=lambda kv: kv[1])
            print(sorted_by_value)
               
webaccess()
