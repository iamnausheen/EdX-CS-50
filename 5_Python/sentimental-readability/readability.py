def main():
    text = input("Text: ")


    letters = 0
    words = 1
    sentences = 0

    for i in range(len(text)):
        c = text[i]

        if i == len(text)-1:
            d = " "
        else:
            d = text[i+1]
        if c == " " :
            words+=1
        elif (c == "." and d == " ") or (c == "?" and d == " ") or (c == "!" and d == " "):
            sentences+=1
        elif c.lower() >= 'a' and c.lower() <= 'z':
            letters+=1

    print(letters, words, sentences)
    L = ((letters)/(words))*100
    S = ((sentences)/(words))*100

    index = round((0.0588*L) - (0.296*S) - (15.8))

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")

main()
