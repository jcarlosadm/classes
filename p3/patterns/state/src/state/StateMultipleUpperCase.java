package state;

import test.StateContext;

public class StateMultipleUpperCase implements StateLike {

    private int count = 0;
    
    @Override
    public void writeName(StateContext context, String name) {
        System.out.println(name.toUpperCase());
        this.count++;
        if(this.count > 1){
            context.setState(new StateLowerCase());
        }
    }

}
