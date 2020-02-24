##搞清楚目录结构
DIR_BIN = ./
DIR_SRC = ./ ./mod_scoped_rwlock ./salary_manage
DIR_INC = ./ ./mod_scoped_rwlock ./salary_manage
DIR_BUILD = ./build
DIR_DEP = $(DIR_BUILD)
DIR_OBJ = $(DIR_BUILD)

APP_NAME = scoped_lock_test.bin
TARGET = $(DIR_BIN)/$(APP_NAME)

## $(foreach <var>,<list>,<text>) 把参数<list>;中的单词逐一取出放到参数<var>;所指定的变量中，然后再执行< text>;所包含的表达式
## $(wildcard PATTERN...) 它被展开为已经存在的、使用空格分开的、匹配此模式的所有文件列表
CPPSOURCES += $(foreach src_dir, $(DIR_SRC), $(wildcard $(src_dir)/*.cpp))
INCLUDE += $(foreach inc_dir, $(DIR_INC), $(wildcard $(inc_dir)/*.h))
INCFLAGS += $(foreach inc_dir, $(DIR_INC), -I$(inc_dir))

$(info $(CPPSOURCES))
$(info $(INCLUDE))

CPPOBJS = $(patsubst %.cpp,%.o,$(notdir $(CPPSOURCES)))
CPPDEPS = $(patsubst %.cpp,%.d,$(notdir $(CPPSOURCES)))
CPPHDRS = $(patsubst %.cpp,%.d,$(notdir $(CPPSOURCES)))

##使用的编译工具
CC = g++

##用vpath关键字，vpath <pattern> <directories>。为符合模式<pattern>的文件指定搜索目录<directories>
vpath %.h $(DIR_INC)
vpath %.cpp $(DIR_SRC)
vpath %.o $(DIR_OBJ)
vpath %.d $(DIR_DEP)

all: create_build_dir $(TARGET)
$(TARGET): $(CPPDEPS) $(CPPOBJS)
	$(CC) $(addprefix $(DIR_OBJ)/,$(CPPOBJS)) $(INCFLAGS) -o $@

%.o: %.cpp
	$(CC) $(INCFLAGS) -c $< -o $(DIR_OBJ)/$@

%.d: %.cpp
	@rm -f $(DIR_DEP)/$@
	@$(CC) $< $(INCFLAGS) -MM -o $(DIR_DEP)/$@

create_build_dir:
	$(shell if [ ! -d $(DIR_BUILD) ]; then mkdir -p $(DIR_BUILD); fi;)

clean:
	@rm -rf *.o
	@rm -rf $(DIR_BUILD) $(TARGET)




