/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1620291505_1_
#define _BUR_1620291505_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct Cas
{	unsigned char Hodina;
	unsigned char Minuta;
	unsigned char Sekunda;
} Cas;

typedef struct Datum
{	unsigned char Den;
	unsigned char Mesiac;
	unsigned short Rok;
} Datum;

typedef struct Cas_STR
{	plcstring Hodina[3];
	plcstring Minuta[3];
	plcstring Sekunda[3];
} Cas_STR;

typedef struct Datum_STR
{	plcstring Den[3];
	plcstring Mesiac[3];
	plcstring Rok[3];
} Datum_STR;

typedef struct Client_typ
{	unsigned short sStep;
	struct TcpOpen TcpOpen_0;
	struct TcpClient TcpClient_0;
	struct TcpRecv TcpRecv_0;
	struct TcpSend TcpSend_0;
	struct TcpIoctl TcpIoctl_0;
	struct TcpClose TcpClose_0;
	struct tcpLINGER_typ linger_opt;
	unsigned long recv_timeout;
	unsigned long TcpOpen_timeout;
	unsigned long TcpClient_timeout;
} Client_typ;

typedef struct LaserCommands_typ
{	plcbit OdosliDataSpravy;
	plcbit ResetPoruchy;
	plcbit VyberSpravuLasera;
} LaserCommands_typ;

typedef struct LaserStatus_typ
{	plcbit PoruchaOtvoreniaKomunikacie;
	plcbit PoruchaOdoslaniaDat;
	plcbit PoruchaZatvoreniaKomunikacie;
	plcbit PoruchaSpojenia_s_Laserom;
	plcbit PoruchaPrijatiaDat;
	plcbit OdoslanieDatSpravy_OK;
	plcbit OdoslanieDatSpravy_NG;
	plcbit VyberSpravy_OK;
	plcbit VyberSpravy_NG;
	plcbit StrataKomunikacie;
	signed long VysledokPorovnaniaOdpovede;
} LaserStatus_typ;

typedef struct LaserData_typ
{	unsigned char Data;
} LaserData_typ;

typedef struct Laser_typ
{	struct LaserCommands_typ Commands;
	struct LaserStatus_typ Status;
	struct LaserData_typ Data;
} Laser_typ;

typedef struct ParametreUzivatelovTyp
{	plcstring Meno[51];
	plcstring Heslo[51];
	unsigned short UrovenUzivatela;
} ParametreUzivatelovTyp;

typedef struct ParametreRecepturTyp
{	plcstring NazovStatora[51];
	plcstring BOM_kod_Statora[21];
} ParametreRecepturTyp;

typedef struct RemPremenne_typ
{	unsigned long RemPrem_0;
} RemPremenne_typ;

typedef struct ZariadenieIN_typ
{	plcbit PrepatovaOchrana_OK;
	plcbit TlakVzduchu_OK;
	plcbit NapajanieLasera_OK;
	plcbit NapajanieOdsavania_OK;
	plcbit TlacitkoSTART;
	plcbit TlacitkoSTOP;
	plcbit TlacitkoRESET_CS;
} ZariadenieIN_typ;

typedef struct ZariadenieOUT_typ
{	plcbit Majak_ZeleneSvetlo;
	plcbit Majak_ZlteSvetlo;
	plcbit Majak_CerveneSvetlo;
	plcbit Majak_Hukacka;
	plcbit LED_Dvojtlacitka_StartStop;
	plcbit LED_Tlacitka_RESET_CS;
} ZariadenieOUT_typ;

typedef struct ZariadeniePAR_typ
{	unsigned long PAR_0;
} ZariadeniePAR_typ;

typedef struct ZariadenieSTAV_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit PoINIT;
	plcbit UkoncenieCyklu;
	unsigned char StavZariadenia;
	plcbit KOM_Checker_OK;
	plcbit KOM_Modul_BC1_OK;
	plcbit KOM_Modul_SI1_OK;
	plcbit KOM_Modul_DI1_OK;
	plcbit KOM_Modul_XV_OK;
	plcbit Moduly_OK;
	plcbit TlakVzduchuOK;
	plcbit PrebiehaResetPoruchy;
	plcbit NezvolenaReceptura;
} ZariadenieSTAV_typ;

typedef struct Zariadenie_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	plcbit KoniecModelu;
	plcbit Hukacka_ON;
	plcbit Hukacka_OFF;
	struct ZariadenieIN_typ IN;
	struct ZariadenieOUT_typ OUT;
	struct ZariadeniePAR_typ PAR;
	struct ZariadenieSTAV_typ STAV;
	plcbit TaktTime_START;
	plcbit TaktTime_RESET;
	plcbit TaktTime_ZAPIS;
	unsigned short TaktTime_Milisekundy;
	unsigned short TaktTime_Sekundy;
	unsigned short TaktTime_Minuty;
	unsigned short TaktTime_Hodiny;
	unsigned short TaktTime_NameraneSekundy;
	unsigned short TaktTime_NameraneMinuty;
	unsigned short TaktTime_NameraneHodiny;
	plcbit PriechodnyRezim;
} Zariadenie_typ;

