package state;

import test.StateContext;

public interface StateLike {
    void writeName(StateContext context, String name);
}
