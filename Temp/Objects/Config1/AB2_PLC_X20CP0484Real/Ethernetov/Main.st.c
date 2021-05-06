#define _DEFAULT_INCLUDE
#include <bur\plctypes.h>
#include "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Ethernetov/Mainst.h"
#line 1 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.nodebug"
#line 2 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.st"
void __BUR__ENTRY_INIT_FUNCT__(void){{


}}
#line 5 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.nodebug"
#line 7 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.st"
void _CYCLIC __BUR__ENTRY_CYCLIC_FUNCT__(void){{

*((char volatile*)&(Laser_Sprava)) = *((char*)&(Laser_Sprava));


switch(Client.sStep){

case 0:{
if(Laser.Commands.VyberSpravuLasera){
(Laser.Status.PoruchaOtvoreniaKomunikacie=0);
(Laser.Status.PoruchaSpojenia_s_Laserom=0);
(Laser.Status.PoruchaOdoslaniaDat=0);
(Laser.Status.PoruchaZatvoreniaKomunikacie=0);
(Laser.Status.PoruchaPrijatiaDat=0);
(Laser.Status.VyberSpravy_NG=0);
(Laser.Status.VyberSpravy_OK=0);
(Laser.Status.StrataKomunikacie=0);
brsmemset(((unsigned long)(&Laser_Sprava)),0,51);
brsmemset(((unsigned long)(&Laser_Odpoved)),0,51);
brsmemcpy(((unsigned long)(&Laser_Sprava[CheckBounds(0,0,50)])),((unsigned long)(&Laser_NazovSpravy)),13);
(Client.sStep=1);
}else if(Laser.Commands.OdosliDataSpravy){
(Laser.Status.PoruchaOtvoreniaKomunikacie=0);
(Laser.Status.PoruchaSpojenia_s_Laserom=0);
(Laser.Status.PoruchaOdoslaniaDat=0);
(Laser.Status.PoruchaZatvoreniaKomunikacie=0);
(Laser.Status.PoruchaPrijatiaDat=0);
(Laser.Status.OdoslanieDatSpravy_OK=0);
(Laser.Status.OdoslanieDatSpravy_NG=0);
(Laser.Status.StrataKomunikacie=0);
brsmemset(((unsigned long)(&Laser_Sprava)),0,51);
brsmemset(((unsigned long)(&Laser_Odpoved)),0,51);
brsmemcpy(((unsigned long)(&Laser_Sprava[CheckBounds(0,0,50)])),((unsigned long)(&Laser_DataSpravy)),48);
(Client.sStep=1);
}



}break;case 1:{
(Client.TcpOpen_0.enable=1);
(Client.TcpOpen_0.pIfAddr=0);
(Client.TcpOpen_0.port=3490);
(Client.TcpOpen_0.options=0);
TcpOpen(&Client.TcpOpen_0);


if((((unsigned long)(unsigned short)Client.TcpOpen_0.status==(unsigned long)(unsigned short)0))){
(Client.TcpOpen_timeout=0);
(Client.sStep=5);
}else if((((unsigned long)(unsigned short)Client.TcpOpen_0.status==(unsigned long)(unsigned short)ERR_FUB_BUSY))){
(Client.TcpOpen_timeout=(Client.TcpOpen_timeout+1));
if((((unsigned long)Client.TcpOpen_timeout>(unsigned long)50))){
(Laser.Status.PoruchaOtvoreniaKomunikacie=1);
(Client.TcpOpen_timeout=0);
(Client.sStep=100);
}

}else{
(Laser.Status.PoruchaOtvoreniaKomunikacie=1);
(Client.TcpOpen_timeout=0);
(Client.sStep=100);
}

}break;case 5:{
(Client.linger_opt.lLinger=0);
(Client.linger_opt.lOnOff=1);
(Client.TcpIoctl_0.enable=1);
(Client.TcpIoctl_0.ident=Client.TcpOpen_0.ident);
(Client.TcpIoctl_0.ioctl=tcpSO_LINGER_SET);
(Client.TcpIoctl_0.pData=((unsigned long)(&Client.linger_opt)));
(Client.TcpIoctl_0.datalen=8);
TcpIoctl(&Client.TcpIoctl_0);

if((((unsigned long)(unsigned short)Client.TcpIoctl_0.status==(unsigned long)(unsigned short)0))){
(Client.sStep=10);
}else if((((unsigned long)(unsigned short)Client.TcpIoctl_0.status==(unsigned long)(unsigned short)ERR_FUB_BUSY))){

}else{
(Client.sStep=100);
}


}break;case 10:{
(Client.TcpClient_0.enable=1);
(Client.TcpClient_0.ident=Client.TcpOpen_0.ident);
(Client.TcpClient_0.portserv=3490);
(Client.TcpClient_0.pServer=((unsigned long)(&"192.168.1.4")));
TcpClient(&Client.TcpClient_0);


if((((unsigned long)(unsigned short)Client.TcpClient_0.status==(unsigned long)(unsigned short)0))){
(Client.TcpClient_timeout=0);
(Client.sStep=20);
}else if((((unsigned long)(unsigned short)Client.TcpClient_0.status==(unsigned long)(unsigned short)ERR_FUB_BUSY))){
(Client.TcpClient_timeout=(Client.TcpClient_timeout+1));
if((((unsigned long)Client.TcpClient_timeout>(unsigned long)50))){
(Laser.Status.StrataKomunikacie=1);
(Client.TcpClient_timeout=0);
(Client.sStep=40);
}


}else if((((unsigned long)(unsigned short)Client.TcpClient_0.status==(unsigned long)(unsigned short)tcpERR_INVALID))){
(Client.TcpClient_timeout=0);
(Client.sStep=40);
}else{
(Laser.Status.PoruchaSpojenia_s_Laserom=1);
(Client.TcpClient_timeout=0);
(Client.sStep=100);
}


}break;case 20:{
(Client.TcpSend_0.enable=1);
(Client.TcpSend_0.ident=Client.TcpOpen_0.ident);
(Client.TcpSend_0.pData=((unsigned long)(&Laser_Sprava)));
(Client.TcpSend_0.datalen=51);
(Client.TcpSend_0.flags=0);
TcpSend(&Client.TcpSend_0);


if((((unsigned long)(unsigned short)Client.TcpSend_0.status==(unsigned long)(unsigned short)0))){
(Client.sStep=30);
}else if((((unsigned long)(unsigned short)Client.TcpSend_0.status==(unsigned long)(unsigned short)ERR_FUB_BUSY))){

}else if(((((unsigned long)(unsigned short)Client.TcpSend_0.status==(unsigned long)(unsigned short)tcpERR_SENTLEN))|(((unsigned long)(unsigned short)Client.TcpSend_0.status==(unsigned long)(unsigned short)tcpERR_NOT_CONNECTED)))){
(Laser.Status.StrataKomunikacie=1);
(Client.sStep=40);
}else{
(Laser.Status.PoruchaOdoslaniaDat=1);
(Client.sStep=100);
}


}break;case 30:{
(Client.TcpRecv_0.enable=1);
(Client.TcpRecv_0.ident=Client.TcpOpen_0.ident);
(Client.TcpRecv_0.pData=((unsigned long)(&Laser_Odpoved)));
(Client.TcpRecv_0.datamax=51);
(Client.TcpRecv_0.flags=0);
TcpRecv(&Client.TcpRecv_0);

if((((unsigned long)(unsigned short)Client.TcpRecv_0.status==(unsigned long)(unsigned short)0))){
(Client.recv_timeout=0);
(Client.sStep=40);
}else if((((unsigned long)(unsigned short)Client.TcpRecv_0.status==(unsigned long)(unsigned short)tcpERR_NO_DATA))){
(Client.recv_timeout=(Client.recv_timeout+1));
if((((unsigned long)Client.recv_timeout>(unsigned long)50))){
(Client.recv_timeout=0);
(Laser.Status.PoruchaPrijatiaDat=1);
(Client.sStep=40);
}

}else if((((unsigned long)(unsigned short)Client.TcpRecv_0.status==(unsigned long)(unsigned short)ERR_FUB_BUSY))){

}else if((((unsigned long)(unsigned short)Client.TcpRecv_0.status==(unsigned long)(unsigned short)tcpERR_NOT_CONNECTED))){
(Client.recv_timeout=0);
(Laser.Status.StrataKomunikacie=1);
(Client.sStep=40);
}else{
(Laser.Status.PoruchaPrijatiaDat=1);
(Client.recv_timeout=0);
(Client.sStep=100);
}


}break;case 40:{
(Client.TcpClose_0.enable=1);
(Client.TcpClose_0.ident=Client.TcpOpen_0.ident);
(Client.TcpClose_0.how=0);
TcpClose(&Client.TcpClose_0);

if((((unsigned long)(unsigned short)Client.TcpClose_0.status==(unsigned long)(unsigned short)0))){
(Client.sStep=50);
}else if((((unsigned long)(unsigned short)Client.TcpClose_0.status==(unsigned long)(unsigned short)ERR_FUB_BUSY))){

}else{
(Laser.Status.PoruchaZatvoreniaKomunikacie=1);
(Client.sStep=100);
}

}break;case 50:{

if(Laser.Commands.VyberSpravuLasera){
(Laser.Status.VysledokPorovnaniaOdpovede=brsmemcmp(((unsigned long)(&Laser_Odpoved)),((unsigned long)(&OK_OdpovedNaVyberSpravy)),51));
if((((signed long)Laser.Status.VysledokPorovnaniaOdpovede==(signed long)0))){
(Laser.Status.VyberSpravy_OK=1);
(Laser.Commands.VyberSpravuLasera=0);
(Client.sStep=0);
}else{
(Laser.Status.VyberSpravy_NG=1);
(Laser.Commands.VyberSpravuLasera=0);
(Client.sStep=0);
}
}else if(Laser.Commands.OdosliDataSpravy){
(Laser.Status.VysledokPorovnaniaOdpovede=brsmemcmp(((unsigned long)(&Laser_Odpoved)),((unsigned long)(&OK_OdpovedNaDataSpravy)),51));
if((((signed long)Laser.Status.VysledokPorovnaniaOdpovede==(signed long)0))){
(Laser.Status.OdoslanieDatSpravy_OK=1);
(Laser.Commands.OdosliDataSpravy=0);
(Client.sStep=0);
}else{
(Laser.Status.OdoslanieDatSpravy_NG=1);
(Laser.Commands.OdosliDataSpravy=0);
(Client.sStep=0);
}
}




}break;case 100:{
(Laser.Commands.VyberSpravuLasera=0);
(Laser.Commands.OdosliDataSpravy=0);
(Client.sStep=0);


}break;}




}imp1_case0_8:imp1_endcase0_0:;}
#line 228 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.nodebug"
#line 230 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.st"
void _EXIT __BUR__ENTRY_EXIT_FUNCT__(void){{


}}
#line 233 "D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.nodebug"

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
__asm__(".ascii \"iecfile \\\"Logical/Komunikacia_Laser/EthernetovaKomunikacia/Types.typ\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Komunikacia_Laser/EthernetovaKomunikacia/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Ethernetov/Main.st.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"plcreplace \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Temp/Objects/Config1/AB2_PLC_X20CP0484/Ethernetov/Main.st.c\\\" \\\"D:/Projekty BER/Embraco_PracoviskoPopisovaniaStatorovLaserom_A2019050/Logical/Komunikacia_Laser/EthernetovaKomunikacia/Main.st\\\"\\n\"");
__asm__(".previous");

