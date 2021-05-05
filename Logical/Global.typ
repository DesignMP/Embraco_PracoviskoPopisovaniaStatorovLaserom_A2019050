(*************Vyèítavanie systémového èasu**********************)

TYPE
	Cas : 	STRUCT 
		Hodina : USINT;
		Minuta : USINT;
		Sekunda : USINT;
	END_STRUCT;
	Datum : 	STRUCT 
		Den : USINT;
		Mesiac : USINT;
		Rok : UINT;
	END_STRUCT;
	Cas_STR : 	STRUCT 
		Hodina : STRING[2];
		Minuta : STRING[2];
		Sekunda : STRING[2];
	END_STRUCT;
	Datum_STR : 	STRUCT 
		Den : STRING[2];
		Mesiac : STRING[2];
		Rok : STRING[4];
	END_STRUCT;
END_TYPE

(**************Ovládanie lasera**********************)

TYPE
	Client_typ : 	STRUCT  (*TCP Client Variables*)
		sStep : UINT; (*TCP Client Step Variable*)
		TcpOpen_0 : TcpOpen; (*AsTCP.TcpOpen FUB*)
		TcpClient_0 : TcpClient; (*AsTCP.TcpClient FUB*)
		TcpRecv_0 : TcpRecv; (*AsTCP.TcpRecv FUB*)
		TcpSend_0 : TcpSend; (*AsTCP.TcpSend FUB*)
		TcpIoctl_0 : TcpIoctl; (*AsTCP.TcpIoctl FUB*)
		TcpClose_0 : TcpClose; (*AsTCP.TcpClose FUB*)
		linger_opt : tcpLINGER_typ; (*AsTCP.tcpLINGER_typ*)
		recv_timeout : UDINT; (*receive timeout*)
		TcpOpen_timeout : UDINT;
		TcpClient_timeout : UDINT;
	END_STRUCT;
	Laser_typ : 	STRUCT 
		Commands : LaserCommands_typ;
		Status : LaserStatus_typ;
		Data : LaserData_typ;
	END_STRUCT;
	LaserCommands_typ : 	STRUCT 
		OdosliDataSpravy : BOOL;
		ResetPoruchy : BOOL;
		VyberSpravuLasera : BOOL;
	END_STRUCT;
	LaserStatus_typ : 	STRUCT 
		PoruchaOtvoreniaKomunikacie : BOOL;
		PoruchaOdoslaniaDat : BOOL;
		PoruchaZatvoreniaKomunikacie : BOOL;
		PoruchaSpojenia_s_Laserom : BOOL;
		PoruchaPrijatiaDat : BOOL;
		OdoslanieDatSpravy_OK : BOOL;
		OdoslanieDatSpravy_NG : BOOL;
		VyberSpravy_OK : BOOL;
		VyberSpravy_NG : BOOL;
		StrataKomunikacie : BOOL;
		VysledokPorovnaniaOdpovede : DINT;
	END_STRUCT;
	LaserData_typ : 	STRUCT  (*Datatyp for global Variables*)
		Data : USINT;
	END_STRUCT;
END_TYPE

(***************Uzivatelia****************************)

TYPE
	ParametreUzivatelovTyp : 	STRUCT 
		Meno : STRING[50];
		Heslo : STRING[50];
		UrovenUzivatela : UINT;
	END_STRUCT;
END_TYPE

(************Receptury*************************)

TYPE
	ParametreRecepturTyp : 	STRUCT 
		NazovStatora : STRING[50];
		BOM_kod_Statora : STRING[20];
	END_STRUCT;
END_TYPE

(************Remanentne premenné*************)

TYPE
	RemPremenne_typ : 	STRUCT 
		RemPrem_0 : UDINT;
	END_STRUCT;
END_TYPE

(**************Zariadenie************************)

