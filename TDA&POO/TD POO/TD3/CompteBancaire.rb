# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 14:08:36 CET 2018
#

load 'CompteEpargne.rb'
load 'CompteCourant.rb'

class CompteBancaire

#Méthode de Classe pour tester les classes CompteCourant et CompteEpargne
	def CompteBancaire.tests()
		x=CompteCourant.ouvrir(001,"wass Mess",1500,200)
		puts x
		y=CompteEpargne.ouvrir(002,"Ouassim MESSAGIER",100,2400)
		puts y
		puts "Retirer 500 à #{x.titulaire}: ",x.retirer(500),"\n"
		puts "Deposer 1000 à #{x.titulaire}: ",x.deposer(1000),"\n"
		puts "Retirer 2100 à #{x.titulaire}: ",x.retirer(2100),"\n"
		puts "Applique interet à #{y.titulaire}: Solde avant : #{y.solde}"
		y.appliqueInteret()
		puts "Solde après : #{y.solde}"

	end

end # Marqueur de fin de classe

CompteBancaire.tests()
