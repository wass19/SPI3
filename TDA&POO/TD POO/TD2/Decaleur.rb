# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 13:18:54 CET 2018
#

class Decaleur

	private_class_method :new

	attr_reader :largeur,:tab

#Creer un tableu de largeur donnéé en paramètre et rempli celui-ci avec "-"
#
# @param [Integer] val Largeur du tableau
	def Decaleur.creer(val)
		new(val)
	end

	def initialize(val)
		@tab = Array.new(val)
		@largeur=val
		raz()
	end

#Entre à la fin du tableau l'élement l et retire le premier élement de ce tableau puis le retourne
#
# @param [String] l Lettre à faire entrer
#
# @return tmp [String] Premier élement du tableau
	def decale(l)
		tmp=@tab.delete_at(0)
		@tab<<l
		return tmp
	end

#Remet à zéro le décaleur en le replissant avec des "-"
	def raz()
		@tab.fill("-")
	end

#Redéfinissions de l'affichage
	def to_s()
		return "<<#{tab.join('')}>>"
	end

end # Marqueur de fin de classe
d = Decaleur.creer(5)
c=Array.new(5)<<5
puts d
puts "Lettre retirer : #{d.decale('a')}"
puts d
puts "Lettre retirer : #{d.decale('b')}"
puts d
puts "Lettre retirer : #{d.decale('c')}"
puts d
puts "Lettre retirer : #{d.decale('d')}"
puts d
puts "Lettre retirer : #{d.decale('e')}"
puts d
puts "Lettre retirer : #{d.decale('f')}"
puts d
puts "Largeur : #{d.largeur}"