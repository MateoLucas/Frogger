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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Back/cars.o \
	${OBJECTDIR}/Back/finishline.o \
	${OBJECTDIR}/Back/frog.o \
	${OBJECTDIR}/Back/frogger.o \
	${OBJECTDIR}/Back/level.o \
	${OBJECTDIR}/Back/loadsave.o \
	${OBJECTDIR}/Back/logs.o \
	${OBJECTDIR}/Back/position.o \
	${OBJECTDIR}/Back/timer.o \
	${OBJECTDIR}/Front/Allegro/al_input.o \
	${OBJECTDIR}/Front/Allegro/allegro.o \
	${OBJECTDIR}/Front/Raspi/rasp_input.o \
	${OBJECTDIR}/Front/Raspi/raspi.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/froggerfinal

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/froggerfinal: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/froggerfinal ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Back/cars.o: Back/cars.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/cars.o Back/cars.c

${OBJECTDIR}/Back/finishline.o: Back/finishline.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/finishline.o Back/finishline.c

${OBJECTDIR}/Back/frog.o: Back/frog.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/frog.o Back/frog.c

${OBJECTDIR}/Back/frogger.o: Back/frogger.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/frogger.o Back/frogger.c

${OBJECTDIR}/Back/level.o: Back/level.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/level.o Back/level.c

${OBJECTDIR}/Back/loadsave.o: Back/loadsave.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/loadsave.o Back/loadsave.c

${OBJECTDIR}/Back/logs.o: Back/logs.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/logs.o Back/logs.c

${OBJECTDIR}/Back/position.o: Back/position.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/position.o Back/position.c

${OBJECTDIR}/Back/timer.o: Back/timer.c
	${MKDIR} -p ${OBJECTDIR}/Back
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Back/timer.o Back/timer.c

${OBJECTDIR}/Front/Allegro/al_input.o: Front/Allegro/al_input.c
	${MKDIR} -p ${OBJECTDIR}/Front/Allegro
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Front/Allegro/al_input.o Front/Allegro/al_input.c

${OBJECTDIR}/Front/Allegro/allegro.o: Front/Allegro/allegro.c
	${MKDIR} -p ${OBJECTDIR}/Front/Allegro
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Front/Allegro/allegro.o Front/Allegro/allegro.c

${OBJECTDIR}/Front/Raspi/rasp_input.o: Front/Raspi/rasp_input.c
	${MKDIR} -p ${OBJECTDIR}/Front/Raspi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Front/Raspi/rasp_input.o Front/Raspi/rasp_input.c

${OBJECTDIR}/Front/Raspi/raspi.o: Front/Raspi/raspi.c
	${MKDIR} -p ${OBJECTDIR}/Front/Raspi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Front/Raspi/raspi.o Front/Raspi/raspi.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
