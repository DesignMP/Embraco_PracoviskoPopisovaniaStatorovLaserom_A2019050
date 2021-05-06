#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Popisovani/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


__AS__Action__OvlStopra();
__AS__Action__OvlZdvizky();
__AS__Action__SpravaPreLaser();



SequenceControl(&SC_Popisovanie);




if((Popisovanie.Reset|PoruchaPopisovania)){
(SC_Popisovanie.Step=0);
}

switch(SC_Popisovanie.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStopra.Step=0);
(SC_OvlZdvizky.Step=0);
(Popisovanie.Automat=0);
(Popisovanie.KoniecCyklu=0);
(Popisovanie.Manual=0);
(Popisovanie.Reset=0);
(Popisovanie.STAV.PoINIT=0);
(Laser.Commands.VyberSpravuLasera=0);
(Laser.Commands.OdosliDataSpravy=0);
(Popisovanie.OUT.Laser_StartZnacenia=0);
(Popisovanie.OUT.Odsavanie_Start=0);
(Popisovanie.PAR.PocetPrazdnychPaletiek=0);
(Popisovanie.STAV.Zdvizka_PritomnostNGkusu=0);


if((Safety.STAV.ZonaCS_Aktivna&(PoruchaPopisovania^1)&Zariadenie.IN.TlakVzduchu_OK&Safety.STAV.ZonaVnutroBunky_Aktivna)){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"1 - Cakam na spustenie vyroby"; for(zzIndex=0; zzIndex<29l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(Popisovanie.Automat){
(SC_Popisovanie.Step=2);
}else if(Popisovanie.Manual){
(SC_Popisovanie.Step=700);
}





}break;case 2:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"2 - Inicializacia - cakam na spustenie inicializacie"; for(zzIndex=0; zzIndex<52l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

(SC_Popisovanie.IdleTime.IN=1);

if(SC_Popisovanie.IdleTime.Q){
(Zariadenie.TaktTime_RESET=1);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=3);
}


}break;case 3:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"3 - Inicializacia - rozhodnutie o inicializacii"; for(zzIndex=0; zzIndex<47l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);


if(Popisovanie.IN.Zdvizka_ZASUNUTA){
if(Popisovanie.IN.StoperZdvizky_VYSUNUTY){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=15);
}else if(Popisovanie.IN.StoperZdvizky_ZASUNUTY){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=4);
}
}else{
if(Popisovanie.IN.StoperZdvizky_VYSUNUTY){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=10);
}else if(Popisovanie.IN.StoperZdvizky_ZASUNUTY){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=5);
}
}


}break;case 4:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"4 - Inicializacia - cakam na odchod paletky zo stopra zdvizky"; for(zzIndex=0; zzIndex<61l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=1000);
(SC_Popisovanie.AlarmTime.PT=5000);

(SC_Popisovanie.IdleTime.IN=(Popisovanie.IN.StoperZdvizky_PritomnostPaletky^1));

if(SC_Popisovanie.IdleTime.Q){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=5);
}


}break;case 5:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"5 - Inicializacia - vysunutie stopra zdvizky"; for(zzIndex=0; zzIndex<44l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(StoperZdvizky_VYSUN=1);
(SC_Popisovanie.Switch1=1);
}

if(Popisovanie.IN.StoperZdvizky_VYSUNUTY){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=10);
}


}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"10 - Inicializacia - zasunutie zdvizky"; for(zzIndex=0; zzIndex<38l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(Zdvizku_ZASUN=1);
(SC_Popisovanie.Switch1=1);
}

if(Popisovanie.IN.Zdvizka_ZASUNUTA){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=15);
}

}break;case 15:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"15 - Inicializacia - vyber spravy do lasera"; for(zzIndex=0; zzIndex<43l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(Laser.Commands.VyberSpravuLasera=1);
(SC_Popisovanie.Switch1=1);
}

