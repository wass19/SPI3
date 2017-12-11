begin
  require 'rubygems'
 rescue LoadError
end
require 'gtk2'
Gtk.init

def onDestroy
	puts "Fin de l'application"
	Gtk.main_quit
end

def onEvt(label,message)
	puts message
	label.set_text(message)
end

monApp = Gtk::Window.new

# Titre de la fenêtre
monApp.set_title("Exemple 12 - Un champ de saisie")
# Taille de la fenêtre
monApp.set_default_size(400,100)
# Réglage de la bordure
monApp.border_width=5
# On ne peut pas redimensionner
monApp.set_resizable(false)
# L'application est toujours centrée
monApp.set_window_position(Gtk::Window::POS_CENTER_ALWAYS)

# Création du Layout
frame=Gtk::VBox.new(true)
monApp.add(frame)

# Création des Boutons
monBout=Gtk::Button.new(Gtk::Stock::QUIT)
monBout1=Gtk::Button.new("Pas Editable")

maSaisie=Gtk::Entry.new()

monBout.signal_connect('clicked') {Gtk.main_quit}
monBout1.signal_connect('clicked') {if maSaisie.editable?
								 maSaisie.set_editable(false)
								 monBout1.set_label("Editable")
							 else 
							      maSaisie.set_editable(true)
							      monBout1.set_label("Pas Editable")
							 end
							}

# On ajoute à la Table les widgets
frame.add(maSaisie)
frame.add(monBout1)
frame.add(monBout)

monApp.show_all
# Quand la fenêtre est détruite il faut quitter
monApp.signal_connect('destroy') {onDestroy}
Gtk.main
