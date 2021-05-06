#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Vycitanie_/citanie_casu_z_PLCab.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.ab"
void __BUR__ENTRY_INIT_FUNCT__(void){
(Zapnutie_citania_casu=1);

}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.ab"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){
(Fub0000100000.enable=Zapnutie_citania_casu);;(Fub0000100000.pDTStructure=((unsigned long)(&System_Cas_Datum)));;DTStructureGetTime(&Fub0000100000);(Status_citania_casu=Fub0000100000.status);


(Systemovy_Cas.Hodina=System_Cas_Datum.hour);
(Systemovy_Cas.Minuta=System_Cas_Datum.minute);
(Systemovy_Cas.Sekunda=System_Cas_Datum.second);

(Systemovy_Datum.Den=System_Cas_Datum.day);
(Systemovy_Datum.Mesiac=System_Cas_Datum.month);
(Systemovy_Datum.Rok=System_Cas_Datum.year);



}
#line 21 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.nodebug"
#line 23 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.ab"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){


}
#line 26 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.nodebug"

void __AS__ImplInitcitanie_casu_z_PLC_ab(void){__BUR__ENTRY_INIT_FUNCT__();}

__asm__(".section \".plc\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsSafety/AsSafety.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsXml/AsXml.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SC/Types.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsTCP/AsTCP.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsMath/AsMath.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpRecipe/MpRecipe.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpRecipe/MpRecipeAlarm.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpRecipe/MpRecipeError.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.typ\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsSafety/AsSafety.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsXml/AsXml.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/IecCheck/IecCheck.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SC/SC.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsTCP/AsTCP.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsMath/AsMath.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpRecipe/MpRecipe.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Includes/AS_TempDecl/Config1/GlobalComponents/MpComponents.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/operator/operator.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/runtime/runtime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsIecCon/AsIecCon.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsSafety/AsSafety.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/FileIO/FileIO.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/DataObj/DataObj.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsXml/AsXml.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsBrStr/AsBrStr.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/sys_lib/sys_lib.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/SC/Constants.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsTCP/AsTCP.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/AsMath/AsMath.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpBase/MpBase.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Vycitanie_/citanie_casu_z_PLC.ab.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Vycitanie_/citanie_casu_z_PLC.ab.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/Vycitanie_casu/citanie_casu_z_PLC.ab\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/AB2_PLC_X20CP0484/Vycitanie_/citanie_casu_z_PLC.ab.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");