typedef struct VstupnyOddelovacIN_typ
{	plcbit Stoper1_ZASUNUTY;
	plcbit Stoper1_VYSUNUTY;
	plcbit Stoper2_ZASUNUTY;
	plcbit Stoper2_VYSUNUTY;
	plcbit Stoper2_PritomnostPaletky;
} VstupnyOddelovacIN_typ;

typedef struct VstupnyOddelovacOUT_typ
{	plcbit Stoper1_VYSUN;
	plcbit Stoper1_ZASUN;
	plcbit Stoper2_VYSUN;
	plcbit Stoper2_ZASUN;
} VstupnyOddelovacOUT_typ;

typedef struct VstupnyOddelovacPAR_typ
{	unsigned long PAR_0;
} VstupnyOddelovacPAR_typ;

typedef struct VstupnyOddelovacSTAV_typ
{	plcbit PoINIT;
	plcbit Stopre_PoziciaNAVAZANIE;
	plcbit Stopre_PoziciaVYVAZANIE;
} VstupnyOddelovacSTAV_typ;

typedef struct VstupnyOddelovac_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	struct VstupnyOddelovacIN_typ IN;
	struct VstupnyOddelovacOUT_typ OUT;
	struct VstupnyOddelovacPAR_typ PAR;
	struct VstupnyOddelovacSTAV_typ STAV;
} VstupnyOddelovac_typ;

typedef struct PopisovanieIN_typ
{	plcbit Laser_StavREADY;
	plcbit Laser_StavEND;
	plcbit Laser_StavBUSY;
	plcbit Laser_STARTUP;
	plcbit Laser_ALARM;
	plcbit StoperZdvizky_ZASUNUTY;
	plcbit StoperZdvizky_VYSUNUTY;
	plcbit StoperZdvizky_PritomnostPaletky;
	plcbit StoperZdvizky_PritomnostStatora;
	plcbit Zdvizka_VYSUNUTA;
	plcbit Zdvizka_ZASUNUTA;
} PopisovanieIN_typ;

typedef struct PopisovanieOUT_typ
{	plcbit Odsavanie_Start;
	plcbit Laser_StartZnacenia;
	plcbit Laser_ResetPoruchy;
	plcbit Zdvizku_VYSUN;
	plcbit Zdvizku_ZASUN;
	plcbit StoperZdvizky_ZASUN;
	plcbit StoperZdvizky_VYSUN;
} PopisovanieOUT_typ;

typedef struct PopisovaniePAR_typ
{	unsigned char PocetPrazdnychPaletiek;
} PopisovaniePAR_typ;

typedef struct PopisovanieSTAV_typ
{	plcbit PoINIT;
	plcbit Zdvizka_PritomnostNGkusu;
} PopisovanieSTAV_typ;

typedef struct Popisovanie_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	struct PopisovanieIN_typ IN;
	struct PopisovanieOUT_typ OUT;
	struct PopisovaniePAR_typ PAR;
	struct PopisovanieSTAV_typ STAV;
} Popisovanie_typ;

typedef struct CheckerIN_typ
{	plcbit TlacitkoBANNER;
	plcbit Checker_OUT0;
	plcbit Checker_OUT1;
	plcbit Checker_OUT2;
	plcbit Checker_OUT3;
	plcbit Stoper1_ZASUNUTY;
	plcbit Stoper1_VYSUNUTY;
	plcbit Stoper2_ZASUNUTY;
	plcbit Stoper2_VYSUNUTY;
	plcbit ZasobaPredStoprom1;
	plcbit Stoper1_PritomnostPaletky;
	plcbit Stoper2_PritomnostPaletky;
	plcbit Stoper2_PritomnostStatora;
	plcbit ZaplnenieVystupnejTrate;
} CheckerIN_typ;

typedef struct CheckerOUT_typ
{	plcbit BANNER_ZelenaLED;
	plcbit BANNER_CervenaLED;
	plcbit Checker_IN0;
	plcbit Checker_IN1;
	plcbit Stoper1_VYSUN;
	plcbit Stoper1_ZASUN;
	plcbit Stoper2_VYSUN;
	plcbit Stoper2_ZASUN;
} CheckerOUT_typ;

typedef struct CheckerCOM_typ
{	unsigned char ControlWord;
	unsigned char StatusWord;
	unsigned char ResultStatus;
	unsigned char ResultControl;
	unsigned short ResultData;
} CheckerCOM_typ;

typedef struct CheckerPAR_typ
{	unsigned long PAR_0;
} CheckerPAR_typ;

typedef struct CheckerSTAV_typ
{	plcbit PoINIT;
	plcbit Stopre_PoziciaNAVAZANIE;
	plcbit Stopre_PoziciaVYVAZANIE;
	plcbit TRIGER_Ready;
	plcbit BUSY;
	plcbit Vysledok_READY;
	plcbit Vysledok_OK;
	plcbit Vysledok_NG;
} CheckerSTAV_typ;

