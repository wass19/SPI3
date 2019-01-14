# encoding: UTF-8

##
# Auteur LeNomDeLEtudiant
# Version 0.1 : Date : Sat Nov 10 12:47:25 CET 2018
#

class NR

	private_class_method :new

	attr_accessor :num, :den

	def NR.simplifier(num,den)
		new(num,den)
	end

	def initialize(num,den)
		@num=num
		@den=den
		mem=1
		if(@num>@den)
			min=@den
			reste=@num % @den
			if(reste!=0)
				mem=reste
			else
				mem=min
			end
		else
			min=@num
			reste=@den % @num
			if(reste!=0)
				mem=reste
			else
				mem=min
			end
		end
		while reste!=0 do
			reste=min%reste
			if(reste!=0)
				mem=reste
			end
		end
		@num=@num/mem
		@den=@den/mem
	end

	def ajouter(b)
		tmpnum=self.num
		tmpden=self.den
		tmpnum=self.num*b.den
		tmpden=self.den*b.den
		b.num=b.num*self.den
		b.den=b.den*self.den
		return NR.simplifier(tmpnum+b.num,tmpden)
	end

	def soustraire(b)
		tmpnum=self.num
		tmpden=self.den
		tmpnum=self.num*b.den
		tmpden=self.den*b.den
		b.num=b.num*self.den
		b.den=b.den*self.den
		return NR.simplifier(tmpnum-b.num,tmpden)
	end

	def multiplier(b)
		return NR.simplifier(self.num*b.num,self.den*b.den)
	end

	def diviser(b)
		return NR.simplifier(self.num*b.den,self.den*b.num)
	end

	def to_s
		if(den!=1)
			return "#{num}/#{den}"
		else
			return "#{num}"
		end
	end

end # Marqueur de fin de classe
