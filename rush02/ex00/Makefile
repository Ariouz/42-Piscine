CFLAGS = -Wall -Werror -Wextra

all : rush-02

rush-02 : main.o fonction01.o print_number.o files.o errors.o dict_spliter.o
	clang -o rush-02 main.o fonction01.o print_number.o files.o errors.o dict_spliter.o $(CFLAG)

main.o : main.c
	clang -o main.o -c srcs/main.c $(CFLAGS)

fonction01.o : fonction01.c
	clang -o fonction01.o -c srcs/fonction01.c $(CFLAGS)

print_number.o : print_number.c
	clang -o print_number.o -c srcs/print_number.c $(CFLAGS)

files.o : files.c
	clang -o files.o -c srcs/files.c $(CFLAGS)

errors.o : errors.c
	clang -o errors.o -c srcs/errors.c $(CFLAGS)

dict_spliter.o : dict_spliter.c
	clang -o dict_spliter.o -c srcs/dict_spliter.c $(CFLAGS)

fclean:
	rm rush-02