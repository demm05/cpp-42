NAME	=	iter
CC		=	c++

HDIR	=	inc
ODIR	=	obj
SDIR	=	src
FLAGS	=	-std=c++98 -Wall -Wextra -Werror -I$(HDIR)

VPATH 	=	$(SDIR)

CFILES	:=	main.cpp
OFILES	:=	$(patsubst %.cpp,$(ODIR)/%.o, $(CFILES))

all: $(NAME)

$(ODIR):
	@mkdir -p $@

$(OFILES): $(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@

r: all
	@./$(NAME)

v: all
	@valgrind ./$(NAME)

compiledb:
	@compiledb make -n all > /dev/null 2>&1

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re compiledb
