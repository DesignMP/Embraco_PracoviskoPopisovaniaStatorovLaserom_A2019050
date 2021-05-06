#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/OvladanieG/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{
(Vizu.Zobraz_HlasenieVymenaModelu=1);
(Vizu.Zobraz_ResetZariadenia=1);
(Vizu.Zobraz_HlasenieNaZdvizkeNGkus=1);

}}
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.nodebug"
#line 9 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


if((Safety.STAV.SafetyPLC_Nabehlo^1)){
(Vizu.CisloZadanejObrazovky=0);
if(((((unsigned long)(unsigned char)Blikac500ms==(unsigned long)(unsigned char)1))&~Edge0000100000&1?((Edge0000100000=(((unsigned long)(unsigned char)Blikac500ms==(unsigned long)(unsigned char)1))&1),1):((Edge0000100000=(((unsigned long)(unsigned char)Blikac500ms==(unsigned long)(unsigned char)1))&1),0))){
(Vizu.Slider=(Vizu.Slider+1));
if((((unsigned long)(unsigned char)Vizu.Slider>(unsigned long)(unsigned char)30))){
(Vizu.Slider=0);
}
}
}


if(((((unsigned long)(unsigned char)Safety.STAV.SafetyPLC_Nabehlo==(unsigned long)(unsigned char)1))&~Edge0000100001&1?((Edge0000100001=(((unsigned long)(unsigned char)Safety.STAV.SafetyPLC_Nabehlo==(unsigned long)(unsigned char)1))&1),1):((Edge0000100001=(((unsigned long)(unsigned char)Safety.STAV.SafetyPLC_Nabehlo==(unsigned long)(unsigned char)1))&1),0))){
(Vizu.CisloZadanejObrazovky=1);
}



if((NastalaPorucha&~Edge0000100002&1?((Edge0000100002=NastalaPorucha&1),1):((Edge0000100002=NastalaPorucha&1),0))){
(Vizu.CisloZadanejObrazovky=5);
}




if((Safety.IN.DvereBunky_AktuatorVzamku&(Safety.STAV.DvereBunky_Zamknute^1))){
(Vizu.LED_TlacitkaZamokDveriBunky=Blikac500ms);
}else if(Safety.STAV.DvereBunky_Zamknute){
(Vizu.LED_TlacitkaZamokDveriBunky=2);
}else{
(Vizu.LED_TlacitkaZamokDveriBunky=3);
}




if(Safety.STAV.VyblokovanieZamkov_Aktivne){
(Vizu.Zobraz_HlasenieZamkyVyblokovane=0);
}else{
(Vizu.Zobraz_HlasenieZamkyVyblokovane=1);
}


if((Zariadenie.IN.TlakVzduchu_OK^1)){
(Vizu.Zobraz_HlasenieNizkyTlakVzduchu=0);
}else{
(Vizu.Zobraz_HlasenieNizkyTlakVzduchu=1);
}




if(Zariadenie.STAV.NezvolenaReceptura){
(Vizu.Zobraz_HlasenieNezvolenaRecept=0);
}else{
(Vizu.Zobraz_HlasenieNezvolenaRecept=1);
}


if(Popisovanie.STAV.Zdvizka_PritomnostNGkusu){
(Vizu.Zobraz_HlasenieNaZdvizkeNGkus=0);
}else{
(Vizu.Zobraz_HlasenieNaZdvizkeNGkus=1);
}



if(((((unsigned long)(unsigned char)Vizu.Zobraz_HlasenieVymenaModelu==(unsigned long)(unsigned char)0))&(Zariadenie.STAV.Automat^1))){
(Vizu.Zobraz_TlacitkoOK_ZmenaModelu=0);
}
if((((unsigned long)(unsigned char)Vizu.Zobraz_HlasenieVymenaModelu==(unsigned long)(unsigned char)1))){
(Vizu.Zobraz_TlacitkoOK_ZmenaModelu=1);
}



if((Safety.STAV.ZonaCS_Aktivna^1)){
(Vizu.ZamkniTlacitkoRezimAutomat=1);
}else if((Safety.STAV.ZonaVnutroBunky_Aktivna^1)){
(Vizu.ZamkniTlacitkoRezimAutomat=1);
}else{
(Vizu.ZamkniTlacitkoRezimAutomat=0);
}



if((Safety.STAV.ZonaCS_Aktivna^1)){
(Vizu.ZamkniTlacitkoRezimManual=1);
}else if(NastalaPorucha){
(Vizu.ZamkniTlacitkoRezimManual=1);
}else if(Zariadenie.STAV.Automat){
(Vizu.ZamkniTlacitkoRezimManual=1);
}else if((Zariadenie.IN.TlakVzduchu_OK^1)){
(Vizu.ZamkniTlacitkoRezimManual=1);
}else if((Zariadenie.STAV.Moduly_OK^1)){
(Vizu.ZamkniTlacitkoRezimManual=1);
}else{
(Vizu.ZamkniTlacitkoRezimManual=0);
}



if((Safety.STAV.ZonaVnutroBunky_Aktivna^1)){
(Vizu.ZamkniTlacitkaOvladaniaZdvizky=1);
}else{
(Vizu.ZamkniTlacitkaOvladaniaZdvizky=0);
}



if(Zariadenie.STAV.Automat){
(Vizu.ZamkniTlacitkoZamokDveriBunky=1);
}else{
(Vizu.ZamkniTlacitkoZamokDveriBunky=0);
}



if(Zariadenie.STAV.Automat){
(Vizu.ZamkniTlacitkoPriechodnyRezim=1);
}else{
(Vizu.ZamkniTlacitkoPriechodnyRezim=0);
}


if((Safety.STAV.ZonaLaser_Aktivna^1)){
(Vizu.ZamkniTlacitko_StartPopisovania=1);
}else if((Popisovanie.IN.Laser_StavREADY^1)){
(Vizu.ZamkniTlacitko_StartPopisovania=1);
}else{
(Vizu.ZamkniTlacitko_StartPopisovania=0);
}


if(Popisovanie.IN.Laser_StavREADY){
(Vizu.ZamkniTlacitkoLaserVolbaSpravy=0);
}else{
(Vizu.ZamkniTlacitkoLaserVolbaSpravy=1);
}



if((Popisovanie.IN.Laser_StavREADY&Laser.Status.VyberSpravy_OK)){
(Vizu.ZamkniTlacitkoLaserPosliData=0);
}else{
(Vizu.ZamkniTlacitkoLaserPosliData=1);
}




}imp1_end19_0:;}
#line 162 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.nodebug"
#line 164 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 167 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/HMI/OvladanieGrafiky/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/HMI/OvladanieGrafiky/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/OvladanieG/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/OvladanieG/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/HMI/OvladanieGrafiky/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/AB2_PLC_X20CP0484/OvladanieG/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");
