import os

def gf(fn):
    f=open(fn)
    t=f.readlines()
    f.close()
    return "\n".join(t)

i=0
while 1:
    os.system("python gener.py>test")
    if os.system("./suffixalgo<test>suffixoutput"):
        print "SUFFIX ERROR"
        break
    if os.system("./brute<test>bruteoutput"):
        print "BRUTE ERROR"
        break
    if gf("bruteoutput")!=gf("suffixoutput"):
        print "FAIL"
        break
    else:
        i+=1
        print "OK", i