TYPE
	Zariadenie_typ : 	STRUCT 
		Automat : BOOL;
		Manual : BOOL;
		Reset : BOOL;
		KoniecCyklu : BOOL;
		KoniecModelu : BOOL;
		Hukacka_ON : BOOL;
		Hukacka_OFF : BOOL;
		IN : ZariadenieIN_typ;
		OUT : ZariadenieOUT_typ;
		PAR : ZariadeniePAR_typ;
		STAV : ZariadenieSTAV_typ;
		TaktTime_START : BOOL;
		TaktTime_RESET : BOOL;
		TaktTime_ZAPIS : BOOL;
		TaktTime_Milisekundy : UINT;
		TaktTime_Sekundy : UINT;
		TaktTime_Minuty : UINT;
		TaktTime_Hodiny : UINT;
		TaktTime_NameraneSekundy : UINT;
		TaktTime_NameraneMinuty : UINT;
		TaktTime_NameraneHodiny : UINT;
		PriechodnyRezim : BOOL;
	END_STRUCT;
	ZariadenieIN_typ : 	STRUCT 
		PrepatovaOchrana_OK : BOOL;
		TlakVzduchu_OK : BOOL;
		NapajanieLasera_OK : BOOL;
		NapajanieOdsavania_OK : BOOL;
		TlacitkoSTART : BOOL;
		TlacitkoSTOP : BOOL;
		TlacitkoRESET_CS : BOOL;
	END_STRUCT;
	ZariadenieOUT_typ : 	STRUCT 
		Majak_ZeleneSvetlo : BOOL;
		Majak_ZlteSvetlo : BOOL;
		Majak_CerveneSvetlo : BOOL;
		Majak_Hukacka : BOOL;
		LED_Dvojtlacitka_StartStop : BOOL;
		LED_Tlacitka_RESET_CS : BOOL;
	END_STRUCT;
	ZariadeniePAR_typ : 	STRUCT 
		PAR_0 : UDINT;
	END_STRUCT;
	ZariadenieSTAV_typ : 	STRUCT 
		Automat : BOOL;
		Manual : BOOL;
		PoINIT : BOOL;
		UkoncenieCyklu : BOOL;
		StavZariadenia : USINT;
		KOM_Checker_OK : BOOL;
		KOM_Modul_BC1_OK : BOOL;
		KOM_Modul_SI1_OK : BOOL;
		KOM_Modul_DI1_OK : BOOL;
		KOM_Modul_XV_OK : BOOL;
		Moduly_OK : BOOL;
		TlakVzduchuOK : BOOL;
		PrebiehaResetPoruchy : BOOL;
		NezvolenaReceptura : BOOL;
	END_STRUCT;
END_TYPE

(*************Vstupný oddelovaè***************)

TYPE
	VstupnyOddelovac_typ : 	STRUCT 
		Automat : BOOL;
		Manual : BOOL;
		Reset : BOOL;
		KoniecCyklu : BOOL;
		IN : VstupnyOddelovacIN_typ;
		OUT : VstupnyOddelovacOUT_typ;
		PAR : VstupnyOddelovacPAR_typ;
		STAV : VstupnyOddelovacSTAV_typ;
	END_STRUCT;
	VstupnyOddelovacIN_typ : 	STRUCT 
		Stoper1_ZASUNUTY : BOOL;
		Stoper1_VYSUNUTY : BOOL;
		Stoper2_ZASUNUTY : BOOL;
		Stoper2_VYSUNUTY : BOOL;
		Stoper2_PritomnostPaletky : BOOL;
	END_STRUCT;
	VstupnyOddelovacOUT_typ : 	STRUCT 
		Stoper1_VYSUN : BOOL;
		Stoper1_ZASUN : BOOL;
		Stoper2_VYSUN : BOOL;
		Stoper2_ZASUN : BOOL;
	END_STRUCT;
	VstupnyOddelovacPAR_typ : 	STRUCT 
		PAR_0 : UDINT;
	END_STRUCT;
	VstupnyOddelovacSTAV_typ : 	STRUCT 
		PoINIT : BOOL;
		Stopre_PoziciaNAVAZANIE : BOOL;
		Stopre_PoziciaVYVAZANIE : BOOL;
	END_STRUCT;
END_TYPE

(*************Popisovanie***************)

