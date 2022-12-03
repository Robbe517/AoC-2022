print(sum((lambda x: x - ord('a') + 1 if x > ord('Z') else x - ord('A') + 27)(ord(next(iter(set(l[:len(l)//2]) & set(l[len(l)//2:]))))) for l in open('input.txt')))

print(sum((lambda x: x - ord('a') + 1 if x > ord('Z') else x - ord('A') + 27)(ord(next(iter(set(l1) & set(l2) & set(l3))))) for l1, l2, l3 in (lambda x: zip(x[::3], x[1::3], x[2::3]))(open('input.txt').read().split())))