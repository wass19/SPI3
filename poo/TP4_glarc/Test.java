/**
* @author LeNomDeLEtudiant
* @version 0.1 : Date : Sun Feb 25 13:14:11 CET 2018
*
*/
public class Test {

	public static void main(String[] args) throws InterruptedException{
		Jeu j = new Jeu();
		Fenetre f = new Fenetre(j);
		j.start();
	}

}