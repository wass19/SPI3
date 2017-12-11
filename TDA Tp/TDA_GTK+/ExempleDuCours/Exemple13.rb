begin
  require 'rubygems'
 rescue LoadError
end
require 'gtk2'

include Gtk  # Pour ajouter Gtk à l'espace de nommage, évite de préfixer par GTK::

# Démonstration des possibilités de combinaison des gestionnaires de placements

class MaFenetre
def initialize 
	# -------------------------------- Création de l'interface
	Gtk.init # Ne pas oublier cela sinon ca plante grave
	monApplication = Window.new
	monApplication.set_title("Démonstration des Layouts Manager en GTK")
	monApplication.border_width=5
	# On ne peut pas redimensionner
	monApplication.set_resizable(false)
	# L'application est toujours centrée
	monApplication.set_window_position(Window::POS_CENTER_ALWAYS)
	# Quand l'UI est détruite il faut quitter
	monApplication.signal_connect('destroy') {main_quit}
	

	monApplication.add(laFenetrePrincipale=HBox.new(true,5))
	laFenetrePrincipale.add(gauche=VBox.new(false,5))
	laFenetrePrincipale.add(milieu=VBox.new(false,5))
	laFenetrePrincipale.add(droite=Table.new(4,3,false))
	
	gauche.add(Label.new("Compose le :"))       # Evidement il faudrait des variables pour stocker les widgets
	gauche.add(Entry.new)                       #  Sinon on ne peut plus "leur parler", Ici on ne s'occupe que
	gauche.add(gaucheBoutons=HBox.new(true,10)) #  de l'aspect de l'interface, pas de la logique applicative
	gaucheBoutons.add(Button.new("Compose !"))
	gaucheBoutons.add(Button.new("Efface"))

	milieu.add(Label.new("Sélection Abrégée"))

	# Création d'une zone scollable avec un seul ascenceur
     win=ScrolledWindow.new()
     win.set_policy(POLICY_NEVER,POLICY_ALWAYS)
     
     # Les données sonts stockées dans un TreeStore
     ls=TreeStore.new(String)
     cell=ls.append(nil)
     cell.set_value(0,"un")
     cell=ls.append(nil)
     cell.set_value(0,"Deux")
     cell=ls.append(nil)
     cell.set_value(0,"Trois")
     cell=ls.append(nil)
     cell.set_value(0,"Quatre")
 
 	# Ajout du Treeview à la zone
     win.add(view=TreeView.new(ls))
     milieu.add(win)

     # Ce sont des cellules de texte
     renderer = Gtk::CellRendererText.new

     # Ajoutons la colonne utilis notre renderer
     col = Gtk::TreeViewColumn.new("", renderer, :text => 0)
     # On cache le titre
     view.set_headers_visible(true)
     view.append_column(col)
     
	milieu.add(Button.new("Copie"))
	
	droite.attach(Button.new("1"),0,1,0,1)
	droite.attach(Button.new("2"),1,2,0,1)
	droite.attach(Button.new("3"),2,3,0,1)
	droite.attach(Button.new("4"),0,1,1,2)
	droite.attach(Button.new("5"),1,2,1,2)
	droite.attach(Button.new("6"),2,3,1,2)
	droite.attach(Button.new("7"),0,1,2,3)
	droite.attach(Button.new("8"),1,2,2,3)
	droite.attach(Button.new("9"),2,3,2,3)
	droite.attach(Button.new("*"),0,1,3,4)
	droite.attach(Button.new("0"),1,2,3,4)
	droite.attach(Button.new("#"),2,3,3,4)
	
monApplication.show_all
main	
end


end


MaFenetre.new

