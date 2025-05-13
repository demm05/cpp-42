NAME	=	bsp
CC		=	c++

HDIR	=	inc
ODIR	=	obj
FLAGS	=	-std=c++98 -Wall -Wextra -Werror -I$(HDIR)

CFILES	:=	Fixed.cpp main.cpp bsp.cpp Point.cpp
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

d: re r

d: FLAGS += -DDEBUG=1

compiledb:
	@compiledb make -n all > /dev/null 2>&1

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re compiledb d
