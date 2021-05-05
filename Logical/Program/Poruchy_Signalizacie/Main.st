
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	//0 - 0 - Porucha - nizky tlak vzduchu !!!
	//1 - 1 - Poruchy prepatovej ochrany rozvadzaca !!!
	//2 - 2 - Porucha modulu BC1 - Modul 8DI/DO !!!
	//3 - 3 - Porucha modulu DI1 - Modul 16DI !!!
	//4 - 4 - Porucha modulu SI1 - Modul safety 4SI !!!
	//5 - 5 - Porucha modulu XV1 - Komunikacny modul ventiloveho terminalu !!!
	//6 - 6 - Porucha komunikacie s kamerou !!!
	//7 - 7 - Porucha - bolo stlacene tlacitko CS na paneli zariadenia !!!
	//8 - 8 - Porucha - bolo stlacene tlacitko CS kamery !!!
	//9 - 9 - Porucha napajania odsavania !!!
	//10 - 10 - Porucha napajania lasera !!! 
	//11 - 11 - Vstupny oddelovac - porucha zasunutia 1 stopra !!!
	//12 - 12 -  Vstupny oddelovac - porucha zasunutia 2 stopra !!!
	//13 - 13 -  Vstupny oddelovac - porucha vysunutia 1 stopra !!!
	//14 - 14 - Vstupny oddelovac - porucha vysunutia 2 stopra !!!
	//15 - 15 - Popisovanie - porucha vysunutia stopra zdvizky !!!
	//16 - 16 - Popisovanie - porucha zasunutia stopra zdvizky !!!
	//17 - 17 - Popisovanie - porucha vysunutia zdvizky !!!
	//18 - 18 - Popisovanie - porucha zasunutia zdvizky !!!
	//19 - 19 - Kamera - porucha zasunutia 1 stopra !!!
	//20 - 20 - Kamera - porucha zasunutia 2 stopra !!!
	//21 - 21 - Kamera - porucha vysunutia 1 stopra !!!
	//22 - 22 - Kamera - porucha vysunutia 2 stopra !!!
	//23 - 23 - Popisovanie - porucha safety snimaca statora pod laserom !!!
	//24 - 24 - Popisovanie - stator zostal zaseknuty v pozicii popisovania laserom !!!
	//25 - 25 - Popisovanie - laser nieje pripraveny !!!
	//26 - 26 - Popisovanie - porucha odoslania spravy do lasera !!!
	//27 - 27 - Porucha lasera !!!
	//28 - 28 - Porucha kamery !!!
	//29 - 29 - Popisovanie - porucha zvolenia spravy v lasery !!!
	
	
	
	
	//*********************************Zistenie alarmu************************************************************//	
	FOR i:=0 TO 100 BY 1 DO
		Alarmy[i];
		IF Alarmy[i] = TRUE THEN
			NastalaPorucha:= TRUE;
		END_IF	
	END_FOR
	
	
	//*********************************Blikanie symbolu poruchy na OP*****************************************//
	IF NastalaPorucha THEN
		ZobrazSymbolAlarmu:= Blikac500ms;
	ELSE
		ZobrazSymbolAlarmu:= FALSE;
	END_IF
	
	
	//*********************************Zelené svetlo majáka****************************************************//
	IF Zariadenie.STAV.Automat AND NOT Zariadenie.STAV.PoINIT THEN 
		Zariadenie.OUT.Majak_ZeleneSvetlo:= Blikac200ms;
	ELSIF Zariadenie.STAV.Automat AND Zariadenie.STAV.PoINIT THEN 
		Zariadenie.OUT.Majak_ZeleneSvetlo:= TRUE;
	ELSE
		Zariadenie.OUT.Majak_ZeleneSvetlo:= FALSE;
	END_IF
	
	
	//**********************************Žlté svetlo majáka*****************************************************//
	
	IF Popisovanie.IN.Laser_StavBUSY THEN
		Zariadenie.OUT.Majak_ZlteSvetlo:= TRUE;
	ELSE
		Zariadenie.OUT.Majak_ZlteSvetlo:= FALSE;
	END_IF	
	
	
	//**********************************Èervené svetlo majáka***************************************************//
	IF NastalaPorucha THEN
		Zariadenie.OUT.Majak_CerveneSvetlo:= Blikac200ms;
	ELSE	
		Zariadenie.OUT.Majak_CerveneSvetlo:= FALSE;
	END_IF
	
	//***********************************Zvuková signalizácia majáka*********************************************//
	IF EDGEPOS (NastalaPorucha = TRUE) THEN
		Zariadenie.Hukacka_ON:= TRUE;
	END_IF
	
	IF Zariadenie.Hukacka_ON THEN
		Zariadenie.OUT.Majak_Hukacka:= Blikac500ms;
	ELSE
		Zariadenie.OUT.Majak_Hukacka:= FALSE;
	END_IF
	
	IF NOT NastalaPorucha THEN
		Zariadenie.Hukacka_ON:= FALSE;
	ELSIF Zariadenie.Hukacka_OFF THEN
		Zariadenie.Hukacka_ON:= FALSE;
	END_IF	
	
	//*********************************Potvrdenie alarmu**********************************************************//
	IF PotvrdenieAlarmov THEN
		Popisovanie.OUT.Laser_ResetPoruchy:= TRUE;
		brsmemset(ADR(Alarmy),0,SIZEOF(Alarmy));
		NastalaPorucha:= FALSE;
		CasPotvrdeniaAlarmu.IN:= TRUE;
		PoruchaVstupnehoOddelovaca:= FALSE;
		PoruchaPopisovania:= FALSE;
		PoruchaCheckera:= FALSE;
		Zariadenie.Hukacka_OFF:= TRUE;
		Zariadenie.STAV.PrebiehaResetPoruchy:= TRUE;
		PotvrdenieAlarmov:= FALSE;
	END_IF
	
	IF CasPotvrdeniaAlarmu.Q AND NOT Popisovanie.IN.Laser_ALARM THEN
		Popisovanie.OUT.Laser_ResetPoruchy:= FALSE;
		Zariadenie.STAV.PrebiehaResetPoruchy:= FALSE;
		Zariadenie.Hukacka_OFF:= FALSE;
		CasPotvrdeniaAlarmu.IN:= FALSE;
	END_IF
	
	CasPotvrdeniaAlarmu.PT:= T#2s;
	CasPotvrdeniaAlarmu();
	
	
	//******************************Porucha tlaku vzduchu*********************************************************//
	
	
	CasMeraniaTlakuVzduchu.IN:= NOT Zariadenie.IN.TlakVzduchu_OK;
		
	IF CasMeraniaTlakuVzduchu.Q THEN
		Alarmy[0]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF	

		
	CasMeraniaTlakuVzduchu.PT:= T#5s;
	CasMeraniaTlakuVzduchu();
	
	
	//*****************************Porucha prepatovej ochrany******************************************************//
	IF Safety.STAV.SafetyPLC_Nabehlo AND NOT Zariadenie.IN.PrepatovaOchrana_OK THEN
		Alarmy[1]:= TRUE;
	END_IF
	
	//*****************************Porucha modulu BC1***********************************************************//
	IF Safety.STAV.SafetyPLC_Nabehlo AND NOT Zariadenie.STAV.KOM_Modul_BC1_OK THEN
		Alarmy[2]:= TRUE;
		Zariadenie.Reset:= TRUE;	
	END_IF	
	
	//*****************************Porucha modulu DI1***********************************************************//
	IF Safety.STAV.SafetyPLC_Nabehlo AND NOT Zariadenie.STAV.KOM_Modul_DI1_OK THEN
		Alarmy[3]:= TRUE;
		Zariadenie.Reset:= TRUE;	
	END_IF	
	
	//*****************************Porucha modulu SI1***********************************************************//
	IF Safety.STAV.SafetyPLC_Nabehlo AND NOT Zariadenie.STAV.KOM_Modul_SI1_OK THEN
		Alarmy[4]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF
	
	//*****************************Porucha modulu XV1***********************************************************//
	CasMeraniaModuluXV1.IN:= Safety.STAV.ZonaCS_Aktivna AND NOT Zariadenie.STAV.KOM_Modul_XV_OK;
		
	IF CasMeraniaModuluXV1.Q THEN
		Alarmy[5]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF	
	
	
	CasMeraniaModuluXV1.PT:= T#10s;
	CasMeraniaModuluXV1();
	
	//*****************************Porucha komunikacie s kamerou***********************************************//
	IF Zariadenie.STAV.Automat AND NOT Zariadenie.STAV.KOM_Checker_OK THEN
		Alarmy[6]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF
	
	
	//******************************Bolo stlaèené tlaèítko CS na ovládacom paneli zariadenia*****************************************************//
	IF EDGENEG (Safety.STAV.CS_Panel_Odblokov) THEN
		Alarmy[7]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF
	
	//******************************Bolo stlaèené tlaèítko CS na kamere*****************************************************//
	IF EDGENEG (Safety.STAV.CS_Checker_Odblokov) THEN
		Alarmy[8]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF
	
	//******************************Porucha napájania odsávania************************************************//
	IF (Zariadenie.STAV.Automat OR Zariadenie.STAV.Manual) AND NOT Zariadenie.IN.NapajanieOdsavania_OK THEN
		Alarmy[9]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF
	
	
	//******************************Porucha napájania lasera************************************************//
	IF (Zariadenie.STAV.Automat OR Zariadenie.STAV.Manual) AND NOT Zariadenie.IN.NapajanieLasera_OK THEN
		Alarmy[10]:= TRUE;
		Zariadenie.Reset:= TRUE;
	END_IF
	
	
	//******************************Porucha lasera**********************************************************//
