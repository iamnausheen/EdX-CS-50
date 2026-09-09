def main():
    # Prompt user for height
    h = -1
    while h <= 0 or h>8:
        try:
            h = int(input("Height: "))
        except ValueError:
            print("Enter a numeric value")

    # Print pyramid
    for i in range(h):
        for k in range(h-i, 1, -1):
            print(" ", end="")
        for j in range(i+1):
            print("#", end="")
        print()
main()
