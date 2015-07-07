package state;

import test.StateContext;

public class StateLowerCase implements StateLike {

    @Override
    public void writeName(final StateContext context, String name) {
        System.out.println(name.toLowerCase());
        context.setState(new StateMultipleUpperCase());
    }

}
