# Makefile for the OpenRTOS part of OpenOSEK

#output EXE
TARGET = OpenSAR

#Base Directory
BD = ../../..

OUT = $(BD)/out

#common compilers
AS = gcc
CC = gcc
LD = gcc
AR = ar
RM = rm

#common flags
ASFLGS = 
INCDIR = 	-I$(BD)/include 		\
			-I$(BD)/include/generic \
			-I$(BD)/include/sys		\
			-I$(BD)/system/kernel/include \
			-I$(BD)/app/config	\
			-I$(BD)/app/config/GEN	\
			-I$(BD)/app/inc			\
			-I$(BD)/arch/generic/mingw/kernel	\
			-I$(BD)/system/EcuM			\
			-I$(BD)/system/SchM			\
			-I$(BD)/diagnostic/Dcm		\
			-I$(BD)/communication/Com

MACROS = 	-DWIN32 			\
			-DAUTOSAR_SIMULATOR	\
			-DUSE_DEBUG_PRINTF	\
			-DUSE_ECUM		\
			-DUSE_CAN		\
			-DUSE_CANIF	\
			-DUSE_CANTP	\
			-DUSE_PDUR	\
			-DUSE_COM	\
			-DUSE_DCM	\
			-DUSE_COMM	\
			-DUSE_CANNM	\
			-DUSE_DET	\
			-DUSE_CANNM	\
			-DUSE_NM	\
			-DUSE_CANSM	\
			-DUSE_MCU	\
			-DUSE_PORT	\
			-DUSE_DIO	\
			-DUSE_FLS	\
			-DUSE_FEE	\
			-DcfgCPU_ENDIAN=COM_LITTLE_ENDIAN	\
			-DDEBUG_FEE		\
			-DUSE_NVM	\
			-DUSE_MEMIF	

CCFLGS = -c -g $(MACROS) -std=gnu99 -O2 -Wall $(INCDIR)
LDFLGS = -g $(MACROS) -std=gnu99 -O2 -Wall $(INCDIR) -lwsock32
ARFLGS = rv
RMFLGS = -f	

#common objectives		
dir-y =	$(BD)/app/config	\
		$(BD)/app/config/GEN			\
		$(BD)/arch/generic/mingw/kernel	\
		$(BD)/arch/generic/mingw/drivers	\
		$(BD)/app/src		\
		$(BD)/app/src/Dia		\
		$(BD)/communication/CanIf	\
		$(BD)/communication/CanTp	\
		$(BD)/communication/PduR	\
		$(BD)/communication/CanNm	\
		$(BD)/communication/Nm		\
		$(BD)/communication/CanSM	\
		$(BD)/communication/Com	\
		$(BD)/communication/ComM	\
		$(BD)/diagnostic/Dcm		\
		$(BD)/diagnostic/Det		\
		$(BD)/system/EcuM			\
		$(BD)/system/SchM			\
		$(BD)/memory/Fee			\
		$(BD)/memory/NvM			\
		$(BD)/memory/MemIf			\
		$(BD)/system/Crc
		
src-y = $(foreach x,$(dir-y),$(wildcard $(addprefix $(x)/*,.c)))
obj-y = $(subst .c,.o,$(src-y))	
# kernel files
obj-y += 	$(BD)/system/kernel/alarm.o	\
			$(BD)/system/kernel/application.o	\
			$(BD)/system/kernel/counter.o	\
			$(BD)/system/kernel/event.o	\
			$(BD)/system/kernel/isr.o	\
			$(BD)/system/kernel/resource.o	\
			$(BD)/system/kernel/sched_table.o	\
			$(BD)/system/kernel/task.o			\
			$(BD)/common/cirq_buffer.o

# common library needed for OpenSAR
lib-y = 

#common rules
%.o:%.c
	@echo compile $<  to $@
	@$(CC) $(CCFLGS) -o $@ $<

.PHONY:all clean gen

gen:
			
all:$(obj-y)
	@$(LD) $(BD)/system/kernel/init.c -o $(OUT)/$(TARGET) $(obj-y) $(LDFLGS)
	@echo ">>>>>>>>>>>>>>>>>  BUILD $(TARGET).EXE DONE   <<<<<<<<<<<<<<<<<<<<<<"

Flash.img:
	dd if=/dev/zero of=Flash.img bs=1M count=1
run:Flash.img
	@(start python $(BD)/tools/can/CanBusServer.py --server 8000)  #LS
	#@(start python $(BD)/tools/can/CanBusServer.py --server 9000)  #HS
	@(start $(OUT)/$(TARGET).exe)	
#	@(cd $(BD)/tools/simulator; start python main.py)	
#	@(start python $(BD)/tools/can/com.py)	
#	@(start python $(BD)/tools/can/uds.py --port 8998 0x731 0x732)
	#@(start python $(BD)/tools/can/uds.py --port 8999 0x741 0x742)
clean:
	@$(RM) -f $(OUT)/$(TARGET).exe $(obj-y)
	@rm Flash.img
	@echo ">>>>>>>>>>>>>>>>>>>> CLEAN $(TARGET) Objs Done <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"		