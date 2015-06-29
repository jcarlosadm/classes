package bridge.example;

import bridge.example.abstraction.Circle;
import bridge.example.abstraction.Shape;
import bridge.example.implement.GreenShape;
import bridge.example.implement.RedShape;

/**
 * http://www.tutorialspoint.com/design_pattern/bridge_pattern.htm
 *
 */
public class BridgePatternDemo {

    public static void main(String[] args) {
        Shape circle = new Circle(100, 100, 10, new RedShape());
        
        circle.draw();
        
        circle.switchColor(new GreenShape());
        
        circle.draw();
    }
}