typedef struct Checker_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	struct CheckerIN_typ IN;
	struct CheckerOUT_typ OUT;
	struct CheckerCOM_typ COM;
	struct CheckerPAR_typ PAR;
	struct CheckerSTAV_typ STAV;
	plcbit TRIGER_Enable;
	plcbit TRIGER;
	plcbit Vysledok_POTVRDENIE;
	plcbit KAMERA_OFF;
} Checker_typ;

typedef struct SafetyIN_typ
{	plcbit DvereBunky_AktuatorVzamku;
	plcbit ZonaCS_SpatnaVezba;
	plcbit ZonaLaser_SpatnaVezba;
	plcbit ZonaVnutroBunky_SpatnaVezba;
	plcbit DvereBunky_KanalA;
	plcbit DvereBunky_KanalB;
	plcbit CS_Panel_KanalA;
	plcbit CS_Panel_KanalB;
	plcbit CS_Checker_KanalA;
	plcbit CS_Checker_KanalB;
	plcbit VyblokovanieZamkov_KanalA;
	plcbit VyblokovanieZamkov_KanalB;
	plcbit ExternyCS_KanalA;
	plcbit ExternyCS_KanalB;
	plcbit StatorPodLaserom_KanalA;
	plcbit StatorPodLaserom_KanalB;
	plcbit KrytLasera_KanalA;
	plcbit KrytLasera_KanalB;
	plcbit ZdvihZdvizky_SpatnaVezba;
} SafetyIN_typ;

typedef struct SafetyOUT_typ
{	plcbit Zona_CS;
	plcbit Zona_VnutroBunky;
	plcbit Zona_Laser;
	plcbit Zona_ExternyCS_KanalA;
	plcbit Zona_ExternyCS_KanalB;
	plcbit DvereBunky_Zamkni;
} SafetyOUT_typ;

typedef struct SafetyPAR_typ
{	unsigned char PAR_0;
} SafetyPAR_typ;

typedef struct SafetySTAV_typ
{	plcbit SafetyPLC_Nabehlo;
	plcbit CS_Checker_Odblokov;
	plcbit CS_Panel_Odblokov;
	plcbit ZonaCS_Aktivna;
	plcbit ZonaLaser_Aktivna;
	plcbit ZonaVnutroBunky_Aktivna;
	plcbit VyblokovanieZamkov_Aktivne;
	plcbit SnimacKrytuLasera_Aktivny;
	plcbit SnimacStatorPodLaserom_Aktivny;
	plcbit DvereBunky_Zamknute;
} SafetySTAV_typ;

typedef struct Safety_typ
{	struct SafetyIN_typ IN;
	struct SafetyOUT_typ OUT;
	struct SafetyPAR_typ PAR;
	struct SafetySTAV_typ STAV;
	plcbit RESET_ZonyLaser;
	plcbit RESET_ZonyVnutroBunky;
	plcbit RESET_ZonyCS;
	plcbit OdomkniDvereBunky;
} Safety_typ;

typedef struct Vizualizacia_typ
{	unsigned char Slider;
	unsigned char CisloAktualnejObrazovky;
	unsigned char CisloZadanejObrazovky;
	unsigned char LED_TlacitkaResetCS;
	unsigned char LED_TlacitkaZamokDveriBunky;
	plcbit BlikanieTlacitkaSTART;
	unsigned char ZamkniTlacitkoRezimAutomat;
	unsigned char ZamkniTlacitkoRezimManual;
	unsigned char ZamkniTlacitkoSTART;
	unsigned char ZamkniTlacitkoSTOP;
	unsigned char ZamkniTlacitkoZamokDveriBunky;
	unsigned char ZamkniTlacitkaOvladaniaZdvizky;
	unsigned char ZamkniTlacitkoPriechodnyRezim;
	unsigned char ZamkniTlacitkoLaserVolbaSpravy;
	unsigned char ZamkniTlacitkoLaserPosliData;
	unsigned char Zobraz_ResetZariadenia;
	unsigned char Zobraz_HlasenieOdoberStator;
	unsigned char Zobraz_HlasenieZamkyVyblokovane;
	unsigned char Zobraz_HlasenieNezvolenaRecept;
	unsigned char Zobraz_HlasenieNizkyTlakVzduchu;
	unsigned char Zobraz_HlasenieVymenaModelu;
	unsigned char Zobraz_HlasenieNaZdvizkeNGkus;
	unsigned char Zobraz_TlacitkoOK_ZmenaModelu;
	unsigned char Stav_VystupnyOddelovac;
	unsigned char Stav_Laser;
	unsigned char Stav_Checker;
	plcbit TlacitkoZamkniDvereBunky;
	plcbit TlacitkoRezimAutomat;
	unsigned char ZamkniTlacitko_StartPopisovania;
	unsigned char ZamkniTlacitko_PriechodnyRezim;
} Vizualizacia_typ;

typedef struct QRkod_typ
{	plcstring BOM_Statora[8];
	plcstring DatumVyroby[7];
	plcstring CasVyroby[7];
	plcstring NazovVyrobnejLinky[9];
	plcstring BOM_PosledneZnaky[5];
} QRkod_typ;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1620291505_1_ */

