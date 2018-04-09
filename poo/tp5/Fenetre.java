

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color; 
import java.awt.Font; 
import java.awt.Dimension;
import javax.swing.JButton;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import javax.swing.BoxLayout;
import java.awt.CardLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.*;



public class Fenetre extends JFrame{
	 private JPanel container = new JPanel();
	 private JTextField jtf = new JTextField("Valeur par défaut");
	 private JTextField jtf2 = new JTextField("Valeur par défaut");
	 private JTextField jtf3 = new JTextField("Valeur par défaut");
	 private JTextField jtf4 = new JTextField("Les personnes connectées");
	 private JTextField jtf5 = new JTextField("La discussionne");
	 private JTextField jtf6 = new JTextField("Le message");

	 
	 private JLabel label_nom = new JLabel("Nom");
	 private JLabel label_addr_ip = new JLabel("Ip");
	 private JLabel label_port = new JLabel("Port");
	 private JLabel label_connectee = new JLabel("connectée");
	 private JLabel label_discussion = new JLabel("Discussion");
	 private JLabel label_message = new JLabel("Message");


	 private JButton b_connection = new JButton("Connection");
	 private JButton b_envoyer = new JButton("Envoyer");


	public Fenetre(){
	    this.setTitle("chat");
	    this.setSize(600, 500);
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    
	    this.setLocationRelativeTo(null);
	      
	    container.setBackground(Color.white);
	    container.setLayout(new BorderLayout());
	    
	    Font police = new Font("Arial", Font.BOLD, 14);
	    
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

	    
	    
	    JPanel enligne = new JPanel();
	    jtf4.setFont(police);
	    jtf4.setForeground(Color.BLACK);
	    jtf4.setPreferredSize(new Dimension(120, 320));
	    enligne.add(label_connectee);
	    Box vBox_enligne = Box.createVerticalBox();
	    vBox_enligne.add(enligne);
	    vBox_enligne.add(jtf4);
	    
	    
	    JPanel disc = new JPanel();
	    jtf5.setFont(police);
	    jtf5.setForeground(Color.BLACK);
	    jtf5.setPreferredSize(new Dimension(400, 170));
	    disc.add(label_discussion);
	    Box vBox_disc = Box.createVerticalBox();
	    vBox_disc.add(disc);
	    vBox_disc.add(jtf5);
	    
	    JPanel message = new JPanel();
	    jtf6.setFont(police);
	    jtf6.setForeground(Color.BLACK);
	    jtf6.setPreferredSize(new Dimension(400, 100));
	    message.add(label_message);
	    Box vBox_message = Box.createVerticalBox();
	    vBox_message.add(message);
	    vBox_message.add(jtf6);
	    
	    JPanel button_envoyer = new JPanel();
	    button_envoyer.add(b_envoyer);
	    
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
	    
	   this.setContentPane(vBox3);
	   //this.setContentPane(hBox);

	    this.setVisible(true);   
	        
	    
	}
    
}

