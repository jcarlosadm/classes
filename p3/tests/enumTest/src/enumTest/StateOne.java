package enumTest;

public class StateOne implements State {

    int value = 1;
    
    @Override
    public void print() {
        System.out.println("StateOne");
    }
    
    public void setValue(int value){
        this.value = value;
    }
    
    public int getValue(){
        return this.value;
    }

}
