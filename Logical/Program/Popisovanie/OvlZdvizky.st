
ACTION OvlZdvizky: 

	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_OvlZdvizky);
	
	
	
	CASE SC_OvlZdvizky.Step OF
		
		0:
			SC_OvlZdvizky.StepName:= '0 - Nulovanie';
			Zdvizku_VYSUN:= FALSE;
			Zdvizku_ZASUN:= FALSE;
			//Popisovanie.OUT.Zdvizku_VYSUN:= FALSE;
			(*Popisovanie.OUT.Zdvizku_ZASUN:= FALSE;*)
			IF SC_Popisovanie.Step <> 0 THEN
				SC_OvlZdvizky.ResetStep:= TRUE;
				SC_OvlZdvizky.Step:= 1;
			END_IF
		
		1:
			SC_OvlZdvizky.StepName:= '1 - Rozhodnutie o cinnosti';
			IF Zdvizku_VYSUN THEN
				SC_OvlZdvizky.Step:= 10;
			ELSIF Zdvizku_ZASUN THEN
				SC_OvlZdvizky.Step:= 20;
			END_IF
	
		10:
			SC_OvlZdvizky.StepName:= '10 - Vysunutie zdvizky';
			SC_OvlZdvizky.IdleTime.PT:= T#3s;
			SC_OvlZdvizky.AlarmTime.PT:= T#3s;
			
			IF Popisovanie.Automat THEN
				SC_OvlZdvizky.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlZdvizky.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlZdvizky.Switch1 THEN
				Popisovanie.OUT.Zdvizku_ZASUN:= FALSE;
				Popisovanie.OUT.Zdvizku_VYSUN:= TRUE;
				SC_OvlZdvizky.IdleTime.IN:= TRUE;
				SC_OvlZdvizky.Switch1:= TRUE;
			END_IF
		
//			IF SC_OvlZdvizky.AlarmTime.Q THEN
//				Alarmy[17]:= TRUE;
//				PoruchaPopisovania:= TRUE;
//				Zariadenie.KoniecCyklu:= TRUE;
//			END_IF
		
			IF (Popisovanie.IN.Zdvizka_VYSUNUTA OR Safety.STAV.SnimacStatorPodLaserom_Aktivny) OR SC_OvlZdvizky.IdleTime.Q THEN
				SC_OvlZdvizky.ResetStep:= TRUE;
				SC_OvlZdvizky.Step:= 0;
			END_IF
		
			
			
			
		20:
			SC_OvlZdvizky.StepName:= '20 - Zasunutie zdvizky';
			SC_OvlZdvizky.IdleTime.PT:= T#3s;
			SC_OvlZdvizky.AlarmTime.PT:= T#3s;
			
			IF Popisovanie.Automat THEN
				SC_OvlZdvizky.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlZdvizky.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlZdvizky.Switch1 THEN
				Popisovanie.OUT.Zdvizku_VYSUN:= FALSE;
				Popisovanie.OUT.Zdvizku_ZASUN:= TRUE;
				SC_OvlZdvizky.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlZdvizky.AlarmTime.Q THEN
				Alarmy[18]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Popisovanie.IN.Zdvizka_ZASUNUTA OR SC_OvlZdvizky.IdleTime.Q THEN
				SC_OvlZdvizky.ResetStep:= TRUE;
				SC_OvlZdvizky.Step:= 0;
			END_IF
		
		
		
		
	END_CASE
	
	
	
END_ACTION
