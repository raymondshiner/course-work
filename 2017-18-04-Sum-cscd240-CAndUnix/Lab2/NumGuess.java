import java.util.Scanner;

public class NumGuess
{
   public static void main(String [] args)
   {
      char goAgain;
      int theNum, guess;
      Scanner kb = new Scanner(System.in);
      
      do
      {
      
         theNum = ((int)(Math.random()* 100)) + 1;
         
         System.out.println(theNum);
         
         do
         {
         
            System.out.print("Please enter a guess between 1 & 100 ");
            guess = kb.nextInt();
            kb.nextLine();
            
            if(guess > theNum)
               System.out.println("Too High");
         
            else if(guess < theNum)
               System.out.println("Too Low");
   
            else
               System.out.println("You go it");
         
         }while(theNum != guess); 
         
         System.out.print("Would you like to play again? (y/n) ");
         goAgain = kb.nextLine().charAt(0);
       
      }while(goAgain == 'y');
   
   
   }// end main

}// end class