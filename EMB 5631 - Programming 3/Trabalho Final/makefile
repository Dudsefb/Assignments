# defina aqui quaisquer ferramentas particulares ao projeto
CC = g++
CFLAGS = -Wall -Wextra -O2 -g

#Especifique os diretórios que serão incluídos
M := model
V := view
C := controller

#Diretório temporário para armazenar objetos de compilação
TEMP = temp

#Automaticamente lista os arquivos .o que deverão ser gerados
SOURCES := $(wildcard $(M)/*.cpp $(V)/*.cpp $(C)/*.cpp)
OBJECTS := $(addprefix $(TEMP)/,$(patsubst %.cpp,%.o,$(notdir $(SOURCES))))

#Compila o executável
output: main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o output.exe

#Regra de compilação do diretório M
$(TEMP)/%.o: $(M)/%.cpp $(M)/%.hpp
	$(CC) $(CFLAGS) -I$(M) -c $< -o $@

#Regra de compilação do diretório V
$(TEMP)/%.o: $(V)/%.cpp $(V)/%.hpp
	$(CC) $(CFLAGS) -I$(V) -c $< -o $@

#Regra de compilação do diretório C
$(TEMP)/%.o: $(C)/%.cpp $(C)/%.hpp
	$(CC) $(CFLAGS) -I$(C) -c $< -o $@

clean:
	rm $(TEMP)/*
	rm output.exe
