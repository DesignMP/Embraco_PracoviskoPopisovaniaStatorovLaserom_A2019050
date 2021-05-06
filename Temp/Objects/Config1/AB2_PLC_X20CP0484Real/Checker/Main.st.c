#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Checker/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{
(Checker.TRIGER_Enable=1);

}}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{



__AS__Action__OvlStoprov();



SequenceControl(&SC_Checker);




if((Checker.Reset|PoruchaCheckera)){
(SC_Checker.Step=0);
}



switch(SC_Checker.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.Step=0);
(Checker.Automat=0);
(Checker.KoniecCyklu=0);
(Checker.Manual=0);
(Checker.Reset=0);
(Checker.STAV.PoINIT=0);
(Checker.OUT.BANNER_CervenaLED=0);
(Checker.OUT.BANNER_ZelenaLED=0);
(Checker.TRIGER=0);
(Checker.Vysledok_POTVRDENIE=0);
(Zariadenie.KoniecModelu=0);

if((Safety.STAV.ZonaCS_Aktivna&(PoruchaCheckera^1)&Zariadenie.IN.TlakVzduchu_OK)){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"1 - Cakam na spustenie vyroby"; for(zzIndex=0; zzIndex<29l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(Checker.Automat){
(SC_Checker.Step=2);
}else if(Checker.Manual){
(SC_Checker.Step=700);
}




}break;case 2:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"2 - Inicializacia - cakam na spustenie inicializacie"; for(zzIndex=0; zzIndex<52l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

(SC_Checker.IdleTime.IN=1);

if(SC_Checker.IdleTime.Q){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=3);
}


}break;case 3:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"3 - Inicializacia - rozhodnutie o inicializacii"; for(zzIndex=0; zzIndex<47l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if(Checker.STAV.Stopre_PoziciaNAVAZANIE){

(SC_Checker.ResetStep=1);
(SC_Checker.Step=10);
}else if(Checker.STAV.Stopre_PoziciaVYVAZANIE){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=5);
}else{
(SC_Checker.ResetStep=1);
(SC_Checker.Step=7);
}





}break;case 5:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"5 - Inicializacia - cakam na odchod paletky z 2 stopra"; for(zzIndex=0; zzIndex<54l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

(SC_Checker.IdleTime.IN=(Checker.IN.Stoper2_PritomnostPaletky^1));

if(SC_Checker.IdleTime.Q){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=7);
}


}break;case 7:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"7 - Inicializacia - preklopenie stoprov do pozicie navazania"; for(zzIndex=0; zzIndex<60l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if((SC_Checker.Switch1^1)){
(Stopre_pozNAVAZANIE=1);
(SC_Checker.Switch1=1);
}

if(Checker.STAV.Stopre_PoziciaNAVAZANIE){

(SC_Checker.ResetStep=1);
(SC_Checker.Step=10);
}


}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"10 - Inicializacia - vynulovanie bitu novy vysledok checkera READY"; for(zzIndex=0; zzIndex<66l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if(Checker.STAV.Vysledok_READY){
(Checker.Vysledok_POTVRDENIE=1);
}else{
(Checker.Vysledok_POTVRDENIE=0);
(Checker.STAV.PoINIT=1);
(SC_Checker.ResetStep=1);
(SC_Checker.Step=100);
}





}break;case 100:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"100 - Automaticky Rezim - cakam na pritomnost paletky na 2 stopri"; for(zzIndex=0; zzIndex<65l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=1000);
(SC_Checker.AlarmTime.PT=5000);

(SC_Checker.IdleTime.IN=Checker.IN.Stoper2_PritomnostPaletky);
(SC_Checker.AlarmTime.IN=(Checker.IN.Stoper2_PritomnostPaletky^1));

