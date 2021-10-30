import java.io.*; 
import java.net.*; 
class Thr extends Thread
{
	Socket s;

	Thr(){s=null; }

	Thr(Socket s1) { s=s1;}

	public void run()
	{
		String clientSentence;
		String capitalizedSentence;
		try{
			BufferedReader inFromClient =new BufferedReader(new InputStreamReader(s.getInputStream()));
			DataOutputStream outToClient=new DataOutputStream(s.getOutputStream()); 
			clientSentence = inFromClient.readLine();
			System.out.println(clientSentence);
			capitalizedSentence = clientSentence.toUpperCase() + '\n';
			outToClient.writeBytes(capitalizedSentence);
			s.close();
			if(clientSentence.equals("exit"))
				 System.exit(1);

		} 
		catch(Exception e){}
		}

		}
		class TCPServer {
			public static void main(String argv[]) throws Exception {

			ServerSocket dataReceive = new ServerSocket(4444);

			while(true) {
			Socket connectionSocket = dataReceive.accept();
			 Thr t=new Thr(connectionSocket);
			 t.start();
		} 
	} 
}