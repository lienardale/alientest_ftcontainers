# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alienard@student.42.fr <alienard>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 12:07:05 by dboyer            #+#    #+#              #
#    Updated: 2021/05/21 13:58:25 by alienard@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                                                       SOURCES
################################################################################

NAME		=	containers
NAME_STL	=	containers_stl

LIST_MAIN	=	./list_main.cpp
LIST_MAIN_STL =	./list_main_stl.cpp

MAP_MAIN	=	./map_main.cpp
MAP_MAIN_STL =	./map_main_stl.cpp

VECTOR_MAIN	=	./vector_main.cpp
VECTOR_MAIN_STL =	./vector_main_stl.cpp

QUEUE_MAIN	=	./queue_main.cpp
QUEUE_MAIN_STL =	./queue_main_stl.cpp

STACK_MAIN	=	./stack_main.cpp
STACK_MAIN_STL =	./stack_main_stl.cpp

INCLUDES	=	-I ../List \
				-I ../Map \
				-I ../Vector \
				-I ../Queue \
				-I ../Stack \
				-I ../

HEADERS	=	../List/List.hpp \
				../List/List_node.hpp \
				../List/List_iterators.hpp \
				../algorithm.hpp \
				../iterator_traits.hpp \
				../utility.hpp \
				../iterator.hpp \
				../Map/Map.hpp \
				../Map/Map_node.hpp \
				../Map/Map_iterators.hpp \
				../Vector/Vector.hpp \
				../Vector/Vector_iterator.hpp \
				../Queue/Queue.hpp \
				../Stack/Stack.hpp


OBJS_LIST_MAIN	=	$(LIST_MAIN:.cpp=.o)
OBJS_LIST_MAIN_STL	=	$(LIST_MAIN_STL:.cpp=.o)

OBJS_MAP_MAIN	=	$(MAP_MAIN:.cpp=.o)
OBJS_MAP_MAIN_STL	=	$(MAP_MAIN_STL:.cpp=.o)

OBJS_VECTOR_MAIN	=	$(VECTOR_MAIN:.cpp=.o)
OBJS_VECTOR_MAIN_STL	=	$(VECTOR_MAIN_STL:.cpp=.o)

OBJS_QUEUE_MAIN	=	$(QUEUE_MAIN:.cpp=.o)
OBJS_QUEUE_MAIN_STL	=	$(QUEUE_MAIN_STL:.cpp=.o)

OBJS_STACK_MAIN	=	$(STACK_MAIN:.cpp=.o)
OBJS_STACK_MAIN_STL	=	$(STACK_MAIN_STL:.cpp=.o)

CXXFLAGS	=	-Werror -Wall -Wextra -std=c++98 -g ${INCLUDES}
# CXXFLAGS	=	-Werror -Wall -Wextra -std=c++98 -fsanitize=address -g3 ${INCLUDES}

CXX	=	clang++
RM	=	rm -f

################################################################################
#                                                               Basic Rules
################################################################################

%.o: %.cpp ${HEADERS}
		$(CXX) $(CXXFLAGS) -c $< -o $@

all		:	$(NAME) $(NAME_STL)

$(NAME) :	$(OBJS_LIST_MAIN) $(OBJS_MAP_MAIN) ${OBJS_VECTOR_MAIN} ${OBJS_QUEUE_MAIN} ${OBJS_STACK_MAIN}
				${CXX} ${CXXFLAGS} -o ${NAME}_list ${OBJS_LIST_MAIN}
				${CXX} ${CXXFLAGS} -o ${NAME}_map ${OBJS_MAP_MAIN}
				${CXX} ${CXXFLAGS} -o ${NAME}_vector ${OBJS_VECTOR_MAIN}
				${CXX} ${CXXFLAGS} -o ${NAME}_queue ${OBJS_QUEUE_MAIN}
				${CXX} ${CXXFLAGS} -o ${NAME}_stack ${OBJS_STACK_MAIN}

$(NAME_STL) : $(OBJS_LIST_MAIN_STL) $(OBJS_MAP_MAIN_STL) $(OBJS_VECTOR_MAIN_STL) $(OBJS_QUEUE_MAIN_STL) $(OBJS_STACK_MAIN_STL)
				${CXX} ${FLAGS} -o ${NAME_STL}_list ${OBJS_LIST_MAIN_STL}
				${CXX} ${FLAGS} -o ${NAME_STL}_map ${OBJS_MAP_MAIN_STL}
				${CXX} ${FLAGS} -o ${NAME_STL}_vector ${OBJS_VECTOR_MAIN_STL}
				${CXX} ${FLAGS} -o ${NAME_STL}_queue ${OBJS_QUEUE_MAIN_STL}
				${CXX} ${FLAGS} -o ${NAME_STL}_stack ${OBJS_STACK_MAIN_STL}

clean   :
		$(RM) ${OBJS_LIST_MAIN} ${OBJS_LIST_MAIN_STL} ${OBJS_MAP_MAIN} ${OBJS_MAP_MAIN_STL} ${OBJS_VECTOR_MAIN} ${OBJS_VECTOR_MAIN_STL} ${OBJS_QUEUE_MAIN} ${OBJS_QUEUE_MAIN_STL} ${OBJS_STACK_MAIN} ${OBJS_STACK_MAIN_STL} *.log

fclean  : clean
		$(RM) $(NAME)_list $(NAME_STL)_list $(NAME)_map $(NAME_STL)_map $(NAME)_vector $(NAME_STL)_vector $(NAME)_queue $(NAME_STL)_queue $(NAME)_stack $(NAME_STL)_stack

re	:	fclean all

################################################################################
#                                                                       Extra Rules
################################################################################
run	:	all
		./${NAME}_list
		./${NAME}_map
		./${NAME}_vector
		./${NAME}_queue
		./${NAME}_stack

list	: all
		./${NAME}_list

map	: all
		./${NAME}_map

vector	: all
		./${NAME}_vector

queue	: all
		./${NAME}_queue

stack	: all
		./${NAME}_stack

stl	:	all
		./${NAME_STL}_list
		./${NAME_STL}_map
		./${NAME_STL}_vector
		./${NAME_STL}_queue
		./${NAME_STL}_stack

test	:	all
			./$(NAME_STL)_list > $(NAME_STL)_list.log
			./$(NAME)_list > $(NAME)_list.log
			diff $(NAME)_list.log $(NAME_STL)_list.log > diff_list.log
			@cat diff_list.log
			./$(NAME_STL)_map > $(NAME_STL)_map.log
			./$(NAME)_map > $(NAME)_map.log
			diff $(NAME)_map.log $(NAME_STL)_map.log > diff_map.log
			@cat diff_map.log
			./$(NAME_STL)_vector > $(NAME_STL)_vector.log
			./$(NAME)_vector > $(NAME)_vector.log
			diff $(NAME)_vector.log $(NAME_STL)_vector.log > diff_vector.log
			@cat diff_vector.log
			./$(NAME_STL)_queue > $(NAME_STL)_queue.log
			./$(NAME)_queue > $(NAME)_queue.log
			diff $(NAME)_queue.log $(NAME_STL)_queue.log > diff_queue.log
			@cat diff_queue.log
			./$(NAME_STL)_stack > $(NAME_STL)_stack.log
			./$(NAME)_stack > $(NAME)_stack.log
			diff $(NAME)_stack.log $(NAME_STL)_stack.log > diff_stack.log
			@cat diff_stack.log

.PHONY  :	all clean fclean re bonus