if(SC_Checker.IdleTime.Q){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=105);
}else if((Checker.KoniecCyklu&(Popisovanie.Automat^1))){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=0);
}else if((Zariadenie.KoniecModelu&SC_Checker.AlarmTime.Q)){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=0);
}

}break;case 105:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"105 - Automaticky Rezim - rozhodnutie o kontrole QR kodu"; for(zzIndex=0; zzIndex<56l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if(Zariadenie.PriechodnyRezim){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=120);
}else if(Checker.KAMERA_OFF){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=120);
}else if(Checker.IN.Stoper2_PritomnostStatora){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=109);
}else{
(SC_Checker.ResetStep=1);
(SC_Checker.Step=120);
}

}break;case 109:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"10 - Automaticky Rezim - vynulovanie bitu novy vysledok checkera READY"; for(zzIndex=0; zzIndex<70l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if(Checker.STAV.Vysledok_READY){
(Checker.Vysledok_POTVRDENIE=1);
}else{
(Checker.Vysledok_POTVRDENIE=0);
(SC_Checker.ResetStep=1);
(SC_Checker.Step=110);
}


}break;case 110:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"110 - Automaticky Rezim - start citania QR kodu"; for(zzIndex=0; zzIndex<47l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if((SC_Checker.Switch1^1)){
(Checker.TRIGER=1);
(SC_Checker.IdleTime.IN=1);
(SC_Checker.Switch1=1);
}

if((Checker.STAV.BUSY|SC_Checker.IdleTime.Q)){
(Checker.TRIGER=0);
(SC_Checker.ResetStep=1);
(SC_Checker.Step=112);
}

}break;case 112:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"112 - Automaticky Rezim - cakam na vysledok z kamery"; for(zzIndex=0; zzIndex<52l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if(Checker.STAV.Vysledok_READY){
if(Checker.STAV.Vysledok_OK){
(Checker.OUT.BANNER_CervenaLED=0);

(SC_Checker.ResetStep=1);
(SC_Checker.Step=120);
}else if(Checker.STAV.Vysledok_NG){

(SC_Checker.ResetStep=1);
(SC_Checker.Step=115);
}
}else if(Checker.KAMERA_OFF){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=120);
}







}break;case 115:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"115 - Automaticky Rezim - vysunutie stopra 1"; for(zzIndex=0; zzIndex<44l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=1000);
(SC_Checker.AlarmTime.PT=5000);

if((SC_Checker.Switch1^1)){
(Stoper1_VYSUN=1);
(SC_Checker.Switch1=1);
}

if(Checker.IN.Stoper1_VYSUNUTY){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=116);
}

}break;case 116:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"116 - Automaticky Rezim - cakam na odobratie statora s paletkou a potvrdenie bannerom"; for(zzIndex=0; zzIndex<80l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=1000);
(SC_Checker.AlarmTime.PT=5000);

(Checker.OUT.BANNER_CervenaLED=Blikac200ms);

if(((Checker.IN.Stoper2_PritomnostPaletky^1)&(Checker.IN.Stoper2_PritomnostStatora^1)&Checker.IN.TlacitkoBANNER)){
(Checker.OUT.BANNER_CervenaLED=0);

(SC_Checker.ResetStep=1);
(SC_Checker.Step=117);
}else if((Checker.KoniecCyklu&(Popisovanie.Automat^1))){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=0);
}


}break;case 117:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"117 - Automaticky Rezim - zasunutie stopra 1"; for(zzIndex=0; zzIndex<44l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=1000);
(SC_Checker.AlarmTime.PT=5000);

if((SC_Checker.Switch1^1)){
(Stoper1_ZASUN=1);
(SC_Checker.Switch1=1);
}

if(Checker.IN.Stoper1_ZASUNUTY){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=100);
}




}break;case 120:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"120 - Automaticky Rezim - cakam na uvolnenie vystupnej trate"; for(zzIndex=0; zzIndex<60l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=1000);
(SC_Checker.AlarmTime.PT=5000);

(SC_Checker.IdleTime.IN=(Checker.IN.ZaplnenieVystupnejTrate^1));

