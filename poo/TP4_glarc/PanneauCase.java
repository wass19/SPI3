/**
* @author LeNomDeLEtudiant
* @version 0.1 : Date : Sun Feb 25 13:11:49 CET 2018
*
*/
import javax.swing.JPanel;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.Color;
import java.util.*;
import java.net.URL;
import java.awt.image.BufferedImage;

public class PanneauCase extends JPanel{

	private Case uneCase;

	public static final Color colorCase = Color.black;
	public static final int scl = 50;
	private static Image imgGlouton, imgBorne, imgPirate, imgBlurf;

	private static final String LIEN_GLOUTON = "https://upload.wikimedia.org/wikipedia/commons/thumb/4/49/Pacman.svg/1200px-Pacman.svg.png";
	private static final String LIEN_BORNE = "https://upload.wikimedia.org/wikipedia/commons/thumb/d/d2/ReuleauxTriangle.svg/220px-ReuleauxTriangle.svg.png";
	private static final String LIEN_PIRATE = "http://www2.mes-coloriages-preferes.biz/colorino/Images/Large/Personnages-feeriques-Pirate-73570.png";
	private static final String LIEN_BLURF = "https://scontent-sea1-1.cdninstagram.com/vp/e26bcd07cf4614de653de887fcd38fb3/5B1BB60A/t51.2885-15/s750x750/sh0.08/e35/12407265_920955204626706_2099186067_n.jpg?ig_cache_key=MTE2MTQ1MzYyMjA3Mzg3NTgwMQ%3D%3D.2";

	static{

		System.setProperty("java.net.useSystemProxies","true");

		try{
	    	imgGlouton = ImageIO.read(new URL(LIEN_GLOUTON));
			imgBorne = ImageIO.read(new URL(LIEN_BORNE));
			imgPirate = ImageIO.read(new URL(LIEN_PIRATE));
			imgBlurf = ImageIO.read(new URL(LIEN_BLURF));
	
	    }catch (IOException e){
	      	e.printStackTrace();
	    }
	}

	public PanneauCase(Case uneCase){
		this.uneCase = uneCase;
	}

	public void paintComponent(Graphics g){
		g.setColor(colorCase);
		
		if(uneCase instanceof CaseObstacle){
			g.fillRect(scl+uneCase.gety()*scl,scl+uneCase.getx()*scl,scl,scl);
		}else if(uneCase instanceof CaseLibre){

			CaseLibre newCase = (CaseLibre) uneCase;
	
			if(!newCase.hasGlark()){
				if(newCase.getBlurf()){
					
					g.drawImage(imgBlurf,scl+newCase.gety()*scl,scl+newCase.getx()*scl,scl,scl,this);
				}
				else g.drawRect(scl+newCase.gety()*scl,scl+newCase.getx()*scl,scl,scl);
			}else{


			if(newCase.getFirstGlark() instanceof Borne)
				g.drawImage(imgBorne,scl+newCase.gety()*scl,scl+newCase.getx()*scl,scl,scl,this);
			else if(newCase.getFirstGlark() instanceof Glouton)
				g.drawImage(imgGlouton,scl+newCase.gety()*scl,scl+newCase.getx()*scl,scl,scl,this);
			else if(newCase.getFirstGlark() instanceof Pirate)
				g.drawImage(imgPirate,scl+newCase.gety()*scl,scl+newCase.getx()*scl,scl,scl,this);
			}
		}
	}
}