package test;

import state.StateLike;
import state.StateLowerCase;

public class StateContext {
    private StateLike myState;
    
    public StateContext() {
        this.setState(new StateLowerCase());
    }
    
    public void setState(final StateLike newState){
        this.myState = newState;
    }
    
    public void writeName(final String name){
        this.myState.writeName(this, name);
    }
}
