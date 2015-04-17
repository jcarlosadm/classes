package enumTest;

public class StateTwo implements State {

    int value = 2;
    
    @Override
    public void print() {
        System.out.println("StateTwo");
    }

    @Override
    public int getValue() {
        return this.value;
    }

    @Override
    public void setValue(int value) {
        this.value = value;
    }

}
