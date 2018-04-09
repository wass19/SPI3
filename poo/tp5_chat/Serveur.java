import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Serveur{
	private int listenPort;
	
	private ServerSocket ss;
	Socket s;
    int nbClients = 0;
    
    private List<ServeurThread> serveurs = new ArrayList<ServeurThread>();
    private List<String> clientconnectées = new ArrayList<String>();
    
    String nom;
	
	public void setListenPort(int numPort) {
		this.listenPort = numPort;
	}
	
	 public int getlistenPort(){
         return listenPort ;
	 }
	 
	 
	public void connect()
     {             
         try {
        	 ss=new ServerSocket(listenPort);
                System.out.println("azertyuiop");
	          while(true) {
	              s = ss.accept();
	              if(!s.isClosed()){	  
		              ServeurThread st = new ServeurThread(s);
		              serveurs.add(st);
		              st.setServeurs(serveurs);
		              st.start();
	              }
	          }
         } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.out.println("eee");
        }
     }
		
	}
