#ifndef __AS__TYPE_
#define __AS__TYPE_
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

#ifndef __AS__TYPE_Cas_STR
#define __AS__TYPE_Cas_STR
typedef struct Cas_STR
{	plcstring Hodina[3];
	plcstring Minuta[3];
	plcstring Sekunda[3];
} Cas_STR;
#endif

#ifndef __AS__TYPE_Datum_STR
#define __AS__TYPE_Datum_STR
typedef struct Datum_STR
{	plcstring Den[3];
	plcstring Mesiac[3];
	plcstring Rok[5];
} Datum_STR;
#endif

#ifndef __AS__TYPE_LaserCommands_typ
#define __AS__TYPE_LaserCommands_typ
typedef struct LaserCommands_typ
{	plcbit OdosliDataSpravy;
	plcbit ResetPoruchy;
	plcbit VyberSpravuLasera;
} LaserCommands_typ;
#endif

#ifndef __AS__TYPE_LaserStatus_typ
#define __AS__TYPE_LaserStatus_typ
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
#endif

#ifndef __AS__TYPE_LaserData_typ
#define __AS__TYPE_LaserData_typ
typedef struct LaserData_typ
{	unsigned char Data;
} LaserData_typ;
#endif

#ifndef __AS__TYPE_Laser_typ
#define __AS__TYPE_Laser_typ
typedef struct Laser_typ
{	LaserCommands_typ Commands;
	LaserStatus_typ Status;
	LaserData_typ Data;
} Laser_typ;
#endif

#ifndef __AS__TYPE_ZariadenieIN_typ
#define __AS__TYPE_ZariadenieIN_typ
typedef struct ZariadenieIN_typ
{	plcbit PrepatovaOchrana_OK;
	plcbit TlakVzduchu_OK;
	plcbit NapajanieLasera_OK;
	plcbit NapajanieOdsavania_OK;
	plcbit TlacitkoSTART;
	plcbit TlacitkoSTOP;
	plcbit TlacitkoRESET_CS;
} ZariadenieIN_typ;
#endif

#ifndef __AS__TYPE_ZariadenieOUT_typ
#define __AS__TYPE_ZariadenieOUT_typ
typedef struct ZariadenieOUT_typ
{	plcbit Majak_ZeleneSvetlo;
	plcbit Majak_ZlteSvetlo;
	plcbit Majak_CerveneSvetlo;
	plcbit Majak_Hukacka;
	plcbit LED_Dvojtlacitka_StartStop;
	plcbit LED_Tlacitka_RESET_CS;
} ZariadenieOUT_typ;
#endif

#ifndef __AS__TYPE_ZariadeniePAR_typ
#define __AS__TYPE_ZariadeniePAR_typ
typedef struct ZariadeniePAR_typ
{	unsigned long PAR_0;
} ZariadeniePAR_typ;
#endif

#ifndef __AS__TYPE_ZariadenieSTAV_typ
#define __AS__TYPE_ZariadenieSTAV_typ
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
#endif

#ifndef __AS__TYPE_Zariadenie_typ
#define __AS__TYPE_Zariadenie_typ
typedef struct Zariadenie_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	plcbit KoniecModelu;
	plcbit Hukacka_ON;
	plcbit Hukacka_OFF;
	ZariadenieIN_typ IN;
	ZariadenieOUT_typ OUT;
	ZariadeniePAR_typ PAR;
	ZariadenieSTAV_typ STAV;
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
#endif

#ifndef __AS__TYPE_PopisovanieIN_typ
#define __AS__TYPE_PopisovanieIN_typ
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
#endif

#ifndef __AS__TYPE_PopisovanieOUT_typ
#define __AS__TYPE_PopisovanieOUT_typ
typedef struct PopisovanieOUT_typ
{	plcbit Odsavanie_Start;
	plcbit Laser_StartZnacenia;
	plcbit Laser_ResetPoruchy;
	plcbit Zdvizku_VYSUN;
	plcbit Zdvizku_ZASUN;
	plcbit StoperZdvizky_ZASUN;
	plcbit StoperZdvizky_VYSUN;
} PopisovanieOUT_typ;
#endif

