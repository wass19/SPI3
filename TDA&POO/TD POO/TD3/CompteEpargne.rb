# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 14:06:16 CET 2018
#

load 'Compte.rb'

class CompteEpargne < Compte

#Réutilisation du constructeur de la classe mère afin d'initialiser un compteEpargne qui possède en plus d'un compte normal un interet que l'on peut appliquer
	def CompteEpargne.ouvrir(n,t,s,i)
		new(n,t,s,i)
	end

	def initialize(n,t,s,i)
		super(n,t,s)
		@interet=i
	end

#Permet d'appliquer l'interet
	def appliqueInteret()
		@solde+=((@interet/100)/12)
	end
	
end # Marqueur de fin de classe
