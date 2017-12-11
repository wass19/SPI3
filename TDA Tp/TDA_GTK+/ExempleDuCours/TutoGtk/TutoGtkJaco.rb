# ***************************************************************************
# * Copyright (C) 2005 by Pierre Jacoboni                                   *
# *   Pierre.Jacoboni@univ-lemans.fr                                        *
# ***************************************************************************

# ***************************************************************************
# * Cet exemple a pour but de montrer les fonctionalités offertes par le    *
# *  couple Ruby/Gtk. Chacun des onglets de cette interface est défini dans *
# *  une frame de nom maFrameX ou X représente le numéro de l'onglet.       *
# * Le but est de comprendre des mécanismes simples de Ruby/Gtk. Le code    *
# *  n'est donc pas optimisé, cela est volontaire pour que chaque Onglet    *
# *  dispose de tout le nécessaire et puisse être repris individuellement   *
# * Cet exemple ne reprends pas l'intégralité des concepts de Ruby/Gtk      *
# *  et nécessite donc une connaissance préalable des bases de ces outils   * 
# ***************************************************************************
require 'gtk2'

# On inclu le module Gtk, cela évite de préfixer les classes du peu élégant Gtk::
include Gtk

Gtk.init

# Deux constantes pour représenter la font et la taille des textes explicatifs 
#  des onglets
TAILLE=12
FONT="\"Times New Roman #{TAILLE}\""

monApplication = Window.new()
monApplication.set_title("Ceci est ma fenêtre de test")
# L'application est toujours centree
monApplication.set_window_position(Window::POS_CENTER_ALWAYS)
monApplication.set_default_size(400,300)

# Une VBox pour mettre les composants de la fenetre dedans
maVBoxAppli= VBox.new(false, 5)

# -------------------------------------------------------------------
# Une Première frame pour y mettre des Trucs dedans
#   Deux boutons horizontaux et Trois boutons verticaux
# -------------------------------------------------------------------
# Quand on est en ISO-8859-1 il faut convertir en utf8
# Pour Gtk
#etexte=GLib.locale_to_utf8("Ma éàFrame1 coucou")
etexte="Ma Frame1 coucou"

puts "Charset =" + GLib.charset

maFrame1 = Frame.new(etexte)
  # Une VBox pour la frame 1
  maVBoxF1=VBox.new(false,10)
  
  # Le texte d'explication
  texteF1= "<span font_desc=#{FONT} foreground=\"#0000FF\">" +
   "Positionnement des Widgets illustre avec des boutons : " +
   "<b>Les HBox</b> et les <b>VBox</b>" +
   "</span>"

  leTexteF1=Label.new()
  leTexteF1.set_markup(texteF1)
  leTexteF1.justify=Gtk::JUSTIFY_CENTER
  leTexteF1.wrap=true
  
  # Une HBox pour les boutons
  maHBoxF1= HBox.new(false, 25)
  
  # UneHBox pour les boutons Horizontaux
  maHBoxBtnF1 = HBox.new(false, 5)
  maHBoxBtnF1.add(Button.new("Bouton un 1"))
  maHBoxBtnF1.add(Button.new("Bouton deux 2"))
  maHBoxF1.add(maHBoxBtnF1)

  # Une VBox pour la Boutons verticaux
  maVBoxBtnF1 = VBox.new(false, 5)
  maVBoxBtnF1.add(Button.new("Button one 1"))
  maVBoxBtnF1.add(Button.new("Button two 2"))
  maVBoxBtnF1.add(Button.new("Button three 3"))
  maHBoxF1.add(maVBoxBtnF1)
  
maVBoxF1.add(leTexteF1)

maVBoxF1.add(maHBoxF1)
maFrame1.add(maVBoxF1)

# ======================= FIN DE LA FRAME 1 =========================

# -------------------------------------------------------------------
# Une seconde Frame pour tester les modifications dans une Box
# -------------------------------------------------------------------
# La Vbox de gauche contient un certain nombre de Boutons, la fVbox de 
#  droitre contient un bouton permettant d'effacer les boutons de rang
#  pair, un bouton pour effacer les boutons de rang impairs et un 
#  boutons pour rétablir la vbox.

maFrame2 = Frame.new("Ma Frame 2") 
  # Une VBox pour la Frame 2
  maVBoxF2 = VBox.new(false, 10)
