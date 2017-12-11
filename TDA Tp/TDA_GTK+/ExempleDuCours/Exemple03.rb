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

monApp = Gtk::Window.new

# Titre de la fenêtre
monApp.set_title("Ma Fenêtre en GTK")
# Taille de la fenêtre
monApp.set_default_size(300,100)
# Réglage de la bordure
monApp.border_width=5
# On ne peut pas redimensionner
monApp.set_resizable(false)
# L'application est toujours centrée
monApp.set_window_position(Gtk::Window::POS_CENTER_ALWAYS)

# Création du Label 
monLabel=Gtk::Label.new("Hello World")
monApp.add(monLabel)

monApp.show_all
# Quand la fenêtre est détruite il faut quitter
monApp.signal_connect('destroy') {onDestroy}
Gtk.main

