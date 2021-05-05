
PROGRAM _INIT
	Vizu.Zobraz_HlasenieVymenaModelu:= 1;
	Vizu.Zobraz_ResetZariadenia:= 1;
	Vizu.Zobraz_HlasenieNaZdvizkeNGkus:= 1;
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Zobrazenie úvodnej obrazovky//
	IF NOT Safety.STAV.SafetyPLC_Nabehlo THEN
		Vizu.CisloZadanejObrazovky:= 0;
		IF EDGEPOS (Blikac500ms = TRUE) THEN
			Vizu.Slider:= Vizu.Slider+1;
			IF Vizu.Slider > 30 THEN
				Vizu.Slider:= 0;
			END_IF
		END_IF
	END_IF
	
	//Prepnutie na hlavnú obrazovku//
	IF EDGEPOS (Safety.STAV.SafetyPLC_Nabehlo = TRUE) THEN
		Vizu.CisloZadanejObrazovky:= 1;
	END_IF
	

	//Prepnutie na obrazovku alarmov//
	IF EDGEPOS(NastalaPorucha) THEN
		Vizu.CisloZadanejObrazovky:= 5;
	END_IF	
	
	
	//******************************************************Podsvietenie tlaèítok**********************************************************//
	//Tlaèítko zámku dverí s rozvádzaèom//
	IF Safety.IN.DvereBunky_AktuatorVzamku AND NOT Safety.STAV.DvereBunky_Zamknute THEN
		Vizu.LED_TlacitkaZamokDveriBunky:= Blikac500ms;
	ELSIF Safety.STAV.DvereBunky_Zamknute THEN
		Vizu.LED_TlacitkaZamokDveriBunky:= 2;
	ELSE
		Vizu.LED_TlacitkaZamokDveriBunky:= 3;
	END_IF
	
	
	//****************************************************Zobrazenie hlásení****************************************************************//
	//Zobrazenie hlásenia zámky vyblokované//
	IF Safety.STAV.VyblokovanieZamkov_Aktivne THEN
		Vizu.Zobraz_HlasenieZamkyVyblokovane:= 0;
	ELSE	
		Vizu.Zobraz_HlasenieZamkyVyblokovane:= 1;
	END_IF	
	
	//Zobrazenie hlásenia nízky tlak vzduchu//
	IF NOT Zariadenie.IN.TlakVzduchu_OK THEN
		Vizu.Zobraz_HlasenieNizkyTlakVzduchu:= 0;
	ELSE	
		Vizu.Zobraz_HlasenieNizkyTlakVzduchu:= 1;
	END_IF	
	
	
	//Zobrazenie hlásenia nezvolená receptura//
	//Príznak nezvolená receptura//
	IF Zariadenie.STAV.NezvolenaReceptura THEN
		Vizu.Zobraz_HlasenieNezvolenaRecept:= 0;
	ELSE	
		Vizu.Zobraz_HlasenieNezvolenaRecept:= 1;
	END_IF	
	
	//Zobrazenie hlásenia na zdvižke je NG kus//
	IF Popisovanie.STAV.Zdvizka_PritomnostNGkusu THEN
		Vizu.Zobraz_HlasenieNaZdvizkeNGkus:= 0;
	ELSE
		Vizu.Zobraz_HlasenieNaZdvizkeNGkus:= 1;
	END_IF	
	
	
	//Zobrazenie tlaèítka OK v hlásení zmena modelu//
	IF Vizu.Zobraz_HlasenieVymenaModelu = 0 AND NOT Zariadenie.STAV.Automat THEN
		Vizu.Zobraz_TlacitkoOK_ZmenaModelu:= 0;
	END_IF	
	IF Vizu.Zobraz_HlasenieVymenaModelu = 1 THEN	 
		Vizu.Zobraz_TlacitkoOK_ZmenaModelu:= 1;
	END_IF	
	
	//****************************************************Zamknutie tlaèítok****************************************************************//
	//Zamknutie tlaèítka Režim Automat//
	IF NOT Safety.STAV.ZonaCS_Aktivna THEN
		Vizu.ZamkniTlacitkoRezimAutomat:= 1;
	ELSIF NOT Safety.STAV.ZonaVnutroBunky_Aktivna THEN
		Vizu.ZamkniTlacitkoRezimAutomat:= 1;
	ELSE	
		Vizu.ZamkniTlacitkoRezimAutomat:= 0;
	END_IF
	
	
	//Zamknutie tlaèítka Režim Manual//
	IF NOT Safety.STAV.ZonaCS_Aktivna THEN
		Vizu.ZamkniTlacitkoRezimManual:= 1;
	ELSIF NastalaPorucha THEN
		Vizu.ZamkniTlacitkoRezimManual:= 1;
	ELSIF Zariadenie.STAV.Automat THEN
		Vizu.ZamkniTlacitkoRezimManual:= 1;
	ELSIF NOT Zariadenie.IN.TlakVzduchu_OK THEN
		Vizu.ZamkniTlacitkoRezimManual:= 1;
	ELSIF NOT Zariadenie.STAV.Moduly_OK THEN
		Vizu.ZamkniTlacitkoRezimManual:= 1;
	ELSE
		Vizu.ZamkniTlacitkoRezimManual:= 0;
	END_IF	
	
	
	//Zamknutie tlaèítok ovládanie zdvižky//
	IF NOT Safety.STAV.ZonaVnutroBunky_Aktivna THEN
		Vizu.ZamkniTlacitkaOvladaniaZdvizky:= 1;
	ELSE
		Vizu.ZamkniTlacitkaOvladaniaZdvizky:= 0;
	END_IF	
	
	
	//Zamknutie tlaèítok ovládania zámkov dverí//
	IF Zariadenie.STAV.Automat THEN
		Vizu.ZamkniTlacitkoZamokDveriBunky:= 1;
	ELSE
		Vizu.ZamkniTlacitkoZamokDveriBunky:= 0;
	END_IF	
		
	
	//Zamknutie tlaèítka Priechodný režim//
	IF Zariadenie.STAV.Automat THEN
		Vizu.ZamkniTlacitkoPriechodnyRezim:= 1;
	ELSE
		Vizu.ZamkniTlacitkoPriechodnyRezim:= 0;
	END_IF	
	
	//Zamknutie tlaèítka Štart popisovania laserom//
	IF NOT Safety.STAV.ZonaLaser_Aktivna THEN
		Vizu.ZamkniTlacitko_StartPopisovania:= 1;
	ELSIF NOT Popisovanie.IN.Laser_StavREADY THEN
		Vizu.ZamkniTlacitko_StartPopisovania:= 1;
	ELSE	
		Vizu.ZamkniTlacitko_StartPopisovania:= 0;
	END_IF	
	
	//Zamknutie tlaèítka Laser - výber správy//
	IF Popisovanie.IN.Laser_StavREADY THEN
		Vizu.ZamkniTlacitkoLaserVolbaSpravy:= 0;
	ELSE
		Vizu.ZamkniTlacitkoLaserVolbaSpravy:= 1;
	END_IF	
	
	
	//Zamknutie tlaèítka Laser - poslanie dát správy//
	IF Popisovanie.IN.Laser_StavREADY AND Laser.Status.VyberSpravy_OK THEN
		Vizu.ZamkniTlacitkoLaserPosliData:= 0;
	ELSE
		Vizu.ZamkniTlacitkoLaserPosliData:= 1;
	END_IF	
	

	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

