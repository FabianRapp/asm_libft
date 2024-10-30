CC := gcc
AS := gcc

INCLUDE := -I./include

FSAN := address
ASFLAGS := -Wall -O0 -fPIC -fsanitize=$(FSAN) -g $(INCLUDE)
CFLAGS := -Wall -O0 -fPIC -fsanitize=$(FSAN) -g $(INCLUDE)


NAME := libft.a
NAME_SO := libft.so
NAME_TESTS := dotests

SOURCES_DIR := src/
OBJECTS_DIR := objs/
TEST_DIR := tests/


SOURCES := \
			isalpha.s \
			isdigit.s \
			isalnum.s \

SOURCES := $(SOURCES:%=$(SOURCES_DIR)%)
OBJECTS := $(SOURCES:src/%.s=$(OBJECTS_DIR)%.o)

SOURCES_TESTS := main.c
SOURCES_TESTS := $(SOURCES_TESTS:%=$(TEST_DIR)%)
OBJECTS_TESTS := $(SOURCES_TESTS:%.c=%.o)

.PHONY: all clean fclean re so

#************************** build rules *******************************

all: $(NAME) $(NAME_TESTS)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

so: $(SOURCES) $(OBJECTS)
	$(CC) -shared $(OBJECTS) -o $(NAME_SO)
#*************************** libft.a ***********************************make

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.s $(OBJECTS_DIR)
	$(AS) $(ASFLAGS) -c $< -o $@

#***************************** tests ***********************************

$(NAME_TESTS): $(NAME) $(TEST_SOURCES) $(OBJECTS_TESTS)
	$(CC) $(CFLAGS) $(OBJECTS_TESTS) $(NAME) -o $(NAME_TESTS)

$(TEST_DIR)%.o: $(TEST_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

#****************************** utils **********************************

clean:
	rm -f $(OBJECTS) $(OBJECTS_TESTS)

fclean: clean
	rm -rf $(OBJECT_DIR)
	rm -f $(NAME) $(NAME_TESTS) $(NAME_SO)

re: fclean all
