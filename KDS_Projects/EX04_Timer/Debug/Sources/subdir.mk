################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/mini casa/Desktop/Eder/P�s_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/EX04_Timer/Static_Code/PDD" -I"C:/Users/mini casa/Desktop/Eder/P�s_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/EX04_Timer/Static_Code/IO_Map" -I"C:/Users/mini casa/Desktop/Eder/P�s_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/EX04_Timer/Sources" -I"C:/Users/mini casa/Desktop/Eder/P�s_Sistemas_Embarcados/Processadores_Embarcados/KDS_Projects/EX04_Timer/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


