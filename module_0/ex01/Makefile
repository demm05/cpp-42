NAME	=	phonebook
CC		=	c++

SDIR	=	src
HDIR	=	inc
ODIR	=	obj
FLAGS	=	-std=c++98 -Wall -Wextra -Werror -I$(HDIR)

VPATH	=	$(SDIR)

CFILES	:=	Contact.class.cpp main.cpp PhoneBook.class.cpp utils.cpp
OFILES	:=	$(patsubst %.cpp,$(ODIR)/%.o, $(CFILES))

all: compiledb $(NAME)

$(ODIR):
	@mkdir -p $@

$(OFILES): $(ODIR)/%.o: %.cpp | $(ODIR)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@

compiledb:
	@compiledb make -n all > /dev/null 2>&1

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
