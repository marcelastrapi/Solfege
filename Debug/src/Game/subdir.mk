################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Game/ChordGame.cpp \
../src/Game/Game.cpp \
../src/Game/GameInterval.cpp 

OBJS += \
./src/Game/ChordGame.o \
./src/Game/Game.o \
./src/Game/GameInterval.o 

CPP_DEPS += \
./src/Game/ChordGame.d \
./src/Game/Game.d \
./src/Game/GameInterval.d 


# Each subdirectory must supply rules for building sources it contributes
src/Game/%.o: ../src/Game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-5 -std=c++14 -D__GXX_EXPERIMENTAL_CXX0X__ -I../include -I/usr/local/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


