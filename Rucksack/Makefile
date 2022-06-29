# Makefile
NAME	=	Rucksack
CC		=	gcc
CFLAGS	=	-Wall -g -I include
LDFLAGS	=	-Wall -g
INCLUDE	=	backpack.h test.h
OBJECTS	=	backpack.o test.o main.o

# compile program listed in $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJECTS)

# compile sources into objects
%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c -o $@ $<

# Build and execute program
run: $(NAME)
	./$(NAME); make clean

# check for errors
check: $(NAME)
	make; make clean

test: $(NAME)
	./$(NAME) test

# compress into tarball
archive: $(NAME)
	make clean
	tar -zcvf ../Arianfar_Reiss_$(NAME).tgz ./

# clean up objects and executable
clean:
	rm $(NAME) *.o

.PHONY: run
.PHONY: check
.PHONY: test
.PHONY: archive
.PHONY: clean
