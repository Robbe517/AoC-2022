print(max(sum(int(i) for i in elf.split()) for elf in open('input.txt').read().split('\n\n')))

print(sum(sorted(sum(int(i) for i in elf.split()) for elf in open('input.txt').read().split('\n\n'))[-3:]))