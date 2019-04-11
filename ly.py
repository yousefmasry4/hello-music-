from youtube_transcript_api import YouTubeTranscriptApi
import urllib.request
import urllib.parse
import re
import sys
import json
xname=""
name=""
counter=1
while(True):
    f=open("D:\data structure\jo\sn.txt")
    x=f.readlines()
    xname=x[0]
    f.close()
    print(xname)
    if(xname != name):
        flag=1
        name=xname
        print("[*]data",name)
        temp=""
        for i in name:
            if(i == "."):
                break
            temp+=i
        name=temp
    else:
        flag=0
    print(name)
    if(flag):
        query_string = urllib.parse.urlencode({"search_query" : name})
        html_content = urllib.request.urlopen("http://www.youtube.com/results?" + query_string)
        search_results = re.findall(r'href=\"\/watch\?v=(.{11})', html_content.read().decode())
        i=0
    while (flag) :
        try:
            data=YouTubeTranscriptApi.get_transcript(search_results[i],["en","Ar"])
            print(data)
            break
        except:
            i+=1
            print(i)
            if i == 40:
                fa=open("D:\data structure\jo\lytemp.txt","w+", encoding='utf-8')
                fa.write(str(0))
                fa.close()
                break
    if(flag):
        noin=0
        f=open("D:\data structure\jo\ly.txt","w")
        f.write("")
        f.close()
        f=open("D:\data structure\jo\lytemp.txt","w+", encoding='utf-8')
        while(True):
            try:
              #  print("[++]data")
                f.write((data[noin]["text"]).replace('\n', '')+"\n")
                f.write((str(data[noin]["start"]))+"\n")
                f.write((str(data[noin]["duration"]))+"\n")
                noin+=1
            except:
                f.close()
                break
