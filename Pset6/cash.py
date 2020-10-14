from cs50 import get_float

coins = 0

while True:
    c = get_float("Change owed:")
    if c > 0.00:
        break
while c > 0.00:
    if (c >= 0.25):
        c = round(c - 0.25, 2)
        coins += 1
    elif (c >= 0.10):
        c = round(c - 0.10, 2)
        coins += 1
    elif (c >= 0.05):
        c = round(c - 0.05, 2)
        coins += 1
    elif (c >= 0.01):
        c = round(c - 0.01, 2)
        coins +=1
print(coins)