__asm__(".section \".plciec\"");
__asm__(".ascii \"plcdata_const 'Client'\\n\"");
__asm__(".ascii \"plcdata_const 'Laser_DataSpravy'\\n\"");
__asm__(".ascii \"plcdata_const 'Laser_NazovSpravy'\\n\"");
__asm__(".ascii \"plcdata_const 'Laser_Sprava'\\n\"");
__asm__(".ascii \"plcdata_const 'Laser_Odpoved'\\n\"");
__asm__(".ascii \"plcdata_const 'OK_OdpovedNaDataSpravy'\\n\"");
__asm__(".ascii \"plcdata_const 'OK_OdpovedNaVyberSpravy'\\n\"");
__asm__(".ascii \"plcdata_const 'ERR_FUB_BUSY'\\n\"");
__asm__(".ascii \"plcdata_const 'tcpERR_NO_DATA'\\n\"");
__asm__(".ascii \"plcdata_const 'tcpERR_SENTLEN'\\n\"");
__asm__(".ascii \"plcdata_const 'tcpERR_INVALID'\\n\"");
__asm__(".ascii \"plcdata_const 'tcpERR_NOT_CONNECTED'\\n\"");
__asm__(".ascii \"plcdata_const 'tcpSO_LINGER_SET'\\n\"");
__asm__(".previous");
