
PROGRAM _INIT
	Vizu.Zobraz_HlasenieVymenaModelu:= 1;
	Vizu.Zobraz_ResetZariadenia:= 1;
	Vizu.Zobraz_HlasenieNaZdvizkeNGkus:= 1;
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Zobrazenie �vodnej obrazovky//
	IF NOT Safety.STAV.SafetyPLC_Nabehlo THEN
		Vizu.CisloZadanejObrazovky:= 0;
		IF EDGEPOS (Blikac500ms = TRUE) THEN
			Vizu.Slider:= Vizu.Slider+1;
			IF Vizu.Slider > 30 THEN
				Vizu.Slider:= 0;
			END_IF
		END_IF
	END_IF
	
	//Prepnutie na hlavn� obrazovku//
	IF EDGEPOS (Safety.STAV.SafetyPLC_Nabehlo = TRUE) THEN
		Vizu.CisloZadanejObrazovky:= 1;
	END_IF
	

	//Prepnutie na obrazovku alarmov//
	IF EDGEPOS(NastalaPorucha) THEN
		Vizu.CisloZadanejObrazovky:= 5;
	END_IF	
	
	
	//******************************************************Podsvietenie tla��tok**********************************************************//
	//Tla��tko z�mku dver� s rozv�dza�om//
	IF Safety.IN.DvereBunky_AktuatorVzamku AND NOT Safety.STAV.DvereBunky_Zamknute THEN
		Vizu.LED_TlacitkaZamokDveriBunky:= Blikac500ms;
	ELSIF Safety.STAV.DvereBunky_Zamknute THEN
		Vizu.LED_TlacitkaZamokDveriBunky:= 2;
	ELSE
		Vizu.LED_TlacitkaZamokDveriBunky:= 3;
	END_IF
	
	
	//****************************************************Zobrazenie hl�sen�****************************************************************//
	//Zobrazenie hl�senia z�mky vyblokovan�//
	IF Safety.STAV.VyblokovanieZamkov_Aktivne THEN
		Vizu.Zobraz_HlasenieZamkyVyblokovane:= 0;
	ELSE	
		Vizu.Zobraz_HlasenieZamkyVyblokovane:= 1;
	END_IF	
	
	//Zobrazenie hl�senia n�zky tlak vzduchu//
	IF NOT Zariadenie.IN.TlakVzduchu_OK THEN
		Vizu.Zobraz_HlasenieNizkyTlakVzduchu:= 0;
	ELSE	
		Vizu.Zobraz_HlasenieNizkyTlakVzduchu:= 1;
	END_IF	
	
	
	//Zobrazenie hl�senia nezvolen� receptura//
	//Pr�znak nezvolen� receptura//
	IF Zariadenie.STAV.NezvolenaReceptura THEN
		Vizu.Zobraz_HlasenieNezvolenaRecept:= 0;
	ELSE	
		Vizu.Zobraz_HlasenieNezvolenaRecept:= 1;
	END_IF	
	
	//Zobrazenie hl�senia na zdvi�ke je NG kus//
	IF Popisovanie.STAV.Zdvizka_PritomnostNGkusu THEN
		Vizu.Zobraz_HlasenieNaZdvizkeNGkus:= 0;
	ELSE
		Vizu.Zobraz_HlasenieNaZdvizkeNGkus:= 1;
	END_IF	
	
	
	//Zobrazenie tla��tka OK v hl�sen� zmena modelu//
	IF Vizu.Zobraz_HlasenieVymenaModelu = 0 AND NOT Zariadenie.STAV.Automat THEN
		Vizu.Zobraz_TlacitkoOK_ZmenaModelu:= 0;
	END_IF	
	IF Vizu.Zobraz_HlasenieVymenaModelu = 1 THEN	 
		Vizu.Zobraz_TlacitkoOK_ZmenaModelu:= 1;
	END_IF	
	
	//****************************************************Zamknutie tla��tok****************************************************************//
	//Zamknutie tla��tka Re�im Automat//
	IF NOT Safety.STAV.ZonaCS_Aktivna THEN
		Vizu.ZamkniTlacitkoRezimAutomat:= 1;
	ELSIF NOT Safety.STAV.ZonaVnutroBunky_Aktivna THEN
		Vizu.ZamkniTlacitkoRezimAutomat:= 1;
	ELSE	
		Vizu.ZamkniTlacitkoRezimAutomat:= 0;
	END_IF
	
	
	//Zamknutie tla��tka Re�im Manual//
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
	
	
	//Zamknutie tla��tok ovl�danie zdvi�ky//
	IF NOT Safety.STAV.ZonaVnutroBunky_Aktivna THEN
		Vizu.ZamkniTlacitkaOvladaniaZdvizky:= 1;
	ELSE
		Vizu.ZamkniTlacitkaOvladaniaZdvizky:= 0;
	END_IF	
	
	
	//Zamknutie tla��tok ovl�dania z�mkov dver�//
	IF Zariadenie.STAV.Automat THEN
		Vizu.ZamkniTlacitkoZamokDveriBunky:= 1;
	ELSE
		Vizu.ZamkniTlacitkoZamokDveriBunky:= 0;
	END_IF	
		
	
	//Zamknutie tla��tka Priechodn� re�im//
	IF Zariadenie.STAV.Automat THEN
		Vizu.ZamkniTlacitkoPriechodnyRezim:= 1;
	ELSE
		Vizu.ZamkniTlacitkoPriechodnyRezim:= 0;
	END_IF	
	
	//Zamknutie tla��tka �tart popisovania laserom//
	IF NOT Safety.STAV.ZonaLaser_Aktivna THEN
		Vizu.ZamkniTlacitko_StartPopisovania:= 1;
	ELSIF NOT Popisovanie.IN.Laser_StavREADY THEN
		Vizu.ZamkniTlacitko_StartPopisovania:= 1;
	ELSE	
		Vizu.ZamkniTlacitko_StartPopisovania:= 0;
	END_IF	
	
	//Zamknutie tla��tka Laser - v�ber spr�vy//
	IF Popisovanie.IN.Laser_StavREADY THEN
		Vizu.ZamkniTlacitkoLaserVolbaSpravy:= 0;
	ELSE
		Vizu.ZamkniTlacitkoLaserVolbaSpravy:= 1;
	END_IF	
	
	
	//Zamknutie tla��tka Laser - poslanie d�t spr�vy//
	IF Popisovanie.IN.Laser_StavREADY AND Laser.Status.VyberSpravy_OK THEN
		Vizu.ZamkniTlacitkoLaserPosliData:= 0;
	ELSE
		Vizu.ZamkniTlacitkoLaserPosliData:= 1;
	END_IF	
	

	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

