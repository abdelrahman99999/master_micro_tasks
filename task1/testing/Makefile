#exe file
EXE_FILE := program.exe

#list of cpp files
SRC_FILES := ./test.cpp 	

#list of obj files
OBJ_FILES := ./tinyexpr.o  
OBJ_FILES += ./math_operation.o

build:
	@g++ ./$(SRC_FILES) ./$(OBJ_FILES) -lgtest -lgtest_main -pthread -o $(EXE_FILE)
	
run: 
	@./$(EXE_FILE)
