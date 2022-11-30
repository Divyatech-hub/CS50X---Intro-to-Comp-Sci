def main_fn():
    Owed = get_the_cash_owed()
    coins = calculate_coins(Owed)
    print(f"{coins}")

# to check if cash owed is a valid input or not


def get_the_cash_owed():
    while True:
        try:
            Owed = float(input("Cash owed: "))
            if Owed > 0:
                break
        except ValueError:             # otherwise will give error. but we're using except block
            None

    return Owed

# to find the no of coins to give user as change


def calculate_coins(Owed):
    cents = round(Owed * 100)
    coins = 0

    while cents > 0:
        if cents >= 25:
            cents = cents - 25
        elif cents >= 10:
            cents = cents - 10
        elif cents >= 5:
            cents = cents - 5
        else:
            cents = cents - 1
        coins = coins + 1            # coins variable keeps track of the total number of coins
    return coins


main_fn()
