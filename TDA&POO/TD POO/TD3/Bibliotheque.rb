# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 15:30:14 CET 2018
#

load 'Dictionnaire.rb'
load 'Livre.rb'

class Bibliotheque

#Méthode qui teste les Classes Livre et Dictionnaire
	def Bibliotheque.tests()
		l=Livre.nouveau("yy","samed",65)
		puts l
		d=Dictionnaire.nouveau("Dico Java","Java",666)
		puts d
	end

end # Marqueur de fin de classe

Bibliotheque.tests