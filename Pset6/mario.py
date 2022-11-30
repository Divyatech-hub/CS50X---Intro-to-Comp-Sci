def main():

    Height = generate_height()
    pyramid_generate(Height, Height)

# function to generate the pyramid


def pyramid_generate(Height, h):
    if Height == 0:
        return
    pyramid_generate(Height - 1, h)
    print(" " * (h - Height), end='')   # this is the crucial step!
    print("#" * Height)

# function to check if input value is valid or not


def generate_height():
    while True:
        try:
            Height = int(input("Height: "))
            if (Height > 0 and Height < 9):   # should be int>0 and <9
                break
        except ValueError:                    # otherwise error is given
            None

    return Height


main()
