
PROGRAM _INIT
	Checker.TRIGER_Enable:= TRUE;
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	
	//Volanie podprogramov//
	OvlStoprov;
	
	
	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_Checker);
	
	 
	
	//Reset sekcie //
	IF Checker.Reset OR PoruchaCheckera THEN
		SC_Checker.Step:= 0;
	END_IF
	
	
	
	CASE SC_Checker.Step OF 
	
		0:
			SC_Checker.StepName:='0 - Nulovanie';
			SC_OvlStoprov.Step:= 0;
			Checker.Automat:= FALSE;
			Checker.KoniecCyklu:= FALSE;
			Checker.Manual:= FALSE;
			Checker.Reset:= FALSE;
			Checker.STAV.PoINIT:= FALSE;
			Checker.OUT.BANNER_CervenaLED:= FALSE;
			Checker.OUT.BANNER_ZelenaLED:= FALSE;
			Checker.TRIGER:= FALSE;
			Checker.Vysledok_POTVRDENIE:= FALSE;
			Zariadenie.KoniecModelu:= FALSE;
						
			IF Safety.STAV.ZonaCS_Aktivna AND NOT PoruchaCheckera AND Zariadenie.IN.TlakVzduchu_OK THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 1;
			END_IF
	
		1:
			SC_Checker.StepName:='1 - Cakam na spustenie vyroby';
			IF Checker.Automat THEN
				SC_Checker.Step:= 2;
			ELSIF Checker.Manual THEN
				SC_Checker.Step:= 700;
			END_IF
			
		
			//********************************************************Inicializácia****************************************************************************//
	
		2:
			SC_Checker.StepName:='2 - Inicializacia - cakam na spustenie inicializacie';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			SC_Checker.IdleTime.IN:= TRUE;
						
			IF SC_Checker.IdleTime.Q THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 3;
			END_IF
	
	
		3:
			SC_Checker.StepName:='3 - Inicializacia - rozhodnutie o inicializacii';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
		
			IF Checker.STAV.Stopre_PoziciaNAVAZANIE THEN
				(*Checker.OUT.BANNER_ZelenaLED:= TRUE;*)
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 10;
			ELSIF Checker.STAV.Stopre_PoziciaVYVAZANIE THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 5;
			ELSE
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 7;
			END_IF	
	
			
				
			
			
		5:
			SC_Checker.StepName:='5 - Inicializacia - cakam na odchod paletky z 2 stopra';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
		
			SC_Checker.IdleTime.IN:= NOT Checker.IN.Stoper2_PritomnostPaletky;
			
			IF SC_Checker.IdleTime.Q THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 7;
			END_IF
	
			
		7:
			SC_Checker.StepName:='7 - Inicializacia - preklopenie stoprov do pozicie navazania';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF NOT SC_Checker.Switch1 THEN
				Stopre_pozNAVAZANIE:= TRUE;
				SC_Checker.Switch1:= TRUE;
			END_IF
			
			IF Checker.STAV.Stopre_PoziciaNAVAZANIE THEN
				(*Checker.OUT.BANNER_ZelenaLED:= TRUE;*)
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 10;
			END_IF		
	
	
		10:
			SC_Checker.StepName:='10 - Inicializacia - vynulovanie bitu novy vysledok checkera READY';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF Checker.STAV.Vysledok_READY THEN
				Checker.Vysledok_POTVRDENIE:= TRUE;
			ELSE
				Checker.Vysledok_POTVRDENIE:= FALSE;
				Checker.STAV.PoINIT:= TRUE;
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 100;
			END_IF	
			
			
	
			//********************************************************Automatický režim****************************************************************************//
				
		100:
			SC_Checker.StepName:='100 - Automaticky Rezim - cakam na pritomnost paletky na 2 stopri';
			SC_Checker.IdleTime.PT:= T#1s;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			SC_Checker.IdleTime.IN:= Checker.IN.Stoper2_PritomnostPaletky;
			SC_Checker.AlarmTime.IN:= NOT Checker.IN.Stoper2_PritomnostPaletky;
			
			IF SC_Checker.IdleTime.Q THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 105;
			ELSIF Checker.KoniecCyklu AND NOT Popisovanie.Automat THEN	
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 0;
			ELSIF Zariadenie.KoniecModelu AND SC_Checker.AlarmTime.Q THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 0;
			END_IF		
			
		105:
			SC_Checker.StepName:='105 - Automaticky Rezim - rozhodnutie o kontrole QR kodu';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF Zariadenie.PriechodnyRezim THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 120;
			ELSIF Checker.KAMERA_OFF THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 120;
			ELSIF Checker.IN.Stoper2_PritomnostStatora THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 109;
			ELSE
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 120;
			END_IF	
		
		109:
			SC_Checker.StepName:='10 - Automaticky Rezim - vynulovanie bitu novy vysledok checkera READY';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF Checker.STAV.Vysledok_READY THEN
				Checker.Vysledok_POTVRDENIE:= TRUE;
			ELSE
				Checker.Vysledok_POTVRDENIE:= FALSE;
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 110;
			END_IF	
			
			
		110:
			SC_Checker.StepName:='110 - Automaticky Rezim - start citania QR kodu';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF NOT SC_Checker.Switch1 THEN
				Checker.TRIGER:= TRUE;
				SC_Checker.IdleTime.IN:= TRUE;
				SC_Checker.Switch1:= TRUE;
			END_IF
			
			IF Checker.STAV.BUSY OR SC_Checker.IdleTime.Q THEN
				Checker.TRIGER:= FALSE;
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 112;
			END_IF	
			
		112:
			SC_Checker.StepName:='112 - Automaticky Rezim - cakam na vysledok z kamery';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;	
			
			IF Checker.STAV.Vysledok_READY THEN
				IF Checker.STAV.Vysledok_OK THEN
					Checker.OUT.BANNER_CervenaLED:= FALSE;
					(*Checker.OUT.BANNER_ZelenaLED:= TRUE;*)
					SC_Checker.ResetStep:= TRUE;
					SC_Checker.Step:= 120;
				ELSIF Checker.STAV.Vysledok_NG THEN	
					(*Checker.OUT.BANNER_ZelenaLED:= FALSE;*)
					SC_Checker.ResetStep:= TRUE;
					SC_Checker.Step:= 115;
				END_IF
			ELSIF Checker.KAMERA_OFF THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 120;
			END_IF	
			
		
			
			
			
				
					
		115:
			SC_Checker.StepName:='115 - Automaticky Rezim - vysunutie stopra 1';
			SC_Checker.IdleTime.PT:= T#1s;
			SC_Checker.AlarmTime.PT:= T#5s;		
			
			IF NOT SC_Checker.Switch1 THEN
				Stoper1_VYSUN:= TRUE;
				SC_Checker.Switch1:= TRUE;
			END_IF
			
			IF Checker.IN.Stoper1_VYSUNUTY THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 116;
			END_IF	
			
		116:
			SC_Checker.StepName:='116 - Automaticky Rezim - cakam na odobratie statora s paletkou a potvrdenie bannerom';
			SC_Checker.IdleTime.PT:= T#1s;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			Checker.OUT.BANNER_CervenaLED:= Blikac200ms;
			
			IF NOT Checker.IN.Stoper2_PritomnostPaletky AND NOT Checker.IN.Stoper2_PritomnostStatora AND Checker.IN.TlacitkoBANNER THEN
				Checker.OUT.BANNER_CervenaLED:= FALSE;
				(*Checker.OUT.BANNER_ZelenaLED:= TRUE;*)
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 117;
			ELSIF Checker.KoniecCyklu AND NOT Popisovanie.Automat THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 0;
			END_IF	
			
			
		117:
			SC_Checker.StepName:='117 - Automaticky Rezim - zasunutie stopra 1';
			SC_Checker.IdleTime.PT:= T#1s;
			SC_Checker.AlarmTime.PT:= T#5s;		
			
			IF NOT SC_Checker.Switch1 THEN
				Stoper1_ZASUN:= TRUE;
				SC_Checker.Switch1:= TRUE;
			END_IF
			
			IF Checker.IN.Stoper1_ZASUNUTY THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 100;
			END_IF	
			
		
			
			
		120:
			SC_Checker.StepName:='120 - Automaticky Rezim - cakam na uvolnenie vystupnej trate';
			SC_Checker.IdleTime.PT:= T#1s;
			SC_Checker.AlarmTime.PT:= T#5s;		
			
			SC_Checker.IdleTime.IN:= NOT Checker.IN.ZaplnenieVystupnejTrate;
			
			IF SC_Checker.IdleTime.Q THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 121;
			ELSIF Checker.KoniecCyklu AND NOT Popisovanie.Automat THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 0;	
			END_IF
		
		
		121:
			SC_Checker.StepName:='121 - Automaticky Rezim - preklopenie stoprov do pozicie vyvazania';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF NOT SC_Checker.Switch1 THEN
				Stopre_pozVYVAZANIE:= TRUE;
				SC_Checker.Switch1:= TRUE;
			END_IF
			
			IF Checker.STAV.Stopre_PoziciaVYVAZANIE THEN
				Checker.STAV.PoINIT:= TRUE;
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 122;
			END_IF		
		
		122:
			SC_Checker.StepName:='122 - Automaticky Rezim - cakam na odchod paletky z 2 stopra';
			SC_Checker.IdleTime.PT:= T#1s;
			SC_Checker.AlarmTime.PT:= T#5s;
		
			SC_Checker.IdleTime.IN:= NOT Checker.IN.Stoper2_PritomnostPaletky;
			
			IF SC_Checker.IdleTime.Q THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 123;
			END_IF
		
		123:
			SC_Checker.StepName:='123 - Automaticky Rezim - preklopenie stoprov do pozicie navazania';
			SC_Checker.IdleTime.PT:= T#500ms;
			SC_Checker.AlarmTime.PT:= T#5s;
			
			IF NOT SC_Checker.Switch1 THEN
				Stopre_pozNAVAZANIE:= TRUE;
				SC_Checker.Switch1:= TRUE;
			END_IF
			
			IF Checker.STAV.Stopre_PoziciaNAVAZANIE THEN
				SC_Checker.ResetStep:= TRUE;
				SC_Checker.Step:= 100;
			END_IF
		
		
			//*******************************************************Manuálny režim*******************************************************************************//
		700:
			SC_Checker.StepName:='700 - Manualny Rezim';
			SC_Checker.IdleTime.PT:= T#8s;
			SC_Checker.AlarmTime.PT:= T#5s;
		
		
		
		
	END_CASE
	
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

