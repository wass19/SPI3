/**
* @author LeNomDeLEtudiant
* @version 0.1 : Date : Sun Feb 25 13:16:02 CET 2018
*
*/
public class PasDeCaseIciException extends Exception {

	/**
	 * Création d'une exception sans description
	 */
	public PasDeCaseIciException() {
		super();
	}
	
	/**
	 * Création d'une exception avec description
	 * @param desc description de l'exception
	 */	
	public PasDeCaseIciException(String desc) {
		super(desc);
	}
	
}