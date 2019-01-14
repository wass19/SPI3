# encoding: UTF-8

##
# Auteur Samed OKTAY
# Version 0.1 : Date : Wed Nov 07 10:00:43 CET 2018
#

load 'Filtre.rb'

class Generateur

	private_class_method :new

	attr_reader :tab

#Création Génerateur qui comporte le premier filtre @filtre de valeur 2, 
#un tableau @tab qui comporte la liste de tout les filtres et 
#un marqueur @nonpremier pour savoir si un nombre est premier ou non
	def Generateur.generateurCreer()
		new()
	end

	def initialize()
		@filtre=Filtre.initialiseFiltre(2)
		@tab=[@filtre]
		@nonpremier=0
	end

#Ajoute au tableau @tab les valeurs allant de 3 à taille si'ils sont premiers
#
# @param taille [Integer] taille du génerateur
	def estPremier(taille)
		3.upto(taille) do |x|
			@nonpremier=0
			@tab.each do |object|
				if (object.compareToi(x)==false)
					@nonpremier=1
				end
			end
			if(@nonpremier==0)
				tab<<Filtre.initialiseFiltre(x)
			end
		end
	end

#Affichage du tableau qui comporte les nombres premiers
	def afficheToi
		@tab.each do |object|
			print object.valeur," "
		end
	end
	
end # Marqueur de fin de classe

