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
COMMANDS_SRC_DIR=./sqlite-db/commands/src
BACKEND_SRC_DIR=./sqlite-db/backend/src

#################################### MAIN ##############################################

main:
		gcc -o main.${TARGET_EXTENSION} ${MAIN_DIR}/main.c ${COMMANDS_SRC_DIR}/*.c  ${BACKEND_SRC_DIR}/*.c
		./main.${TARGET_EXTENSION}

##################################### CLEAN ############################################
clean:	
		${CLEANUP} *.${TARGET_EXTENSION}