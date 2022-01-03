from subprocess import Popen, PIPE

a = 0
b = 1
while a < 2 ** 63:
    if a in [0, 1]:
        print(f"{a}: [],")
    else:
        proc = Popen(["factor", str(a)], stdout=PIPE)
        stdout, _ = proc.communicate()
        print(f"{a}: {[int(x) for x in stdout.decode('utf-8').split()[1:]]},")
    t = a
    a = b
    b += t
