################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Solfege/ChordNotes.cpp \
../src/Solfege/IntervalNotes.cpp \
../src/Solfege/Note.cpp \
../src/Solfege/ScaleNotes.cpp 

OBJS += \
./src/Solfege/ChordNotes.o \
./src/Solfege/IntervalNotes.o \
./src/Solfege/Note.o \
./src/Solfege/ScaleNotes.o 

CPP_DEPS += \
./src/Solfege/ChordNotes.d \
./src/Solfege/IntervalNotes.d \
./src/Solfege/Note.d \
./src/Solfege/ScaleNotes.d 


# Each subdirectory must supply rules for building sources it contributes
src/Solfege/%.o: ../src/Solfege/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-5 -std=c++14 -D__GXX_EXPERIMENTAL_CXX0X__ -I../include -I/usr/local/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


