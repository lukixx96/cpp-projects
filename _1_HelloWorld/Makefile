
# Variabili
CXX = g++          # Compilatore
CXXFLAGS = -Wall   # Opzioni del compilatore
TARGET = helloworld.exe # Nome dell'eseguibile
SRCS = helloworld.cpp functions.cpp # File sorgenti
OBJS = $(SRCS:.cpp=.o) # File oggetto generati dai sorgenti

# Regola predefinita: compila tutto
all: $(TARGET)

# Regola per costruire l'eseguibile
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Regola per costruire i file oggetto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia dei file generati
clean:
	rm -f $(OBJS) $(TARGET)
