import java.util.Scanner;
import java.math.BigInteger;
class BISHOPS
 {
 	public static void main(String args[])
 	 {
 	 	try{
              BigInteger num,two=new BigInteger("2"),ans;
              Scanner sc= new Scanner(System.in);
              while(sc.hasNextBigInteger())
              {
              	num=sc.nextBigInteger();
              	if(num.compareTo(BigInteger.ONE)==0)
              	{
                        System.out.println(BigInteger.ONE);
              	}
              	else if(num.compareTo(BigInteger.ZERO)==0)
              	{
                       System.out.println(BigInteger.ZERO);
              	}
                 else
                 {
                 	 ans=num.add(num);
                     ans=ans.subtract(two);
                     System.out.println(ans);
                 }
               
              }
 	 	}catch(Exception e)
 	 	{

 	 	}
 	 }
 }