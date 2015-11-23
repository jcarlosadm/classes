package interpreter.expression.imp;

import java.util.Map;

import interpreter.expression.Expression;

public class Minus implements Expression {

    private Expression leftOperand;
    private Expression rightOperand;
    
    public Minus(Expression left, Expression right) {
        this.leftOperand = left;
        this.rightOperand = right;
    }
    
    @Override
    public int interpret(Map<String, Expression> variables) {
        return this.leftOperand.interpret(variables) - this.rightOperand.interpret(variables);
    }

}
