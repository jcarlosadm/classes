package test;


import java.util.ArrayList;
import java.util.List;

import memento.Memento;
import memento.Originator;

public class Test {
    public static void main(String[] args) {
        List<Memento> savedStates = new ArrayList<>();
        
        Originator originator = new Originator();
        originator.setState("State1");
        originator.setState("State2");
        savedStates.add(originator.saveToMemento());
        originator.setState("State3");
        savedStates.add(originator.saveToMemento());
        originator.setState("State4");
        
        originator.restoreFromMemento(savedStates.get(1));
    }
}
