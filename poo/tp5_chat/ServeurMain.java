

public class ServeurMain {
	public static void main(String[] args) {
		Serveur server = new Serveur();
		server.setListenPort(8888);
		server.connect();
		
	}		   
	
	
}
