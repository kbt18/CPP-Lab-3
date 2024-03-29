OBJ = ChessMain.o ChessBoard.o ChessPiece.o Pawn.o Rook.o Bishop.o Knight.o Queen.o King.o Helpers.o 
EXE = chess
CXX = g++
CXXFLAGS = -Wall -g -MMD

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

-include $(OBJ:.o=.d)

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)
