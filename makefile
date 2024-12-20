# Makefile for Java programs
JAVAC = javac
JAVA_FILES = $(wildcard *.java)
CLASS_FILES = $(patsubst %.java, bin/%.class, $(JAVA_FILES))

# Create bin directory if not exists
bin/%.class: %.java
	@mkdir -p bin
	$(JAVAC) -d bin $<
	@echo "\n> Compiled $< successfully!"

all: $(CLASS_FILES)
	@if [ "$(MAKECMDGOALS)" = "all" ]; then \
		echo "> All Java files compiled successfully!\n";\
	fi

# Run a specified Java file using pattern matching
run-%: all
	@echo && java -cp bin $*  && echo "\n> All files executing as required!\n" \

# Clean up all compiled files
clean:
	@rm -rf bin
	@echo "\n> Cleaned up all the compiled files successfully!\n" \
