package test;

import visitor.CarElementDoVisitor;
import visitor.CarElementPrintVisitor;
import element.Car;
import element.ICarElement;

public class TestVisitor {
    public static void main(String[] args) {
        ICarElement car = new Car();
        
        car.accept(new CarElementPrintVisitor());
        car.accept(new CarElementDoVisitor());
    }
}
