ROOT_DIR := $(shell dirname '$(realpath $(firstword $(MAKEFILE_LIST)))')
SRC_DIR := $(ROOT_DIR)/src/
INCLUDE_DIR := $(ROOT_DIR)/include/
OBJ_DIR := $(ROOT_DIR)/obj/
BIN_DIR := $(ROOT_DIR)/bin/
LIB_DIR := $(ROOT_DIR)/lib/
MKDIR := @mkdir -p 
CXX := g++
COMP_FLAGS := -std=c++17 -Wall -Werror -c -fPIC -Iinclude
LINK_FLAGS := -shared

.PHONY: all
all: $(LIB_DIR)libArgumentParser.so

.PHONY: clean
clean:
	-rm -r lib
	-rm -r obj
	-rm -r bin

$(OBJ_DIR): 
	$(MKDIR) $@
	@echo "Created folder $@"

$(BIN_DIR): 
	$(MKDIR) $@
	@echo "Created folder $@"

$(LIB_DIR): 
	$(MKDIR) $@
	@echo "Created folder $@"

$(OBJ_DIR)ArgumentParser.o: $(SRC_DIR)ArgumentParser.cpp $(INCLUDE_DIR)ArgumentParser.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)NamedArgumentsParser.o: $(SRC_DIR)NamedArgumentsParser.cpp $(INCLUDE_DIR)NamedArgumentsParser.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)FunctionSignature.o: $(SRC_DIR)FunctionSignature.cpp $(INCLUDE_DIR)FunctionSignature.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)IArgumentProperties.o: $(SRC_DIR)IArgumentProperties.cpp $(INCLUDE_DIR)IArgumentProperties.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgumentAction.o: $(SRC_DIR)ArgumentAction.cpp $(INCLUDE_DIR)ArgumentAction.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgumentDefinition.o: $(SRC_DIR)ArgumentDefinition.cpp $(INCLUDE_DIR)ArgumentDefinition.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)IArgument.o: $(SRC_DIR)IArgument.cpp $(INCLUDE_DIR)IArgument.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)Argument.o: $(SRC_DIR)Argument.cpp $(INCLUDE_DIR)Argument.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgumentsMap.o: $(SRC_DIR)ArgumentsMap.cpp $(INCLUDE_DIR)ArgumentsMap.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UsageManualGenerator.o: $(SRC_DIR)UsageManualGenerator.cpp $(INCLUDE_DIR)UsageManualGenerator.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

# CONVERTERS

$(OBJ_DIR)BoolConverter.o: $(SRC_DIR)converters/BoolConverter.cpp $(INCLUDE_DIR)BoolConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)CharConverter.o: $(SRC_DIR)converters/CharConverter.cpp $(INCLUDE_DIR)CharConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)DoubleConverter.o: $(SRC_DIR)converters/DoubleConverter.cpp $(INCLUDE_DIR)DoubleConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)FloatConverter.o: $(SRC_DIR)converters/FloatConverter.cpp $(INCLUDE_DIR)FloatConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)IntConverter.o: $(SRC_DIR)converters/IntConverter.cpp $(INCLUDE_DIR)IntConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)LongConverter.o: $(SRC_DIR)converters/LongConverter.cpp $(INCLUDE_DIR)LongConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)LongDoubleConverter.o: $(SRC_DIR)converters/LongDoubleConverter.cpp $(INCLUDE_DIR)LongDoubleConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)LongLongConverter.o: $(SRC_DIR)converters/LongLongConverter.cpp $(INCLUDE_DIR)LongLongConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)PathConverter.o: $(SRC_DIR)converters/PathConverter.cpp $(INCLUDE_DIR)PathConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UnsignedConverter.o: $(SRC_DIR)converters/UnsignedConverter.cpp $(INCLUDE_DIR)UnsignedConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UnsignedLongConverter.o: $(SRC_DIR)converters/UnsignedLongConverter.cpp $(INCLUDE_DIR)UnsignedLongConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UnsignedLongLongConverter.o: $(SRC_DIR)converters/UnsignedLongLongConverter.cpp $(INCLUDE_DIR)UnsignedLongLongConverter.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

