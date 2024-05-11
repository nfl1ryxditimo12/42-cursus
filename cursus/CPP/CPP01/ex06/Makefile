NAME			=	harlFilter
CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic
CXXDEBUGFLAGS	=	-fsanitize=address -fsanitize=undefined

INC_DIR			=	includes/
OBJ_DIR			=	objects/
SRC_DIR			=	sources/

SOURCES			=	main.cpp\
					Harl.cpp\

OBJ_FILES		=	$(SOURCES:.cpp=.o)
OBJECTS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

MKDIR			=	$(shell mkdir $(OBJ_DIR) 2> /dev/null)

all		:	$(MKDIR) $(NAME)

debug	:	CXXFLAGS += $(CXXDEBUGFLAGS)
debug	:	re

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME)	:	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	rm -rf $(OBJ_DIR)

fclean	:	clean
	rm -rf $(NAME)

re		: fclean
	make all

.PHONY: all clean fclean re debug