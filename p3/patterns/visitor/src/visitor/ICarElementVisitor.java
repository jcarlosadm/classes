package visitor;

import element.Body;
import element.Car;
import element.Engine;
import element.Wheel;

public interface ICarElementVisitor {
    void visit(Wheel wheel);
    void visit(Engine engine);
    void visit(Body body);
    void visit(Car car);
}
