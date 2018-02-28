TD1 EX1 /****/

import java.lang.Math;

public class EnsembleDeChiffre {
	private boolean[] present;

	/*Constructeur de la classe*/
	public EnsembleDeChiffre(){
		present = new boolean[10];
	}

	public void ajoute(int i){
		present[i]=true;
	}

	public void retire(int i){
		present[i]=false;
	}

	public void tirerAuHasard(){
		for(int i=0; i<10;i++){
			present[i]=(Math.random() < 0.5);
		}
	}

	public boolean appartient(int i){
		return(present[i]);
	}


	public boolean equals(Object o) {
		if(o instanceof EnsembleDeChiffre) {
			EnsembleDeChiffre e = (EnsembleDeChiffre) o;
			int i=0;
			while(i<this.present.length){
				if(this.appartient(i) == e.appartient(i)){
					i++;
				}else{
					return false;
				}
			}
			if(i>=this.present.length){
				return true;
			}
		}
		return false;
	}

	public EnsembleDeChiffre instersectionAvec(EnsembleDeChiffre ensemble){
		EnsembleDeChiffre resultat = new EnsembleDeChiffre();
		for(int i=0;i<this.present.length;i++){
			if(this.appartient(i) && ensemble.appartient(i)){
				resultat.ajoute(i);
			}
		}
		return(resultat);
	}


	public EnsembleDeChiffre unionAvec(EnsembleDeChiffre ensemble){
		EnsembleDeChiffre resultat = new EnsembleDeChiffre();
		for(int i=0;i<10;i++){
			if(this.appartient(i) || ensemble.appartient(i)){
				resultat.ajoute(i);
			}
		}
		return(resultat);

	}

	public boolean estInclusDans(EnsembleDeChiffre ensemble){
			return instersectionAvec(ensemble).equals(this);
	}

	public void afficher(){
			System.out.print("(");
			for(int i=0;i<10;i++){
				if(this.appartient(i)){
					System.out.print(" "+i);
				}
			}
			System.out.print(")\n");
		}

}

/**** TEST EX1 *****/

public class Test {

	public static void main(String[] args){
		System.out.println("Programme de test pour la classe EnsembleDeChiffre");

		System.out.println("\nTest1: Ensemble vide");
		EnsembleDeChiffre ensemble= new EnsembleDeChiffre();
		ensemble.afficher();


		System.out.println("\nTest2: Ajout de 2,4,7 et 9");
		ensemble.ajoute(2);
		ensemble.ajoute(4);
		ensemble.ajoute(7);
		ensemble.ajoute(9);
		ensemble.afficher();

		System.out.println("\nTest3: Ajout de 5 et suppression de 2");
		ensemble.ajoute(5);
		System.out.print("Aprés ajout de 5 :");
		ensemble.afficher();
		ensemble.retire(2);
		System.out.print("Aprés suppression de 2 :");
		ensemble.afficher();

		System.out.println("\nTest4: Inclusion dans un ensemble allant de 0 à 9");
		EnsembleDeChiffre ensemble1= new EnsembleDeChiffre();
		ensemble1.ajoute(0);
		ensemble1.ajoute(1);
		ensemble1.ajoute(2);
		ensemble1.ajoute(3);
		ensemble1.ajoute(4);
		ensemble1.ajoute(5);
		ensemble1.ajoute(6);
		ensemble1.ajoute(7);
		ensemble1.ajoute(8);
		ensemble1.ajoute(9);
		System.out.print("L'ensemble e1:");
		ensemble.afficher();
		System.out.print("L'ensemble e2:");
		ensemble1.afficher();
		System.out.print("e1 inclus dans e2 ? "+ ensemble.estInclusDans(ensemble1));

		System.out.print("\nOn retire 5 à e2:");
		ensemble1.retire(5);
		ensemble1.afficher();
		System.out.print("e1 inclus dans e2 ? "+ ensemble.estInclusDans(ensemble1));


		System.out.println("\n\nTest5: Union");
		EnsembleDeChiffre ensemble2= new EnsembleDeChiffre();
		ensemble2.ajoute(0);
		ensemble2.ajoute(1);
		ensemble2.ajoute(2);
		ensemble2.ajoute(3);
		System.out.print("L'ensemble e1:");
		ensemble.afficher();
		System.out.print("L'ensemble e2:");
		ensemble2.afficher();
		System.out.print("L'union de e1 et e2 est:");
		(ensemble.unionAvec(ensemble2)).afficher();



	}
}
/****** EX2 ******/

public class Rationnel{
	private int p;
	private int q;

	//constructeur
	public Rationnel(int p, int q){
		this.p = p;
		this.q = q;
		if(q==0){
			//System.out.println("Erreur division par 0!!");
			this.q=1;
		}
	}

	public void afficher(){
		System.out.println(this.p+"/"+this.q);
	}


	public int num(){
		return(this.p);
	}

