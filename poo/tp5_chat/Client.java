import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JOptionPane;

public class Client {
	private String msg_recu = "";
	private String ip;
	private int port;
	private Socket clientSocket;
   // private PrintWriter out;
   // private BufferedReader in ;
    InputStream is;
    ObjectInputStream ois;
    OutputStream os;
    ObjectOutputStream oos;

	
	public Client (String ip,int port) {
		this.ip = ip;
		this.port = port;
	}
      
	public void connexion() throws UnknownHostException, IOException{
      try {
          clientSocket = new Socket(ip,port); 
          
          
          Thread recevoir = new Thread(){
  		    @Override
  		    public void run() {
  		         while(true){
  		        	
  			        	try {
							is=clientSocket.getInputStream();
							ois = new ObjectInputStream(is);
	  			        	Object o = ois.readObject();
	  			        	if(o instanceof String) {
		  			            System.out.println("Serveur : "+ (String) o);
		  			            setMsg_recu((String) o);
		  		        	}
						} catch (IOException | ClassNotFoundException e) {
							// TODO Auto-generated catch block
							this.interrupt();
						}
  			    }
  		    }
         };
  		recevoir.start();
      }catch (IOException e) {
        e.printStackTrace();
      }
	}
	

 
	
	public void envoyer_msg(String msg) {
           //flux pour envoyer
         
         Thread envoyer = new Thread(new Runnable() {
             @Override
              public void run() {
            	 try {
	              os = clientSocket.getOutputStream();
	              oos = new ObjectOutputStream(os);
	              oos.writeObject(msg);
		          oos.flush();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
                
             }
         });
         envoyer.start();      
	}
	
	

	public synchronized String getMsg_recu() {
		return this.msg_recu;
	}

	public synchronized void setMsg_recu(String msg) {
		this.msg_recu = msg;
	}
	
	
	
	public void deconnexion() throws IOException {
		try {
    		is.close();
    		ois.close();
    		os.close();
    		oos.close();
    		clientSocket.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

}