# Le texte d'explication
  texteF2= "<span font_desc=#{FONT} foreground=\"#0000FF\" >" +
   "Tester les modifications : <b>ajout</b> et <b>suppression</b> dans les <b>Box</b>. " +
   "Utiliser les boutons pour effacer les boutons de rang pair ou impair dans la VBox" +
"</span>"

  leTexteF2=Label.new()
  leTexteF2.set_markup(texteF2)

  leTexteF2.justify=Gtk::JUSTIFY_CENTER
  leTexteF2.wrap=true

# Une HBox pour la Frame 2
  maHBoxF2 = HBox.new(false, 5)
  maVBoxWidgF2 = VBox.new(false, 5) # Ce qu'on veut détruire
  maVBoxBtnF2 = VBox.new(false, 5)   # Pour les Boutons

  effBtnPairF2=Button.new("Effacer les rangs pairs")
  effBtnImpairF2=Button.new("Effacer les rangs impairs")
  remettreBtnF2=Button.new("Restaurer les Boutons")
  maVBoxBtnF2.add(effBtnPairF2)
  maVBoxBtnF2.add(remettreBtnF2)
  maVBoxBtnF2.add(effBtnImpairF2)
  0.upto(5) do |i|
    maVBoxWidgF2.add(Button.new("#{i}-Bouton "+"ABCDEF"[i].chr))
  end
  
  maHBoxF2.add(maVBoxWidgF2)
  maHBoxF2.add(maVBoxBtnF2)
  maVBoxF2.add(leTexteF2)
  maVBoxF2.add(maHBoxF2)
  maFrame2.add(maVBoxF2)
  
  # ------------------------- ----------------
  #      Les signaux pour cette frame
  # -----------------------------------------
  # Le bouton qui efface les widgets de rang pair dans la Vbox de gauche
  effBtnPairF2.signal_connect('clicked') {
    i=0
    compteur=0
    maVBoxWidgF2.each {|enf|
      if (i%2 == 0) 
        maVBoxWidgF2.remove(enf)
      else
        enf.label="#{compteur}-"+enf.label
        compteur+=1
      end
      i+=1
    }
  }
  # Le bouton qui restaure les widgets dans la Vbox de gauche
  remettreBtnF2.signal_connect('clicked') {
    maVBoxWidgF2.each {|enf|
      maVBoxWidgF2.remove(enf)
    }
    0.upto(5) do |i,btn|
      maVBoxWidgF2.add(Button.new("#{i}-Bouton "+"ABCDEF"[i].chr))
    end
     # c'est pas les memes boutons il faus les afficher.
    maVBoxWidgF2.show_all
  }

# Le bouton qui efface les widgets de rang impair dans la Vbox de gauche
  effBtnImpairF2.signal_connect('clicked') {
    i=0
    compteur=0
    maVBoxWidgF2.each {|enf|
      if (i%2 != 0) 
        maVBoxWidgF2.remove(enf)
      else
        enf.label="#{compteur}-"+enf.label
        compteur+=1
      end
      i+=1
    }
  }
  
# ======================= FIN DE LA FRAME 2 =========================

# -------------------------------------------------------------------
# Une troisième Frame pour tester les listes et les treeview
#  Possibilité d'éditer le Prénom
#   Ou on découvre l'association ListStore et TreeView
#    et les CellRendererText
# -------------------------------------------------------------------
maFrame3 = Frame.new("Ma Frame 3 pour tester les listes")
  # Une VBox pour la Frame 3
  maVBoxF3 = VBox.new(false, 5)

