print(sum(ord(line[2]) - ord('X') + 1 + (ord(line[2]) - ord('X') - ord(line[0]) + ord('A') + 1) % 3 * 3 for line in open('input.txt')))

print(sum((ord(line[2]) - ord('X')) * 3 + (ord(line[2]) - ord('X') + ord(line[0]) - ord('A') + 2) % 3 + 1 for line in open('input.txt')))