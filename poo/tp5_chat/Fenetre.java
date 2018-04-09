

import javax.swing.*;
import java.awt.Color; 
import java.awt.Font; 
import java.awt.Dimension;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.CardLayout;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.awt.event.ActionEvent;
import java.awt.Color; 
import java.awt.Font; 
import java.awt.Dimension;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.CardLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.lang.Integer;


public class Fenetre extends JFrame{
	 private JPanel container = new JPanel();
	 private JTextField jtf = new JTextField("");
	 private JTextField jtf2 = new JTextField("");
	 private JTextField jtf3 = new JTextField("8888");
//	 private JTextField jtf4 = new JTextField("Les personnes connectées");
//	 private JTextField jtf5 = new JTextField("La discussionne");
	 private JTextArea jtf6 = new JTextArea("");

	 
	 private JLabel label_nom = new JLabel("Nom");
	 private JLabel label_addr_ip = new JLabel("Ip");
	 private JLabel label_port = new JLabel("Port");
	 private JLabel label_connectee = new JLabel("connectée");
	 private JLabel label_discussion = new JLabel("Discussion");
	 private JLabel label_message = new JLabel("Message");


	 private JButton b_connection = new JButton("Connection");
	 private JButton b_envoyer = new JButton("Envoyer");
	 private JButton b_deconnection = new JButton("Déconnection");
	 
	 String msg;
	 
	 int n;

	

