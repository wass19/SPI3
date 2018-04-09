/**
* @author LeNomDeLEtudiant
* @version 0.1 : Date : Sun Feb 25 13:13:37 CET 2018
*
*/
enum Sens {
	
	NORD, EST, SUD, OUEST;

	public Sens next(){
		switch(this){
			case NORD: return EST;
			case EST : return SUD;
			case SUD : return OUEST;
			case OUEST : return NORD;
			default : return null;
		}
	}

	public Sens previous(){
		switch(this){
			case NORD: return OUEST;
			case EST : return NORD;
			case SUD : return EST;
			case OUEST : return SUD;
			default : return null;
		}
	}

	public Sens addTwo(){
		switch(this){
			case NORD: return SUD;
			case EST : return OUEST;
			case SUD : return NORD;
			case OUEST : return EST;
			default : return null;
		}
	}
}