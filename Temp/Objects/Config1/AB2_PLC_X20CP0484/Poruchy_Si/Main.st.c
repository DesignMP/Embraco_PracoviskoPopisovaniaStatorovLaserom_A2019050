#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Poruchy_Si/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{



































for((i=0);i<=100;i+=1){
*((char volatile*)&(Alarmy)) = *((char*)&(Alarmy));
if((((unsigned long)(unsigned char)Alarmy[CheckBounds(i,0,100)]==(unsigned long)(unsigned char)1))){
(NastalaPorucha=1);
}
}imp1_endfor0_0:;



if(NastalaPorucha){
(ZobrazSymbolAlarmu=Blikac500ms);
}else{
(ZobrazSymbolAlarmu=0);
}



if((Zariadenie.STAV.Automat&(Zariadenie.STAV.PoINIT^1))){
(Zariadenie.OUT.Majak_ZeleneSvetlo=Blikac200ms);
}else if((Zariadenie.STAV.Automat&Zariadenie.STAV.PoINIT)){
(Zariadenie.OUT.Majak_ZeleneSvetlo=1);
}else{
(Zariadenie.OUT.Majak_ZeleneSvetlo=0);
}




if(Popisovanie.IN.Laser_StavBUSY){
(Zariadenie.OUT.Majak_ZlteSvetlo=1);
}else{
(Zariadenie.OUT.Majak_ZlteSvetlo=0);
}



if(NastalaPorucha){
(Zariadenie.OUT.Majak_CerveneSvetlo=Blikac200ms);
}else{
(Zariadenie.OUT.Majak_CerveneSvetlo=0);
}


if(((((unsigned long)(unsigned char)NastalaPorucha==(unsigned long)(unsigned char)1))&~Edge0000100000&1?((Edge0000100000=(((unsigned long)(unsigned char)NastalaPorucha==(unsigned long)(unsigned char)1))&1),1):((Edge0000100000=(((unsigned long)(unsigned char)NastalaPorucha==(unsigned long)(unsigned char)1))&1),0))){
(Zariadenie.Hukacka_ON=1);
}

if(Zariadenie.Hukacka_ON){
(Zariadenie.OUT.Majak_Hukacka=Blikac500ms);
}else{
(Zariadenie.OUT.Majak_Hukacka=0);
}

if((NastalaPorucha^1)){
(Zariadenie.Hukacka_ON=0);
}else if(Zariadenie.Hukacka_OFF){
(Zariadenie.Hukacka_ON=0);
}


if(PotvrdenieAlarmov){
(Popisovanie.OUT.Laser_ResetPoruchy=1);
brsmemset(((unsigned long)(&Alarmy)),0,101);
(NastalaPorucha=0);
(CasPotvrdeniaAlarmu.IN=1);
(PoruchaVstupnehoOddelovaca=0);
(PoruchaPopisovania=0);
(PoruchaCheckera=0);
(Zariadenie.Hukacka_OFF=1);
(Zariadenie.STAV.PrebiehaResetPoruchy=1);
(PotvrdenieAlarmov=0);
}

if((CasPotvrdeniaAlarmu.Q&(Popisovanie.IN.Laser_ALARM^1))){
(Popisovanie.OUT.Laser_ResetPoruchy=0);
(Zariadenie.STAV.PrebiehaResetPoruchy=0);
(Zariadenie.Hukacka_OFF=0);
(CasPotvrdeniaAlarmu.IN=0);
}

(CasPotvrdeniaAlarmu.PT=2000);
TON(&CasPotvrdeniaAlarmu);





(CasMeraniaTlakuVzduchu.IN=(Zariadenie.IN.TlakVzduchu_OK^1));

if(CasMeraniaTlakuVzduchu.Q){
(Alarmy[CheckBounds(0,0,100)]=1);
(Zariadenie.Reset=1);
}


(CasMeraniaTlakuVzduchu.PT=5000);
TON(&CasMeraniaTlakuVzduchu);



if((Safety.STAV.SafetyPLC_Nabehlo&(Zariadenie.IN.PrepatovaOchrana_OK^1))){
(Alarmy[CheckBounds(1,0,100)]=1);
}


if((Safety.STAV.SafetyPLC_Nabehlo&(Zariadenie.STAV.KOM_Modul_BC1_OK^1))){
(Alarmy[CheckBounds(2,0,100)]=1);
(Zariadenie.Reset=1);
}


if((Safety.STAV.SafetyPLC_Nabehlo&(Zariadenie.STAV.KOM_Modul_DI1_OK^1))){
(Alarmy[CheckBounds(3,0,100)]=1);
(Zariadenie.Reset=1);
}


