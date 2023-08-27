ROOT_DIR := $(shell dirname '$(realpath $(firstword $(MAKEFILE_LIST)))')
SRC_DIR := $(ROOT_DIR)/src/
INCLUDE_DIR := $(ROOT_DIR)/include/
OBJ_DIR := $(ROOT_DIR)/obj/
LIB_DIR := $(ROOT_DIR)/lib/
MKDIR := @mkdir -p 
CXX := g++
COMP_FLAGS := -std=c++14 -Wall -Werror -c -fPIC -Iinclude
LINK_FLAGS := -shared

.PHONY: all
all: argument_parser

.PHONY: clean
clean:
	-rm -r lib
	-rm -r obj

$(OBJ_DIR): 
	$(MKDIR) $@
	@echo "Created folder $@"

$(LIB_DIR): 
	$(MKDIR) $@
	@echo "Created folder $@"

$(OBJ_DIR)ArgumentParser.o: $(SRC_DIR)ArgumentParser.cpp $(INCLUDE_DIR)ArgumentParser.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgumentDefinition.o: $(SRC_DIR)ArgumentDefinition.cpp $(INCLUDE_DIR)ArgumentDefinition.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)Argument.o: $(SRC_DIR)Argument.cpp $(INCLUDE_DIR)Argument.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgumentsMap.o: $(SRC_DIR)ArgumentsMap.cpp $(INCLUDE_DIR)ArgumentsMap.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)InvalidArgumentNameException.o: $(SRC_DIR)errors/InvalidArgumentNameException.cpp $(INCLUDE_DIR)errors/InvalidArgumentNameException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UnknownArgumentException.o: $(SRC_DIR)errors/UnknownArgumentException.cpp $(INCLUDE_DIR)errors/UnknownArgumentException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)TooManyArgumentsException.o: $(SRC_DIR)errors/TooManyArgumentsException.cpp $(INCLUDE_DIR)errors/TooManyArgumentsException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)TooFewArgumentsException.o: $(SRC_DIR)errors/TooFewArgumentsException.cpp $(INCLUDE_DIR)errors/TooFewArgumentsException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgKeyException.o: $(SRC_DIR)errors/ArgKeyException.cpp $(INCLUDE_DIR)errors/ArgKeyException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

argument_parser: \
$(OBJ_DIR)ArgumentParser.o \
$(OBJ_DIR)ArgumentDefinition.o \
$(OBJ_DIR)Argument.o \
$(OBJ_DIR)ArgumentsMap.o \
$(OBJ_DIR)InvalidArgumentNameException.o \
$(OBJ_DIR)UnknownArgumentException.o \
$(OBJ_DIR)TooManyArgumentsException.o \
$(OBJ_DIR)TooFewArgumentsException.o \
$(OBJ_DIR)ArgKeyException.o \
| $(LIB_DIR)
	$(CXX) $^ $(LINK_FLAGS) -o $(LIB_DIR)libArgumentParser.so

$(OBJ_DIR)Tester.o: $(SRC_DIR)Tester.cpp | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

tester: $(OBJ_DIR)Tester.o | argument_parser
	$(CXX) -Llib -lArgumentParser $^ -o tester