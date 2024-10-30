CC := clang
AS := clang

FSAN := address

ASFLAGS := -Wall -fsanitize=$(FSAN)
CFLAGS := -Wall -fsanitize=$(FSAN)

NAME := libft.a
NAME_TESTS := dotests

SOURCES_DIR := src/
OBJECTS_DIR := objs/
TEST_DIR := tests/


SOURCES :=	isalpha.s
SOURCES := $(SOURCES:%=$(SOURCES_DIR)%)
OBJECTS := $(SOURCES:src/%.s=$(OBJECTS_DIR)%.o)

SOURCES_TESTS := main.c
SOURCES_TESTS := $(SOURCES_TESTS:%=$(TEST_DIR)%)
OBJECTS_TESTS := $(SOURCES_TESTS:%.c=%.o)

.PHONY: all clean fclean re

#************************** build rules *******************************

all: $(NAME) $(NAME_TESTS)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

#*************************** libft.a ***********************************

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.s $(OBJECTS_DIR)
	$(AS) $(ASFLAGS) -c $< -o $@

#***************************** tests ***********************************

$(NAME_TESTS): $(NAME) $(TEST_SOURCES) $(OBJECTS_TESTS)
	$(CC) $(CLFAGS) $(OBJECTS_TESTS) $(NAME) -o $(NAME_TESTS)

$(TEST_DIR)%.o: $(TEST_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

#****************************** utils **********************************

clean:
	rm -f $(OBJECTS)

fclean:
	rm -rf $(OBJECT_DIR)
	rm -f $(NAME)

re: fclean all
