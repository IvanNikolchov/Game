#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Main.o \
	${OBJECTDIR}/src/Board.o \
	${OBJECTDIR}/src/BoardColumn.o \
	${OBJECTDIR}/src/Checker.o \
	${OBJECTDIR}/src/Dice.o \
	${OBJECTDIR}/Include/Bitmap.o \
	${OBJECTDIR}/Include/Game.o \
	${OBJECTDIR}/src/StatusBar.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lGL -lGLU -lglut
CXXFLAGS=-lGL -lGLU -lglut

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/backgammon

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/backgammon: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/backgammon ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/Main.o: src/Main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Main.o src/Main.cpp

${OBJECTDIR}/src/Board.o: src/Board.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Board.o src/Board.cpp

${OBJECTDIR}/src/BoardColumn.o: src/BoardColumn.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/BoardColumn.o src/BoardColumn.cpp

${OBJECTDIR}/src/Checker.o: src/Checker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Checker.o src/Checker.cpp

${OBJECTDIR}/src/Dice.o: src/Dice.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Dice.o src/Dice.cpp

${OBJECTDIR}/Include/Bitmap.o: Include/Bitmap.cpp 
	${MKDIR} -p ${OBJECTDIR}/Include
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Include/Bitmap.o Include/Bitmap.cpp

${OBJECTDIR}/Include/Game.o: Include/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/Include
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Include/Game.o Include/Game.cpp

${OBJECTDIR}/src/StatusBar.o: src/StatusBar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/StatusBar.o src/StatusBar.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/backgammon

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
