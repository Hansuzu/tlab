import random

m="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
m="qwertyuiopasdfghjklzxcvbnm"

def rm():
    global m
    return m[random.randint(0, len(m)-1)]

s=""
for i in range(int(16e6)):
    s+=rm()
print s
