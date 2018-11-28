OBJ = Driver.o ChessBoard.o ChessPiece.o Helpers.o
EXE = chess
CXX = g++
CXXFLAGS = -Wall -g -MMD

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

.PHONY: clean
#clean:
#	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)

clean:
		rm -f *o enigma
