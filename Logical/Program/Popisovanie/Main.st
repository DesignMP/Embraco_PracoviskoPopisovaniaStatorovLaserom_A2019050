
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Volanie podprogramov//
	OvlStopra;
	OvlZdvizky;
	SpravaPreLaser;
	
	
	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_Popisovanie);
	
	 
	
	//Reset sekcie //
	IF Popisovanie.Reset OR PoruchaPopisovania THEN
		SC_Popisovanie.Step:= 0;
	END_IF
	
	CASE SC_Popisovanie.Step OF 
	
		0:
			SC_Popisovanie.StepName:='0 - Nulovanie';
			SC_OvlStopra.Step:= 0;
			SC_OvlZdvizky.Step:= 0;
			Popisovanie.Automat:= FALSE;
			Popisovanie.KoniecCyklu:= FALSE;
			Popisovanie.Manual:= FALSE;
			Popisovanie.Reset:= FALSE;
			Popisovanie.STAV.PoINIT:= FALSE;
			Laser.Commands.VyberSpravuLasera:= FALSE;
			Laser.Commands.OdosliDataSpravy:= FALSE;
			Popisovanie.OUT.Laser_StartZnacenia:= FALSE;
			Popisovanie.OUT.Odsavanie_Start:= FALSE;
			Popisovanie.PAR.PocetPrazdnychPaletiek:= 0;
			Popisovanie.STAV.Zdvizka_PritomnostNGkusu:= FALSE;
			
						
			IF Safety.STAV.ZonaCS_Aktivna AND NOT PoruchaPopisovania AND Zariadenie.IN.TlakVzduchu_OK AND Safety.STAV.ZonaVnutroBunky_Aktivna THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 1;
			END_IF
	
		1:
			SC_Popisovanie.StepName:='1 - Cakam na spustenie vyroby';
			IF Popisovanie.Automat THEN
				SC_Popisovanie.Step:= 2;
			ELSIF Popisovanie.Manual THEN
				SC_Popisovanie.Step:= 700;
			END_IF
			
		
			//********************************************************Inicializácia****************************************************************************//
	
	
		2:
			SC_Popisovanie.StepName:='2 - Inicializacia - cakam na spustenie inicializacie';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
			
			SC_Popisovanie.IdleTime.IN:= TRUE;
						
			IF SC_Popisovanie.IdleTime.Q THEN
				Zariadenie.TaktTime_RESET:= TRUE;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 3;
			END_IF
	
		
		3:
			SC_Popisovanie.StepName:='3 - Inicializacia - rozhodnutie o inicializacii';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
		
			IF Popisovanie.IN.Zdvizka_ZASUNUTA THEN
				IF Popisovanie.IN.StoperZdvizky_VYSUNUTY THEN
					SC_Popisovanie.ResetStep:= TRUE;
					SC_Popisovanie.Step:= 15;
				ELSIF Popisovanie.IN.StoperZdvizky_ZASUNUTY THEN
					SC_Popisovanie.ResetStep:= TRUE;
					SC_Popisovanie.Step:= 4;
				END_IF
			ELSE
				IF Popisovanie.IN.StoperZdvizky_VYSUNUTY THEN
					SC_Popisovanie.ResetStep:= TRUE;
					SC_Popisovanie.Step:= 10;
				ELSIF Popisovanie.IN.StoperZdvizky_ZASUNUTY THEN
					SC_Popisovanie.ResetStep:= TRUE;
					SC_Popisovanie.Step:= 5;
				END_IF
			END_IF	
		
			
		4:
			SC_Popisovanie.StepName:='4 - Inicializacia - cakam na odchod paletky zo stopra zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#1s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			SC_Popisovanie.IdleTime.IN:= NOT Popisovanie.IN.StoperZdvizky_PritomnostPaletky;
			
			IF SC_Popisovanie.IdleTime.Q THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 5;
			END_IF	
			
			
		5:
			SC_Popisovanie.StepName:='5 - Inicializacia - vysunutie stopra zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
			IF NOT SC_Popisovanie.Switch1 THEN
				StoperZdvizky_VYSUN:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Popisovanie.IN.StoperZdvizky_VYSUNUTY THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 10;
			END_IF	
		
		
		10:
			SC_Popisovanie.StepName:='10 - Inicializacia - zasunutie zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
			IF NOT SC_Popisovanie.Switch1 THEN
				Zdvizku_ZASUN:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Popisovanie.IN.Zdvizka_ZASUNUTA THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 15;
			END_IF	
			
		15:
			SC_Popisovanie.StepName:='15 - Inicializacia - vyber spravy do lasera';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
			
			IF NOT SC_Popisovanie.Switch1 THEN
				Laser.Commands.VyberSpravuLasera:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF EDGEPOS(Laser.Status.VyberSpravy_OK) THEN
				Popisovanie.STAV.PoINIT:= TRUE;
				IF NOT Zariadenie.PriechodnyRezim THEN
					Popisovanie.OUT.Odsavanie_Start:= TRUE;
				END_IF	
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 100;
			ELSIF EDGEPOS(Laser.Status.VyberSpravy_NG) THEN
				Alarmy[29]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF	
			
		
		
			//********************************************************Automatický režim****************************************************************************//
				
		100:
			SC_Popisovanie.StepName:='100 - Automaticky Rezim - cakam na pritomnost paletky na stopri zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
					
			SC_Popisovanie.IdleTime.IN:= Popisovanie.IN.StoperZdvizky_PritomnostPaletky;
			
			IF Popisovanie.KoniecCyklu THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 0;
			ELSIF Zariadenie.KoniecModelu THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 0;
			ELSIF SC_Popisovanie.IdleTime.Q THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 103;
			END_IF
		
			
		103:
			SC_Popisovanie.StepName:='103 - Automaticky Rezim - rozhodnutie o popisovani statora';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
			
			IF Zariadenie.PriechodnyRezim THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 130;
			ELSIF Stav_StatorPopisany THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 130;
			ELSIF Popisovanie.IN.StoperZdvizky_PritomnostStatora THEN
				Popisovanie.PAR.PocetPrazdnychPaletiek:= 0;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 105;
			ELSE
				Popisovanie.PAR.PocetPrazdnychPaletiek:= Popisovanie.PAR.PocetPrazdnychPaletiek + 1;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 120;
			END_IF
		
			
		105:
			SC_Popisovanie.StepName:='105 - Automaticky Rezim - kontrola safety snimaca statora pod laserom';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
			
			IF NOT Safety.STAV.SnimacStatorPodLaserom_Aktivny THEN
				Zariadenie.TaktTime_ZAPIS:= TRUE;
				Zariadenie.TaktTime_START:= TRUE;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 107;
			ELSE	
				Alarmy[23]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
			
				
		107:
			SC_Popisovanie.StepName:='107 - Automaticky Rezim - vysunutie zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#4s;	
			
			IF NOT SC_Popisovanie.Switch1 THEN
				Zdvizku_VYSUN:= TRUE;
				SC_Popisovanie.AlarmTime.IN:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Safety.STAV.SnimacStatorPodLaserom_Aktivny THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 111;
			ELSIF SC_Popisovanie.AlarmTime.Q THEN
				Popisovanie.STAV.Zdvizka_PritomnostNGkusu:= TRUE;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 110;
			END_IF	
		
			
			
		110:
			SC_Popisovanie.StepName:='107 - Automaticky Rezim - cakam na potvrdenie obsluhy';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			IF NOT Popisovanie.STAV.Zdvizka_PritomnostNGkusu AND SC_OvlZdvizky.Step = 1 THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 115;
			END_IF	
			
		
		111:
			SC_Popisovanie.StepName:='111 - Automaticky Rezim - posielam spravu do lasera';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			IF NOT SC_Popisovanie.Switch1 THEN
				Laser.Commands.OdosliDataSpravy:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF EDGEPOS(Laser.Status.OdoslanieDatSpravy_OK) THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 112;
			ELSIF EDGEPOS(Laser.Status.OdoslanieDatSpravy_NG) THEN
				Alarmy[26]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF	
			
					
		112:
			SC_Popisovanie.StepName:='112 - Automaticky Rezim - cakam na stav Laser READY';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			SC_Popisovanie.AlarmTime.IN:= TRUE;
			
			IF Popisovanie.IN.Laser_StavREADY AND Safety.STAV.ZonaLaser_Aktivna THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 113;
			END_IF	
			
			IF SC_Popisovanie.AlarmTime.Q THEN
				Alarmy[25]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF	
			
			
		113:
			SC_Popisovanie.StepName:='113 - Automaticky Rezim - start popisovania';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			IF NOT SC_Popisovanie.Switch1 THEN
				Popisovanie.OUT.Laser_StartZnacenia:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Popisovanie.IN.Laser_StavBUSY THEN
				Popisovanie.OUT.Laser_StartZnacenia:= FALSE;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 114;
			END_IF	
			
		114:
			SC_Popisovanie.StepName:='114 - Automaticky Rezim - cakam na ukoncenie popisovania';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			IF Popisovanie.IN.Laser_StavEND THEN
				Stav_StatorPopisany:= TRUE;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 115;
			END_IF	
			
	
		115:
			SC_Popisovanie.StepName:='115 - Automaticky Rezim - zasunutie zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
			IF NOT SC_Popisovanie.Switch1 THEN
				Zdvizku_ZASUN:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Popisovanie.IN.Zdvizka_ZASUNUTA AND NOT Safety.STAV.SnimacStatorPodLaserom_Aktivny THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 130;
			ELSIF Popisovanie.IN.Zdvizka_ZASUNUTA AND Safety.STAV.SnimacStatorPodLaserom_Aktivny THEN
				Alarmy[24]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF	
			
		
		120:
			SC_Popisovanie.StepName:='120 - Automaticky Rezim - kontrola poctu prazdnych paletiek';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
			
			IF Popisovanie.PAR.PocetPrazdnychPaletiek >= 2 THEN
				Zariadenie.KoniecModelu:= TRUE;
				Vizu.Zobraz_HlasenieVymenaModelu:= 0;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 130;
			ELSE
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 130;
			END_IF	
			
		
		
		130:
			SC_Popisovanie.StepName:='130 - Automaticky Rezim - cakam na uvolnenie snimaca zasoby pred kamerou';
			SC_Popisovanie.IdleTime.PT:= T#200ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
			
			SC_Popisovanie.IdleTime.IN:= NOT Checker.IN.ZasobaPredStoprom1;
			
			IF SC_Popisovanie.IdleTime.Q THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 131;
			ELSIF Popisovanie.KoniecCyklu THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 0;
			END_IF	
				
			
			
		131:
			SC_Popisovanie.StepName:='131 - Automaticky Rezim - zasunutie stopra zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
			IF NOT SC_Popisovanie.Switch1 THEN
				StoperZdvizky_ZASUN:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Popisovanie.IN.StoperZdvizky_ZASUNUTY THEN
				Stav_StatorPopisany:= FALSE;
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 133;
			END_IF			
		
		133:
			SC_Popisovanie.StepName:='133 - Automaticky Rezim - cakam na odchod paletky zo stopra zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;	
			
			SC_Popisovanie.IdleTime.IN:= NOT Popisovanie.IN.StoperZdvizky_PritomnostPaletky;
			
			IF SC_Popisovanie.IdleTime.Q THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 135;
			END_IF	
			
			
		135:
			SC_Popisovanie.StepName:='135 - Automaticky Rezim - vysunutie stopra zdvizky';
			SC_Popisovanie.IdleTime.PT:= T#500ms;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
			IF NOT SC_Popisovanie.Switch1 THEN
				StoperZdvizky_VYSUN:= TRUE;
				SC_Popisovanie.Switch1:= TRUE;
			END_IF
			
			IF Popisovanie.IN.StoperZdvizky_VYSUNUTY THEN
				SC_Popisovanie.ResetStep:= TRUE;
				SC_Popisovanie.Step:= 100;
			END_IF	
			
			
			
			
		
		
		
			//*******************************************************Manuálny režim*******************************************************************************//
		700:
			SC_Popisovanie.StepName:='700 - Manualny Rezim';
			SC_Popisovanie.IdleTime.PT:= T#8s;
			SC_Popisovanie.AlarmTime.PT:= T#5s;
		
		
		
	
	END_CASE
			
			
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

