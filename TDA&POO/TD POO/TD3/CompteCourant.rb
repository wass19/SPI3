# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 14:04:04 CET 2018
#

load 'Compte.rb'

class CompteCourant < Compte

#Réutilisation du constructeur de la classe mère afin d'initialiser un compteCourant qui possède en plus d'un compte normal un seuil de découvert
	def CompteCourant.ouvrir(n,t,s,seuil)
		new(n,t,s,seuil)
	end

	def initialize(n,t,s,seuil)
		super(n,t,s)
		@seuil=seuil
	end

#Redéfinissions de la méthode seuil qui ne fesait que renvoyer 0
	def seuil()
		return -@seuil
	end


end # Marqueur de fin de classe