if(SC_Checker.IdleTime.Q){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=121);
}else if((Checker.KoniecCyklu&(Popisovanie.Automat^1))){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=0);
}


}break;case 121:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"121 - Automaticky Rezim - preklopenie stoprov do pozicie vyvazania"; for(zzIndex=0; zzIndex<66l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if((SC_Checker.Switch1^1)){
(Stopre_pozVYVAZANIE=1);
(SC_Checker.Switch1=1);
}

if(Checker.STAV.Stopre_PoziciaVYVAZANIE){
(Checker.STAV.PoINIT=1);
(SC_Checker.ResetStep=1);
(SC_Checker.Step=122);
}

}break;case 122:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"122 - Automaticky Rezim - cakam na odchod paletky z 2 stopra"; for(zzIndex=0; zzIndex<60l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=1000);
(SC_Checker.AlarmTime.PT=5000);

(SC_Checker.IdleTime.IN=(Checker.IN.Stoper2_PritomnostPaletky^1));

if(SC_Checker.IdleTime.Q){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=123);
}

}break;case 123:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"123 - Automaticky Rezim - preklopenie stoprov do pozicie navazania"; for(zzIndex=0; zzIndex<66l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=500);
(SC_Checker.AlarmTime.PT=5000);

if((SC_Checker.Switch1^1)){
(Stopre_pozNAVAZANIE=1);
(SC_Checker.Switch1=1);
}

if(Checker.STAV.Stopre_PoziciaNAVAZANIE){
(SC_Checker.ResetStep=1);
(SC_Checker.Step=100);
}



}break;case 700:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Checker.StepName; plcstring* zzRValue=(plcstring*)"700 - Manualny Rezim"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Checker.IdleTime.PT=8000);
(SC_Checker.AlarmTime.PT=5000);




}break;}



}imp2_case1_19:imp2_endcase1_0:;}
#line 360 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.nodebug"
#line 362 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 365 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/OvlStoprov.st"
static void __AS__Action__OvlStoprov(void){
{

(Checker.STAV.Stopre_PoziciaNAVAZANIE=(Checker.IN.Stoper1_ZASUNUTY&Checker.IN.Stoper2_VYSUNUTY));
(Checker.STAV.Stopre_PoziciaVYVAZANIE=(Checker.IN.Stoper1_VYSUNUTY&Checker.IN.Stoper2_ZASUNUTY));




SequenceControl(&SC_OvlStoprov);



switch(SC_OvlStoprov.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(Stopre_pozNAVAZANIE=0);
(Stopre_pozVYVAZANIE=0);
(Stoper1_VYSUN=0);
(Stoper1_ZASUN=0);
(Checker.OUT.Stoper1_VYSUN=0);
(Checker.OUT.Stoper1_ZASUN=0);
(Checker.OUT.Stoper2_VYSUN=0);
(Checker.OUT.Stoper2_ZASUN=0);
if((((unsigned long)(unsigned short)SC_Checker.Step!=(unsigned long)(unsigned short)0))){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"1 - Rozhodnutie o cinnosti"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(Stopre_pozNAVAZANIE){
(SC_OvlStoprov.Step=10);
}else if(Stopre_pozVYVAZANIE){
(SC_OvlStoprov.Step=20);
}else if(Stoper1_VYSUN){
(SC_OvlStoprov.Step=30);
}else if(Stoper1_ZASUN){
(SC_OvlStoprov.Step=40);
}

}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"10 - Prepnutie oddelovaca do pozicie navazania"; for(zzIndex=0; zzIndex<46l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.IdleTime.PT=3000);
(SC_OvlStoprov.AlarmTime.PT=3000);

if(Checker.Automat){
(SC_OvlStoprov.AlarmTime.IN=1);
}else{
(SC_OvlStoprov.IdleTime.IN=1);
}

if((SC_OvlStoprov.Switch1^1)){
(Checker.OUT.Stoper1_ZASUN=1);
(Checker.OUT.Stoper2_VYSUN=1);
(SC_OvlStoprov.Switch1=1);
}

if(SC_OvlStoprov.AlarmTime.Q){
if((Checker.IN.Stoper1_ZASUNUTY^1)){
(Alarmy[CheckBounds(19,0,100)]=1);
}else if((Checker.IN.Stoper2_VYSUNUTY^1)){
(Alarmy[CheckBounds(22,0,100)]=1);
}
(PoruchaCheckera=1);
(Zariadenie.KoniecCyklu=1);
}

if((Checker.STAV.Stopre_PoziciaNAVAZANIE|SC_OvlStoprov.IdleTime.Q)){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=0);
}


}break;case 20:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"20 - Prepnutie oddelovaca do pozicie vyvazania"; for(zzIndex=0; zzIndex<46l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.IdleTime.PT=3000);
(SC_OvlStoprov.AlarmTime.PT=3000);

if(Checker.Automat){
(SC_OvlStoprov.AlarmTime.IN=1);
}else{
(SC_OvlStoprov.IdleTime.IN=1);
}

if((SC_OvlStoprov.Switch1^1)){
(Checker.OUT.Stoper1_VYSUN=1);
(Checker.OUT.Stoper2_ZASUN=1);
(SC_OvlStoprov.Switch1=1);
}

if(SC_OvlStoprov.AlarmTime.Q){
if((Checker.IN.Stoper1_VYSUNUTY^1)){
(Alarmy[CheckBounds(21,0,100)]=1);
}else if((Checker.IN.Stoper2_ZASUNUTY^1)){
(Alarmy[CheckBounds(20,0,100)]=1);
}
(PoruchaCheckera=1);
(Zariadenie.KoniecCyklu=1);
}

if((Checker.STAV.Stopre_PoziciaVYVAZANIE|SC_OvlStoprov.IdleTime.Q)){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=0);
}


}break;case 30:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"30 - Vysunutie stopra 1"; for(zzIndex=0; zzIndex<23l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.IdleTime.PT=3000);
(SC_OvlStoprov.AlarmTime.PT=3000);