# Une structure de liste pour stocker les données
  listStoreF3 = ListStore.new(String, String, Integer)
  # ajouter un élément à la liste
  element = listStoreF3.append()
    element[0] = "Robert" ; element[1] = "Schmurff";
  # un Autre
  element = listStoreF3.append()
    element[0] = "Henri" ; element[1] = "Schmurff" ; element[2] = 1960
  # encore un Autre
  element = listStoreF3.append()
    element[0] = "Ludovic" ; element[1] = "Schmurff" ; element[2] = 1994
  # encore un Autre
  element = listStoreF3.append()
    element[0] = "Victor" ; element[1] = "Schmurff" ; element[2] = 1999
    
  # Un TreeView pour visualiser les données de la liste
  viewListeF3 = TreeView.new(listStoreF3)
    viewListeF3.selection.mode = SELECTION_SINGLE
      # Les 'renderer' permettent de préciser comment afficher les données
      renderer = CellRendererText.new
      # On rend éditable ce rendu pour permettre de modifier
      renderer.set_editable(true)
        # Ajout d'uhe colonne utilisant ce rendu
        col = TreeViewColumn.new("Prenom", renderer, :text => 0)
      # On sauvegarde la modification dans la listStore.  
      renderer.signal_connect('edited') { |cell,ligne,nouvelle|
        p renderer
        listStoreF3.get_iter(ligne).set_value(0,nouvelle)
      }
    
      viewListeF3.append_column(col)
      # Un autre rendu modifiant la fonte
      renderer = CellRendererText.new
        # On utilise Pango pour obtenir le gras
        renderer.weight = Pango::FontDescription::WEIGHT_BOLD
        # Ajout d'une colonne utilisant ce rendu
        col = TreeViewColumn.new("Nom", renderer, :text => 1)
        viewListeF3.append_column(col)
      # Un dernier rendu modifiant la couleur
        renderer = CellRendererText.new
        renderer.foreground = "red"
        # Ajout d'une colonne utilisant ce rendu
        col = TreeViewColumn.new("Age", renderer)
        viewListeF3.append_column(col)
        
	  # Création d'une formule de cellule pour calculer l'age.
        # Dans la troisième colonne on ne veut pas afficher l'année (fournie)
        # mais l'age (calculé)
        col.set_cell_data_func(renderer) do |col, renderer, model, iter|
        anneeCourante = 2005 
        anneeNaissance = iter[2]
        if (anneeNaissance <= anneeCourante) && (anneeNaissance > 0)
          renderer.text = sprintf("%i ans", anneeCourante - anneeNaissance)
          # Utiliser la couleur par défaut (noir) si l'age est connu
          renderer.foreground_set = false
        else
          renderer.text = "age inconnu"
          # Utiliser la couleur du renderer (rouge) si l'age est inconnu
          renderer.foreground_set = true
        end
      end

  # Un Label pour afficher la sélection courante
  maSelectionF3 = Label.new()
  
  maVBoxF3.add(viewListeF3)
  maVBoxF3.add(maSelectionF3)
  maFrame3.add(maVBoxF3)

  # -----------------------------------------
  #      Les signaux pour cette frame
  # -----------------------------------------
  
  # Gestion du signal de modification du curseur dans la liste
  # le label est modifié pour indiquer l'élément selectionné
  viewListeF3.signal_connect("cursor-changed") { |v|
      maSelectionF3.text = v.selection.selected.get_value(0)
      maSelectionF3.text += " / " + v.selection.selected.get_value(1)
      maSelectionF3.text += " / " + String(v.selection.selected.get_value(2))
  }

# ======================= FIN DE LA FRAME 3 =========================
  
  
# -------------------------------------------------------------------
# Une Quatrième Frame pour tester les arbres et les treeview
#   Ou on découvre l'association TreeStore et TreeView
#    et toujours les CellRendererText
# -------------------------------------------------------------------
maFrame4 = Frame.new("Ma Frame 4")
  # Une VBox pour la Frame 4
  maVBoxF4 = VBox.new(false, 5)
  # Le texte d'explication
  texteF4= "<span font_desc=#{FONT} foreground=\"#0000FF\">" +
   "Tester les Arbres : " +
   "Ou on decouvre l'association <b>TreeStore</b> et <b>TreeView</b> et toujours" +
   " les <b>CellRendererText</b></span>"

  leTexteF4=Label.new()
  leTexteF4.set_markup(texteF4)
  leTexteF4.justify=Gtk::JUSTIFY_CENTER
  leTexteF4.wrap=true
  
  maVBoxF4.add(leTexteF4)
  # Une structure d'arbre pour stocker les données
  treeStoreF4 = TreeStore.new(String, String, Integer)
  # La racine de l'arbre
  parent = treeStoreF4.append(nil)
  parent[0] = "Robert"
  parent[1] = "Schmurff"
  # Ajout d'un premier fils
  fils = treeStoreF4.append(parent)
    fils[0] = "Henri" ; fils[1] = "Schmurff" ; fils[2] = 1960
  # Ajout de qqes enfants au fils
    enfant = treeStoreF4.append(fils)
      enfant[0] = "Ludovic" ; enfant[1] = "Schmurff" ; enfant[2] = 1994
    enfant = treeStoreF4.append(fils)
      enfant[0] = "Victor" ; enfant[1] = "Schmurff" ; enfant[2] = 1999


  # Ajout d'un second fils
  fils = treeStoreF4.append(parent)
    fils[0] = "Sophie" ; fils[1] = "Miroufff" ; fils[2] = 1962
  # Ajout de qqes enfants au fils
    enfant = treeStoreF4.append(fils)
      enfant[0] = "Pauline" ; enfant[1] = "Miroufff" ; enfant[2] = 1990
    enfant = treeStoreF4.append(fils)
      enfant[0] = "Jean" ; enfant[1] = "Miroufff" ; enfant[2] = 1994

  # Ajout d'un troisième fils
  fils = treeStoreF4.append(parent)
    fils[0] = "Marc" ; fils[1] = "Schmurff" ; fils[2] = 1963
    # Ajout de qqes enfants au fils
    enfant = treeStoreF4.append(fils)
      enfant[0] = "Marie" ; enfant[1] = "Schmurff" ; enfant[2] = 1990
    enfant = treeStoreF4.append(fils)
      enfant[0] = "Serge" ; enfant[1] = "Schmurff" ; enfant[2] = 1993