#ifndef __AS__TYPE_PopisovaniePAR_typ
#define __AS__TYPE_PopisovaniePAR_typ
typedef struct PopisovaniePAR_typ
{	unsigned char PocetPrazdnychPaletiek;
} PopisovaniePAR_typ;
#endif

#ifndef __AS__TYPE_PopisovanieSTAV_typ
#define __AS__TYPE_PopisovanieSTAV_typ
typedef struct PopisovanieSTAV_typ
{	plcbit PoINIT;
	plcbit Zdvizka_PritomnostNGkusu;
} PopisovanieSTAV_typ;
#endif

#ifndef __AS__TYPE_Popisovanie_typ
#define __AS__TYPE_Popisovanie_typ
typedef struct Popisovanie_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	PopisovanieIN_typ IN;
	PopisovanieOUT_typ OUT;
	PopisovaniePAR_typ PAR;
	PopisovanieSTAV_typ STAV;
} Popisovanie_typ;
#endif

#ifndef __AS__TYPE_CheckerIN_typ
#define __AS__TYPE_CheckerIN_typ
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
#endif

#ifndef __AS__TYPE_CheckerOUT_typ
#define __AS__TYPE_CheckerOUT_typ
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
#endif

#ifndef __AS__TYPE_CheckerCOM_typ
#define __AS__TYPE_CheckerCOM_typ
typedef struct CheckerCOM_typ
{	unsigned char ControlWord;
	unsigned char StatusWord;
	unsigned char ResultStatus;
	unsigned char ResultControl;
	unsigned short ResultData;
} CheckerCOM_typ;
#endif

#ifndef __AS__TYPE_CheckerPAR_typ
#define __AS__TYPE_CheckerPAR_typ
typedef struct CheckerPAR_typ
{	unsigned long PAR_0;
} CheckerPAR_typ;
#endif

#ifndef __AS__TYPE_CheckerSTAV_typ
#define __AS__TYPE_CheckerSTAV_typ
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
#endif

#ifndef __AS__TYPE_Checker_typ
#define __AS__TYPE_Checker_typ
typedef struct Checker_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	CheckerIN_typ IN;
	CheckerOUT_typ OUT;
	CheckerCOM_typ COM;
	CheckerPAR_typ PAR;
	CheckerSTAV_typ STAV;
	plcbit TRIGER_Enable;
	plcbit TRIGER;
	plcbit Vysledok_POTVRDENIE;
	plcbit KAMERA_OFF;
} Checker_typ;
#endif

#ifndef __AS__TYPE_SafetyIN_typ
#define __AS__TYPE_SafetyIN_typ
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
#endif

#ifndef __AS__TYPE_SafetyOUT_typ
#define __AS__TYPE_SafetyOUT_typ
typedef struct SafetyOUT_typ
{	plcbit Zona_CS;
	plcbit Zona_VnutroBunky;
	plcbit Zona_Laser;
	plcbit Zona_ExternyCS_KanalA;
	plcbit Zona_ExternyCS_KanalB;
	plcbit DvereBunky_Zamkni;
} SafetyOUT_typ;
#endif

#ifndef __AS__TYPE_SafetyPAR_typ
#define __AS__TYPE_SafetyPAR_typ
typedef struct SafetyPAR_typ
{	unsigned char PAR_0;
} SafetyPAR_typ;
#endif

#ifndef __AS__TYPE_SafetySTAV_typ
#define __AS__TYPE_SafetySTAV_typ
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
#endif

#ifndef __AS__TYPE_Safety_typ
#define __AS__TYPE_Safety_typ
typedef struct Safety_typ
{	SafetyIN_typ IN;
	SafetyOUT_typ OUT;
	SafetyPAR_typ PAR;
	SafetySTAV_typ STAV;
	plcbit RESET_ZonyLaser;
	plcbit RESET_ZonyVnutroBunky;
	plcbit RESET_ZonyCS;
	plcbit OdomkniDvereBunky;
} Safety_typ;
#endif

#ifndef __AS__TYPE_Vizualizacia_typ
#define __AS__TYPE_Vizualizacia_typ
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
#endif

#ifndef __AS__TYPE_QRkod_typ
#define __AS__TYPE_QRkod_typ
typedef struct QRkod_typ
{	plcstring BOM_Statora[8];
	plcstring DatumVyroby[9];
	plcstring CasVyroby[5];
	plcstring NazovVyrobnejLinky[9];
	plcstring BOM_PosledneZnaky[5];
} QRkod_typ;
#endif

