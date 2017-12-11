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
monApp.set_title("Exemple 11 - Evènements des Boutons")
# Taille de la fenêtre
monApp.set_default_size(400,100)
# Réglage de la bordure
monApp.border_width=5
# On ne peut pas redimensionner
monApp.set_resizable(false)
# L'application est toujours centrée
monApp.set_window_position(Gtk::Window::POS_CENTER_ALWAYS)

# Création du Layout
frame=Gtk::VBox.new(false)
monApp.add(frame)

# Création des Boutons
monBout=Gtk::Button.new("Test")
monBout1=Gtk::Button.new(Gtk::Stock::YES)

monBout1.signal_connect('clicked') {if monBout1.label=="gtk-yes"
								monBout1.set_label(Gtk::Stock::NO)
							else
							 	monBout1.set_label(Gtk::Stock::YES)
							end
							}

monLabel=Gtk::Label.new("Que ce passe t-il ?")
frame.add(monLabel)
frame.add(mycombo=Gtk::Combo.new)
mycombo.popdown_strings=(["ligne1","ligne 2","ligne 3"])
monBout.signal_connect('activate') {onEvt(monLabel,"Evenement ACTIVATE")}
monBout.signal_connect('clicked')  {onEvt(monLabel,"Evenement  CLICKED")}
monBout.signal_connect('enter')    {onEvt(monLabel,"Evenement    ENTER")}
monBout.signal_connect('leave')    {onEvt(monLabel,"Evenement    LEAVE")}
monBout.signal_connect('pressed')  {onEvt(monLabel,"Evenement  PRESSED")}
monBout.signal_connect('released') {onEvt(monLabel,"Evenement RELEASED")}

# On ajoute a la Table les widgets
frame.add(monBout)
frame.add(monBout1)

monApp.show_all
# Quand la fenêtre est détruite il faut quitter
monApp.signal_connect('destroy') {onDestroy}
Gtk.main
