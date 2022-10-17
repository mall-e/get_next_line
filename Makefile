NAME = prolab.a


all: $(NAME)

$(NAME):
	gcc *.c get_next_line/*.c -o prolab && ./prolab

