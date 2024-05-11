NAME		=	megaphone
CLANG		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJ_DIR		=	objects/
SRC_DIR		=	sources/

SOURCES		=	megaphone.cpp


OBJ_FILES	=	$(SOURCES:.cpp=.o)
OBJECTS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

MKDIR		=	$(shell mkdir $(OBJ_DIR) 2> /dev/null)

all		:	$(MKDIR) $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
	$(CLANG) $(CXXFLAGS) -c $< -o $@

$(NAME)	:	$(OBJECTS)
	$(CLANG) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	rm -rf $(OBJ_DIR)

fclean	:	clean
	rm -rf $(NAME)

re		: fclean
	make all

.PHONY: all clean fclean re