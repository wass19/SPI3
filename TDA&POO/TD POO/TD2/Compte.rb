# encoding: UTF-8

##
# Auteur
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
		if(@solde-s>self.seuil())
			@solde-=s
		else
			raise "Fond insuffisant"
		end
	end

#Retourne le seuil du compte(0 pour ce TD)
	def seuil()
		return 0
	end

# Affiche le numéro, le titulaire et le solde du compte
	def to_s()
		return "Numero : #{@numero} Titulaire : #{@titulaire} Solde : #{@solde} Seuil : #{self.seuil()}\n"
	end
end # Marqueur de fin de classe


x=Compte.compteOuvrir(001,"wass mess",1500)
print x
print "Retirer 500 : ",x.retirer(500),"\n"
print "Deposer 1000 : ",x.deposer(1000),"\n"
print "Retirer 5000 : ",x.retirer(5000),"\n"