# un Arbre pour visualiser les données de la liste
  viewListeF4 = TreeView.new(treeStoreF4)
    viewListeF4.selection.mode = SELECTION_SINGLE
    # Les 'renderer' permettent de préciser comment afficher les données 
      renderer = CellRendererText.new
        # Ajout d'uhe colonne utilisant ce rendu
        col = TreeViewColumn.new("Prenom", renderer, :text => 0)
        # On utilise Pango pour obtenir le gras
        renderer.weight = Pango::FontDescription::WEIGHT_BOLD
        viewListeF4.append_column(col)
    # Un autre rendu modifiant la fonte
      renderer = CellRendererText.new
        # Ajout d'une colonne utilisant ce rendu
        col = TreeViewColumn.new("Nom", renderer, :text => 1)
        viewListeF4.append_column(col)
    # Un dernier rendu modifiant la couleur
      renderer = CellRendererText.new
      renderer.foreground = "red"
      # Ajout d'une colonne utilisant ce rendu
        col = TreeViewColumn.new("Age", renderer)
        viewListeF4.append_column(col)
      # Creation d'une formule de cellule pour calculer l'age.
      # Dans la troisième colonne on ne veut pas afficher l'annee (fournie)
      # mais l'age (calculé)
      col.set_cell_data_func(renderer) do |col, renderer, model, iter|
        anneeCourante = 2005 
        anneeNaissance = iter[2]
        if (anneeNaissance <= anneeCourante) && (anneeNaissance > 0)
          renderer.text = sprintf("%i ans", anneeCourante - anneeNaissance)
          # Utiliser la couleur par défaut (noir) si l'age est connu
          renderer.foreground_set = false
        else
          renderer.text = "Age inconnu"
          # Utiliser la couleur du renderer (rouge) si l'age est inconnu
          renderer.foreground_set = true
        end
      end
      
  # Un Label pour afficher la sélection courante
  maSelectionF4 = Label.new()
  
  maVBoxF4.add(viewListeF4)
  maVBoxF4.add(maSelectionF4)
 
  maFrame4.add(maVBoxF4)
  
  # -----------------------------------------
  #      Les signaux pour cette frame
  # -----------------------------------------
  
  # Gestion du signal de modification du curseur dans la liste
  # le Label est modifié pour indiquer l'élément selectionné
  viewListeF4.signal_connect("cursor-changed") { |v|
      maSelectionF4.text = v.selection.selected.get_value(0)
      maSelectionF4.text += " / " + v.selection.selected.get_value(1)
      maSelectionF4.text += " / " + String(v.selection.selected.get_value(2))
  }
  
 # ======================= FIN DE LA FRAME 4 =========================


# -------------------------------------------------------------------
# Une cinquième Frame pour tester les échanges entre 2 listes
# -------------------------------------------------------------------
maFrame5 = Frame.new("Ma Frame 5")
  maVBoxF5=VBox.new(false,5)
  # Le texte d'explication
  texte= "<span font_desc=#{FONT} foreground=\"#0000FF\">" +
   "Tester les echanges entre 2 listes. " +
   "Selection <b>multiple</b> a gauche, Selection <b>simple</b> a droite</span>"

  leTexte=Label.new()
  leTexte.set_markup(texte)
  leTexte.justify=Gtk::JUSTIFY_CENTER
  leTexte.wrap=true
  
  maVBoxF5.add(leTexte)
  # UneHBox pour la Frame 5
  maHBoxF5 = HBox.new(false, 5)
 
