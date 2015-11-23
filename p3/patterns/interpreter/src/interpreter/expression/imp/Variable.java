package interpreter.expression.imp;

import java.util.Map;

import interpreter.expression.Expression;

public class Variable implements Expression {

    private String name;
    
    public Variable(String name) {
        this.name = name;
    }
    
    @Override
    public int interpret(Map<String, Expression> variables) {
        if (null == variables.get(this.name)) {
            return 0;
        }
        
        return variables.get(name).interpret(variables);
    }

}
