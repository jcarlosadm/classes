package bridge.example;

import bridge.example.abstraction.Circle;
import bridge.example.abstraction.Shape;
import bridge.example.implement.GreenCircle;
import bridge.example.implement.RedCircle;

/**
 * http://www.tutorialspoint.com/design_pattern/bridge_pattern.htm
 *
 */
public class BridgePatternDemo {

    public static void main(String[] args) {
        Shape circle = new Circle(100, 100, 10, new RedCircle());
        
        circle.draw();
        
        circle.switchColor(new GreenCircle());
        
        circle.draw();
    }
}
