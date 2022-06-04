NAME	=	container

SRCS	=	main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)
DEPS	=	$(OBJS:%.o=%.d)

CXX		=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -MMD -MP -Wshadow


all		:	$(NAME)

$(NAME)	:	$(OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

-include ${DEP}
%.o		:	%.cpp vector.hpp
	${CXX} ${CXXFLAGS} -o $@ -c $<

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all