if(Checker.Automat){
(SC_OvlStoprov.AlarmTime.IN=1);
}else{
(SC_OvlStoprov.IdleTime.IN=1);
}

if((SC_OvlStoprov.Switch1^1)){
(Checker.OUT.Stoper1_VYSUN=1);
(SC_OvlStoprov.Switch1=1);
}

if(SC_OvlStoprov.AlarmTime.Q){
(Alarmy[CheckBounds(21,0,100)]=1);
(PoruchaCheckera=1);
(Zariadenie.KoniecCyklu=1);
}

if((Checker.IN.Stoper1_VYSUNUTY|SC_OvlStoprov.IdleTime.Q)){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=0);
}

}break;case 40:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStoprov.StepName; plcstring* zzRValue=(plcstring*)"40 - Zasunutie stopra 1"; for(zzIndex=0; zzIndex<23l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStoprov.IdleTime.PT=3000);
(SC_OvlStoprov.AlarmTime.PT=3000);

if(Checker.Automat){
(SC_OvlStoprov.AlarmTime.IN=1);
}else{
(SC_OvlStoprov.IdleTime.IN=1);
}

if((SC_OvlStoprov.Switch1^1)){
(Checker.OUT.Stoper1_ZASUN=1);
(SC_OvlStoprov.Switch1=1);
}

if(SC_OvlStoprov.AlarmTime.Q){
(Alarmy[CheckBounds(19,0,100)]=1);
(PoruchaCheckera=1);
(Zariadenie.KoniecCyklu=1);
}

if((Checker.IN.Stoper1_ZASUNUTY|SC_OvlStoprov.IdleTime.Q)){
(SC_OvlStoprov.ResetStep=1);
(SC_OvlStoprov.Step=0);
}



}break;}


}imp16385_case0_5:imp16385_endcase0_0:;}
#line 367 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/Program/Checker/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/Checker/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Checker/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Checker/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Checker/Main.st\\\"\\n\"");
__asm__(".previous");
