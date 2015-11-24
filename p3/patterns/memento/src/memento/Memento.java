package memento;

public class Memento {
    private final String state;
    
    protected Memento(String stateToSave) {
        this.state = stateToSave;
    }
    
    protected String getSavedState(){
        return this.state;
    }
}
