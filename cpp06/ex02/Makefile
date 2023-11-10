SRCS =		main.cpp		\
			Base.cpp

OBJS = 		${SRCS:.cpp=.o}

INCLUDE =	-Iinclude

NAME = 		IdentifyRealType

CXX		= 	c++

CXXFLAGS	= 	-Wall -Wextra -Werror -std=c++98

.c.o:		${SRCS}
			${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS} ${HEAD}
			${CXX} ${OBJS} ${CXXFLAGS} ${INCLUDE} -o ${NAME}
			@echo "\033[33;31mCOMPILED\t\t\tCONGRATS\033[0m"

all: 		${NAME}

clean:
			@rm -f ${OBJS}
			@echo "\033[33;34mCLEAN !\t\t\t\tBUT YOU CAN DO BETTER\033[0m"

fclean:		clean
			rm -f ${NAME}
			@echo "\033[33;32mALL CLEAN !\t\t\tYOU'RE VERY PROPER\033[0m"

re:			fclean all
			@echo "\033[33;36mRECOMPILED !\t\t\tIT'S WORK NOW ?\033[0m"

.PHONY:		all fclean clean re
