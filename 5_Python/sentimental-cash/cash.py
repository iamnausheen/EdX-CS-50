def main():

    # Prompt user for change
    c = -1
    while c < 0:
        try:
            c=float(input("Change: "))
            c=c*100
            print(c)
        except ValueError:
            print("Enter Numeric Value")

    # Calculate minimum number of coins greedily
    coins = 0
    if c >= 25:
        coins += int(c/25)
        c=(c%25)
    if c >= 10:
        coins += int(c/10)
        c=(c%10)
    if c>=5:
        coins += int(c/5)
        c=(c%5)
    if c >= 1:
        coins += int(c)
        c= (c%1)

    coins = int(coins)
    print(coins)

main()
