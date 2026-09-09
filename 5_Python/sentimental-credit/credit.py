def checksum(num):
    d = int(num%10)
    sum = 0
    flag = 0

    while num:
        if int(flag%2) == 0:
            sum+=d
        else:
            x = 2*d
            if x > 9:
                ones = int(x%10)
                tens = int(x/10)
                sum += ones + tens
            else:
                sum += x

        num = int(num/10)
        d = int(num%10)
        flag += 1

    if int(sum%10) != 0:
        return True
    else:
        return False

def Digits(num):
    count = 0
    while num:
        count+=1
        num=int(num/10)
    return count

def main():
    num = -1
    while num <=0:
        try:
            num = int(input("Number: "))
        except ValueError:
            print("Invalid")

    digits = Digits(num)

    # Invalid Conditions
    if digits != 13 and digits != 15 and digits != 16:
        print("INVALID")
        return
    if (not(checksum(num))):
        print("INVALID")
        return

    # TYPE OF CARD

    initial_digits = int(num/pow(10, (digits-2)))
    if digits == 15 and (initial_digits == 34 or initial_digits == 37):
        print("AMEX")
        return
    elif digits == 16 and (initial_digits == 51 or initial_digits == 52 or initial_digits == 53
                           or initial_digits == 54 or initial_digits == 55):
        print("MASTERCARD")
        return
    elif (digits == 13 or digits == 16) and int(initial_digits/10) == 4:
        print("VISA")
        return
    else:
        print("INVALID")

main()
