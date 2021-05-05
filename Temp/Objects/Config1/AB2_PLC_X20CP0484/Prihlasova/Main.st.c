#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Prihlasova/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{
(MpRecipeXml_1.Load=1);
{int zzIndex; plcstring* zzLValue=(plcstring*)ZvolenyUzivatel; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ZvolenaUroven=0);
(TP_ZobrazPopUpPrihlasenie=1);

}}
#line 8 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.nodebug"
#line 10 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{


SequenceControl(&SC_Uzivatelia);



if((MpRecipeXml_1.Load&(MpRecipeXml_1.CommandDone|MpRecipeXml_1.Error))){
(MpRecipeXml_1.Load=0);
(old_a=1);
(i=0);
(IndexZoznam=0);
}



((*(unsigned long*)&(MpRecipeXml_1.MpLink))=((unsigned long)(&gUzivatelXmlLink)));
(MpRecipeXml_1.Enable=1);
((*(unsigned long*)&(MpRecipeXml_1.Category))=((unsigned long)(&"UZIVATELIA")));
((*(unsigned long*)&(MpRecipeXml_1.Category))=((unsigned long)(&strCategory)));
((*(unsigned long*)&(MpRecipeXml_1.DeviceName))=((unsigned long)(&"HDD")));
((*(unsigned long*)&(MpRecipeXml_1.FileName))=((unsigned long)(&"UlozenyUzivatel")));
MpRecipeXml(&MpRecipeXml_1);

((*(unsigned long*)&(MpRecipeRegPar_1.MpLink))=((unsigned long)(&gUzivatelXmlLink)));
(MpRecipeRegPar_1.Enable=1);
((*(unsigned long*)&(MpRecipeRegPar_1.Category))=((unsigned long)(&"UZIVATELIA")));
((*(unsigned long*)&(MpRecipeRegPar_1.PVName))=((unsigned long)(&"Uzivatel")));
MpRecipeRegPar(&MpRecipeRegPar_1);



