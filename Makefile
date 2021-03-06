NAME := ft_containers
SRC := 	main.cpp
# SRC := vector_perf.cpp
# SRC := map_perf.cpp
# SRC := main42.cpp

MAKE = make
# MAKEFLAGS += --ignore-errors
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -MMD -std=c++98 -g3
BUILD_DIR := .build
INCLUDES_DIR := includes
SOURCE_DIR := sources
DEP := $(SRC:%.cpp=$(BUILD_DIR)/%.d)
OBJ := $(DEP:.d=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

vpath %.cpp $(SOURCE_DIR)

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES_DIR:%=-I %) -c $< -o $@

.PHONY: all clean fclean re test