if((Laser.Status.VyberSpravy_OK&~Edge0000400000&1?((Edge0000400000=Laser.Status.VyberSpravy_OK&1),1):((Edge0000400000=Laser.Status.VyberSpravy_OK&1),0))){
(Popisovanie.STAV.PoINIT=1);
if((Zariadenie.PriechodnyRezim^1)){
(Popisovanie.OUT.Odsavanie_Start=1);
}
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=100);
}else if((Laser.Status.VyberSpravy_NG&~Edge0000400001&1?((Edge0000400001=Laser.Status.VyberSpravy_NG&1),1):((Edge0000400001=Laser.Status.VyberSpravy_NG&1),0))){
(Alarmy[CheckBounds(29,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}





}break;case 100:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"100 - Automaticky Rezim - cakam na pritomnost paletky na stopri zdvizky"; for(zzIndex=0; zzIndex<71l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);


(SC_Popisovanie.IdleTime.IN=Popisovanie.IN.StoperZdvizky_PritomnostPaletky);

if(Popisovanie.KoniecCyklu){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=0);
}else if(Zariadenie.KoniecModelu){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=0);
}else if(SC_Popisovanie.IdleTime.Q){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=103);
}


}break;case 103:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"103 - Automaticky Rezim - rozhodnutie o popisovani statora"; for(zzIndex=0; zzIndex<58l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if(Zariadenie.PriechodnyRezim){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=130);
}else if(Stav_StatorPopisany){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=130);
}else if(Popisovanie.IN.StoperZdvizky_PritomnostStatora){
(Popisovanie.PAR.PocetPrazdnychPaletiek=0);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=105);
}else{
(Popisovanie.PAR.PocetPrazdnychPaletiek=(Popisovanie.PAR.PocetPrazdnychPaletiek+1));
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=120);
}


}break;case 105:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"105 - Automaticky Rezim - kontrola safety snimaca statora pod laserom"; for(zzIndex=0; zzIndex<69l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if((Safety.STAV.SnimacStatorPodLaserom_Aktivny^1)){
(Zariadenie.TaktTime_ZAPIS=1);
(Zariadenie.TaktTime_START=1);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=107);
}else{
(Alarmy[CheckBounds(23,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}


}break;case 107:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"107 - Automaticky Rezim - vysunutie zdvizky"; for(zzIndex=0; zzIndex<43l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=4000);

if((SC_Popisovanie.Switch1^1)){
(Zdvizku_VYSUN=1);
(SC_Popisovanie.AlarmTime.IN=1);
(SC_Popisovanie.Switch1=1);
}

if(Safety.STAV.SnimacStatorPodLaserom_Aktivny){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=111);
}else if(SC_Popisovanie.AlarmTime.Q){
(Popisovanie.STAV.Zdvizka_PritomnostNGkusu=1);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=110);
}



}break;case 110:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"107 - Automaticky Rezim - cakam na potvrdenie obsluhy"; for(zzIndex=0; zzIndex<53l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if(((Popisovanie.STAV.Zdvizka_PritomnostNGkusu^1)&(((unsigned long)(unsigned short)SC_OvlZdvizky.Step==(unsigned long)(unsigned short)1)))){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=115);
}


}break;case 111:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"111 - Automaticky Rezim - posielam spravu do lasera"; for(zzIndex=0; zzIndex<51l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(Laser.Commands.OdosliDataSpravy=1);
(SC_Popisovanie.Switch1=1);
}

if((Laser.Status.OdoslanieDatSpravy_OK&~Edge0000400002&1?((Edge0000400002=Laser.Status.OdoslanieDatSpravy_OK&1),1):((Edge0000400002=Laser.Status.OdoslanieDatSpravy_OK&1),0))){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=112);
}else if((Laser.Status.OdoslanieDatSpravy_NG&~Edge0000400003&1?((Edge0000400003=Laser.Status.OdoslanieDatSpravy_NG&1),1):((Edge0000400003=Laser.Status.OdoslanieDatSpravy_NG&1),0))){
(Alarmy[CheckBounds(26,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}


}break;case 112:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"112 - Automaticky Rezim - cakam na stav Laser READY"; for(zzIndex=0; zzIndex<51l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

(SC_Popisovanie.AlarmTime.IN=1);

if((Popisovanie.IN.Laser_StavREADY&Safety.STAV.ZonaLaser_Aktivna)){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=113);
}

if(SC_Popisovanie.AlarmTime.Q){
(Alarmy[CheckBounds(25,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}


}break;case 113:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"113 - Automaticky Rezim - start popisovania"; for(zzIndex=0; zzIndex<43l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(Popisovanie.OUT.Laser_StartZnacenia=1);
(SC_Popisovanie.Switch1=1);
}

if(Popisovanie.IN.Laser_StavBUSY){
(Popisovanie.OUT.Laser_StartZnacenia=0);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=114);
}

}break;case 114:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"114 - Automaticky Rezim - cakam na ukoncenie popisovania"; for(zzIndex=0; zzIndex<56l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if(Popisovanie.IN.Laser_StavEND){
(Stav_StatorPopisany=1);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=115);
}


}break;case 115:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"115 - Automaticky Rezim - zasunutie zdvizky"; for(zzIndex=0; zzIndex<43l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(Zdvizku_ZASUN=1);
(SC_Popisovanie.Switch1=1);
}

if((Popisovanie.IN.Zdvizka_ZASUNUTA&(Safety.STAV.SnimacStatorPodLaserom_Aktivny^1))){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=130);
}else if((Popisovanie.IN.Zdvizka_ZASUNUTA&Safety.STAV.SnimacStatorPodLaserom_Aktivny)){
(Alarmy[CheckBounds(24,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}


}break;case 120:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"120 - Automaticky Rezim - kontrola poctu prazdnych paletiek"; for(zzIndex=0; zzIndex<59l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);

if((((unsigned long)(unsigned char)Popisovanie.PAR.PocetPrazdnychPaletiek>=(unsigned long)(unsigned char)2))){
(Zariadenie.KoniecModelu=1);
(Vizu.Zobraz_HlasenieVymenaModelu=0);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=130);
}else{
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=130);
}



}break;case 130:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"130 - Automaticky Rezim - cakam na uvolnenie snimaca zasoby pred kamerou"; for(zzIndex=0; zzIndex<72l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=200);
(SC_Popisovanie.AlarmTime.PT=5000);

