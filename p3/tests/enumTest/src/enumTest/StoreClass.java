package enumTest;

public class StoreClass {
    State currentState;
    ChangeClass changeClass;
    
    public StoreClass() {
        this.currentState = new StateOne();
        this.print();
        this.changeClass = new ChangeClass(this);
        this.changeClass.changeState();
    }
    
    public void print() {
        this.currentState.print();
    }
    
    public void changeState(State t){
        this.currentState = t;
    }
    
    public static void main(String[] args) {
        StoreClass sc = new StoreClass();
        sc.print();
    }
}