# Une structure de liste pour stocker les données
  sourceStoreF5 = ListStore.new(String, String, Integer)
  destinStoreF5 = ListStore.new(String, String, Integer)
  # ajouter un élément à la source
  element = sourceStoreF5.append()
    element[0] = "Robert" ; element[1] = "Schmurff"
  # un Autre
  element = sourceStoreF5.append()
    element[0] = "Henri" ; element[1] = "Schmurff" ; element[2] = 1960
  # un Autre
  element = sourceStoreF5.append()
    element[0] = "Ludovic" ; element[1] = "Schmurff" ; element[2] = 1994
  # un Autre
  element = sourceStoreF5.append()
    element[0] = "Victor" ; element[1] = "Schmurff" ; element[2] = 1999
    
  # un TreeView pour visualiser les données de la liste
  sourceListeF5 = TreeView.new(sourceStoreF5)
  destinListeF5 = TreeView.new(destinStoreF5)
    sourceListeF5.selection.mode = SELECTION_MULTIPLE
    destinListeF5.selection.mode = SELECTION_SINGLE
    # Les 'renderer' permettent de préciser comment afficher les données
      renderer = CellRendererText.new
        # Ajout d'uhe colonne utilisant ce rendu
        cols = TreeViewColumn.new("Prenom", renderer, :text => 0)
        sourceListeF5.append_column(cols)
    # Un autre rendu modifiant la fonte
      renderer = CellRendererText.new
      # On utilise Pango pour obtenir le gras
      renderer.weight = Pango::FontDescription::WEIGHT_BOLD
      # Ajout d'une colonne utilisant ce rendu dans les deux listes
        # pour le Nom dans la liste source
        cols = TreeViewColumn.new("Nom", renderer, :text => 1)
        # Pour le Prénom dans la liste Destination
        cold = TreeViewColumn.new("Prenom", renderer, :text => 0)
        sourceListeF5.append_column(cols)
        destinListeF5.append_column(cold)
    # Un dernier rendu modifiant la couleur
      renderer = CellRendererText.new
      renderer.foreground = "red"
      # Ajout d'une colonne utilisant ce rendu
        col = TreeViewColumn.new("Age", renderer)
        sourceListeF5.append_column(col)
      # Création d'une formule de cellule pour calculer l'age.
      # Dans la troisième colonne on ne veut pas afficher l'année (fournie)
      # mais l'age (calculé)
      col.set_cell_data_func(renderer) do |col, renderer, model, iter|
        anneeCourante = 2005 
        anneeNaissance = iter[2]
        if (anneeNaissance <= anneeCourante) && (anneeNaissance > 0)
          renderer.text = sprintf("%i ans", anneeCourante - anneeNaissance)
          # Utiliser la couleur par défaut (noir) si l'age est connu
          renderer.foreground_set = false
        else
          renderer.text = "age inconnu"
          # Utiliser la couleur du renderer (rouge) si l'age est inconnu
          renderer.foreground_set = true
        end
      end
  
  maHBoxF5.add(sourceListeF5)
  maHBoxF5.add(autreVBoxF5=VBox.new(false, 5))
  btn1F5=Button.new("-->")
  btn2F5=Button.new("<--")
  btn3F5=Button.new("->>")
  btn4F5=Button.new("<<-")

  autreVBoxF5.add(Label.new)
  autreVBoxF5.add(Label.new)
  autreVBoxF5.add(btn1F5)
  autreVBoxF5.add(btn3F5)
  autreVBoxF5.add(Label.new)
  autreVBoxF5.add(btn2F5)
  autreVBoxF5.add(btn4F5)

  maHBoxF5.add(destinListeF5)

  maVBoxF5.add(maHBoxF5) 

  maFrame5.add(maVBoxF5)
  
  # ------------------------- ----------------
  #      Les signaux pour cette frame
  # -----------------------------------------
  # Le bouton de transfert de gauche à droite
  btn1F5.signal_connect('clicked') {|sel, element|
    sel=sourceListeF5.selection
    adetruire=Array.new
    sel.selected_each {|model,path,iter|
      # On stocke dans un tableau les éléments à détruire
      #  on ne peut pas les détruire pendant l'itération
      adetruire.push(iter)     
      element=destinStoreF5.append()
      element[0]=iter.get_value(0)
      element[1]=iter.get_value(1)
      element[2]=iter.get_value(2)
    }
    # maintenant il reste à détruire
    adetruire.each {|ind|
        sourceStoreF5.remove(ind)
    }
  }
  
  # Le bouton de transfert de tout de gauche à droite
  btn3F5.signal_connect('clicked') {|element|
    sourceStoreF5.each {|ele|
      element=destinStoreF5.append()
        element[0]=ele[2].get_value(0)
        element[1]=ele[2].get_value(1)
        element[2]=ele[2].get_value(2)
    }
    sourceStoreF5.clear
  }
  
  # Le bouton de transfert de droite à gauche
  btn2F5.signal_connect('clicked') {|sel, element|
    sel=destinListeF5.selection.selected
    if sel != nil
      element=sourceStoreF5.append()
      element[0]=sel.get_value(0)
      element[1]=sel.get_value(1)
      element[2]=sel.get_value(2)
      destinStoreF5.remove(sel)
    end
  }
  # Le bouton de transfert de tout de droite à gauche
  btn4F5.signal_connect('clicked') {|element|
    destinStoreF5.each {|ele|
      element=sourceStoreF5.append()
        element[0]=ele[2].get_value(0)
        element[1]=ele[2].get_value(1)
        element[2]=ele[2].get_value(2)
    }
    destinStoreF5.clear
  }
  
