package interpreter.expression.imp;

import java.util.Map;

import interpreter.expression.Expression;

public class Plus implements Expression {

    private Expression leftOperand;
    private Expression rightOperand;
    
    public Plus(Expression left, Expression right) {
        this.leftOperand = left;
        this.rightOperand = right;
    }
    
    @Override
    public int interpret(Map<String, Expression> variables) {
        return this.leftOperand.interpret(variables) + rightOperand.interpret(variables);
    }

}
