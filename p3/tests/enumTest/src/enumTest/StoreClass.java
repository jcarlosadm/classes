package enumTest;

public class StoreClass {
    State currentState;
    State state2;
    ChangeClass changeClass;
    ChangeClass2 changeClass2;
    
    public StoreClass() {
        this.currentState = new StateOne();
        this.changeClass = new ChangeClass(this);
        this.changeClass.changeState();
        
        this.state2 = new StateOne();
        this.changeClass2 = new ChangeClass2(this.state2);
    }
    
    public void print() {
        this.currentState.print();
        System.out.println(this.state2.getValue());
    }
    
    public void changeState(State t){
        this.currentState = t;
    }
    
    public static void main(String[] args) {
        StoreClass sc = new StoreClass();
        sc.print();
    }
}
