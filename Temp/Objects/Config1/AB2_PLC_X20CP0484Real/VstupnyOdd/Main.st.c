#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/VstupnyOdd/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


__AS__Action__OvlStoprov();



SequenceControl(&SC_VstupnyOddelovac);




if((VstupnyOddelovac.Reset|PoruchaVstupnehoOddelovaca)){
(SC_VstupnyOddelovac.Step=0);
}


switch(SC_VstupnyOddelovac.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.Step=0);
(VstupnyOddelovac.Automat=0);
(VstupnyOddelovac.KoniecCyklu=0);
(VstupnyOddelovac.Manual=0);
(VstupnyOddelovac.Reset=0);
(VstupnyOddelovac.STAV.PoINIT=0);

if((Safety.STAV.ZonaCS_Aktivna&(PoruchaVstupnehoOddelovaca^1)&Zariadenie.IN.TlakVzduchu_OK)){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"1 - Cakam na spustenie vyroby"; for(zzIndex=0; zzIndex<29l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(VstupnyOddelovac.Automat){
(SC_VstupnyOddelovac.Step=2);
}else if(VstupnyOddelovac.Manual){
(SC_VstupnyOddelovac.Step=700);
}




}break;case 2:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"2 - Inicializacia - cakam na spustenie inicializacie"; for(zzIndex=0; zzIndex<52l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=500);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);

(SC_VstupnyOddelovac.IdleTime.IN=1);

if(SC_VstupnyOddelovac.IdleTime.Q){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=3);
}


}break;case 3:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"3 - Inicializacia - rozhodnutie o inicializacii"; for(zzIndex=0; zzIndex<47l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=500);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);

if(VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE){
(VstupnyOddelovac.STAV.PoINIT=1);
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=100);
}else if(VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=5);
}else{
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=5);
}

}break;case 5:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"5 - Inicializacia - cakam na odchod paletky z 2 stopra"; for(zzIndex=0; zzIndex<54l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=1000);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);

(SC_VstupnyOddelovac.IdleTime.IN=(VstupnyOddelovac.IN.Stoper2_PritomnostPaletky^1));

if(SC_VstupnyOddelovac.IdleTime.Q){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=7);
}

}break;case 7:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"7 - Inicializacia - preklopenie stoprov do pozicie navazania"; for(zzIndex=0; zzIndex<60l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=500);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);

if((SC_VstupnyOddelovac.Switch1^1)){
(Stopre_pozNAVAZANIE=1);
(SC_VstupnyOddelovac.Switch1=1);
}

if(VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE){
(VstupnyOddelovac.STAV.PoINIT=1);
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=100);
}







}break;case 100:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"100 - Automaticky Rezim - cakam na pritomnost paletky na 2 stopri a vyvezenie na stoper zdvizky"; for(zzIndex=0; zzIndex<80l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=100);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);

(SC_VstupnyOddelovac.IdleTime.IN=(Popisovanie.IN.StoperZdvizky_PritomnostPaletky^1));

if(VstupnyOddelovac.KoniecCyklu){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=0);
}else if(Zariadenie.KoniecModelu){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=0);
}else if(Popisovanie.STAV.PoINIT){
if((VstupnyOddelovac.IN.Stoper2_PritomnostPaletky&Popisovanie.IN.Zdvizka_ZASUNUTA&Popisovanie.IN.StoperZdvizky_VYSUNUTY&(Popisovanie.IN.StoperZdvizky_PritomnostPaletky^1))){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=101);
}else if((VstupnyOddelovac.IN.Stoper2_PritomnostPaletky&Popisovanie.IN.Zdvizka_ZASUNUTA&SC_VstupnyOddelovac.IdleTime.Q)){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=101);
}
}


}break;case 101:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"101 - Automaticky Rezim - preklopenie stoprov do pozicie vyvazania"; for(zzIndex=0; zzIndex<66l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=500);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);


if((SC_VstupnyOddelovac.Switch1^1)){
(Stopre_pozVYVAZANIE=1);
(SC_VstupnyOddelovac.Switch1=1);
}

if(VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=105);
}


}break;case 105:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"105 - Automaticky Rezim - cakam na odchod paletky z 2 stopra"; for(zzIndex=0; zzIndex<60l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=500);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);


(SC_VstupnyOddelovac.IdleTime.IN=(VstupnyOddelovac.IN.Stoper2_PritomnostPaletky^1));

if(SC_VstupnyOddelovac.IdleTime.Q){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=108);
}




}break;case 108:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"108 - Automaticky Rezim - preklopenie stoprov do pozicie navazania"; for(zzIndex=0; zzIndex<66l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=500);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);

if((SC_VstupnyOddelovac.Switch1^1)){
(Stopre_pozNAVAZANIE=1);
(SC_VstupnyOddelovac.Switch1=1);
}