//	IF (Zariadenie.STAV.Automat OR Zariadenie.STAV.Manual) AND Popisovanie.IN.Laser_ALARM THEN
//		Alarmy[27]:= TRUE;
//		Zariadenie.Reset:= TRUE;
//	END_IF
	

	
	//Tlaèítko Reset CS//
	IF Safety.STAV.CS_Checker_Odblokov AND Safety.STAV.CS_Panel_Odblokov AND NOT Safety.STAV.ZonaCS_Aktivna THEN
		Zariadenie.OUT.LED_Tlacitka_RESET_CS:= Blikac500ms;
	ELSIF Safety.STAV.ZonaCS_Aktivna THEN
		Zariadenie.OUT.LED_Tlacitka_RESET_CS:= TRUE;
	ELSE	
		Zariadenie.OUT.LED_Tlacitka_RESET_CS:= FALSE;
	END_IF	
	
	//Tlaèítko Štart Automat//
	IF NOT Zariadenie.STAV.Automat AND Safety.STAV.ZonaCS_Aktivna AND NOT NastalaPorucha AND Safety.STAV.ZonaVnutroBunky_Aktivna AND NOT Zariadenie.STAV.UkoncenieCyklu AND Zariadenie.IN.TlakVzduchu_OK AND Zariadenie.STAV.Moduly_OK AND Vizu.CisloAktualnejObrazovky = 2 AND NOT Zariadenie.STAV.NezvolenaReceptura AND NOT Zariadenie.KoniecModelu THEN
		Zariadenie.OUT.LED_Dvojtlacitka_StartStop:= Blikac500ms;
	ELSIF Zariadenie.STAV.Automat AND Zariadenie.STAV.UkoncenieCyklu THEN
		Zariadenie.OUT.LED_Dvojtlacitka_StartStop:= Blikac200ms;
	ELSIF Zariadenie.STAV.Automat AND NOT Zariadenie.STAV.PoINIT THEN
		Zariadenie.OUT.LED_Dvojtlacitka_StartStop:= TRUE;
	ELSIF Zariadenie.STAV.Automat AND Zariadenie.STAV.PoINIT THEN	
		Zariadenie.OUT.LED_Dvojtlacitka_StartStop:= TRUE;
	ELSE
		Zariadenie.OUT.LED_Dvojtlacitka_StartStop:= FALSE;
	END_IF	
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

