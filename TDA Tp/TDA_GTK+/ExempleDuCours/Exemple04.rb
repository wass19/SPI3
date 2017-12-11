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
# On peut redimensionner
monApp.set_resizable(true)
# L'application est toujours centrée
monApp.set_window_position(Gtk::Window::POS_CENTER_ALWAYS)

# Création du Label 
texte= "<span font_desc=\"Courier New bold 10\">Courier New 10 Gras</span>\n"
texte += "<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Times New Roman 12 Italique</span>\n"
texte += "<span font_desc=\"Comic Sans MS 16\" foreground=\"#0000FF\">Comic Sans MS 16</span>\n"
texte += "<span font_desc=\"Verdana 20\"><u>Verdana 20 Souligne</u></span>"

monLabel=Gtk::Label.new()
monLabel.set_markup(texte)
monLabel.set_justify(Gtk::JUSTIFY_CENTER)
#
#
monApp.add(monLabel)

monApp.show_all
# Quand la fenêtre est détruite il faut quitter
monApp.signal_connect('destroy') {onDestroy}
Gtk.main

