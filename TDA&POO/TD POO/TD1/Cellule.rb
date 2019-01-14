# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Sat Nov 10 14:27:40 CET 2018
#

class Cellule

	private_class_method :new

	attr_accessor :val, :suivant

#Création d'une cellule qui contient une valeur v et par default aucune cellule suivante
#
# @param v [Integer] Valeur de la cellule
	def Cellule.creer(v)
		new(v)
	end

	def initialize(v)
		@val=v
		@suivant=nil
	end

#Redéfinission de l'affichage pour afficher la valeur de la cellule
	def to_s
		return "#{val}"
	end

end # Marqueur de fin de classe

