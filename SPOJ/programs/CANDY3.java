import java.util.Scanner;
import java.math.BigInteger;
class CANDY3
{
   public static void main(String args[])
   {
   	   try{
            Scanner s= new Scanner(System.in);
            BigInteger noc,num,sum,i,j,temp,mod1;
            noc=s.nextBigInteger();
            for(i=BigInteger.ZERO;i.compareTo(noc)==-1;i=i.add(BigInteger.ONE))
            {
            	num=s.nextBigInteger();
            	sum=BigInteger.ZERO;
            	for(j=BigInteger.ZERO;j.compareTo(num)==-1;j=j.add(BigInteger.ONE))
            	{
                     temp=s.nextBigInteger();
                     sum=sum.add(temp);
            	}
            	mod1=sum.mod(num);
            	if(mod1.compareTo(BigInteger.ZERO)==0)
            		System.out.println("YES");
            	else
            		System.out.println("NO");
            }
   	   }catch(NumberFormatException e)
   	   {

   	   }
   }
}