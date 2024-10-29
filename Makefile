CC := clang
AS := clang
NAME := libft.a
AS_FLAGS := -Wall
SOURCES_DIR := src/
SOURCES :=	isalpha.s
SOURCES := $(SOURCES:%=$(SOURCES_DIR)%)
OBJECTS_DIR := objs/
OBJECTS := $(SOURCES:src/%.s=$(OBJECTS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

main:
	$(CC) -Wall -Wextra main.c $(NAME)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.s $(OBJECTS_DIR)
	$(AS) $(AS_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:
	rm -rf $(OBJECT_DIR)
	rm -f $(NAME)
