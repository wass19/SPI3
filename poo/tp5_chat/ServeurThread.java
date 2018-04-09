import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.List;

public class ServeurThread extends Thread {

    private Socket socket = null;
    private String s;
    private List<ServeurThread> serveurs;
    InputStream is;
    ObjectInputStream ois;
    OutputStream os;
    ObjectOutputStream oos;

    public ServeurThread(Socket s) {
        socket = s;
    }

    public void run() {

	  	while(!socket.isClosed()){
			  try {
				    System.out.println("waiting");
				    is = socket.getInputStream();			    	
					ois = new ObjectInputStream(is);
					
					s = (String) ois.readObject();
					if((s!="") ||(s!= null))
		            System.out.println("received string: " + s);	  

					for(int i =0 ; i< serveurs.size(); i++){
			            System.out.println("sent object back to client " + i);
						os = serveurs.get(i).socket.getOutputStream();
						oos = new ObjectOutputStream(os);
						oos.writeObject(s);
					}
				} catch (Exception e) {
		            fermer_socket();
				}
	  	}

	}
    
    public void fermer_socket() {
		try {
		
			this.serveurs.remove(this.serveurs.indexOf(this));
			socket.close();

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }

	public void setServeurs(List<ServeurThread> serveurs) {
		this.serveurs = serveurs;
	}

}