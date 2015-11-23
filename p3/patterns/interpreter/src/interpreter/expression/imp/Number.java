package interpreter.expression.imp;

import java.util.Map;

import interpreter.expression.Expression;

public class Number implements Expression {

    private int number;
    
    public Number(int number) {
        this.number = number;
    }
    
    @Override
    public int interpret(Map<String, Expression> variables) {
        return this.number;
    }

}
