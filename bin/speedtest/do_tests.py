import os


koot=[100000, 200000, 300000, 400000, 50000, 750000, 1000000, 2500000, 5000000, 7500000, 10000000, 15000000, 20000000]
koot_az=koot
koot_azAZ=koot[:11]
koot_asxii=koot[:9]

def gf(fn):
    f=open(fn, "r")
    t=f.readlines()
    f.close()
    return t

def gener(koko, nimi):
    os.system("python gener.py SZ="+str(koko)+" "+nimi+">test")

def test_program(nimi):
    cmd="/usr/bin/time -o tout -f%e "+nimi+" < test"
    os.system(cmd)
    data=gf("tout")
    time=float(data[0][:-1])
    return time

def test(koko, nimi):
    gener(koko, nimi)
    return test_program("./speedtest"), test_program("./speedtest_old")


def test_alphabet(numbers, name):
    tulos_={}
    tulos_old={}
    for i in numbers:
        print name, i
        t, a=test(i, "az")
        tulos[i]=t
        tulos_old[i]=a
    return tulos, tulos_old

tulos_az, tulos_az_old=test_alphabet(koot_az, "az")
print tulos_az
print tulos_az_old
tulos_azAZ, tulos_azAZ_old=test_alphabet(koot_azAZ, "azAZ")
print tulos_azAZ
print tulos_azAZ_old
tulos_ascii, tulos_ascii_old=test_alphabet(koot_az, "ascii")
print tulos_ascii
print tulos_acii_old