(SC_Popisovanie.IdleTime.IN=(Checker.IN.ZasobaPredStoprom1^1));

if(SC_Popisovanie.IdleTime.Q){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=131);
}else if(Popisovanie.KoniecCyklu){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=0);
}



}break;case 131:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"131 - Automaticky Rezim - zasunutie stopra zdvizky"; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(StoperZdvizky_ZASUN=1);
(SC_Popisovanie.Switch1=1);
}

if(Popisovanie.IN.StoperZdvizky_ZASUNUTY){
(Stav_StatorPopisany=0);
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=133);
}

}break;case 133:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"133 - Automaticky Rezim - cakam na odchod paletky zo stopra zdvizky"; for(zzIndex=0; zzIndex<67l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

(SC_Popisovanie.IdleTime.IN=(Popisovanie.IN.StoperZdvizky_PritomnostPaletky^1));

if(SC_Popisovanie.IdleTime.Q){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=135);
}


}break;case 135:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"135 - Automaticky Rezim - vysunutie stopra zdvizky"; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=500);
(SC_Popisovanie.AlarmTime.PT=5000);

if((SC_Popisovanie.Switch1^1)){
(StoperZdvizky_VYSUN=1);
(SC_Popisovanie.Switch1=1);
}

if(Popisovanie.IN.StoperZdvizky_VYSUNUTY){
(SC_Popisovanie.ResetStep=1);
(SC_Popisovanie.Step=100);
}








}break;case 700:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Popisovanie.StepName; plcstring* zzRValue=(plcstring*)"700 - Manualny Rezim"; for(zzIndex=0; zzIndex<20l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Popisovanie.IdleTime.PT=8000);
(SC_Popisovanie.AlarmTime.PT=5000);




}break;}


}imp4_case1_23:imp4_endcase1_0:;}
#line 446 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"
#line 448 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 451 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/OvlStopra.st"
static void __AS__Action__OvlStopra(void){
{

SequenceControl(&SC_OvlStopra);



switch(SC_OvlStopra.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStopra.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(StoperZdvizky_VYSUN=0);
(StoperZdvizky_ZASUN=0);
(Popisovanie.OUT.StoperZdvizky_VYSUN=0);
(Popisovanie.OUT.StoperZdvizky_ZASUN=0);
if((((unsigned long)(unsigned short)SC_Popisovanie.Step!=(unsigned long)(unsigned short)0))){
(SC_OvlStopra.ResetStep=1);
(SC_OvlStopra.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStopra.StepName; plcstring* zzRValue=(plcstring*)"1 - Rozhodnutie o cinnosti"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(StoperZdvizky_VYSUN){
(SC_OvlStopra.Step=10);
}else if(StoperZdvizky_ZASUN){
(SC_OvlStopra.Step=20);
}

}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStopra.StepName; plcstring* zzRValue=(plcstring*)"10 - Vysunutie stopra"; for(zzIndex=0; zzIndex<21l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStopra.IdleTime.PT=3000);
(SC_OvlStopra.AlarmTime.PT=3000);

if(Popisovanie.Automat){
(SC_OvlStopra.AlarmTime.IN=1);
}else{
(SC_OvlStopra.IdleTime.IN=1);
}

if((SC_OvlStopra.Switch1^1)){
(Popisovanie.OUT.StoperZdvizky_VYSUN=1);
(SC_OvlStopra.Switch1=1);
}

if(SC_OvlStopra.AlarmTime.Q){
(Alarmy[CheckBounds(15,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}

if((Popisovanie.IN.StoperZdvizky_VYSUNUTY|SC_OvlStopra.IdleTime.Q)){
(SC_OvlStopra.ResetStep=1);
(SC_OvlStopra.Step=0);
}

}break;case 20:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlStopra.StepName; plcstring* zzRValue=(plcstring*)"20 - Zasunutie stopra"; for(zzIndex=0; zzIndex<21l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlStopra.IdleTime.PT=3000);
(SC_OvlStopra.AlarmTime.PT=3000);

if(Popisovanie.Automat){
(SC_OvlStopra.AlarmTime.IN=1);
}else{
(SC_OvlStopra.IdleTime.IN=1);
}

if((SC_OvlStopra.Switch1^1)){
(Popisovanie.OUT.StoperZdvizky_ZASUN=1);
(SC_OvlStopra.Switch1=1);
}

if(SC_OvlStopra.AlarmTime.Q){
(Alarmy[CheckBounds(16,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}

if((Popisovanie.IN.StoperZdvizky_ZASUNUTY|SC_OvlStopra.IdleTime.Q)){
(SC_OvlStopra.ResetStep=1);
(SC_OvlStopra.Step=0);
}


}break;}


}imp16385_case0_3:imp16385_endcase0_0:;}
#line 453 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/OvlZdvizky.st"
static void __AS__Action__OvlZdvizky(void){
{

SequenceControl(&SC_OvlZdvizky);



switch(SC_OvlZdvizky.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlZdvizky.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(Zdvizku_VYSUN=0);
(Zdvizku_ZASUN=0);


if((((unsigned long)(unsigned short)SC_Popisovanie.Step!=(unsigned long)(unsigned short)0))){
(SC_OvlZdvizky.ResetStep=1);
(SC_OvlZdvizky.Step=1);
}

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlZdvizky.StepName; plcstring* zzRValue=(plcstring*)"1 - Rozhodnutie o cinnosti"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(Zdvizku_VYSUN){
(SC_OvlZdvizky.Step=10);
}else if(Zdvizku_ZASUN){
(SC_OvlZdvizky.Step=20);
}

}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlZdvizky.StepName; plcstring* zzRValue=(plcstring*)"10 - Vysunutie zdvizky"; for(zzIndex=0; zzIndex<22l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlZdvizky.IdleTime.PT=3000);
(SC_OvlZdvizky.AlarmTime.PT=3000);

if(Popisovanie.Automat){
(SC_OvlZdvizky.AlarmTime.IN=1);
}else{
(SC_OvlZdvizky.IdleTime.IN=1);
}

if((SC_OvlZdvizky.Switch1^1)){
(Popisovanie.OUT.Zdvizku_ZASUN=0);
(Popisovanie.OUT.Zdvizku_VYSUN=1);
(SC_OvlZdvizky.IdleTime.IN=1);
(SC_OvlZdvizky.Switch1=1);
}







if(((Popisovanie.IN.Zdvizka_VYSUNUTA|Safety.STAV.SnimacStatorPodLaserom_Aktivny)|SC_OvlZdvizky.IdleTime.Q)){
(SC_OvlZdvizky.ResetStep=1);
(SC_OvlZdvizky.Step=0);
}




}break;case 20:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_OvlZdvizky.StepName; plcstring* zzRValue=(plcstring*)"20 - Zasunutie zdvizky"; for(zzIndex=0; zzIndex<22l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_OvlZdvizky.IdleTime.PT=3000);
(SC_OvlZdvizky.AlarmTime.PT=3000);

if(Popisovanie.Automat){
(SC_OvlZdvizky.AlarmTime.IN=1);
}else{
(SC_OvlZdvizky.IdleTime.IN=1);
}

if((SC_OvlZdvizky.Switch1^1)){
(Popisovanie.OUT.Zdvizku_VYSUN=0);
(Popisovanie.OUT.Zdvizku_ZASUN=1);
(SC_OvlZdvizky.Switch1=1);
}

if(SC_OvlZdvizky.AlarmTime.Q){
(Alarmy[CheckBounds(18,0,100)]=1);
(PoruchaPopisovania=1);
(Zariadenie.KoniecCyklu=1);
}

if((Popisovanie.IN.Zdvizka_ZASUNUTA|SC_OvlZdvizky.IdleTime.Q)){
(SC_OvlZdvizky.ResetStep=1);
(SC_OvlZdvizky.Step=0);
}




}break;}



}imp16386_case0_3:imp16386_endcase0_0:;}
#line 453 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/SpravaPreLaser.st"
static void __AS__Action__SpravaPreLaser(void){
{




{int zzIndex; plcstring* zzLValue=(plcstring*)QR_Kod.BOM_Statora; plcstring* zzRValue=(plcstring*)ZvolenyBOM_kod_Statora; for(zzIndex=0; zzIndex<7l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};



if((((unsigned long)(unsigned char)System_Cas_Datum.day<(unsigned long)(unsigned char)10))){
brsstrcpy(((unsigned long)(&Systemovy_Datum_STR.Den)),((unsigned long)(&"0")));
usint2str(System_Cas_Datum.day,Den_String,3);
brsstrcat(((unsigned long)(&Systemovy_Datum_STR.Den)),((unsigned long)(&Den_String)));
}else{
usint2str(System_Cas_Datum.day,Systemovy_Datum_STR.Den,3);
}

if((((unsigned long)(unsigned char)System_Cas_Datum.month<(unsigned long)(unsigned char)10))){
brsstrcpy(((unsigned long)(&Systemovy_Datum_STR.Mesiac)),((unsigned long)(&"0")));
usint2str(System_Cas_Datum.month,Mesiac_String,3);
brsstrcat(((unsigned long)(&Systemovy_Datum_STR.Mesiac)),((unsigned long)(&Mesiac_String)));
}else{
usint2str(System_Cas_Datum.month,Systemovy_Datum_STR.Mesiac,3);
}

uint2str(System_Cas_Datum.year,Rok_STRING,5);
brsmemcpy(((unsigned long)(&Rok_PoleUSINT)),((unsigned long)(&Rok_STRING)),5);

brsmemcpy(((unsigned long)(&Rok_Cislica1)),((unsigned long)(&Rok_PoleUSINT[CheckBounds(2,0,3)])),1);
brsmemcpy(((unsigned long)(&Rok_Cislica2)),((unsigned long)(&Rok_PoleUSINT[CheckBounds(3,0,3)])),1);

{int zzIndex; plcstring* zzLValue=(plcstring*)Systemovy_Datum_STR.Rok; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
brsstrcat(((unsigned long)(&Systemovy_Datum_STR.Rok)),((unsigned long)(&Rok_Cislica1)));
brsstrcat(((unsigned long)(&Systemovy_Datum_STR.Rok)),((unsigned long)(&Rok_Cislica2)));

{int zzIndex; plcstring* zzLValue=(plcstring*)TextPole_Datum; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
brsstrcat(((unsigned long)(&TextPole_Datum)),((unsigned long)(&Systemovy_Datum_STR.Rok)));

brsstrcat(((unsigned long)(&TextPole_Datum)),((unsigned long)(&Systemovy_Datum_STR.Mesiac)));

brsstrcat(((unsigned long)(&TextPole_Datum)),((unsigned long)(&Systemovy_Datum_STR.Den)));

{int zzIndex; plcstring* zzLValue=(plcstring*)QR_Kod.DatumVyroby; plcstring* zzRValue=(plcstring*)TextPole_Datum; for(zzIndex=0; zzIndex<6l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};





if((((unsigned long)(unsigned char)System_Cas_Datum.hour<(unsigned long)(unsigned char)10))){
brsstrcpy(((unsigned long)(&Systemovy_Cas_STR.Hodina)),((unsigned long)(&"0")));
usint2str(System_Cas_Datum.hour,Hodina_String,3);
brsstrcat(((unsigned long)(&Systemovy_Cas_STR.Hodina)),((unsigned long)(&Hodina_String)));
}else{
usint2str(System_Cas_Datum.hour,Systemovy_Cas_STR.Hodina,3);
}



if((((unsigned long)(unsigned char)System_Cas_Datum.minute<(unsigned long)(unsigned char)10))){
brsstrcpy(((unsigned long)(&Systemovy_Cas_STR.Minuta)),((unsigned long)(&"0")));
usint2str(System_Cas_Datum.minute,Minuta_String,3);
brsstrcat(((unsigned long)(&Systemovy_Cas_STR.Minuta)),((unsigned long)(&Minuta_String)));
}else{
usint2str(System_Cas_Datum.minute,Systemovy_Cas_STR.Minuta,3);
}


if((((unsigned long)(unsigned char)System_Cas_Datum.second<(unsigned long)(unsigned char)10))){
brsstrcpy(((unsigned long)(&Systemovy_Cas_STR.Sekunda)),((unsigned long)(&"0")));
usint2str(System_Cas_Datum.second,Sekunda_String,3);
brsstrcat(((unsigned long)(&Systemovy_Cas_STR.Sekunda)),((unsigned long)(&Sekunda_String)));
}else{
usint2str(System_Cas_Datum.second,Systemovy_Cas_STR.Sekunda,3);
}


{int zzIndex; plcstring* zzLValue=(plcstring*)TextPole_Cas; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
brsstrcat(((unsigned long)(&TextPole_Cas)),((unsigned long)(&Systemovy_Cas_STR.Hodina)));

brsstrcat(((unsigned long)(&TextPole_Cas)),((unsigned long)(&Systemovy_Cas_STR.Minuta)));
brsstrcat(((unsigned long)(&TextPole_Cas)),((unsigned long)(&Systemovy_Cas_STR.Sekunda)));

{int zzIndex; plcstring* zzLValue=(plcstring*)QR_Kod.CasVyroby; plcstring* zzRValue=(plcstring*)TextPole_Cas; for(zzIndex=0; zzIndex<6l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};





{int zzIndex; plcstring* zzLValue=(plcstring*)QR_Kod.NazovVyrobnejLinky; plcstring* zzRValue=(plcstring*)"StatorEM"; for(zzIndex=0; zzIndex<8l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};






(length=brsstrlen(((unsigned long)(&ZvolenyBOM_kod_Statora))));
if((((unsigned long)length>=(unsigned long)4))){
brsmemcpy(((unsigned long)(&KodStatora_PoleUSINT)),((unsigned long)(&ZvolenyBOM_kod_Statora)),8);
(i=KodStatora_PoleUSINT[CheckBounds((length-4),0,19)]);
brsstrcpy(((unsigned long)(&PosledneZnaky)),((unsigned long)(&i)));
(i=KodStatora_PoleUSINT[CheckBounds((length-3),0,19)]);
brsstrcat(((unsigned long)(&PosledneZnaky)),((unsigned long)(&i)));
(i=KodStatora_PoleUSINT[CheckBounds((length-2),0,19)]);
brsstrcat(((unsigned long)(&PosledneZnaky)),((unsigned long)(&i)));
(i=KodStatora_PoleUSINT[CheckBounds((length-1),0,19)]);
brsstrcat(((unsigned long)(&PosledneZnaky)),((unsigned long)(&i)));
}

{int zzIndex; plcstring* zzLValue=(plcstring*)QR_Kod.BOM_PosledneZnaky; plcstring* zzRValue=(plcstring*)PosledneZnaky; for(zzIndex=0; zzIndex<4l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};




brsmemcpy(((unsigned long)(&Laser_DataSpravy[CheckBounds(8,0,47)])),((unsigned long)(&QR_Kod.BOM_Statora)),7);
brsmemcpy(((unsigned long)(&Laser_DataSpravy[CheckBounds(17,0,47)])),((unsigned long)(&QR_Kod.DatumVyroby)),6);
brsmemcpy(((unsigned long)(&Laser_DataSpravy[CheckBounds(25,0,47)])),((unsigned long)(&QR_Kod.CasVyroby)),6);
brsmemcpy(((unsigned long)(&Laser_DataSpravy[CheckBounds(33,0,47)])),((unsigned long)(&QR_Kod.NazovVyrobnejLinky)),8);
brsmemcpy(((unsigned long)(&Laser_DataSpravy[CheckBounds(43,0,47)])),((unsigned long)(&QR_Kod.BOM_PosledneZnaky)),4);










}}
#line 453 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/Program/Popisovanie/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Program/Popisovanie/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Popisovani/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Popisovani/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Program/Popisovanie/Main.st\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Temp/Objects/Config1/AB2_PLC_X20CP0484/Popisovani/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'Rok_PoleUSINT'\\n\"");
__asm__(".ascii \"plcdata_const 'Rok_STRING'\\n\"");
__asm__(".ascii \"plcdata_const 'ZvolenyBOM_kod_Statora'\\n\"");
__asm__(".previous");
