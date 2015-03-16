package election.main;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Test class
 *
 */
public class ElectionTest {
    /**
     * main method
     * @param args
     */
    public static void main(String[] args) {
        
        Scanner user_input = new Scanner(System.in);
        
        int totalVotes = getUserInput("Tip total votes: ", user_input);
        int psdbVotes = getUserInput("Tip PSDB votes: ", user_input);
        int pmdbVotes = getUserInput("Tip PMDB votes: ", user_input);
        
        user_input.close();
        
        if(psdbVotes+pmdbVotes > totalVotes){
            psdbVotes = 0;
            pmdbVotes = 0;
        }
        
        int nullVotes = totalVotes - psdbVotes - pmdbVotes;
        
        if(validElection(totalVotes, nullVotes)){
            if(psdbVotes > pmdbVotes){
                System.out.println("PSDB wins");
            }else if(pmdbVotes > psdbVotes){
                System.out.println("PMDB wins");
            }else{
                System.out.println("no wins");
            }
        }else{
            System.out.println("Election canceled");
        }
        
        System.out.println("PSDB Votes: "+psdbVotes);
        System.out.println("PMDB Votes: "+pmdbVotes);
        System.out.println("NULL Votes: "+nullVotes);
        System.out.println("Total Votes: "+totalVotes);
    }

    private static int getUserInput(String message, Scanner user_input) {
        
        int value = 0;
        boolean validValue = false;

        while(!validValue){
            try {
                System.out.print(message);
                value = user_input.nextInt();
                
                if(value >= 0){
                    validValue = true;
                }else{
                    System.out.println("Invalid value");
                }
                
            } catch (InputMismatchException e) {
                System.out.println("Invalid value");
            }
        }
        
        return value;
    }

    private static boolean validElection(int totalVotes, int nullVotes) {
        if(nullVotes >= (totalVotes/2)){
            return false;
        }
        return true;
    }
}
