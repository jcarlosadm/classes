package enumTest;

public class ChangeClass {
    StoreClass st;
    
    public ChangeClass(StoreClass s) {
        this.st = s;
    }
    
    public void changeState(){
        this.st.changeState(new StateTwo());
    }
}