TYPE
	Popisovanie_typ : 	STRUCT 
		Automat : BOOL;
		Manual : BOOL;
		Reset : BOOL;
		KoniecCyklu : BOOL;
		IN : PopisovanieIN_typ;
		OUT : PopisovanieOUT_typ;
		PAR : PopisovaniePAR_typ;
		STAV : PopisovanieSTAV_typ;
	END_STRUCT;
	PopisovanieIN_typ : 	STRUCT 
		Laser_StavREADY : BOOL;
		Laser_StavEND : BOOL;
		Laser_StavBUSY : BOOL;
		Laser_STARTUP : BOOL;
		Laser_ALARM : BOOL;
		StoperZdvizky_ZASUNUTY : BOOL;
		StoperZdvizky_VYSUNUTY : BOOL;
		StoperZdvizky_PritomnostPaletky : BOOL;
		StoperZdvizky_PritomnostStatora : BOOL;
		Zdvizka_VYSUNUTA : BOOL;
		Zdvizka_ZASUNUTA : BOOL;
	END_STRUCT;
	PopisovanieOUT_typ : 	STRUCT 
		Odsavanie_Start : BOOL;
		Laser_StartZnacenia : BOOL;
		Laser_ResetPoruchy : BOOL;
		Zdvizku_VYSUN : BOOL;
		Zdvizku_ZASUN : BOOL;
		StoperZdvizky_ZASUN : BOOL;
		StoperZdvizky_VYSUN : BOOL;
	END_STRUCT;
	PopisovaniePAR_typ : 	STRUCT 
		PocetPrazdnychPaletiek : USINT;
	END_STRUCT;
	PopisovanieSTAV_typ : 	STRUCT 
		PoINIT : BOOL;
		Zdvizka_PritomnostNGkusu : BOOL;
	END_STRUCT;
END_TYPE

(*************Checker***************)

TYPE
	Checker_typ : 	STRUCT 
		Automat : BOOL;
		Manual : BOOL;
		Reset : BOOL;
		KoniecCyklu : BOOL;
		IN : CheckerIN_typ;
		OUT : CheckerOUT_typ;
		COM : CheckerCOM_typ;
		PAR : CheckerPAR_typ;
		STAV : CheckerSTAV_typ;
		TRIGER_Enable : BOOL;
		TRIGER : BOOL;
		Vysledok_POTVRDENIE : BOOL;
		KAMERA_OFF : BOOL;
	END_STRUCT;
	CheckerIN_typ : 	STRUCT 
		TlacitkoBANNER : BOOL;
		Checker_OUT0 : BOOL; (*OUT_0*)
		Checker_OUT1 : BOOL; (*OUT_1*)
		Checker_OUT2 : BOOL; (*OUT_2*)
		Checker_OUT3 : BOOL; (*OUT_3*)
		Stoper1_ZASUNUTY : BOOL;
		Stoper1_VYSUNUTY : BOOL;
		Stoper2_ZASUNUTY : BOOL;
		Stoper2_VYSUNUTY : BOOL;
		ZasobaPredStoprom1 : BOOL;
		Stoper1_PritomnostPaletky : BOOL;
		Stoper2_PritomnostPaletky : BOOL;
		Stoper2_PritomnostStatora : BOOL;
		ZaplnenieVystupnejTrate : BOOL;
	END_STRUCT;
	CheckerOUT_typ : 	STRUCT 
		BANNER_ZelenaLED : BOOL;
		BANNER_CervenaLED : BOOL;
		Checker_IN0 : BOOL;
		Checker_IN1 : BOOL;
		Stoper1_VYSUN : BOOL;
		Stoper1_ZASUN : BOOL;
		Stoper2_VYSUN : BOOL;
		Stoper2_ZASUN : BOOL;
	END_STRUCT;
	CheckerCOM_typ : 	STRUCT 
		ControlWord : USINT;
		StatusWord : USINT;
		ResultStatus : USINT;
		ResultControl : USINT;
		ResultData : UINT;
	END_STRUCT;
	CheckerPAR_typ : 	STRUCT 
		PAR_0 : UDINT;
	END_STRUCT;
	CheckerSTAV_typ : 	STRUCT 
		PoINIT : BOOL;
		Stopre_PoziciaNAVAZANIE : BOOL;
		Stopre_PoziciaVYVAZANIE : BOOL;
		TRIGER_Ready : BOOL;
		BUSY : BOOL;
		Vysledok_READY : BOOL;
		Vysledok_OK : BOOL;
		Vysledok_NG : BOOL;
	END_STRUCT;
END_TYPE

(**************Bezpecnost************************)

