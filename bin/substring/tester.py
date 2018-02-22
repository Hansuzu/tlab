import os
TESTS=["suffixalgo", "suffixalgo_stdset", "suffixalgo_fastset"]

def gf(fn):
    f=open(fn)
    t=f.readlines()
    f.close()
    return "\n".join(t)


print "TESTING:", TESTS
i=0
while 1:
    if os.system("python gener.py>test"):
        print "GENER ERROR"
        break
    if os.system("./brute<test>bruteoutput"):
        print "BRUTE ERROR"
        break
    ok=1
    for TEST in TESTS:
        if os.system("./"+TEST+"<test>suffixoutput"):
            print "ERROR", TEST
            ok=0
            break
        if gf("bruteoutput")!=gf("suffixoutput"):
            print "FAIL", TEST
            ok=0
            break
    if not ok:
        break
    else:
        i+=1
        print "OK", i

