##
# Auteur Pierre Jacoboni
# Version 0.1 : Date : Mon Jul 01 10:17:02 CEST 2013
#

# La demo en Live du cours A TERMINER
require 'gtk2'

class Builder < Gtk::Builder

  def initialize 
    super()
    self.add_from_file(__FILE__.sub(".rb",".glade"))

    self['window1'].set_window_position Gtk::Window::POS_CENTER
    self['window1'].signal_connect('destroy') { Gtk.main_quit }
    self['window1'].show_all
    # Creation d'une variable d'instance par composant glade
    self.objects.each() { |p|
      puts "Création d'une variable d'instance : '@#{p.builder_name}'"
      instance_variable_set("@#{p.builder_name}".intern, self[p.builder_name])
    }
    puts " "
    self.connect_signals(){ |handler| 
      puts "Connection d\'un signal à la méthode : '#{handler}'"
      method(handler) 
    }
    @taux=6.55957

  end

  def on_btnQuitter_clicked
    Gtk.main_quit
  end 

  def on_btnFrancs_clicked
  end 

  def on_btnEuros_clicked
    on_txtFrancs_activate
  end 

  def on_txtEuros_activate
  end

	def on_txtFrancs_activate
    e = @txtFrancs.text.to_f / @taux
    d = Gtk::MessageDialog.new(@window1, Gtk::Dialog::DESTROY_WITH_PARENT,
                             Gtk::MessageDialog::INFO,
                             Gtk::MessageDialog::BUTTONS_CLOSE,
                             "#{@txtFrancs.text.to_f} FRF = #{e} EUR")
    d.run
    d.destroy  
  end
   
end


 Gtk.init
 builder = Builder.new()
 Gtk.main