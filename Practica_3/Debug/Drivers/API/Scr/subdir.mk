################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Scr/API_delay.c 

OBJS += \
./Drivers/API/Scr/API_delay.o 

C_DEPS += \
./Drivers/API/Scr/API_delay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Scr/%.o: ../Drivers/API/Scr/%.c Drivers/API/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/CMSIS/Include" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/BSP/STM32F4xx_Nucleo_144" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/Core/Inc" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/API" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/API/Inc" -I"C:/Users/andre/OneDrive/Documentos/CESE/CESE_PdM_workspace/Practica_3/Drivers/API/Scr" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Scr

clean-Drivers-2f-API-2f-Scr:
	-$(RM) ./Drivers/API/Scr/API_delay.d ./Drivers/API/Scr/API_delay.o

.PHONY: clean-Drivers-2f-API-2f-Scr

