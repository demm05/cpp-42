NAME	=	PmergeMe
CC		=	c++

HDIR	=	inc
ODIR	=	obj
SDIR	=	src
FLAGS	=	-Wall -Wextra -I$(HDIR) -g3 -O0

VPATH 	=	$(SDIR)

CFILES	:=	main.cpp
OFILES	:=	$(patsubst %.cpp,$(ODIR)/%.o, $(CFILES))
DEPS	:=	$(patsubst %.o,%.d,$(OFILES))

all: $(NAME)

$(ODIR):
	@mkdir -p $@

$(OFILES): $(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@

r run: all
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

-include $(DEPS)

.PHONY: all clean re compiledb
