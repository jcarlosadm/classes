package shape;

public class Circle extends Shape {

    public Circle() {
        this.type = "Circle";
    }
    
    @Override
    public void draw() {
        System.out.println("Inside Circle::draw() method");
    }

}
