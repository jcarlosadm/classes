package arrayLimit;

public class Test {
    public static void main(String[] args) {
        
        int[] intArray = new int[3];
        intArray[0] = 1;
        intArray[1] = 2;
        intArray[2] = 3;
        
        try {
            int i = 0;
            
            while(true){
                System.out.println(intArray[i++]);
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("atingiu o limite!");
        }
        
        System.out.println("outside of try/catch!");
    }
}
