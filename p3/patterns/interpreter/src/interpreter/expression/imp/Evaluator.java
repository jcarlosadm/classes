package interpreter.expression.imp;

import java.util.Map;
import java.util.Stack;

import interpreter.expression.Expression;

public class Evaluator implements Expression {

    private Expression syntaxTree;

    public Evaluator(String expression) {
        // TODO Auto-generated constructor stub

        Stack<Expression> expressionStack = new Stack<Expression>();
        for (String token : expression.split(" ")) {
            if (token.equals("+")) {
                Expression subexpression = new Plus(expressionStack.pop(), expressionStack.pop());
                expressionStack.push(subexpression);
            } else if (token.equals("-")) {
                Expression right = expressionStack.pop();
                Expression left = expressionStack.pop();
                Expression subexpression = new Minus(left, right);
                expressionStack.push(subexpression);
            } else {
                expressionStack.push(new Variable(token));
            }
        }
        
        syntaxTree = expressionStack.pop();
    }

    @Override
    public int interpret(Map<String, Expression> context) {
        return this.syntaxTree.interpret(context);
    }

}
