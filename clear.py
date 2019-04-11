import os
print("clear")
f=open("dir.txt")
x=f.readlines()
arr=[]
for i in x:
    if ".m" in i:
        arr.append(i)
f.close()
f = open("d:/data structure/jo/dir.txt", "w")
print(arr)
for i in arr:
    f.write(i)
f.close()
print("[2]done...")