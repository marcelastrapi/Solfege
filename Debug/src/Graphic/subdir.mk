################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graphic/DesktopBase.cpp \
../src/Graphic/Staff.cpp \
../src/Graphic/StaffWidget.cpp 

OBJS += \
./src/Graphic/DesktopBase.o \
./src/Graphic/Staff.o \
./src/Graphic/StaffWidget.o 

CPP_DEPS += \
./src/Graphic/DesktopBase.d \
./src/Graphic/Staff.d \
./src/Graphic/StaffWidget.d 


# Each subdirectory must supply rules for building sources it contributes
src/Graphic/%.o: ../src/Graphic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-5 -std=c++14 -D__GXX_EXPERIMENTAL_CXX0X__ -I../include -I/usr/local/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


