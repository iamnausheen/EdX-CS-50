for _ in range(3):
    print("meow")

before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.upper(), end="")
print()

print(before.upper())