	public int den(){
		return(this.q);
	}

	public double toDouble(){
		double res = (double)this.p/this.q;
		return(res);
	}

	public Rationnel somme(Rationnel r){
		int n = this.p*r.q+r.p*this.q;
		int d = r.q*this.q;
		Rationnel ratio = new Rationnel(n,d);
		return(ratio);
	}



	public Rationnel difference(Rationnel r){
		int n = this.p*r.q-r.p*this.q;
		int d = r.q*this.q;
		Rationnel ratio = new Rationnel(n,d);
		return(ratio);
	}


	public Rationnel produit(Rationnel r){
		int n = r.p*this.p;
		int d = r.q*this.q;
		Rationnel ratio = new Rationnel(n,d);
		return(ratio);
	}


	public Rationnel quotient(Rationnel r){
		int n = this.p * r.q ;
		int d = this.q * r.p ;
		Rationnel ratio = new Rationnel(n,d);
		return(ratio);
	}


	public int compareTo(Rationnel r){
		if(this.toDouble()<r.toDouble()){
			return(-1);
		}else if(this.toDouble()==r.toDouble()){
			return(0);
		}else{
			return(1);
		}
	}

	public Rationnel abs(){
		Rationnel inverse = new Rationnel(this.p*(-1),this.q);
		if(this.compareTo(inverse)>=0){
			return(this);
		}
		return(inverse);
	}

	public static Rationnel moyenne(Rationnel[] t){
		Rationnel somme = new Rationnel(0,1);//initialisation à 0
		Rationnel nb = new Rationnel(t.length,1);
		for(int i=0; i<t.length;i++){
			somme = somme.somme(t[i]);
		}
		somme = somme.quotient(nb);
		return(somme);
	}

	public static Rationnel[] systeme(int a,int b,int c,int d,int e,int f){
		Rationnel tab[] = new Rationnel[2];
		int res = (a*e)-(b*d);
		if(res == 0){
			tab[0]= null;
			tab[1]= null;
			return(tab);
		}
		int xx = (b*f)-(c*e);
		int xy = res;
		int yx = (c*d)-(a*f);
		int yy = res;
		Rationnel x = new Rationnel(xx,xy);
		Rationnel y = new Rationnel(yx,yy);
		tab[0] = x;
		tab[1] = y;
		return(tab);
	}


	public static Rationnel sqrt(Rationnel r, Rationnel precision){
		Rationnel demi = new Rationnel(1,2);
		Rationnel t0 = r.produit(demi);
		Rationnel t1 = demi.produit(t0.somme(r.quotient(t0)));
		while(t0.difference(t1).abs().compareTo(precision)>0){
			t0 = t1;
			t1 = demi.produit(t0.somme(r.quotient(t0)));
		}
		return(t1);
	}


	public Rationnel puissance(int n){
		Rationnel res = new Rationnel(1,1);
		for(int i=0 ; i<n ; i++){
			res = res.produit(this);
		}
		return res;
	}


	public static Rationnel std(Rationnel[] t, Rationnel precision){
		Rationnel moyenne = Rationnel.moyenne(t);
		Rationnel acc = new Rationnel(0,1);
		Rationnel frac = new Rationnel(1,t.length);
		Rationnel ecart, res;
		for(int i=0; i<t.length;i++){
			ecart = t[i].difference(moyenne);
			acc = acc.somme(ecart.puissance(2));
		}
		res = Rationnel.sqrt(acc.produit(frac), precision);
		return(res);
	}

	public static Rationnel[] trinome(Rationnel[] coeffs, Rationnel precision){
		Rationnel quatre = new Rationnel(4,1);
		Rationnel deux = new Rationnel(2,1);
		Rationnel zero = new Rationnel(0,1);
		Rationnel[] res = new Rationnel[2];


		Rationnel delta = coeffs[1].puissance(2).difference(quatre.produit(coeffs[2].produit(coeffs[0])));
		System.out.println("Delta =" + delta.toDouble());
		if(delta.compareTo(zero)<0){
			res[0] = null;
			res[1] = null;
			return res;
		}
		else if(delta.compareTo(zero) == 0){
			res[0] = (zero.difference(coeffs[1])).quotient(deux.produit(coeffs[2]));
			res[1] = null;
			return res;
		}
		res[0] = ((zero.difference(coeffs[1])).difference(Rationnel.sqrt(delta,precision))).quotient(deux.produit(coeffs[2]));
		res[1] = ((zero.difference(coeffs[1])).somme(Rationnel.sqrt(delta,precision))).quotient(deux.produit(coeffs[2]));
		return res;
	}
}
/********* TEST EX2*********/