#ifndef __AS__TYPE_DTStructure
#define __AS__TYPE_DTStructure
typedef struct DTStructure
{	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char wday;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned short millisec;
	unsigned short microsec;
} DTStructure;
#endif

struct TON
{	plctime PT;
	plctime ET;
	plctime StartTime;
	unsigned long Restart;
	plcbit IN;
	plcbit Q;
	plcbit M;
};
_BUR_PUBLIC void TON(struct TON* inst);
#ifndef __AS__TYPE_SequenceControlTyp
#define __AS__TYPE_SequenceControlTyp
typedef struct SequenceControlTyp
{	plcstring StepName[81];
	unsigned short Step;
	plcbit Switch1;
	plcbit Switch2;
	plcbit Switch3;
	plcbit ResetStep;
	plcbit LastStep;
	struct TON IdleTime;
	struct TON AlarmTime;
} SequenceControlTyp;
#endif

_BUR_PUBLIC plcstring* usint2str(unsigned char IN, plcstring pStr[81], unsigned long len);
_BUR_PUBLIC plcstring* uint2str(unsigned short IN, plcstring pStr[81], unsigned long len);
_BUR_PUBLIC unsigned long brsmemcpy(unsigned long pDest, unsigned long pSrc, unsigned long length);
_BUR_PUBLIC unsigned long brsstrcat(unsigned long pDest, unsigned long pSrc);
_BUR_PUBLIC unsigned long brsstrlen(unsigned long pString);
_BUR_PUBLIC unsigned long brsstrcpy(unsigned long pDest, unsigned long pSrc);
_BUR_PUBLIC signed long CheckBounds(signed long index, signed long lower, signed long upper);
_BUR_PUBLIC plcbit SequenceControl(struct SequenceControlTyp(* SC));
_BUR_LOCAL SequenceControlTyp SC_OvlStopra;
_BUR_LOCAL plcbit StoperZdvizky_VYSUN;
_BUR_LOCAL plcbit StoperZdvizky_ZASUN;
_BUR_LOCAL SequenceControlTyp SC_OvlZdvizky;
_BUR_LOCAL plcbit Zdvizku_VYSUN;
_BUR_LOCAL plcbit Zdvizku_ZASUN;
_BUR_LOCAL unsigned char PoleUSINT[20];
_BUR_LOCAL unsigned long length;
_BUR_LOCAL plcstring PosledneZnaky[5];
_BUR_LOCAL unsigned char i;
_GLOBAL DTStructure System_Cas_Datum;
_GLOBAL Cas_STR Systemovy_Cas_STR;
_GLOBAL Datum_STR Systemovy_Datum_STR;
_GLOBAL plcstring TextPole_Cas[5];
_GLOBAL plcstring TextPole_Datum[9];
_GLOBAL plcstring Hodina_String[3];
_GLOBAL plcstring Minuta_String[3];
_GLOBAL plcstring Mesiac_String[3];
_GLOBAL plcstring Den_String[3];
_GLOBAL Laser_typ Laser;
_GLOBAL unsigned char Laser_DataSpravy[48];
_GLOBAL plcbit Alarmy[101];
_GLOBAL plcbit PoruchaPopisovania;
_GLOBAL plcstring ZvolenyBOM_kod_Statora[8];
_GLOBAL Safety_typ Safety;
_GLOBAL Vizualizacia_typ Vizu;
_GLOBAL Zariadenie_typ Zariadenie;
_GLOBAL SequenceControlTyp SC_Popisovanie;
_GLOBAL Popisovanie_typ Popisovanie;
_GLOBAL Checker_typ Checker;
_GLOBAL QRkod_typ QR_Kod;
_GLOBAL_RETAIN plcbit Stav_StatorPopisany;
_LOCAL plcbit Edge0000400000;
_LOCAL plcbit Edge0000400001;
_LOCAL plcbit Edge0000400002;
_LOCAL plcbit Edge0000400003;
static void __AS__Action__OvlStopra(void);
static void __AS__Action__OvlZdvizky(void);
static void __AS__Action__SpravaPreLaser(void);
