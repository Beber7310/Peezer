################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/helper/http_fetcher/testfetch/testfetch.c 

OBJS += \
./src/helper/http_fetcher/testfetch/testfetch.o 

C_DEPS += \
./src/helper/http_fetcher/testfetch/testfetch.d 


# Each subdirectory must supply rules for building sources it contributes
src/helper/http_fetcher/testfetch/%.o: ../src/helper/http_fetcher/testfetch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

