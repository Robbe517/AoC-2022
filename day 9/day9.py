h = [0, 0]
s = [0, 0]
positions = {tuple(s)}

for r in open("input", "r"):
    for _ in range(int(r.strip().split()[-1])):
        if r[0] == "U": h[0] += 1
        if r[0] == "D": h[0] -= 1
        if r[0] == "R": h[1] += 1
        if r[0] == "L": h[1] -= 1
        if max(abs(hi - si) for hi, si in zip(h, s)) > 1:
            s = [si + ((hi > si) * 2 - 1)*(hi != si) for hi, si in zip(h, s)]
            positions.add(tuple(s))

print(len(positions))

t = [[0, 0] for _ in range(10)]
positions = {tuple(t[-1])}

for r in open("input", "r"):
    for _ in range(int(r.strip().split()[-1])):
        if r[0] == "U": t[0][0] += 1
        if r[0] == "D": t[0][0] -= 1
        if r[0] == "R": t[0][1] += 1
        if r[0] == "L": t[0][1] -= 1
        for h, s in zip(t[:-1], t[1:]):
            if max(abs(hi - si) for hi, si in zip(h, s)) > 1:
                s[0] += ((h[0] > s[0]) * 2 - 1)*(h[0] != s[0])
                s[1] += ((h[1] > s[1]) * 2 - 1)*(h[1] != s[1])
        positions.add(tuple(t[-1]))

print(len(positions))