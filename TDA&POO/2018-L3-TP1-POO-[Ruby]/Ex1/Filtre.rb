# encoding: UTF-8

##
# Auteur Samed OKTAY
# Version 0.1 : Date : Wed Nov 07 10:14:03 CET 2018
#

class Filtre

	private_class_method :new

	attr_reader :valeur

#Création Filtre avec une valeur
#
# @param valeur [Integer] Valeur du filtre
	def Filtre.initialiseFiltre(val)
		new(val)
	end

	def initialize(val)
		@valeur=val
	end

#Compare n à la valeur du filtre
#
# @param n [Integer] Valeur comparée au filtre
#
# @return true si n est un nombre premier
#	  false si n n'est pas un nombre premier
	def compareToi(n)
		if(n%@valeur!=0)
			return true
		else
			return false
		end
	end
	
end # Marqueur de fin de classe