# ======================= FIN DE LA FRAME 5 =========================


# -------------------------------------------------------------------
# Une sixième Frame pour tester les l'édition et la sauvegarde entre 2 listes
# -------------------------------------------------------------------
# C'est la même que la 5 on rajoute un bouton sauver, un bouton effacer 
#  et un bouton charger. 
# Possibilité d"édition du prénom

maFrame6 = Frame.new("Ma Frame 6") 
  # Une VBox pour la Frame 6 (Une rangée de Treview et une rangée de boutons)
  maVBoxF6 = VBox.new(false, 5)
  maHBoxStoreF6 = HBox.new(false, 10) # Pour les Listes
  maHBoxBtnF6 = HBox.new(false, 5)   # Pour les Boutons
# Le texte d'explication
  texte= "<span font_desc=#{FONT} foreground=\"#0000FF\">" +
   "Tester l'edition, la sauvegarde et la restitution avec 2 listes. " +
   "Tester la <b>serialisation</b> avec les boutons <b>Sauver</b>, <b>Effacer</b> " +
   "et <b>Charger</b>. Possibilite <b>d'edition</b> du prenom dans la liste de gauche</span>"

  leTexte=Label.new()
  leTexte.set_markup(texte)
  leTexte.justify=Gtk::JUSTIFY_CENTER
  leTexte.wrap=true
  
  maVBoxF6.add(leTexte)
