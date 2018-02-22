#coding: utf-8
import matplotlib.pyplot as plt
import os

MAX=(1<<25)


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

def test(koko, maksimi, program, times):
    s=0
    for i in range(times): 
        gener(koko, maksimi)
        s+=test_program(program)
    return s/times

x=[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384]
y=[[0.14, 0.91, 1.27, 1.34, 1.29, 1.22, 1.26, 1.21, 1.13, 1.69, 2.6, 4.1, 4.87, 7.48, 12.69], [0.15, 1.55, 1.81, 2.08, 2.03, 2.03, 2.13, 2.3, 1.92, 2.4, 2.65, 3.43, 3.45, 2.64, 2.18], [0.15, 1.21, 1.59, 2.1, 2.67, 3.08, 3.05, 3.97, 3.19, 3.23, 4.04, 4.76, 4.77, 3.67, 3.84], [0.14, 0.94, 1.3, 1.42, 1.38, 1.34, 1.33, 1.56, 1.23, 1.46, 2.44, 3.09, 2.49, 1.76, 1.74], [0.13, 0.86, 0.96, 1.03, 1.12, 1.28, 1.39, 1.7, 2.17]]


def test_all(times):
    global x, y
    alphabet_size=1
    x=[]
    y=[[], [], [], [], []]

    while alphabet_size<MAX:
        print "TESTING:", alphabet_size
        x.append(alphabet_size)
        y[1].append(test(2000000, alphabet_size, "./speedtest_fastset", times))
        y[2].append(test(2000000, alphabet_size, "./speedtest_stdset", times))
        if alphabet_size<10000:
            y[0].append(test(2000000, alphabet_size, "./speedtest", times))
        if alphabet_size<500:
            y[4].append(test(2000000, alphabet_size, "./speedtest_array", times))
        if alphabet_size<200000:
            y[3].append(test(2000000, alphabet_size, "./speedtest_binary_search", times))
        alphabet_size*=2

def plot():
    global x, y
    plt.plot(x[:len(y[0])], y[0], "r", x[:len(y[1])], y[1], "b", x[:len(y[2])], y[2], "g", x[:len(y[3])], y[3], "c", x[:len(y[4])], y[4], "m")
    plt.xscale('log')
    plt.title("Merkkijonon pituus 2000000")
    plt.xlabel("Aakkoston koko")
    plt.ylabel("Aika (s)")
    plt.ylim(0, 5)
    plt.savefig("alphabet.png")
    plt.show()
test_all(5)
plot()