for((IndexZoznam=0);IndexZoznam<=50;IndexZoznam+=1){
{int zzIndex; plcstring* zzLValue=(plcstring*)ZoznamUzivatelov[IndexZoznam]; plcstring* zzRValue=(plcstring*)Uzivatel[IndexZoznam].Meno; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
}imp1_endfor1_0:;


if(MoveUP){
if((((signed long)(signed long)(short)i<(signed long)(signed long)(short)50))){
(i=(i+1));
}
(MoveUP=0);
}

if(MoveDown){
if((((signed long)(signed long)(short)i>(signed long)(signed long)(short)0))){
(i=(i-1));
}
(MoveDown=0);
}


if(((((signed long)(signed long)(short)old_a!=(signed long)(signed long)(short)i))&(((signed long)(signed long)(short)i>=(signed long)(signed long)(short)0))&(((signed long)(signed long)(short)i<=(signed long)(signed long)(short)50)))){
{int zzIndex; plcstring* zzLValue=(plcstring*)MenoUzivatela; plcstring* zzRValue=(plcstring*)Uzivatel[i].Meno; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)HesloUzivatela; plcstring* zzRValue=(plcstring*)Uzivatel[i].Heslo; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(UrovenUzivatela=Uzivatel[CheckBounds(i,0,50)].UrovenUzivatela);
(old_a=i);
}




switch(SC_Uzivatelia.Step){

case 0:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"0 - Nulovanie"; for(zzIndex=0; zzIndex<13l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(UlozUzivatelov=0);
(PrihlasUzivatela=0);
(VymazUzivatela=0);
(OdhlasUzivatela=0);
(MpRecipeXml_1.Save=0);
(b=0);
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=1);

}break;case 1:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"1 - Rozhodnutie o cinnosti"; for(zzIndex=0; zzIndex<26l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if(UlozUzivatelov){
(SC_Uzivatelia.Step=10);
}else if(PrihlasUzivatela){
(SC_Uzivatelia.Step=20);
}else if(OdhlasUzivatela){
(SC_Uzivatelia.Step=30);
}else if(VymazUzivatela){
(SC_Uzivatelia.Step=40);
}

}break;case 10:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"10 - Ulozenie uzivatela"; for(zzIndex=0; zzIndex<23l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)Uzivatel[i].Meno; plcstring* zzRValue=(plcstring*)MenoUzivatela; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)Uzivatel[i].Heslo; plcstring* zzRValue=(plcstring*)HesloUzivatela; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(Uzivatel[CheckBounds(i,0,50)].UrovenUzivatela=UrovenUzivatela);
(MpRecipeXml_1.Save=1);
if(MpRecipeXml_1.CommandDone){
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=0);
}


}break;case 20:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"20 - Kontrola prazdneho uzivatela"; for(zzIndex=0; zzIndex<33l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if((((__AS__STRING_CMP(ZadaneMenoUzivatela,"")!=0))&((__AS__STRING_CMP(ZadaneHesloUzivatela,"")!=0)))){
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=21);
}else{
{int zzIndex; plcstring* zzLValue=(plcstring*)ZadaneHesloUzivatela; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=0);
}

}break;case 21:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"21 - Kontrola prihláseného uzivatela"; for(zzIndex=0; zzIndex<36l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
if((((__AS__STRING_CMP(Uzivatel[b].Meno,ZadaneMenoUzivatela)==0))&((__AS__STRING_CMP(Uzivatel[b].Heslo,ZadaneHesloUzivatela)==0)))){
{int zzIndex; plcstring* zzLValue=(plcstring*)ZvolenyUzivatel; plcstring* zzRValue=(plcstring*)Uzivatel[b].Meno; for(zzIndex=0; zzIndex<50l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ZvolenaUroven=Uzivatel[CheckBounds(b,0,50)].UrovenUzivatela);
{int zzIndex; plcstring* zzLValue=(plcstring*)ZadaneHesloUzivatela; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(TP_ZobrazPopUpPrihlasenie=1);
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=0);
}else{
(b=(b+1));
if(((((signed long)(signed long)(short)b==(signed long)(signed long)(short)51))|(((signed long)(signed long)(short)b<(signed long)(signed long)(short)0))|(((signed long)(signed long)(short)b>(signed long)(signed long)(short)51)))){
{int zzIndex; plcstring* zzLValue=(plcstring*)ZadaneMenoUzivatela; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)ZadaneHesloUzivatela; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=0);
}
}

}break;case 30:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"30 - Odhlasenie uzivatela"; for(zzIndex=0; zzIndex<25l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)ZvolenyUzivatel; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(ZvolenaUroven=0);
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=0);


}break;case 40:{
{int zzIndex; plcstring* zzLValue=(plcstring*)SC_Uzivatelia.StepName; plcstring* zzRValue=(plcstring*)"40 - Vymazanie uzivatela"; for(zzIndex=0; zzIndex<24l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)Uzivatel[i].Meno; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
{int zzIndex; plcstring* zzLValue=(plcstring*)Uzivatel[i].Heslo; plcstring* zzRValue=(plcstring*)""; for(zzIndex=0; zzIndex<0l && zzRValue[zzIndex]!=0; zzIndex++) zzLValue[zzIndex] = zzRValue[zzIndex]; zzLValue[zzIndex] = 0;};
(Uzivatel[CheckBounds(i,0,50)].UrovenUzivatela=0);
(MpRecipeXml_1.Save=1);
if(MpRecipeXml_1.CommandDone){
(SC_Uzivatelia.ResetStep=1);
(SC_Uzivatelia.Step=0);
}

}break;}






}imp1_case7_6:imp1_endcase7_0:;}
#line 165 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.nodebug"
#line 167 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 170 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/PrihlasovaciSystem/PrihlasovaciSystem/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/PrihlasovaciSystem/PrihlasovaciSystem/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Prihlasova/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Prihlasova/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/PrihlasovaciSystem/PrihlasovaciSystem/Main.st\\\"\\n\"");
__asm__(".previous");
