# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 15:28:25 CET 2018
#

load 'Document.rb'

class Dictionnaire < Document

	private_class_method :new
	
	attr_reader :langue,:nbarticle
	
#Création d'un dictionnaire en utilisant le constructeur de la classe mère et 
#ajout de deux variables supplémentaires langue et nbarticle
#
# @param t [String] Titre du dictionnaire
# @param l [String Langue du dictionnaire
# @param art [String] Nombre d'articles
	def Dictionnaire.nouveau(t,l,art)
		new(t,l,art)
	end

	def initialize(t,l,art)
		super(t)
		@langue=l
		@nbarticle=art
	end

#Surcharge méthode to_s
	def to_s()
		super()+", Langue = #{langue}, Nombre d'Articles=#{nbarticle}"
	end

end # Marqueur de fin de classe