if(VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE){
(SC_VstupnyOddelovac.ResetStep=1);
(SC_VstupnyOddelovac.Step=100);
}




}break;case 700:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_VstupnyOddelovac.StepName; plcstring* zzRValue=(plcstring*)"700 - Manualny Rezim"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_VstupnyOddelovac.IdleTime.PT=8000);
(SC_VstupnyOddelovac.AlarmTime.PT=5000);




}break;}




}imp2_case1_10:imp2_endcase1_0:;}
#line 203 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.nodebug"
#line 205 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 208 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/OvlStoprov.st"
static void __AS__Action__OvlStoprov(void){
{


(VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE=(VstupnyOddelovac.IN.Stoper1_ZASUNUTY&VstupnyOddelovac.IN.Stoper2_VYSUNUTY));
(VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE=(VstupnyOddelovac.IN.Stoper1_VYSUNUTY&VstupnyOddelovac.IN.Stoper2_ZASUNUTY));




SequenceControl(&SC_OvlStoprov);



switch(SC_OvlStoprov.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(Stopre_pozNAVAZANIE=0);
(Stopre_pozVYVAZANIE=0);
(VstupnyOddelovac.OUT.Stoper1_VYSUN=0);
(VstupnyOddelovac.OUT.Stoper1_ZASUN=0);
(VstupnyOddelovac.OUT.Stoper2_VYSUN=0);
(VstupnyOddelovac.OUT.Stoper2_ZASUN=0);
if((((unsigned long)(unsigned short)SC_VstupnyOddelovac.Step!=(unsigned long)(unsigned short)0))){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"1 - Rozhodnutie o cinnosti"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(Stopre_pozNAVAZANIE){
(SC_OvlStoprov.Step=10);
}else if(Stopre_pozVYVAZANIE){
(SC_OvlStoprov.Step=20);
}

}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"10 - Prepnutie oddelovaca do pozicie navazania"; for(zzIndex=0; zzIndex<46l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.IdleTime.PT=3000);
(SC_OvlStoprov.AlarmTime.PT=3000);

if(VstupnyOddelovac.Automat){
(SC_OvlStoprov.AlarmTime.IN=1);
}else{
(SC_OvlStoprov.IdleTime.IN=1);
}

if((SC_OvlStoprov.Switch1^1)){
(VstupnyOddelovac.OUT.Stoper1_ZASUN=1);
(VstupnyOddelovac.OUT.Stoper2_VYSUN=1);
(SC_OvlStoprov.Switch1=1);
}

if(SC_OvlStoprov.AlarmTime.Q){
if((VstupnyOddelovac.IN.Stoper1_ZASUNUTY^1)){
(Alarmy[CheckBounds(11,0,100)]=1);
}else if((VstupnyOddelovac.IN.Stoper2_VYSUNUTY^1)){
(Alarmy[CheckBounds(14,0,100)]=1);
}
(PoruchaVstupnehoOddelovaca=1);
(Zariadenie.KoniecCyklu=1);
}

if((VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE|SC_OvlStoprov.IdleTime.Q)){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=0);
}


}break;case 20:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"20 - Prepnutie oddelovaca do pozicie vyvazania"; for(zzIndex=0; zzIndex<46l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.IdleTime.PT=3000);
(SC_OvlStoprov.AlarmTime.PT=3000);

if(VstupnyOddelovac.Automat){
(SC_OvlStoprov.AlarmTime.IN=1);
}else{
(SC_OvlStoprov.IdleTime.IN=1);
}

if((SC_OvlStoprov.Switch1^1)){
(VstupnyOddelovac.OUT.Stoper1_VYSUN=1);
(VstupnyOddelovac.OUT.Stoper2_ZASUN=1);
(SC_OvlStoprov.Switch1=1);
}

if(SC_OvlStoprov.AlarmTime.Q){
if((VstupnyOddelovac.IN.Stoper1_VYSUNUTY^1)){
(Alarmy[CheckBounds(13,0,100)]=1);
}else if((VstupnyOddelovac.IN.Stoper2_ZASUNUTY^1)){
(Alarmy[CheckBounds(12,0,100)]=1);
}
(PoruchaVstupnehoOddelovaca=1);
(Zariadenie.KoniecCyklu=1);
}

if((VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE|SC_OvlStoprov.IdleTime.Q)){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=0);
}



}break;}


}imp16385_case0_3:imp16385_endcase0_0:;}
#line 210 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/Program/VstupnyOddelovac/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/VstupnyOddelovac/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/VstupnyOdd/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/VstupnyOdd/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/VstupnyOddelovac/Main.st\\\"\\n\"");
__asm__(".previous");
