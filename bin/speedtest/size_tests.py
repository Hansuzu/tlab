import os
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import random

ALPHABET_SIZE=128
TESTS=[10, 100, 1000, 10000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000, 2000000, 4000000, 6000000, 8000000]

x=[10, 100, 1000, 10000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000, 2500000, 5000000, 7500000, 10000000]
y=[[0.0, 0.0, 0.0, 0.0, 0.030000000000000006, 0.07000000000000002, 0.11600000000000002, 0.16199999999999998, 0.21800000000000003, 0.38100000000000006, 0.48599999999999993, 1.539, 3.6449999999999996, 6.148999999999999, 8.709], [0.0, 0.0, 0.0, 0.0, 0.07000000000000002, 0.147, 0.23000000000000004, 0.315, 0.403, 0.651, 0.908, 2.809, 6.174000000000001, 10.520999999999999], [0.0, 0.0, 0.0, 0.0, 0.07999999999999999, 0.17899999999999996, 0.30399999999999994, 0.461, 0.625, 1.0479999999999998, 1.504, 4.837, 11.081], [0.0, 0.0, 0.0, 0.0, 0.039999999999999994, 0.08999999999999998, 0.15, 0.19299999999999998, 0.254, 0.42400000000000004, 0.598, 1.886, 4.1049999999999995, 6.609999999999999], [0.0, 0.0, 0.0, 0.001, 0.07000000000000002, 0.14300000000000002, 0.23199999999999998, 0.2800000000000001, 0.361, 0.554, 0.8019999999999999, 2.168]]


def get_arrays(d):
    a=[(k, v) for k, v in d.iteritems()]
    a.sort()
    return [i[0] for i in a], [i[1] for i in a]


def plot_dicts(a, b, xtitle, ytitle, title, filename):
    ak, av=get_arrays(a)
    bk, bv=get_arrays(b)
    plt.plot(ak, av, "r", bk, bv, "b")
    plt.savefig(filename)
    plt.show()


def gf(fn):
    f=open(fn, "r")
    t=f.readlines()
    f.close()
    return t

def gener(size, alphabet_size):
    os.system("./gener Z"+str(size)+" X"+str(alphabet_size)+" > test")

def test_program(nimi):
    cmd="/usr/bin/time -o tout -f%e "+nimi+" < test"
    os.system(cmd)
    data=gf("tout")
    time=float(data[0][:-1])
    return time

def test(size, alphabet_size, program):
    gener(size, alphabet_size)
    return test_program(program)

def program_name(index):
    if index==0: return "./speedtest"
    if index==1: return "./speedtest_fastset"
    if index==2: return "./speedtest_stdset"
    if index==3: return "./speedtest_ordered_vector"
    if index==4: return "./speedtest_array"


def test_all(times):
    global x, y
    global ALPHABET_SIZE, TESTS

    alphabet_size=1
    x=[]
    y=[[], [], [], [], []]
    results=[{}, {}, {}, {}, {}]
    tests=[]
    for SZ in TESTS:
        x.append(SZ)
        if SZ<15000000:y[0].append(0)
        if SZ<8000000:y[1].append(0)
        if SZ<7000000:y[2].append(0)
        if SZ<10000000:y[3].append(0)
        if SZ<6000001: y[4].append(0)

        for i in range(times):
            if SZ<15000000:tests.append((0, SZ))
            if SZ<8000000:tests.append((1, SZ))
            if SZ<7000000: tests.append((2, SZ))
            if SZ<10000000:tests.append((3, SZ))
            if SZ<6000001: tests.append((4, SZ))

    random.shuffle(tests) #Run tests in random order
    print "START TESTING."
    for i in range(len(tests)):
        program_id=tests[i][0] 
        SZ=tests[i][1]
        print "TEST ", i, "/", len(tests), program_name(program_id), SZ
        if not SZ in results[program_id]: results[program_id][SZ]=[]
        test_result=test(SZ, ALPHABET_SIZE, program_name(program_id))
        results[program_id][SZ].append(test_result)
        print test_result

    for program_id in range(5):
        for SZ in results[program_id]:
            result=sum(results[program_id][SZ])/times
            y[program_id][x.index(SZ)]=result



def plot():
    global x, y
    fig, ax=plt.subplots()
    ax.plot(x[:len(y[0])], y[0], "r", x[:len(y[1])], y[1], "b", x[:len(y[2])], y[2], "g", x[:len(y[3])], y[3], "c", x[:len(y[4])], y[4], "m")
    plt.title("Aakkoston koko 128")
    plt.xlabel("Merkkijonon pituus")
    plt.ylabel("Aika (s)")
    plt.ylim(0, 6.5)
    plt.xlim(0, 8.0e6)
    ax.xaxis.set_major_formatter(ticker.FormatStrFormatter('%0.e'))

    plt.savefig("stringlength.png")
    plt.show()

test_all(10)
plot()
print x
print y
