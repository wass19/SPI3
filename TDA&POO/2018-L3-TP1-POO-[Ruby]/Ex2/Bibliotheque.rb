# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Sat Nov 10 11:35:23 CET 2018
#

load 'Livre.rb'

class Bibliotheque

	private_class_method :new

	attr_reader :biblio

#Création d'une Bibliotheque (tableau vide)
	def Bibliotheque.creer()
		new()
	end

	def initialize()
		@biblio=[]
	end

#Ajoute au tableau @biblio le livre L
#
# @param l [Livre] Livre à ajouter à la bibliothèque
	def ajouterLivre(l)
		@biblio<<l
	end

#Affiche chaque livre contenu par la Bibliothèque
	def afficherBiblio
		@biblio.each do |object|
			print object
		end
	end

end # Marqueur de fin de classe

l=Livre.ranger("Ruby","Jacob",5)
l2=Livre.ranger("C","Jacoboni",2225)
b=Bibliotheque.creer()
print "Ajout premier livre Affichage biblio :\n"
b.ajouterLivre(l)
b.afficherBiblio
print "Ajout second livre Affichage biblio :\n"
b.ajouterLivre(l2)
b.afficherBiblio