# les structure de liste pour stocker les données
  sourceStoreF6 = ListStore.new(String, String, Integer)
  destinStoreF6 = ListStore.new(String, String, Integer)
  # ajouter un élément à la source
    element = sourceStoreF6.append()
    element[0] = "Robert" ; element[1] = "Schmurff"
  # un Autre
  element = sourceStoreF6.append()
    element[0] = "Henri" ; element[1] = "Schmurff" ; element[2] = 1960
  # encore un Autre
  element = sourceStoreF6.append()
    element[0] = "Ludovic" ; element[1] = "Schmurff" ; element[2] = 1994
  # encore un Autre
  element = sourceStoreF6.append()
    element[0] = "Victor" ; element[1] = "Schmurff" ; element[2] = 1999
    
  # un TreeView pour visualiser les données de la liste
  sourceListeF6 = TreeView.new(sourceStoreF6)
  destinListeF6 = TreeView.new(destinStoreF6)
    sourceListeF6.selection.mode = SELECTION_SINGLE
    destinListeF6.selection.mode = SELECTION_NONE
    # Les 'renderer' permettent de préciser comment afficher les données
      rendererGauche = CellRendererText.new
      rendererGauche.foreground = "blue"
      rendererDroite = CellRendererText.new
      rendererDroite.foreground = "green"
      # On rend éditable ce rendu de prénom à gauche pour permettre de modifier
      rendererGauche.set_editable(true)
      # On sauvegarde la modification dans la listStore.  
      rendererGauche.signal_connect('edited') { |cell,ligne,nouvelle|
        sourceStoreF6.get_iter(ligne).set_value(0,nouvelle)
      }
        # Ajout d'une colonne utilisant ce rendu
        cols = TreeViewColumn.new("Prenom", rendererGauche, :text => 0)
        cold = TreeViewColumn.new("Prenom", rendererDroite, :text => 0)
        sourceListeF6.append_column(cols)
        destinListeF6.append_column(cold)
    # Un autre rendu modifiant la fonte
      renderer = CellRendererText.new
      renderer.foreground = "white"
      renderer.background = "black"
      # On utilise Pango pour obtenir le gras
      renderer.weight = Pango::FontDescription::WEIGHT_BOLD
      # Ajout d'une colonne utilisant ce rendu dans les deux listes
        # pour le Nom dans la liste source
        cols = TreeViewColumn.new("Nom", renderer, :text => 1)
        cold = TreeViewColumn.new("Nom", renderer, :text => 1)
        sourceListeF6.append_column(cols)
        destinListeF6.append_column(cold)
    # Un dernier rendu modifiant la couleur
      renderer = CellRendererText.new
      renderer.foreground = "red"
      # Ajout d'une colonne utilisant ce rendu
        cols = TreeViewColumn.new("Age", renderer, :text => 2)
        cold = TreeViewColumn.new("Annee", renderer, :text => 2)
      # Création d'une formule de cellule pour calculer l'age.
      # Dans la troisième colonne on ne veut pas afficher l'année (fournie)
      # mais l'age (calculé)
      cols.set_cell_data_func(renderer) do |col, renderer, model, iter|
        anneeCourante = 2005 
        anneeNaissance = iter[2]
        if (anneeNaissance <= anneeCourante) && (anneeNaissance > 0)
          renderer.text = sprintf("%i ans", anneeCourante - anneeNaissance)
          # Utiliser la couleur par défaut (noir) si l'age est connu
          renderer.foreground_set = false
        else
          renderer.text = "age inconnu"
          # Utiliser la couleur du renderer (rouge) si l'age est inconnu
          renderer.foreground_set = true
        end
      end

        sourceListeF6.append_column(cols)
        destinListeF6.append_column(cold)

  # Un bouton de sauvegarde
  sauveBtnF6 = Button.new("Sauver")
  # Un bouton de chargement
  chargeBtnF6 = Button.new("Charger")
  # Un bouton pour effacer la destination
  effaceBtnF6 = Button.new("Effacer")
  
  maHBoxStoreF6.add(sourceListeF6)
  maHBoxStoreF6.add(destinListeF6)

  maHBoxBtnF6.add(sauveBtnF6)
  maHBoxBtnF6.add(effaceBtnF6)
  maHBoxBtnF6.add(chargeBtnF6)
  maVBoxF6.add(maHBoxStoreF6)
  maVBoxF6.add(maHBoxBtnF6)
  
  maFrame6.add(maVBoxF6)
  # ------------------------- ----------------
  #      Les signaux pour cette frame
  # -----------------------------------------

  # Le bouton qui sauve en sérialisant les données de la Liste Source
  sauveBtnF6.signal_connect('clicked') {
    File.open("SauveF6.dat","w") {|f|
      sourceStoreF6.each {|ele|
        Marshal.dump(ele[2].get_value(0),f)
        Marshal.dump(ele[2].get_value(1),f)
        Marshal.dump(ele[2].get_value(2),f)
      }
    }
  }

  # Le bouton pour effacer la liste destination
  effaceBtnF6.signal_connect('clicked') {
    destinStoreF6.clear
  }

  # Le Bouton qui charge dans la liste Destination les données
  #  sérialisées dans le fichier
  chargeBtnF6.signal_connect('clicked') {
    destinStoreF6.clear
    File.open("SauveF6.dat","r") {|f|
      while (!f.eof()) do
        ele=destinStoreF6.append()
        ele[0]=Marshal.load(f)
        ele[1]=Marshal.load(f)
        ele[2]=Marshal.load(f)
      end
    }
  }

# ======================= FIN DE LA FRAME 6 =========================




# -------------------------------------------------------------------
# Une Huitième Frame pour tester les ComboBox
# -------------------------------------------------------------------

maFrame8 = Frame.new("Ma Frame 8") 
  # Une VBox pour la Frame 8
  maVBoxF8 = VBox.new(false, 10)
# Le texte d'explication
  texteF8= "<span font_desc=#{FONT} foreground=\"#0000FF\">" +
   "Tester les <b>ComboBox</b> et la detection des changements de selection. " +
   "Le <b>Label</b> affiche en permanence l'element selectionne." +
   "</span>"

  leTexteF8=Label.new()
  leTexteF8.set_markup(texteF8)
  leTexteF8.justify=Gtk::JUSTIFY_CENTER
  leTexteF8.wrap=true

