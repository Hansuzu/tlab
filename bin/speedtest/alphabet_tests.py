#coding: utf-8
import matplotlib.pyplot as plt
import os
import random

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

def test(koko, maksimi, program):
    gener(koko, maksimi)
    return test_program(program)

x=[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216]
y=[[0.14, 0.94, 1.27, 1.37, 1.32, 1.36, 1.28, 1.16, 1.18, 1.77, 2.76, 3.46, 4.57, 8.21], [0.23, 1.79, 2.24, 2.38, 2.35, 2.99, 2.4, 3.44, 2.19, 2.71, 3.26, 3.16, 2.99, 4.4, 3.0, 2.48, 2.96, 3.25, 4.11, 3.92, 4.04, 4.36, 4.59, 4.63, 4.88], [0.14, 1.2, 1.6, 2.33, 2.77, 3.16, 3.27, 3.72, 3.64, 3.53, 5.0, 4.96, 4.43, 4.59, 4.15, 5.48, 3.55, 3.58, 4.66, 5.78, 3.72, 4.19, 3.78, 3.64, 3.64], [0.14, 0.91, 1.34, 1.62, 1.54, 1.4, 1.52, 1.52, 1.25, 1.5, 2.36, 2.76, 2.31, 1.9, 1.73, 1.96, 3.63, 11.19], [0.13, 0.93, 1.23, 1.13, 1.2, 1.32, 1.45, 1.8, 3.15]]



def program_name(index):
    if index==0: return "./speedtest"
    if index==1: return "./speedtest_fastset"
    if index==2: return "./speedtest_stdset"
    if index==3: return "./speedtest_ordered_vector"
    if index==4: return "./speedtest_array"

def test_all(times):
    global x, y
    alphabet_size=1
    x=[]
    y=[[], [], [], [], []]
    results=[{}, {}, {}, {}, {}]
    tests=[]
    while alphabet_size<MAX:
        x.append(alphabet_size)
        y[1].append(0)
        y[2].append(0)
        if alphabet_size<10000: y[0].append(0)
        if alphabet_size<500: y[4].append(0)
        if alphabet_size<200000: y[3].append(0)

        for i in range(times):
            tests.append((1, alphabet_size))
            tests.append((2, alphabet_size))
            if alphabet_size<10000:
                tests.append((0, alphabet_size))
            if alphabet_size<500:
                tests.append((4, alphabet_size))
            if alphabet_size<200000:
                tests.append((3, alphabet_size))
        alphabet_size*=2

    random.shuffle(tests) #Run tests in random order
    print "START TESTING."
    for i in range(len(tests)):
        print "TEST ", i, "/", len(tests)
        program_id=tests[i][0] 
        asz=tests[i][1]
        if not asz in results[program_id]: results[program_id][asz]=[]
        results[program_id][asz].append(test(2000000, asz, program_name(program_id)))

    for program_id in range(5):
        for alphabet_size in results[program_id]:
            result=sum(results[program_id][alphabet_size])/times
            y[program_id][x.index(alphabet_size)]=result

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
test_all(10)
plot()
print x
print y
