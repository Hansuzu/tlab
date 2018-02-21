import random

m="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
m="qwertyuiopasdfghjklzxcvbnm"

SZ=10000
T=1000
MXT=100


MXT=min(MXT, SZ)

def rm():
    global m
    return m[random.randint(0, len(m)-1)]

s=""
for i in range(SZ):
    s+=rm()

print s
print T

for i in range(T):
    z=random.randint(1, MXT)
    p=random.randint(0, len(s)-z)
    ss=s[p:(p+z)]
    ch=random.randint(0, 3)
    for i in range(ch):
        j=random.randint(0, len(ss)-1)
        ss=ss[:j]+rm()+ss[(j+1):]
    print ss

