boolean oj = System.getProperty("ONLINE_JUDGE") != null;
Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("input.txt");
Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("output.txt");
StreamTokenizer in = new StreamTokenizer(new BufferedReader(reader));
PrintWriter out = new PrintWriter(writer);



import java.io.*;
import java.util.*;

public class SumDif
{
   public static void main(String[] args) throws IOException
   {
      new SumDif().run();
   }

   StreamTokenizer in;
   PrintWriter out;

   int nextInt() throws IOException
   {
      in.nextToken();
      return (int)in.nval;
   }

   void run() throws IOException
   {
      in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
      out = new PrintWriter(new OutputStreamWriter(System.out));
      solve();
      out.flush();
   }

   void solve() throws IOException
   {
      int a = nextInt();
      int b = nextInt();
      out.print(a + b);
      out.print(" ");
      out.println(a - b);
   }
}