if((Safety.STAV.SafetyPLC_Nabehlo&(Zariadenie.STAV.KOM_Modul_SI1_OK^1))){
(Alarmy[CheckBounds(4,0,100)]=1);
(Zariadenie.Reset=1);
}


(CasMeraniaModuluXV1.IN=(Safety.STAV.ZonaCS_Aktivna&(Zariadenie.STAV.KOM_Modul_XV_OK^1)));

if(CasMeraniaModuluXV1.Q){
(Alarmy[CheckBounds(5,0,100)]=1);
(Zariadenie.Reset=1);
}


(CasMeraniaModuluXV1.PT=10000);
TON(&CasMeraniaModuluXV1);


if((Zariadenie.STAV.Automat&(Zariadenie.STAV.KOM_Checker_OK^1))){
(Alarmy[CheckBounds(6,0,100)]=1);
(Zariadenie.Reset=1);
}



if((~Safety.STAV.CS_Panel_Odblokov&Edge0000100001&1?((Edge0000100001=Safety.STAV.CS_Panel_Odblokov&1),1):((Edge0000100001=Safety.STAV.CS_Panel_Odblokov&1),0))){
(Alarmy[CheckBounds(7,0,100)]=1);
(Zariadenie.Reset=1);
}


if((~Safety.STAV.CS_Checker_Odblokov&Edge0000100002&1?((Edge0000100002=Safety.STAV.CS_Checker_Odblokov&1),1):((Edge0000100002=Safety.STAV.CS_Checker_Odblokov&1),0))){
(Alarmy[CheckBounds(8,0,100)]=1);
(Zariadenie.Reset=1);
}


if(((Zariadenie.STAV.Automat|Zariadenie.STAV.Manual)&(Zariadenie.IN.NapajanieOdsavania_OK^1))){
(Alarmy[CheckBounds(9,0,100)]=1);
(Zariadenie.Reset=1);
}



if(((Zariadenie.STAV.Automat|Zariadenie.STAV.Manual)&(Zariadenie.IN.NapajanieLasera_OK^1))){
(Alarmy[CheckBounds(10,0,100)]=1);
(Zariadenie.Reset=1);
}











if((Safety.STAV.CS_Checker_Odblokov&Safety.STAV.CS_Panel_Odblokov&(Safety.STAV.ZonaCS_Aktivna^1))){
(Zariadenie.OUT.LED_Tlacitka_RESET_CS=Blikac500ms);
}else if(Safety.STAV.ZonaCS_Aktivna){
(Zariadenie.OUT.LED_Tlacitka_RESET_CS=1);
}else{
(Zariadenie.OUT.LED_Tlacitka_RESET_CS=0);
}


if(((Zariadenie.STAV.Automat^1)&Safety.STAV.ZonaCS_Aktivna&(NastalaPorucha^1)&Safety.STAV.ZonaVnutroBunky_Aktivna&(Zariadenie.STAV.UkoncenieCyklu^1)&Zariadenie.IN.TlakVzduchu_OK&Zariadenie.STAV.Moduly_OK&(((unsigned long)(unsigned char)Vizu.CisloAktualnejObrazovky==(unsigned long)(unsigned char)2))&(Zariadenie.STAV.NezvolenaReceptura^1)&(Zariadenie.KoniecModelu^1))){
(Zariadenie.OUT.LED_Dvojtlacitka_StartStop=Blikac500ms);
}else if((Zariadenie.STAV.Automat&Zariadenie.STAV.UkoncenieCyklu)){
(Zariadenie.OUT.LED_Dvojtlacitka_StartStop=Blikac200ms);
}else if((Zariadenie.STAV.Automat&(Zariadenie.STAV.PoINIT^1))){
(Zariadenie.OUT.LED_Dvojtlacitka_StartStop=1);
}else if((Zariadenie.STAV.Automat&Zariadenie.STAV.PoINIT)){
(Zariadenie.OUT.LED_Dvojtlacitka_StartStop=1);
}else{
(Zariadenie.OUT.LED_Dvojtlacitka_StartStop=0);
}


}imp1_end23_0:;}
#line 241 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.nodebug"
#line 243 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 246 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.nodebug"

void __AS__ImplInitMain_st(void){__BUR__ENTRY_INIT_FUNCT__();}

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
__asm__(".ascii \"iecfile \\\"Logical/Program/Poruchy_Signalizacie/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/Poruchy_Signalizacie/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Poruchy_Si/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Poruchy_Si/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Poruchy_Signalizacie/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/AB2_PLC_X20CP0484/Poruchy_Si/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'Alarmy'\\n\"");
__asm__(".previous");
