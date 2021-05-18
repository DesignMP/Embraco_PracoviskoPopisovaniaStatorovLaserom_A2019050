export AS_SYSTEM_PATH := C:/BrAutomation/AS/System
export AS_BIN_PATH := C:/BrAutomation/AS47/Bin-en
export AS_INSTALL_PATH := C:/BrAutomation/AS47
export AS_PATH := C:/BrAutomation/AS47
export AS_VC_PATH := C:/BrAutomation/AS47/AS/VC
export AS_GNU_INST_PATH := C:/BrAutomation/AS47/AS/GnuInst/V6.3.0
export AS_STATIC_ARCHIVES_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Archives/Config1/AB2_PLC_X20CP0484
export AS_CPU_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484
export AS_CPU_PATH_2 := D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484
export AS_TEMP_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp
export AS_BINARIES_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Binaries
export AS_PROJECT_CPU_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Physical/Config1/AB2_PLC_X20CP0484
export AS_PROJECT_CONFIG_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Physical/Config1
export AS_PROJECT_PATH := D:/Projekty\ BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050
export AS_PROJECT_NAME := Embraco_PracoviskoPopisovaniaLaserom
export AS_PLC := AB2_PLC_X20CP0484
export AS_TEMP_PLC := AB2_PLC_X20CP0484
export AS_USER_NAME := Martin\ Dvorscak
export AS_CONFIGURATION := Config1
export AS_COMPANY_NAME := \ 
export AS_VERSION := 4.7.6.114\ SP


default: \
	$(AS_CPU_PATH)/Visu.br \
	vcPostBuild_Visu \



include $(AS_CPU_PATH)/Visu/Visu.mak
