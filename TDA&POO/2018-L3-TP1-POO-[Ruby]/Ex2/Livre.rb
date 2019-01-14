# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Wed Nov 07 11:47:19 CET 2018
#

class Livre

	private_class_method :new

	attr_reader :numero,:titre,:auteur,:nbpages,:etat
	attr_accessor :dispo

#Variable de la classe Livre qui représente le numéro d'un livre et qui 
#s'incrémente à chaque initialisation d'un livre
	@@num=0

#Création d'un livre avec 3 paramètres : 
#
# @param t [String] Titre du Livre
#
# @param aut [String] Auteur du Livre
#
# @param page [Integer] Nombre de pages
	def Livre.ranger(t,aut,page)
		new(t,aut,page)
	end

	def initialize(t,aut,page)
		@titre=t
		@numero=@@num
		@@num+=1
		@auteur=aut
		@nbpages=page
		@etat='ok'
		@dispo=true
	end

#Redéfinission de la méthode to_s afin d'obtenir un affichage correspondant aux 
#informations à propos du livre
	def to_s
		return " Livre : Numéro = #{@numero}, Titre = '#{@titre}', Auteur = #{@auteur}, Nombre de pages = #{@nbpages},\n\t  Etat = #{@etat}, Disponibilité = #{@dispo}\n"
	end	
end # Marqueur de fin de classe