	public Fenetre(){
		this.setTitle("Chat");
	    this.setSize(600, 500);
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    
	    this.setLocationRelativeTo(null);
	      
	    container.setBackground(Color.white);
	    container.setLayout(new BorderLayout());
	    
	    Font police = new Font("Arial", Font.BOLD, 14);
	    
	    //init du bouton b_connection a faux
	    b_connection.setEnabled(false);
	    b_envoyer.setEnabled(false);

		System.out.println("ip + port " + jtf2.getText() + (jtf3.getText()));
		Client clt;
	    
	    //on regarde si les champs sont vides ou pas 
	    KeyListener listener_connection =new KeyListener() {
				
			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub
			}
			
			@Override
			public void keyReleased(KeyEvent e) {
				// TODO Auto-generated method stub
				boolean value = (!jtf.getText().toString().isEmpty() && !jtf2.getText().toString().isEmpty() && !jtf3.getText().toString().isEmpty());
	    		b_connection.setEnabled(value);
	    		
		    }
			
			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				
			}
		};
		
	    KeyListener listener_envoyer =new KeyListener() {
			
			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub
			}
			
			@Override
			public void keyReleased(KeyEvent e) {
				// TODO Auto-generated method stub
				boolean value = (!jtf6.getText().toString().isEmpty());
	    		b_envoyer.setEnabled(value);
		    }
			
			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
			}
		};
		
	    
	       
	    JPanel name = new JPanel();
	    jtf.setFont(police);
	    jtf.setForeground(Color.BLACK);
	    jtf.setPreferredSize(new Dimension(150, 30));	    
	    name.add(label_nom);
	    name.add(jtf);
	                  
	    
	    JPanel ip = new JPanel();
	    jtf2.setFont(police);
	    jtf2.setForeground(Color.BLACK);
	    jtf2.setPreferredSize(new Dimension(150, 30));
	    ip.add(label_addr_ip);
	    ip.add(jtf2);	  	    
	    
	    JPanel port = new JPanel();
	    jtf3.setFont(police);
	    jtf3.setForeground(Color.BLACK);
	    jtf3.setPreferredSize(new Dimension(150, 30));
	    port.add(label_port);
	    port.add(jtf3);	
	    
	   
	    JPanel button = new JPanel();
	    button.add(b_connection);
	    b_connection.setPreferredSize(new Dimension(150,30));
	 
		jtf.addKeyListener(listener_connection);
		jtf2.addKeyListener(listener_connection);
		jtf3.addKeyListener(listener_connection);


	    
		DefaultListModel<String> listModel = new DefaultListModel<String>();
		//listModel.addElement("user1");
		//listModel.addElement("user2");
		//listModel.addElement("user3");
		
		JList<String> listeConnectes = new JList<String>(listModel);
		listeConnectes.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		listeConnectes.setLayoutOrientation(JList.VERTICAL);
		listeConnectes.setVisibleRowCount(-1);
		
		
		JScrollPane scrollerListeConnectes = new JScrollPane(listeConnectes);
		scrollerListeConnectes.setPreferredSize(new Dimension(200, 500));
	    
	    JPanel button_deconnection = new JPanel();
	    button_deconnection.add(b_deconnection);
	    b_deconnection.setPreferredSize(new Dimension(150,30));
		
	    JPanel enligne = new JPanel();
	    enligne.add(label_connectee);
	    Box vBox_enligne = Box.createVerticalBox();
	    vBox_enligne.add(enligne);
	    vBox_enligne.add(scrollerListeConnectes);
	    vBox_enligne.add(button_deconnection);
	    
	    
		DefaultListModel<String> listText = new DefaultListModel<String>();
  		JList<String> listDisc = new JList<String>(listText);
		listDisc.setSelectionMode(DefaultListSelectionModel.SINGLE_INTERVAL_SELECTION);
		listDisc.setLayoutOrientation(JList.VERTICAL);
		listDisc.setVisibleRowCount(-1);
		listDisc.setSelectionModel(new AucuneSelection());
		
		JScrollPane scrollerListeDisc = new JScrollPane(listDisc);
		scrollerListeDisc.setPreferredSize(new Dimension(400, 170));
	    
	    
	    
	    JPanel disc = new JPanel();
	    disc.add(label_discussion);
	    Box vBox_disc = Box.createVerticalBox();
	    vBox_disc.add(disc);
	    vBox_disc.add(scrollerListeDisc);
	    
	    JPanel message = new JPanel();
	    jtf6.setFont(police);
	    jtf6.setForeground(Color.BLACK);
	    jtf6.setLineWrap(true);
	    JScrollPane text = new JScrollPane(jtf6);
	    text.setPreferredSize(new Dimension(400, 100));
	    
	    message.add(label_message);
	    Box vBox_message = Box.createVerticalBox();
	    vBox_message.add(message);
	    vBox_message.add(text);
	    
		listeConnectes.addMouseListener(new MouseAdapter() {			
			 public void mouseClicked(MouseEvent evt) {			 
			        if (evt.getClickCount() == 2) {
			            int index = listeConnectes.locationToIndex(evt.getPoint());
			            jtf6.setText(jtf6.getText() + " @" + listModel.getElementAt(index).toString() + " ");
			            jtf6.requestFocus();
			        }			        
			 }	
		});
		
		
		

	    
	    JPanel button_envoyer = new JPanel();
	    button_envoyer.add(b_envoyer);
		jtf6.addKeyListener(listener_envoyer);
		

	    
	    Box vBox_disc_message = Box.createVerticalBox();
	    vBox_disc_message.add(vBox_disc);
	    vBox_disc_message.add(vBox_message);
	    vBox_disc_message.add(button_envoyer);

	    
	    Box vBox_name_ip = Box.createVerticalBox();
	    vBox_name_ip.add(name);
	    vBox_name_ip.add(ip);
	    
        Box vBox_button_port = Box.createVerticalBox();
        vBox_button_port.add(button);
        vBox_button_port.add(port);
        
        Box hBox1 = Box.createHorizontalBox();
	    hBox1.add(vBox_name_ip);
	    hBox1.add(vBox_button_port);
	    
	    
	    Box hBox2 = Box.createHorizontalBox();
	    hBox2.add(vBox_enligne);
	    hBox2.add(vBox_disc_message);

	    Box vBox3 = Box.createVerticalBox();
        vBox3.add(hBox1);
        vBox3.add(hBox2);
		hBox2.setVisible(false);

	clt  = new Client(jtf2.getText(),Integer.parseInt(jtf3.getText()));

        ActionListener connect = new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		hBox2.setVisible(true);
        		hBox1.setVisible(false);
        		n=1;
				setTitle("Bienvenue " + jtf.getText());

        		//on allume le client
        			
        		try {
					clt.connexion();
					//listModel.addElement(jtf.getText()) ;
					clt.envoyer_msg("#@#" + " " + jtf.getText() + " " + " s'est connecté");
					Thread actualiser = new Thread(){
						
						public void run() {

							while(true) {
								try {
									System.out.print("");
									if(clt.getMsg_recu() != "") {
										//if(clt.getMsg_recu().substring(0, 3).equals("#@#")) {
											//System.out.println("ce que je vien de recevoir  nom :" + clt.getMsg_recu().substring(5));
											//listModel.addElement(clt.getMsg_recu().substring(1)) ;
											//clt.setMsg_recu("");
										//}
										//else {
											listText.addElement(clt.getMsg_recu());
											clt.setMsg_recu("");
										//}
										
									}
								
								}catch(Exception e) {
									e.printStackTrace();
								}
							}
						}
					};
					actualiser.start();
        			} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
        		
           	}
        };
        
        b_connection.addActionListener(connect);
        
        ActionListener disconnect = new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		hBox2.setVisible(false);
        		hBox1.setVisible(true);
        		n=0;
				setTitle("Chat");

        		
        		try {
					clt.deconnexion();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
        		jtf.setText("");
        		jtf2.setText("");
        		jtf3.setText("");

        	}
        };

        b_deconnection.addActionListener(disconnect);
        
		b_envoyer.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				//listText.addElement("<"+ jtf.getText() + ">" + jtf6.getText());
				clt.envoyer_msg("<"+ jtf.getText() + ">" + jtf6.getText());
				jtf6.setText("");

			}
		});



	   this.setContentPane(vBox3);
	   //this.setContentPane(hBox);

	    this.setVisible(true);   
	        
	}
	
	private class AucuneSelection extends DefaultListSelectionModel{

		   @Override
		   public void setAnchorSelectionIndex(final int anchorIndex) {}

		   @Override
		   public void setLeadAnchorNotificationEnabled(final boolean flag) {}

		   @Override
		   public void setLeadSelectionIndex(final int leadIndex) {}

		   @Override
		   public void setSelectionInterval(final int index0, final int index1) {}
	}
    
}

