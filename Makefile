CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = Quadris
OBJECTS = main.o autocomplete.o block.o board.o cell.o centerblock.o commandinterpreter.o down.o drop.o game.o graphicdisplay.o grid.o hint.o i.o j.o l.o l0.o l1.o l2.o l3.o left.o level.o leveldown.o levelup.o norandom.o o.o random.o restart.o right.o rotateccw.o rotatecw.o s.o score.o t.o textdisplay.o window.o z.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
