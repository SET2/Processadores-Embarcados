################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/Clock_10_ms.c \
../Generated_Code/Cpu.c \
../Generated_Code/Infrared_sensor.c \
../Generated_Code/LED_Blue.c \
../Generated_Code/LED_Green.c \
../Generated_Code/LED_Red.c \
../Generated_Code/MCUC1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/Vectors.c \
../Generated_Code/WAIT1.c 

OBJS += \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/Clock_10_ms.o \
./Generated_Code/Cpu.o \
./Generated_Code/Infrared_sensor.o \
./Generated_Code/LED_Blue.o \
./Generated_Code/LED_Green.o \
./Generated_Code/LED_Red.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o 

C_DEPS += \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/Clock_10_ms.d \
./Generated_Code/Cpu.d \
./Generated_Code/Infrared_sensor.d \
./Generated_Code/LED_Blue.d \
./Generated_Code/LED_Green.d \
./Generated_Code/LED_Red.d \
./Generated_Code/MCUC1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/Vectors.d \
./Generated_Code/WAIT1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/mini casa/Desktop/Eder/Pós_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/Trabalho/Static_Code/PDD" -I"C:/Users/mini casa/Desktop/Eder/Pós_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/Trabalho/Static_Code/IO_Map" -I"C:/Users/mini casa/Desktop/Eder/Pós_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/Trabalho/Sources" -I"C:/Users/mini casa/Desktop/Eder/Pós_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/Trabalho/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


