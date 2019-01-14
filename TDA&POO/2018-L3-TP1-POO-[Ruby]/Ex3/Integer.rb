# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Sat Nov 10 11:57:54 CET 2018
#

load 'NR.rb'

class Integer

	def listeDesDiviseurs
		listediv=[]
		1.upto(self) do |x|
			if(self%x==0)
				listediv << x
			end
		end
		return listediv
	end

	def listeDesNonsDiviseurs
		listenondiv=[]
		1.upto(self) do |x|
			if(self % x!=0)
				listenondiv << x
			end
		end
		return listenondiv
	end

	def rapDivNonDiv
		sommediv=0
		sommenondiv=0
		self.listeDesDiviseurs.each do |x|
			sommediv+=x
		end
		self.listeDesNonsDiviseurs.each do |y|
			sommenondiv+=y
		end
		return NR.simplifier(sommediv,sommenondiv)
	end

end # Marqueur de fin de classe

puts "\n\tTest de la classe Integer"
puts "\t=========================="
print "Les Diviseurs de 6       = "
p 6.listeDesDiviseurs
print "Les Nons Diviseurs de 6  = "
p 6.listeDesNonsDiviseurs
print "Le rapport des deux      = "
puts 6.rapDivNonDiv

puts "\n\tTest de la classe NR"
puts "\t====================="
a=NR.simplifier(6,9)
b=NR.simplifier(5,3)
c=NR.simplifier(15,18)
d=NR.simplifier(5,20)
i=NR.simplifier(12,2)
puts "(#{a}) + (#{b}) = #{e=a.ajouter(b)}"
puts "(#{e}) - (#{c}) = #{f=e.soustraire(c)}"
puts "(#{f}) * (#{d}) = #{g=f.multiplier(d)}"
puts "(#{e}) / (#{e}) = #{h=e.diviser(e)}"
puts "i = 12/2 = #{i}"
