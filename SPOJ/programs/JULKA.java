import java.util.Scanner;
import java.math.BigInteger;
class JULKA
 {
 	public static void main(String args[])
 	  {
 	  	try{
 	  	Scanner sc= new Scanner(System.in);
 	  	BigInteger a,b,x,y,two=new BigInteger("2");
 	  	for(int i=0;i<10;i++)
 	  	{
 	  	  a=sc.nextBigInteger();
 	      b=sc.nextBigInteger();
          x=a.add(b);
          y=a.subtract(b);
          x=x.divide(two);
          y=y.divide(two);
          System.out.println(x);
          System.out.println(y); 
 	  	}
 	  

 	  	}catch(NumberFormatException e)
 	  	  {

 	  	  }
 	  	
 	  }
 }