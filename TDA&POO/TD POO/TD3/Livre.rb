# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 15:04:43 CET 2018
#
load 'Document.rb'

class Livre < Document

	private_class_method :new
	
	attr_reader :auteur,:nbpage

#Création d'un livre en utilisant le constructeur de la classe mère et 
#ajout de deux variables supplémentaires auteur et nbpage
#
# @param t [String] Titre du livre
# @param aut [String Auteur du livre
# @param page [String] Nombre de pages
	def Livre.nouveau(t,aut,page)
		new(t,aut,page)
	end

	def initialize(t,aut,page)
		super(t)
		@auteur=aut
		@nbpage=page
	end

#Surcharge méthode to_s
	def to_s()
		super()+", Auteur = #{auteur}, Nombre de pages=#{nbpage}"
	end
	
end # Marqueur de fin de classe

