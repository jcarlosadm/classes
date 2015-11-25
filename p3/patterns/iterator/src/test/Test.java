package test;

import iterator.Iterator;
import repository.NameRepository;

public class Test {
    public static void main(String[] args) {
        NameRepository nameRepository = new NameRepository();
        
        for(Iterator iter = nameRepository.getIterator(); iter.hasNext();){
            String name = (String) iter.next();
            System.out.println("Name: "+name);
        }
    }
}
