import random

m="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
m="qwertyuiopasdfghjklzxcvbnm"

SZ=random.randint(1, 100)
T=1000000
MXT=50


MXT=min(MXT, SZ)

def rm():
    global m
    return m[random.randint(0, len(m)-1)]

def rms(l):
    a=""
    for i in range(l):
        a+=rm()
    return a

s=rms(SZ)

print s
print T

for i in range(T):
    z=random.randint(1, MXT)
    p=random.randint(0, len(s)-z)
    t=random.randint(0, 3)
    if t==0:
        ss=s[p:(p+z)]
        ch=random.randint(0, 3)
        for i in range(ch):
            t=random.randint(0, 3)
            if t==0 and len(ss)>1:
                j=random.randint(0, len(ss))
                ss=ss[:j]+ss[(j+1):]    
            elif t==1:
                j=random.randint(0, len(ss))
                ss=ss[:j]+rm()+ss[j:]
            else:
                j=random.randint(0, len(ss)-1)
                ss=ss[:j]+rm()+ss[(j+1):]
    elif t==1:
        ss=s[p:(p+z)]
    else:
        ss=rms(z)
            
    print ss

