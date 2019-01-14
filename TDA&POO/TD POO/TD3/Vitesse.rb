# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 18:32:31 CET 2018
#

load 'Latence.rb'

class Vitesse < Latence

	private_class_method :new
	
	attr_reader :vitesse

#Créér un afficheur avec une latence et une vitesse
# 
# @param largeur [Integer] Largeur de l'afficheur
# @param lat [Integer] Latence entre chaque message
# @param v [Integer] Vitesse du décallage

	def Vitesse.creer(largeur,lat,v)
		new(largeur,lat,v)
	end

	def initialize(largeur,lat,v)
		super(largeur,lat)
		@vitesse=v
	end

#Surcharge méthode top
	def top()
		1.upto(@vitesse) do
			super()
		end		
	end

end # Marqueur de fin de classe
leMessage=['D','e','s','p','r','e','s']

a=Vitesse.creer(10,2,3)
a.setMessage(leMessage)
1.upto(12) do
	a.top()
	puts a
end