package returnList;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ClassList {
    
    private List<String> myStrings = new ArrayList<>();
    
    public ClassList() {
        this.myStrings.add("one");
        this.myStrings.add("two");
        this.myStrings.add("three");
    }

    @Override
    public String toString() {
        String result = "";
        for (String string : this.myStrings) {
            result += string + " ";
        }
        
        return result;
    }
    
    public List<String> getList(){
        return this.myStrings;
    }
    
    public List<String> getUnmodifiableList(){
        return Collections.unmodifiableList(this.myStrings);
    }
    
}
