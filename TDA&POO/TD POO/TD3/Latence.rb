# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 18:17:37 CET 2018
#

load 'Afficheur.rb'

class Latence < Afficheur

	private_class_method :new
	
	attr_reader :latence
	attr_accessor :index

#Créér un afficheur avec une latence
# 
# @param largeur [Integer] Largeur de l'afficheur
# @param lat [Integer] Latence entre chaque message
	def Latence.creer(largeur,lat)
		new(largeur,lat)
	end

	def initialize(largeur,lat)
		super(largeur)
		@latence=lat
		@cmpt=0
	end

#Surcharge de la fonction top pour y ajouter la latence
	def top()
		if(self.index==self.message.length && @cmpt < @latence)
			self.decaleur.decale(' ')
			@cmpt+=1
		elsif (@cmpt==@latence)
			@cmpt=0
			self.index=self.index+1
		else
			super()
		end		
	end

end # Marqueur de fin de classe