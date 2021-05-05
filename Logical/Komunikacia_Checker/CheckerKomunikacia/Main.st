
PROGRAM _INIT
	
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Vstupy pre checker KOGNEX//
	Checker.COM.ControlWord.0:= Checker.TRIGER_Enable;
	Checker.COM.ControlWord.1:= Checker.TRIGER;
	Checker.COM.ResultControl.1:= Checker.Vysledok_POTVRDENIE;
	
	//Výstupy z checkera KOGNEX//
	Checker.STAV.TRIGER_Ready:= Checker.COM.StatusWord.0;
	Checker.STAV.BUSY:= Checker.COM.ResultStatus.0;
	Checker.STAV.Vysledok_READY:= Checker.COM.ResultStatus.3;
	Checker.STAV.Vysledok_OK:= Checker.COM.ResultData.0;
	Checker.STAV.Vysledok_NG:= NOT Checker.COM.ResultData.0;
	
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

