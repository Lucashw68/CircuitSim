SRC			=		CircuitSim/Main.cpp			\
					CircuitSim/CircuitSim.cpp			\
					Error/CircuitSimError.cpp			\
					Error/ComponentError.cpp		\
					Error/InputError.cpp			\
					Component/ComponentFactory.cpp		\
					Component/Clock.cpp			\
					Component/Input.cpp			\
					Component/Output.cpp			\
					Component/True.cpp			\
					Component/False.cpp			\
					Component/And.cpp			\
					Component/Or.cpp			\
					Component/Nand.cpp			\
					Component/Nor.cpp			\
					Component/Xor.cpp			\
					Component/Inv.cpp			\
					Component/C4081.cpp			\
					Component/C4001.cpp			\
					Component/C4008.cpp			\
					Component/C4011.cpp			\
					Component/C4030.cpp			\
					Component/C4069.cpp			\
					Component/C4071.cpp			\
					Parser/Parser.cpp

OBJ			=		$(SRC:.cpp=.o)

NAME			=		circuitsim

CXXFLAGS		+=		-W -Wall -Wextra -std=c++17 -lstdc++ -IError -IComponent -ICircuitSim -IParser -g

CC			=		g++ -o

RM			=		rm -f

ALL			=		all

CLEAN			=		clean

FCLEAN			=		fclean

RE			=		re

all:					$(NAME)

$(NAME):				$(OBJ)
					$(CC) $(NAME) $(OBJ) $(CXXFLAGS)

clean:
					$(RM) $(OBJ)

fclean:					$(CLEAN)
					$(RM) $(NAME)

re: 					$(FCLEAN) $(ALL)

.PHONY:					$(RE) $(FCLEAN) $(CLEAN) $(ALL)
