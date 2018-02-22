import os


koot=[50000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000, 2500000, 5000000, 7500000, 10000000, 15000000]
koot_d={4: koot[:10], 8: koot[:10], 16: koot[:10], 32: koot[:10], 64: koot[:10], 128: koot[:9], 256: koot[:8], 512: koot[:8]}

def gf(fn):
    f=open(fn, "r")
    t=f.readlines()
    f.close()
    return t

def gener(koko, maksimi):
    os.system("./gener Z"+str(koko)+" X"+str(maksimi)+" > test")

def test_program(nimi):
    cmd="/usr/bin/time -o tout -f%e "+nimi+" < test"
    os.system(cmd)
    data=gf("tout")
    time=float(data[0][:-1])
    return time

def test(koko, maksimi):
    gener(koko, maksimi)
    return test_program("./speedtest"), test_program("./speedtest_old")


def test_alphabet(numbers, maksimi):
    TESTS=1

    tulos={}
    tulos_old={}
    for i in numbers:
        print "TESTING STRING LENGTH:", i
        T=0
        A=0
        for j in range(TESTS):
            t, a=test(i, maksimi)
            T+=t
            A+=a
        T/=TESTS
        A/=TESTS
        tulos[i]=T
        tulos_old[i]=A
    return tulos, tulos_old

tulokset={}
for i in koot_d:
    print "TESTING ALPHABETSIZE", i
    tulos, tulos_old=test_alphabet(koot_d[i], i)
    tulokset[i]=[tulos, tulos_old]
print "results =", tulokset




