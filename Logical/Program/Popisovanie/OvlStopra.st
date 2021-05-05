
ACTION OvlStopra: 

	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_OvlStopra);
	
	
	
	CASE SC_OvlStopra.Step OF
		
		0:
			SC_OvlStopra.StepName:= '0 - Nulovanie';
			StoperZdvizky_VYSUN:= FALSE;
			StoperZdvizky_ZASUN:= FALSE;
			Popisovanie.OUT.StoperZdvizky_VYSUN:= FALSE;
			Popisovanie.OUT.StoperZdvizky_ZASUN:= FALSE;
			IF SC_Popisovanie.Step <> 0 THEN
				SC_OvlStopra.ResetStep:= TRUE;
				SC_OvlStopra.Step:= 1;
			END_IF
		
		1:
			SC_OvlStopra.StepName:= '1 - Rozhodnutie o cinnosti';
			IF StoperZdvizky_VYSUN THEN
				SC_OvlStopra.Step:= 10;
			ELSIF StoperZdvizky_ZASUN THEN
				SC_OvlStopra.Step:= 20;
			END_IF
	
		10:
			SC_OvlStopra.StepName:= '10 - Vysunutie stopra';
			SC_OvlStopra.IdleTime.PT:= T#3s;
			SC_OvlStopra.AlarmTime.PT:= T#3s;
			
			IF Popisovanie.Automat THEN
				SC_OvlStopra.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStopra.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStopra.Switch1 THEN
				Popisovanie.OUT.StoperZdvizky_VYSUN:= TRUE;
				SC_OvlStopra.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStopra.AlarmTime.Q THEN
				Alarmy[15]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Popisovanie.IN.StoperZdvizky_VYSUNUTY OR SC_OvlStopra.IdleTime.Q THEN
				SC_OvlStopra.ResetStep:= TRUE;
				SC_OvlStopra.Step:= 0;
			END_IF
	
		20:
			SC_OvlStopra.StepName:= '20 - Zasunutie stopra';
			SC_OvlStopra.IdleTime.PT:= T#3s;
			SC_OvlStopra.AlarmTime.PT:= T#3s;
			
			IF Popisovanie.Automat THEN
				SC_OvlStopra.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStopra.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStopra.Switch1 THEN
				Popisovanie.OUT.StoperZdvizky_ZASUN:= TRUE;
				SC_OvlStopra.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStopra.AlarmTime.Q THEN
				Alarmy[16]:= TRUE;
				PoruchaPopisovania:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Popisovanie.IN.StoperZdvizky_ZASUNUTY OR SC_OvlStopra.IdleTime.Q THEN
				SC_OvlStopra.ResetStep:= TRUE;
				SC_OvlStopra.Step:= 0;
			END_IF
			
			
	END_CASE		
	
	
END_ACTION