TYPE
	Safety_typ : 	STRUCT 
		IN : SafetyIN_typ;
		OUT : SafetyOUT_typ;
		PAR : SafetyPAR_typ;
		STAV : SafetySTAV_typ;
		RESET_ZonyLaser : BOOL;
		RESET_ZonyVnutroBunky : BOOL;
		RESET_ZonyCS : BOOL;
		OdomkniDvereBunky : BOOL;
	END_STRUCT;
	SafetyIN_typ : 	STRUCT 
		DvereBunky_AktuatorVzamku : BOOL;
		ZonaCS_SpatnaVezba : BOOL;
		ZonaLaser_SpatnaVezba : BOOL;
		ZonaVnutroBunky_SpatnaVezba : BOOL;
		DvereBunky_KanalA : BOOL;
		DvereBunky_KanalB : BOOL;
		CS_Panel_KanalA : BOOL;
		CS_Panel_KanalB : BOOL;
		CS_Checker_KanalA : BOOL;
		CS_Checker_KanalB : BOOL;
		VyblokovanieZamkov_KanalA : BOOL;
		VyblokovanieZamkov_KanalB : BOOL;
		ExternyCS_KanalA : BOOL;
		ExternyCS_KanalB : BOOL;
		StatorPodLaserom_KanalA : BOOL;
		StatorPodLaserom_KanalB : BOOL;
		KrytLasera_KanalA : BOOL;
		KrytLasera_KanalB : BOOL;
		ZdvihZdvizky_SpatnaVezba : BOOL;
	END_STRUCT;
	SafetyOUT_typ : 	STRUCT 
		Zona_CS : BOOL; (*SO1*)
		Zona_VnutroBunky : BOOL; (*SO3*)
		Zona_Laser : BOOL;
		Zona_ExternyCS_KanalA : BOOL;
		Zona_ExternyCS_KanalB : BOOL;
		DvereBunky_Zamkni : BOOL;
	END_STRUCT;
	SafetyPAR_typ : 	STRUCT 
		PAR_0 : USINT;
	END_STRUCT;
	SafetySTAV_typ : 	STRUCT 
		SafetyPLC_Nabehlo : BOOL;
		CS_Checker_Odblokov : BOOL;
		CS_Panel_Odblokov : BOOL;
		ZonaCS_Aktivna : BOOL;
		ZonaLaser_Aktivna : BOOL;
		ZonaVnutroBunky_Aktivna : BOOL;
		VyblokovanieZamkov_Aktivne : BOOL;
		SnimacKrytuLasera_Aktivny : BOOL;
		SnimacStatorPodLaserom_Aktivny : BOOL;
		DvereBunky_Zamknute : BOOL;
	END_STRUCT;
END_TYPE

(**************Vizualizacia************************)

TYPE
	Vizualizacia_typ : 	STRUCT 
		Slider : USINT;
		CisloAktualnejObrazovky : USINT;
		CisloZadanejObrazovky : USINT;
		LED_TlacitkaResetCS : USINT;
		LED_TlacitkaZamokDveriBunky : USINT;
		BlikanieTlacitkaSTART : BOOL;
		ZamkniTlacitkoRezimAutomat : USINT;
		ZamkniTlacitkoRezimManual : USINT;
		ZamkniTlacitkoSTART : USINT;
		ZamkniTlacitkoSTOP : USINT;
		ZamkniTlacitkoZamokDveriBunky : USINT;
		ZamkniTlacitkaOvladaniaZdvizky : USINT;
		ZamkniTlacitkoPriechodnyRezim : USINT;
		ZamkniTlacitkoLaserVolbaSpravy : USINT;
		ZamkniTlacitkoLaserPosliData : USINT;
		Zobraz_ResetZariadenia : USINT;
		Zobraz_HlasenieOdoberStator : USINT;
		Zobraz_HlasenieZamkyVyblokovane : USINT;
		Zobraz_HlasenieNezvolenaRecept : USINT;
		Zobraz_HlasenieNizkyTlakVzduchu : USINT;
		Zobraz_HlasenieVymenaModelu : USINT;
		Zobraz_HlasenieNaZdvizkeNGkus : USINT;
		Zobraz_TlacitkoOK_ZmenaModelu : USINT;
		Stav_VystupnyOddelovac : USINT;
		Stav_Laser : USINT;
		Stav_Checker : USINT;
		TlacitkoZamkniDvereBunky : BOOL;
		TlacitkoRezimAutomat : BOOL;
		ZamkniTlacitko_StartPopisovania : USINT;
		ZamkniTlacitko_PriechodnyRezim : USINT;
	END_STRUCT;
	QRkod_typ : 	STRUCT 
		BOM_Statora : STRING[7];
		DatumVyroby : STRING[8];
		CasVyroby : STRING[4];
		NazovVyrobnejLinky : STRING[8];
		BOM_PosledneZnaky : STRING[4];
	END_STRUCT;
END_TYPE
