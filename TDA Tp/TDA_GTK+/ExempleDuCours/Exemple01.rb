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
monApp.show

# Quand la fenètre est détruite il faut quitter
monApp.signal_connect('destroy') {onDestroy}
Gtk.main
