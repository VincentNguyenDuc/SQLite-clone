#################################### COMMANDS ##########################################

ifeq ($(OSTYPE),cygwin)
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
else ifeq ($(OS),Windows_NT)
	CLEANUP=del /F /Q
	MKDIR=mkdir
	TARGET_EXTENSION=exe
else
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
endif

#################################### DIR ###############################################

MAIN_DIR=./sqlite-db
SRC_DIR=./sqlite-db/src

#################################### MAIN ##############################################
main:
		gcc -o main.${TARGET_EXTENSION} ${MAIN_DIR}/main.c ${SRC_DIR}/input.c ${SRC_DIR}/meta_command.c ${SRC_DIR}/statement.c ${SRC_DIR}/table.c ${SRC_DIR}/promt.c
		./main.${TARGET_EXTENSION}

##################################### CLEAN ############################################
clean:	
		${CLEANUP} *.${TARGET_EXTENSION}