
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	 
	//Meranie taktime bunky//
	IF Zariadenie.TaktTime_START THEN
		Zariadenie.TaktTime_Milisekundy:= Zariadenie.TaktTime_Milisekundy + 2;//Pretože je v taskovej triede 2ms tak prirátaváme + 2//
		IF Zariadenie.TaktTime_Milisekundy >= 1000 THEN
			Zariadenie.TaktTime_Sekundy:= Zariadenie.TaktTime_Sekundy + 1;
			Zariadenie.TaktTime_Milisekundy:= 0;
		END_IF
		IF Zariadenie.TaktTime_Sekundy >= 60 THEN
			Zariadenie.TaktTime_Minuty:= Zariadenie.TaktTime_Minuty + 1;
			Zariadenie.TaktTime_Sekundy:= 0;
		END_IF	
		IF Zariadenie.TaktTime_Minuty >= 60 THEN
			Zariadenie.TaktTime_Hodiny:= Zariadenie.TaktTime_Hodiny + 1;
			Zariadenie.TaktTime_Minuty:= 0;
		END_IF
		IF Zariadenie.TaktTime_Hodiny >= 24 THEN
			Zariadenie.TaktTime_RESET:= TRUE;
		END_IF
	END_IF	
		
	IF Zariadenie.TaktTime_RESET THEN
		Zariadenie.TaktTime_START:= FALSE;
		Zariadenie.TaktTime_Milisekundy:= 0;
		Zariadenie.TaktTime_Sekundy:= 0;
		Zariadenie.TaktTime_Minuty:= 0;
		Zariadenie.TaktTime_Hodiny:= 0;
		Zariadenie.TaktTime_RESET:= FALSE;
	END_IF	
	
	IF Zariadenie.TaktTime_ZAPIS THEN
		Zariadenie.TaktTime_NameraneHodiny:= Zariadenie.TaktTime_Hodiny;
		Zariadenie.TaktTime_NameraneMinuty:= Zariadenie.TaktTime_Minuty;
		Zariadenie.TaktTime_NameraneSekundy:= Zariadenie.TaktTime_Sekundy;
		Zariadenie.TaktTime_Milisekundy:= 0;
		Zariadenie.TaktTime_Sekundy:= 0;
		Zariadenie.TaktTime_Minuty:= 0;
		Zariadenie.TaktTime_Hodiny:= 0;	
		Zariadenie.TaktTime_ZAPIS:= FALSE;
	END_IF	
	
	
	
	
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

