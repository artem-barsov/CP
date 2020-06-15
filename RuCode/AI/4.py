class Gruppe:
    def __init__(self, count, time):
        self.count = count
        self.time = time

def inside(gr):
    return gr.count**2 * gr.time

def between(gr1, gr2):
    return 2 * gr1.count * gr2.count

def total(a, p, t):
    return inside(a)+inside(p)+inside(t)+between(a, p)+between(p, t)+between(a, t)

a = Gruppe(20, 3)
p = Gruppe(20, 4)
t = Gruppe(20, 7)

print(total(a, p, t))
