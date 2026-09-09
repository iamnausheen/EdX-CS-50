names = ["Ted", "Robin", "Marshall"]

name = input("Name:")
                        # for-else available in python
for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not Found")

if name in names:
    print("Found")
else:
    print("Not Found")


# Dictionary

people = [
    {"name":"Ted", "number":"9999999999"},
    {"name":"ROBIN", "number":"9999999989"},
    {"name":"Barney", "number":"9999998899"},
]

for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        print(f"Found {person['number']}")
        break
    else:
        print("Not Found")


# DICTIONARY

people = {
    "Ted":"999999999"
    "Robin":"9999999989"
    "Barney":"9999998998"
}

name = input("Name: ")

if name in people:
    number = people[name]
    print(f"Found {number}")
else:
    print("Not Found")
