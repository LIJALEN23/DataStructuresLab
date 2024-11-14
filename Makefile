# 编译器
CC = g++

# 编译选项
CFLAGS = -std=c++11 -Wall -Wextra -g -O0 -Iinclude

# 源文件目录
SRCDIR = src

# 对象文件目录
OBJDIR = obj

# 目标文件目录
BINDIR = bin

# 目标文件
TARGET = myprogram

# 递归查找所有源文件
SOURCES := $(shell find $(SRCDIR) -name "*.cpp")

# 生成对象文件路径
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# 默认目标
all: $(BINDIR)/$(TARGET)

# 构建可执行文件
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

# 编译 .c 为 .o文件
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# 重新构建
rebuild: clean all

.PHONY: all clean rebuild
