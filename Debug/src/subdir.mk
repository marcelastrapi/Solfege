################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Musicien.cpp \
../src/Sound.cpp \
../src/main.cpp 

OBJS += \
./src/Musicien.o \
./src/Sound.o \
./src/main.o 

CPP_DEPS += \
./src/Musicien.d \
./src/Sound.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-5 -std=c++14 -D__GXX_EXPERIMENTAL_CXX0X__ -I../include -I/usr/local/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


