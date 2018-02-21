import random
import sys

azAZ="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
az="qwertyuiopasdfghjklzxcvbnm"
ascii="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890.,;:\\-*?+()[]}{/&%#$'<>\"!@^_`|~"

m=az
SZ=int(8e6)

args=sys.argv[1:]
for i in args:
    if i=="azAZ":
        m=azAZ
    elif i=="az":
        m=az
    elif i=="ascii":
        m=ascii
    elif i[:3]=="SZ=":
        t=i[3:]
        try:
            SZ=int(t)
        except Exception:
            print "LOL, HUONO NUMERO", t


def rm():
    global m
    return m[random.randint(0, len(m)-1)]




s=""
for i in range(SZ):
    s+=rm()

print s
