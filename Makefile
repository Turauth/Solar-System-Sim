# Define the compiler.
CXX = g++

# Define the compiler flags.
CXXFLAGS = -Wall -std=c++17

# Define the target executable.
TARGET = solsys

# Define the source files.
SRCS = solsys.cpp celestialBody.cpp planet.cpp moon.cpp

#Define the object files.
OBJS = $(SRCS:.cpp=.o)

# Rule to build the target executable.
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files.
%.o %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
    rm -f $ (OBJS) # $(TARGET)