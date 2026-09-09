def main():
    height = -1
    while height <=0 or height > 8:
        try:
            height = int(input("Height: "))
        except ValueError:
            print("Enter Numeric Value")

    for i in range(height):

        # Left spaces
        for j in range(height-i, 1, -1):
            print(" ", end="")

        # Right aligned pyramid
        for k in range(i+1):
            print("#", end="")

        print("  ", end="")

        for l in range(i+1):
            print("#", end="")

        print()
main()
