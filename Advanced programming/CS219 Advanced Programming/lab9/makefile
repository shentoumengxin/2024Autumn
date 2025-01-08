# 变量定义
CXX = g++                 # 指定编译器
CXXFLAGS = -Wall -g       # 编译选项，-Wall 开启所有警告，-g 开启调试信息
TARGET = candybar # 目标可执行文件名
SRC = main.cpp candybar.cpp # 源文件
OBJ = $(SRC:.cpp=.o)      # 对应的目标文件（.o 文件）

# 默认目标
$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

# 编译每个 .cpp 文件为 .o 文件的规则
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
