# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Thu Nov 22 18:02:04 CET 2018
#

load 'Decaleur.rb'

class Afficheur

	private_class_method :new
	
	attr_reader :index,:decaleur,:message,:index

#Création Afficheur avec en paramètre la largeur
#
# @param largeur [Integer] Largeur de l'afficheur
	def Afficheur.creer(largeur)
		new(largeur)
	end

	def initialize(largeur)
		@decaleur=Decaleur.creer(largeur)
	end

#Initialisation du message à afficher
#
# @param msg [Array] Message à afficher
	def setMessage(msg)
		@message=msg
		@index=0
	end

#Permet de décaler une seule fois le message vers la gauche
	def top()
		if(index<@message.length)
			@decaleur.decale(@message[index])
			@index+=1
		else
			@index=0
			@decaleur.decale(@message[index])
			@index+=1
		end
	end

#Redéfinissions de l'affichage
	def to_s
		return "#{self.decaleur}"
	end

end # Marqueur de fin de classe