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
monApp.set_title("Exemple 10 - Construire des Boutons")
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
monBout1=Gtk::Button.new()
monBout2=Gtk::Button.new("Bouton2")
monBout3=Gtk::Button.new("_Bouton3",true)
monBout4=Gtk::Button.new("_Bouton4",false)
monBout5=Gtk::Button.new(Gtk::Stock::CONVERT)

# On ajoute à la Table les widgets
frame.add(monBout1)
frame.add(monBout2)
frame.add(monBout3)
frame.add(monBout4)
frame.add(monBout5)

monApp.show_all
# Quand la fenêtre est détruite il faut quitter
monApp.signal_connect('destroy') {onDestroy}
Gtk.main
