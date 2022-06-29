# Makefile
NAME	=	Reverse
CC		=	gcc
CFLAGS	=	-Wall -g -I include
LDFLAGS	=	-Wall -g
INCLUDE	=	
OBJECTS	=	main.o

# compile program listed in $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJECTS)

# compile sources into objects
%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c -o $@ $<

# report missing requirements
%.c:
	echo ERROR: MISSING $@

# Build and execute program
run: $(NAME)
	./$(NAME); make clean

# check for errors
check: $(NAME)
	make; make clean

# compress into tarball
archive: $(NAME)
	make clean
	tar -zcvf ../Arianfar_Reiss_$(NAME).tgz ./

# clean up objects and executable
clean:
	rm $(NAME) *.o

.PHONY: run
.PHONY: check
.PHONY: archive
.PHONY: clean
