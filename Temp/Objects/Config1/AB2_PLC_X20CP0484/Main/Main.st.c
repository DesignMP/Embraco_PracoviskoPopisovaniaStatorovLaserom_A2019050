#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Main/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


__AS__Action__OvlSafety();


if((VstupnyOddelovac.Automat|Popisovanie.Automat|Checker.Automat)){
(Zariadenie.STAV.Automat=1);
}else{
(Zariadenie.STAV.Automat=0);
(Zariadenie.STAV.UkoncenieCyklu=0);
}


if((VstupnyOddelovac.Manual|Popisovanie.Manual|Checker.Manual)){
(Zariadenie.STAV.Manual=1);
}else{
(Zariadenie.STAV.Manual=0);
}


if((VstupnyOddelovac.STAV.PoINIT&Popisovanie.STAV.PoINIT&Checker.STAV.PoINIT)){
(Zariadenie.STAV.PoINIT=1);
}else{
(Zariadenie.STAV.PoINIT=0);
}


if((Zariadenie.IN.TlacitkoSTART&~Edge0000200000&1?((Edge0000200000=Zariadenie.IN.TlacitkoSTART&1),1):((Edge0000200000=Zariadenie.IN.TlacitkoSTART&1),0))){
if((Safety.STAV.ZonaCS_Aktivna&(NastalaPorucha^1)&Safety.STAV.ZonaVnutroBunky_Aktivna&(Zariadenie.STAV.UkoncenieCyklu^1)&Zariadenie.IN.TlakVzduchu_OK&(Zariadenie.STAV.Manual^1)&Zariadenie.STAV.Moduly_OK&(((unsigned long)(unsigned char)Vizu.CisloAktualnejObrazovky==(unsigned long)(unsigned char)2))&(Zariadenie.STAV.NezvolenaReceptura^1)&(Zariadenie.KoniecModelu^1))){
(VstupnyOddelovac.Automat=1);
(Popisovanie.Automat=1);
(Checker.Automat=1);
}
}



if(Zariadenie.Manual){
if((Safety.STAV.ZonaCS_Aktivna&(NastalaPorucha^1)&(Zariadenie.STAV.Automat^1))){
(VstupnyOddelovac.Manual=1);
(Popisovanie.Manual=1);
(Checker.Manual=1);
}
(Zariadenie.Manual=0);
}



if(Vizu.TlacitkoRezimAutomat){
if((Zariadenie.STAV.Automat^1)){
(Zariadenie.Reset=1);
}
(Vizu.TlacitkoRezimAutomat=0);
}





if(Zariadenie.Reset){
(VstupnyOddelovac.Reset=1);
(Popisovanie.Reset=1);
(Checker.Reset=1);
(Zariadenie.Reset=0);
}


if(Vizu.TlacitkoRezimAutomat){
if((Zariadenie.STAV.Automat^1)){
(Zariadenie.Reset=1);
}
(Vizu.TlacitkoRezimAutomat=0);
}



if(((Zariadenie.IN.TlacitkoSTOP&~Edge0000200001&1?((Edge0000200001=Zariadenie.IN.TlacitkoSTOP&1),1):((Edge0000200001=Zariadenie.IN.TlacitkoSTOP&1),0))|Zariadenie.KoniecCyklu)){
if((Zariadenie.STAV.PoINIT&(Zariadenie.STAV.UkoncenieCyklu^1))){
(VstupnyOddelovac.KoniecCyklu=1);
(Popisovanie.KoniecCyklu=1);
(Checker.KoniecCyklu=1);
(Zariadenie.STAV.UkoncenieCyklu=1);
}
(Zariadenie.KoniecCyklu=0);
}


(Zariadenie.STAV.Moduly_OK=(Zariadenie.STAV.KOM_Modul_BC1_OK&Zariadenie.STAV.KOM_Modul_DI1_OK&Zariadenie.STAV.KOM_Modul_SI1_OK&Zariadenie.STAV.KOM_Modul_XV_OK));



if((((__AS__STRING_CMP(ZvolenyNazovStatora,"")==0))&(Zariadenie.PriechodnyRezim^1))){
(Zariadenie.STAV.NezvolenaReceptura=1);
(Vizu.Zobraz_HlasenieNezvolenaRecept=0);
}else{
(Zariadenie.STAV.NezvolenaReceptura=0);
(Vizu.Zobraz_HlasenieNezvolenaRecept=1);
}




}imp2_end14_0:;}
#line 110 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.nodebug"
#line 112 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 115 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/OvlSafety.st"
static void __AS__Action__OvlSafety(void){
{


if((Vizu.TlacitkoZamkniDvereBunky&~Edge1638500000&1?((Edge1638500000=Vizu.TlacitkoZamkniDvereBunky&1),1):((Edge1638500000=Vizu.TlacitkoZamkniDvereBunky&1),0))){
if((Safety.STAV.ZonaCS_Aktivna&Safety.IN.DvereBunky_AktuatorVzamku&(Safety.STAV.DvereBunky_Zamknute^1)&Zariadenie.IN.TlakVzduchu_OK)){
(Safety.OUT.DvereBunky_Zamkni=1);
}else if((Safety.STAV.DvereBunky_Zamknute&(Zariadenie.STAV.Automat^1))){
(Safety.OUT.DvereBunky_Zamkni=0);
}
}else if((Safety.STAV.ZonaCS_Aktivna^1)){
(Safety.OUT.DvereBunky_Zamkni=0);
}else if((Safety.OdomkniDvereBunky&(Zariadenie.STAV.Automat^1))){
(Safety.OUT.DvereBunky_Zamkni=0);
}

if((Safety.STAV.DvereBunky_Zamknute^1)){
(Safety.OdomkniDvereBunky=0);
}




(Safety.RESET_ZonyCS=Zariadenie.IN.TlacitkoRESET_CS);



if((Safety.STAV.ZonaCS_Aktivna&Safety.STAV.DvereBunky_Zamknute&(Safety.STAV.ZonaVnutroBunky_Aktivna^1))){
(Safety.RESET_ZonyVnutroBunky=1);
}else{
(Safety.RESET_ZonyVnutroBunky=0);
}


if((Safety.STAV.ZonaCS_Aktivna&Safety.STAV.ZonaVnutroBunky_Aktivna&Safety.STAV.SnimacKrytuLasera_Aktivny&Safety.STAV.SnimacStatorPodLaserom_Aktivny&(Safety.STAV.ZonaLaser_Aktivna^1))){
(Safety.RESET_ZonyLaser=1);
}else{
(Safety.RESET_ZonyLaser=0);
}



}imp16385_end4_0:;}
#line 117 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.nodebug"

void __AS__ImplInitMain_st(void){__BUR__ENTRY_INIT_FUNCT__();}

signed long __AS__STRING_CMP(char* pstr1, char* pstr2)
{while (*pstr1 != 0 && *pstr1 == *pstr2){ pstr1++;pstr2++; } return (*pstr1 == 0 && *pstr2 != 0) ? -1 : (*pstr1 != 0 && *pstr2 == 0) ? 1 : *pstr1 - *pstr2;}

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
__asm__(".ascii \"iecfile \\\"Logical/Program/Main/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/Main/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Main/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Main/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Main/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/AB2_PLC_X20CP0484/Main/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");
