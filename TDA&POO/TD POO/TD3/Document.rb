# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 14:57:42 CET 2018
#

#Classe abstraite impossible de creer un Document
class Document

	private_class_method :new
	
	attr_reader :numero,:titre
	
	@@nb=0

#Création d'un document défini par un titre
#
# @param titre [String] Titre du Document
	def initialize(titre)
		@titre=titre
		@numero=@@nb
		@@nb+=1
	end

	def to_s
		return "#{self.class} : Numero = #{self.numero}, Titre = #{self.titre}"
	end

end # Marqueur de fin de classe