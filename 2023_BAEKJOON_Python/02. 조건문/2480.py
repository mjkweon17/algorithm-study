import sys

dice1, dice2, dice3 = map(int, sys.stdin.readline().split())

if dice1 == dice2 and dice2 == dice3:
    print(10000 + dice1 * 1000)
elif dice1 != dice2 and dice1 != dice3 and dice2 != dice3:
    print(max(dice1, dice2, dice3) * 100)
else:
    if dice1 == dice2:
        print(1000 + dice1 * 100)
    elif dice1 == dice3:
        print(1000 + dice1 * 100)
    else:
        print(1000 + dice2 * 100)