public class Test {
	public static void main(String[] args){
		System.out.println("Programme de test pour la classe Rationnel");

		System.out.println("\nTest1: Création de 1/2 et 5/3");

		Rationnel r1 = new Rationnel(1,2);
		Rationnel r2 = new Rationnel(5,3);
		System.out.print("r1 = ");
		r1.afficher();
		System.out.print("r2 = ");
		r2.afficher();

		System.out.println("\nTest2: Division par 0 (5/0)");
		Rationnel rtest = new Rationnel(5,0);
		System.out.print("r = ");
		rtest.afficher();


		System.out.println("\nTest2: toDouble");
		System.out.print("r1 = ");
		r1.afficher();
		System.out.println("valeur approchée de r1 ="+r1.toDouble());
		System.out.print("r2 = ");
		r2.afficher();
		System.out.println("valeur approchée de r1 ="+r2.toDouble());


		System.out.println("\nTest4: Somme");
		System.out.print("somme = ");
		(r1.somme(r2)).afficher();
		System.out.println("valeur approchée de 1/2 + 5/3  ="+(r1.somme(r2)).toDouble());


		System.out.println("\nTest5: difference");
		System.out.print("difference = ");
		(r1.difference(r2)).afficher();
		System.out.println("valeur approchée de 1/2 - 5/3  ="+(r1.difference(r2)).toDouble());


		System.out.println("\nTest6: produit");
		System.out.print("produit = ");
		(r1.produit(r2)).afficher();
		System.out.println("valeur approchée de 1/2 * 5/3  ="+(r1.produit(r2)).toDouble());


		System.out.println("\nTest7: quotient");
		System.out.print("quotient = ");
		(r1.quotient(r2)).afficher();
		System.out.println("valeur approchée de 1/2 / 5/3  ="+(r1.quotient(r2)).toDouble());


		System.out.println("\nTest8: Valeur absolue");
		Rationnel r3 = new Rationnel(-7,2);
		System.out.print("r3 = ");
		r3.afficher();
		System.out.print("valeur absolue de r3=");
		(r3.abs()).afficher();


		System.out.println("\nTest9: Moyenne");
		System.out.println("Creation d'un tableau de Rationnel :");
		Rationnel tab[] = new Rationnel[4];
		tab[0] = new Rationnel(2,2);
		tab[1] = new Rationnel(2,3);
		tab[2] = new Rationnel(3,4);
		tab[3] = new Rationnel(4,5);
		tab[0].afficher();
		tab[1].afficher();
		tab[2].afficher();
		tab[3].afficher();
		System.out.println("Moyenne du tableau de rationnel :");
		Rationnel.moyenne(tab).afficher();


		System.out.println("\nTest10: Systeme");
		System.out.println("Creation d'un systeme avec a = 1 ; b = 12; c = 7; d = 0; e = 9; f = 3");
		Rationnel tab2[] = new Rationnel[2];
		tab2 = Rationnel.systeme(1, 12, 7, 0, 9, 3);
		tab2[0].afficher();
		tab2[1].afficher();


		System.out.println("\nTest11: Racine Carré");
		Rationnel r4 = new Rationnel(9, 1);
		System.out.print("r4 = ");
		r4.afficher();
		Rationnel precision = new Rationnel(1,1);
		System.out.print("precision = ");
		precision.afficher();
		Rationnel racine = Rationnel.sqrt(r4,precision);
		System.out.print("racine de "+r4.toDouble()+" est environ ="+racine.toDouble());


		System.out.println("\n\nTest12: std");
		System.out.println("tableau de Rationnel :");
		tab[0].afficher();
		tab[1].afficher();
		tab[2].afficher();
		tab[3].afficher();
		System.out.print("precision = ");
		precision.afficher();
		System.out.println("écart type de la liste :"+Rationnel.std(tab,precision).toDouble());


		System.out.println("\nTest12: trinôme");
		Rationnel coeff[] = new Rationnel[3];
		coeff[0] = new Rationnel(-5,1);//c
		coeff[1] = new Rationnel(2,1);//b
		coeff[2] = new Rationnel(3,1);//a
		coeff[0].afficher();
		coeff[1].afficher();
		coeff[2].afficher();
		Rationnel res1[] = new Rationnel[2];
		res1=Rationnel.trinome(coeff,precision);

		if(res1[0] == null && res1[1] == null){
			System.out.println("Le trinome n'a pas de solution");
		}
		else if(res1[1] == null){
			System.out.println("Le trinome à une solution : "+res1[0].toDouble());
		}
		else{
			System.out.println("Le trinome à 2 solution : x1="+res1[0].toDouble()+"et x2="+res1[1].toDouble());
		}

	}
}






















	public Iterator selectionne(Selectionneur s){
		Iterator i= base.iterator();
		if(s.estSatisfaitPar((Document)i)){
			return i;
		}
	}

	public List NonEmprunteSelectionneur(){
		Iterator i= base.iterator();
		List l = new LinkedList();
		for(;i.hasNext() == true; i.next()){
			if(i.estDisponible((Document)i)==true){
				l.add(i);
			}
		}
	}
