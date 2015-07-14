package element;

import visitor.ICarElementVisitor;

public class Car implements ICarElement {

    ICarElement[] elements;
    
    public Car() {
        this.elements = new ICarElement[] {
                new Wheel("front left"),new Wheel("front right"),
                new Wheel("back left"), new Wheel("back right"),
                new Body(), new Engine() };
    }
    
    @Override
    public void accept(ICarElementVisitor visitor) {
        for (ICarElement iCarElement : elements) {
            iCarElement.accept(visitor);
        }
        
        visitor.visit(this);
    }

}
