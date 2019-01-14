# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Sat Nov 10 14:30:10 CET 2018
#

load 'Cellule.rb'

class TdaFileCirc

	private_class_method :new

	attr_accessor :premier, :dernier
	attr_reader :nb

#Création d'une file vide
	def TdaFileCirc.creer
		new()
	end

	def initialize
		@nb=0
		@premier=nil
		@dernier=nil
	end

#Ajoute à la file la cellule v
#
# @param v [Cellule] Cellule qu'on ajoute à la file
	def	entrer(v)
		if(@nb==0)
			@premier=v
			@dernier=v
			@premier.suivant=@dernier
		elsif (@nb==1)
			@dernier=v
			@premier.suivant=@dernier
		else
			@dernier.suivant=v
			@dernier=v
		end
		@nb+=1
	end

#Sortie du premier élement de la file
	def	sortir()
		if(@nb==0)
			puts "File Vide impossible"
		elsif (@nb==1)
			@dernier=nil
			@premier.suivant=nil
			@nb-=1
		elsif (@nb==2)
			@premier=@dernier
			@premier.suivant=@dernier
			@dernier.suivant=@premier
			@nb-=1
		else
			@premier=@premier.suivant
			@nb-=1
		end
		
	end

#Retourne vrai si la file est vide, faux si non
	def estVide?
		if(@nb==0)
			return true
		end
		return false
	end

#Redéfinission de l'affichage pour l'adapter à la file
	def to_s
		if(@nb==0)
			return "File Vide"
		else
			pos=@premier
			chaine="#{@premier.val}"
			if(@nb==1)
				return chaine
			else
				pos=@premier.suivant
				chaine += " #{pos.val}"
				while (pos != @dernier) do
					pos=pos.suivant
					chaine += " #{pos.val}"
				end
				return chaine
			end
		end
	end
	
end # Marqueur de fin de classe

puts a=Cellule.creer(5)
puts b=Cellule.creer(8)
puts c=Cellule.creer(13)
f=TdaFileCirc.creer
puts "File vide : #{f.estVide?}"
puts "Affichage File : #{f}"
puts "Ajout : #{a}  "
f.entrer(a)
puts "Affichage File : #{f}"
puts "File vide : #{f.estVide?}"
puts "Ajout : #{b} "
f.entrer(b)
puts "Affichage File : #{f}"
puts "Ajout : #{c} "
f.entrer(c)
puts "Affichage File : #{f}"
puts "Sortie :"
f.sortir()
puts "Affichage File : #{f}"
puts "Sortie :"
f.sortir()
puts "Affichage File : #{f}"
puts "Sortie :"
f.sortir()
puts "Affichage File : #{f}"