# ERRORS
$(OBJ_DIR)InvalidArgumentNameException.o: $(SRC_DIR)errors/InvalidArgumentNameException.cpp $(INCLUDE_DIR)errors/InvalidArgumentNameException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)InvalidAbbreviationException.o: $(SRC_DIR)errors/InvalidAbbreviationException.cpp $(INCLUDE_DIR)errors/InvalidAbbreviationException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UnknownArgumentException.o: $(SRC_DIR)errors/UnknownArgumentException.cpp $(INCLUDE_DIR)errors/UnknownArgumentException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)UnknownNamedArgException.o: $(SRC_DIR)errors/UnknownNamedArgException.cpp $(INCLUDE_DIR)errors/UnknownNamedArgException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)TooManyArgumentsException.o: $(SRC_DIR)errors/TooManyArgumentsException.cpp $(INCLUDE_DIR)errors/TooManyArgumentsException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)TooFewArgumentsException.o: $(SRC_DIR)errors/TooFewArgumentsException.cpp $(INCLUDE_DIR)errors/TooFewArgumentsException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgKeyException.o: $(SRC_DIR)errors/ArgKeyException.cpp $(INCLUDE_DIR)errors/ArgKeyException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)MissingRequiredArgsException.o: $(SRC_DIR)errors/MissingRequiredArgsException.cpp $(INCLUDE_DIR)errors/MissingRequiredArgsException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)MissingRequiredNamedArgumentException.o: $(SRC_DIR)errors/MissingRequiredNamedArgumentException.cpp $(INCLUDE_DIR)errors/MissingRequiredNamedArgumentException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)IncompatibleActionException.o: $(SRC_DIR)errors/IncompatibleActionException.cpp $(INCLUDE_DIR)errors/IncompatibleActionException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ArgumentConversionException.o: $(SRC_DIR)errors/ArgumentConversionException.cpp $(INCLUDE_DIR)errors/ArgumentConversionException.h | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(LIB_DIR)libArgumentParser.so: \
$(OBJ_DIR)ArgumentParser.o \
$(OBJ_DIR)NamedArgumentsParser.o \
$(OBJ_DIR)FunctionSignature.o \
$(OBJ_DIR)IArgumentProperties.o \
$(OBJ_DIR)ArgumentAction.o \
$(OBJ_DIR)ArgumentDefinition.o \
$(OBJ_DIR)IArgument.o \
$(OBJ_DIR)Argument.o \
$(OBJ_DIR)ArgumentsMap.o \
$(OBJ_DIR)UsageManualGenerator.o \
$(OBJ_DIR)BoolConverter.o \
$(OBJ_DIR)CharConverter.o \
$(OBJ_DIR)DoubleConverter.o \
$(OBJ_DIR)FloatConverter.o \
$(OBJ_DIR)IntConverter.o \
$(OBJ_DIR)LongConverter.o \
$(OBJ_DIR)LongDoubleConverter.o \
$(OBJ_DIR)LongLongConverter.o \
$(OBJ_DIR)PathConverter.o \
$(OBJ_DIR)UnsignedConverter.o \
$(OBJ_DIR)UnsignedLongConverter.o \
$(OBJ_DIR)UnsignedLongLongConverter.o \
$(OBJ_DIR)InvalidArgumentNameException.o \
$(OBJ_DIR)InvalidAbbreviationException.o \
$(OBJ_DIR)UnknownArgumentException.o \
$(OBJ_DIR)UnknownNamedArgException.o \
$(OBJ_DIR)TooManyArgumentsException.o \
$(OBJ_DIR)TooFewArgumentsException.o \
$(OBJ_DIR)ArgKeyException.o \
$(OBJ_DIR)MissingRequiredArgsException.o \
$(OBJ_DIR)MissingRequiredNamedArgumentException.o \
$(OBJ_DIR)IncompatibleActionException.o \
$(OBJ_DIR)ArgumentConversionException.o \
| $(LIB_DIR)
	$(CXX) $^ $(LINK_FLAGS) -o $(LIB_DIR)libArgumentParser.so

$(OBJ_DIR)Tester.o: $(SRC_DIR)Tester.cpp | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

$(OBJ_DIR)ConvertersTester.o: $(SRC_DIR)ConvertersTester.cpp | $(OBJ_DIR)
	$(CXX) $(COMP_FLAGS) $(ADDITIONAL_COMP_FLAGS) $< -o $@

tester: $(OBJ_DIR)Tester.o | argument_parser $(BIN_DIR)
	$(CXX) -Llib -lArgumentParser $^ -o $(BIN_DIR)tester

converters_tester: $(OBJ_DIR)ConvertersTester.o | argument_parser $(BIN_DIR)
	$(CXX) -Llib -lArgumentParser $^ -o $(BIN_DIR)converters_tester