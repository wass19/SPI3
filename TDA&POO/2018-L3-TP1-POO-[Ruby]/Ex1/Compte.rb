# encoding: UTF-8

##
# Auteur Samed OKTAY
# Version 0.1 : Date : Wed Nov 07 08:57:47 CET 2018
#

class Compte
	#Création Méthodes d'accès
	private_class_method :new


	attr_accessor :solde   
	attr_reader :titulaire 
	attr_reader :numero   

# Permet d'ouvrir un compte avec 3 paramètres:
#
# @param numero [Integer] Numero du compte
#
# @param titulaire [String] Titulaire du compte
#
# @param solde [Integer] Solde du compte
	def Compte.compteOuvrir(n,t,s)	
		new(n,t,s)
	end

	def initialize(n,t,s)
		@numero=n
		@titulaire=t
		@solde=s
	end

# Ajoute au @solde la somme s
# @param s [Integer] Somme a ajouter
	def deposer(s)
		@solde+=s
	end

# Retire au @solde la somme s
# @param s [Integer] Somme a retirer
	def retirer(s)
		@solde-=s
	end

# Affiche le numéro, le titulaire et le solde du compte
	def afficheToi()
		print "Numero : #{@numero} Titulaire : #{@titulaire} Solde : #{@solde}\n"
	end
end # Marqueur de fin de classe


x=Compte.compteOuvrir(001,"Samed OKTAY",1500)
x.afficheToi()
print "Retirer 500 : ",x.retirer(500),"\n"
print "Deposer 1000 : ",x.deposer(1000),"\n"