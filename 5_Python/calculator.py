# Concatenated string
a = input("a: ")
b = input("b: ")
print(a+b)

# Addition
x = int(input("x: "))
y = int(input("y: "))
print(x + y)

# How to Adjust for when user doesn't enter an int
import cs50
m = cs50.get_int("m: ")
n = cs50.get_int("n: ")
print(m + n)

# TRUNCATION
c = int(input("x: "))
d = int(input("y: "))

e = c/d
print(f"{e:.3f}")
