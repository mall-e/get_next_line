NAME = prolab.a


all: $(NAME)

$(NAME):
	gcc *.c -o prolab && ./prolab

