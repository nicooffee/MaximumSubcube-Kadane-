from random import randint
N=5
for a in range(2,6):
    F=open("./ar"+str(a)+".txt","w")
    F.write(str(a)+"\n")
    for i in range(a):
        for j in range(a):
            for k in range(a):
                F.write(str(randint(-N,N))+" ")
            print("", file=F)
    F.close()    