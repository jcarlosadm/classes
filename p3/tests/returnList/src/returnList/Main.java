package returnList;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        ClassList classList = new ClassList();
        
        System.out.println(classList);
        
        List<String> list = classList.getList();
        
        try {
            list.remove("three");
            System.out.println("three removed");
        } catch (UnsupportedOperationException e) {
            System.out.println("you can't remove three");
        }
        
        System.out.println(classList);
        
        List<String> unmodifiableList = classList.getUnmodifiableList();
        
        try {
            unmodifiableList.remove("two");
            System.out.println("two removed");
        } catch (UnsupportedOperationException e) {
            System.out.println("you can't remove two");
        }
        
        System.out.println(classList);
    }
}
