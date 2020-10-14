from cs50 import get_int

while True:

    n = get_int("Height: ")
    while n >= 1 and n <= 8:

        for i in range(1, n+1):
            for j in range(n - i):
                print(" ", end='')
            if i == 1:
                print("#  #")
            if i == 2:
                print("##  ##")
            if i == 3:
                print("###  ###")
            if i == 4:
                print("####  ####")
            if i == 5:
                print("#####  #####")
            if i == 6:
                print("######  ######")
            if i == 7:
                print("#######  #######")
            if i == 8:
                print("########  ########")
        break
    break