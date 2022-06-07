SRCS_STACK	=	main_stack.cpp
OBJS_STACK	=	$(SRCS_STACK:%.cpp=%.o)
DEPS_STACK	=	$(OBJS_STACK:%.o=%.d)

SRCS_VECTOR	=	main_vector.cpp
OBJS_VECTOR	=	$(SRCS_VECTOR:%.cpp=%.o)
DEPS_VECTOR	=	$(OBJS_VECTOR:%.o=%.d)

SRCS_MAP	=	main_map.cpp
OBJS_MAP	=	$(SRCS_MAP:%.cpp=%.o)
DEPS_MAP	=	$(OBJS_MAP:%.o=%.d)

CXX			=	clang++
CXXFLAGS	=	-Wall -Wextra -Werror -MMD -MP -Wshadow -g3


all		:
	$(info Need to make with the name of containers ex: stack vector map)

stack	:	$(SRCS_STACK)
	${CXX} ${CXXFLAGS} -o $@ ${SRCS_STACK}

vector	:	$(SRCS_VECTOR)
	${CXX} ${CXXFLAGS} -o $@ ${SRCS_VECTOR}

map	:	$(SRCS_MAP)
	${CXX} ${CXXFLAGS} -o $@ ${SRCS_MAP}

fclean	:
	rm -rf stack vector map

re		:	fclean all