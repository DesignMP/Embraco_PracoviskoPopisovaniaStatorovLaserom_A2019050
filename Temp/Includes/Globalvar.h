/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1621250404_1_
#define _BUR_1621250404_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
 #define SeparatorDatumu "."
 #define SeparatorCasu ":"
#else
 _GLOBAL_CONST plcstring SeparatorDatumu[2];
 _GLOBAL_CONST plcstring SeparatorCasu[2];
#endif


/* Variables */
_GLOBAL_RETAIN plcbit Stav_StatorPopisany;
_GLOBAL struct QRkod_typ QR_Kod;
_GLOBAL struct Checker_typ Checker;
_GLOBAL struct SequenceControlTyp SC_Checker;
_GLOBAL struct Popisovanie_typ Popisovanie;
_GLOBAL struct SequenceControlTyp SC_Popisovanie;
_GLOBAL struct VstupnyOddelovac_typ VstupnyOddelovac;
_GLOBAL struct SequenceControlTyp SC_VstupnyOddelovac;
_GLOBAL struct Zariadenie_typ Zariadenie;
_GLOBAL struct Vizualizacia_typ Vizu;
_GLOBAL struct Safety_typ Safety;
_GLOBAL struct SequenceControlTyp SC_Uzivatelia;
_GLOBAL plcbit OdhlasUzivatela;
_GLOBAL plcbit VymazUzivatela;
_GLOBAL plcbit PrihlasUzivatela;
_GLOBAL plcbit UlozUzivatelov;
_GLOBAL unsigned char TP_ZobrazPopUpPrihlasenie;
_GLOBAL unsigned short ZvolenaUroven;
_GLOBAL plcstring ZvolenyUzivatel[51];
_GLOBAL plcstring ZadaneHesloUzivatela[51];
_GLOBAL plcstring ZadaneMenoUzivatela[51];
_GLOBAL unsigned short UrovenUzivatela;
_GLOBAL plcstring HesloUzivatela[51];
_GLOBAL plcstring MenoUzivatela[51];
_GLOBAL plcstring ZoznamUzivatelov[51][51];
_GLOBAL struct ParametreUzivatelovTyp Uzivatel[51];
_GLOBAL struct MpRecipeRegPar MpRecipeRegPar_1;
_GLOBAL struct MpRecipeXml MpRecipeXml_1;
_GLOBAL plcstring ZvolenyBOM_kod_Statora[8];
_GLOBAL plcstring ZvolenyNazovStatora[51];
_GLOBAL plcstring BOM_kod_Statora[8];
_GLOBAL plcstring NazovStatora[51];
_GLOBAL plcbit NacitajRecepturu;
_GLOBAL plcbit UlozRecepturu;
_GLOBAL plcstring ZoznamReceptur[151][51];
_GLOBAL struct ParametreRecepturTyp Receptura[151];
_GLOBAL struct MpRecipeXml MpRecipeXml_0;
_GLOBAL struct MpRecipeRegPar MpRecipeRegPar_0;
_GLOBAL plcbit PoruchaCheckera;
_GLOBAL plcbit PoruchaPopisovania;
_GLOBAL plcbit PoruchaVstupnehoOddelovaca;
_GLOBAL plcbit PotvrdenieAlarmov;
_GLOBAL plcbit ZobrazSymbolAlarmu;
_GLOBAL plcbit NastalaPorucha;
_GLOBAL plcbit Alarmy[101];
_GLOBAL plcbit Blikac1s;
_GLOBAL plcbit Blikac5s;
_GLOBAL plcbit Blikac500ms;
_GLOBAL plcbit Blikac200ms;
_GLOBAL unsigned char OK_OdpovedNaVyberSpravy[51];
_GLOBAL unsigned char OK_OdpovedNaDataSpravy[51];
_GLOBAL unsigned char Laser_Odpoved[51];
_GLOBAL unsigned char Laser_Sprava[51];
_GLOBAL unsigned char Laser_NazovSpravy[13];
_GLOBAL unsigned char Laser_DataSpravy[48];
_GLOBAL struct Laser_typ Laser;
_GLOBAL struct Client_typ Client;
_GLOBAL plcstring Den_String[3];
_GLOBAL plcstring Mesiac_String[3];
_GLOBAL plcstring Minuta_String[3];
_GLOBAL plcstring Hodina_String[3];
_GLOBAL plcstring Sekunda_String[3];
_GLOBAL plcstring TextPole_Datum[7];
_GLOBAL plcstring TextPole_Cas[7];
_GLOBAL struct Datum_STR Systemovy_Datum_STR;
_GLOBAL struct Cas_STR Systemovy_Cas_STR;
_GLOBAL struct Datum Systemovy_Datum;
_GLOBAL struct Cas Systemovy_Cas;
_GLOBAL unsigned short Status_citania_casu;
_GLOBAL struct DTStructure System_Cas_Datum;
_GLOBAL plcbit Zapnutie_citania_casu;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/MpRecipe/MpRecipe.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1621250404_1_ */