# Une ComboBox quand le paramètre n'est pas true il faut utiliser une
#   ListStore (je crois)
maComboBoxF8=ComboBox.new(true)
maComboBoxF8.append_text("Coucou")
maComboBoxF8.append_text("Bonjour")
maComboBoxF8.append_text("Salut")
maComboBoxF8.append_text("Hello")
maComboBoxF8.append_text("Buenas dias")
maComboBoxF8.append_text("Gutten tag")


# L'élément actif est celui à la position 0
maComboBoxF8.active=0
texte="<span font_desc=\"Times New Roman 12\" foreground=\"#FF0000\">" +
        "Element selectionne : <b>#{maComboBoxF8.active_iter.get_value(0)}</b></span>"
# Un label pour afficher l'élément séléctionné
monLabelF8=Label.new()
monLabelF8.justify=Gtk::JUSTIFY_CENTER
monLabelF8.wrap=true

monLabelF8.set_markup(texte)
  maVBoxF8.add(leTexteF8)
  maVBoxF8.add(maComboBoxF8)
  maVBoxF8.add(monLabelF8)
  maFrame8.add(maVBoxF8)
  
  # ------------------------- ----------------
  #      Les signaux pour cette frame
  # -----------------------------------------
  #Quand on change de sélection on change le label
  maComboBoxF8.signal_connect('changed') {
  texteF8="<span font_desc=\"Times New Roman 12\" foreground=\"#FF0000\">" +
        "Element selectionne : <b>#{maComboBoxF8.active_iter.get_value(0)}</b></span>"
  monLabelF8.set_markup(texteF8)
}
  
# -------------------------------------------------------------------
#             Fin de la définition des Frames pour les onglets
# -------------------------------------------------------------------


# -------------------------------------------------------------------
#  Création d'un panneau a onglets pour toutes ces Frames 
# -------------------------------------------------------------------
mesOnglets = Notebook.new
mesOnglets.scrollable=true

frameOnglet={"Positionnement" => maFrame1,"Modif Box" => maFrame2,
             "Liste" => maFrame3, "Arbre" => maFrame4,
             "Transfert" => maFrame5,"Serialisation" => maFrame6,
             "ComboBox" => maFrame8}
titreOnglet=["Positionnement","Modif Box","Liste","Arbre","Transfert",
              "Serialisation","ComboBox"] 

titreOnglet.each {|titre,frame|
  frame=frameOnglet[titre]
  ongBox=HBox.new()
  # Sur l'onglet Modif Box on met un bouton de fermeture pour tester
  if titre=="Modif Box" 
    image = Image.new 
    image.set(:'gtk-close', Gtk::IconSize::MENU)
    btn=Button.new()
    btn.add(image)
    btn.set_relief(Gtk::RELIEF_NONE)
    ongBox.pack_start(Label.new(titre))
    ongBox.pack_end(btn)
    btn.signal_connect('clicked') {
      mesOnglets.remove_page(mesOnglets.page_num(frame))
    }
  else 
    ongBox.pack_start(Label.new(titre))
  end
  # Bizarre mais nécessaire
  ongBox.show_all
  mesOnglets.append_page_menu(frame,ongBox,Label.new(titre))
}

# On active le menu Popup
mesOnglets.enable_popup=true

# Un Label pour afficher l'onglet courant
monLabel = Label.new()

# Un Bouton pour Quitter
quitter = Button.new(Stock::QUIT)

  # ------------------------------------------------------------------
  # Le traitement des signaux sur les onglets, la fenetre et le bouton
  # ------------------------------------------------------------------

  # On change de page d'onglet on écrit la page courante dans le Label 
  #  en utilisant le langage de description
  mesOnglets.signal_connect('switch-page') {|note,page,indexPage|
    texte  = "<span font_desc=\"Comic sans MS 10\" foreground=\"#0000FF\">"
    texte += "Page en cours #{indexPage+1}/#{note.n_pages}</span>"
    monLabel.set_markup(texte)
  }

  def bye()
    print 'Au Revoir !'
    Gtk.main_quit
  end
  
  # On clique sur le bouton pour quitter
  quitter.signal_connect('clicked') {
    bye()
  }

  # On peut aussi quitter avec la croix de la fenetre.
  monApplication.signal_connect('destroy') {
    bye()
  }


# Construction de l'application
  maVBoxAppli.add(mesOnglets)
  maVBoxAppli.add(monLabel)
  maVBoxAppli.add(quitter)
  monApplication.add(maVBoxAppli)

monApplication.show_all

Gtk.main
