
ACTION OvlSafety: 

	//********************************************Ovladanie zámkov****************************************************//
	//Zámok dverí bunky//
	IF EDGEPOS(Vizu.TlacitkoZamkniDvereBunky) THEN
		IF Safety.STAV.ZonaCS_Aktivna AND Safety.IN.DvereBunky_AktuatorVzamku AND NOT Safety.STAV.DvereBunky_Zamknute AND Zariadenie.IN.TlakVzduchu_OK THEN
			Safety.OUT.DvereBunky_Zamkni:= TRUE;
		ELSIF Safety.STAV.DvereBunky_Zamknute AND NOT Zariadenie.STAV.Automat THEN
			Safety.OUT.DvereBunky_Zamkni:= FALSE;
		END_IF	
	ELSIF NOT Safety.STAV.ZonaCS_Aktivna THEN
		Safety.OUT.DvereBunky_Zamkni:= FALSE;
	ELSIF Safety.OdomkniDvereBunky AND NOT Zariadenie.STAV.Automat THEN
		Safety.OUT.DvereBunky_Zamkni:= FALSE;
	END_IF
	
	IF NOT Safety.STAV.DvereBunky_Zamknute THEN
		Safety.OdomkniDvereBunky:= FALSE;
	END_IF	
	
	
	//****************************************Resetovanie zón****************************************************************//
	//Reset zóny CS//
	Safety.RESET_ZonyCS:= Zariadenie.IN.TlacitkoRESET_CS;
	
	
	//Reset zóny vnútra bunky//
	IF Safety.STAV.ZonaCS_Aktivna AND Safety.STAV.DvereBunky_Zamknute AND NOT Safety.STAV.ZonaVnutroBunky_Aktivna THEN
		Safety.RESET_ZonyVnutroBunky:= TRUE;
	ELSE	
		Safety.RESET_ZonyVnutroBunky:= FALSE;
	END_IF
	
	//Reset zóny laser//
	IF Safety.STAV.ZonaCS_Aktivna AND Safety.STAV.ZonaVnutroBunky_Aktivna AND Safety.STAV.SnimacKrytuLasera_Aktivny AND Safety.STAV.SnimacStatorPodLaserom_Aktivny AND NOT Safety.STAV.ZonaLaser_Aktivna THEN
		Safety.RESET_ZonyLaser:= TRUE;
	ELSE	
		Safety.RESET_ZonyLaser:= FALSE;
	END_IF	
	
	
	
END_ACTION
