
# single compilation
%.o: %.cpp
	g++ -c $< -o $@ 
# '$<' is first requirement of the rule, '$@' is the target

# compile all
allobj: $(patsubst %.cpp, %.o, $(wildcard *.cpp))
# wildcard collects all the elements with the same pattern, patsubst substitutes the patterns to
# obtain the set of *.o: there is no comand because now that the rule requires *.o, make
# calls the first rule for each of them automatically to obtain them.

# compile all and link
all: $(patsubst %.cpp, %.o, $(wildcard *.cpp))
	g++ $^ -o main.exe
# '$^' is all the required files; it is the same as above + the command to link the *.o

# cleaning
clean:
	rm -f *.o program.exe