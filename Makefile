.PHONY : clean

CXX := g++ -Wall -Wextra -Wfatal-errors -Wunreachable-code -Wfloat-equal -Winline -Wshadow -Wredundant-decls -Wcast-qual -Wcast-align -Wlogical-op -pedantic -std=c++11 -I ./include

building = @echo Building $@

define CMD
$(building)
@$(CXX) -c $< -o $@
endef

bin/locker : build/locker.o
	$(building)
	@$(CXX) -o $@ $< build/append_sfx.o build/common.o build/encrypt.o

build/locker.o : src/locker.cpp build/append_sfx.o
	$(CMD)

build/append_sfx.o : src/append_sfx.cpp include/append_sfx.h build/common.o include/common_template.cpp build/encrypt.o
	$(CMD)

build/encrypt.o : src/encrypt.cpp include/encrypt.h build/common.o
	$(CMD)

bin/sfx : build/sfx_client.o
	$(building)
	@$(CXX) -o $@ $< build/sfx.o build/common.o build/decrypt.o

build/sfx_client.o : src/sfx_client.cpp build/sfx.o
	$(CMD)

build/sfx.o : src/sfx.cpp include/sfx.h build/common.o include/common_template.cpp build/decrypt.o
	$(CMD)

build/decrypt.o : src/decrypt.cpp include/decrypt.h build/common.o
	$(CMD)

build/common.o : src/common.cpp include/common.h
	$(CMD)

clean :
	@echo Cleaning...
	@rm -r build
	@rm -r bin
	@echo Cleaning complete!
