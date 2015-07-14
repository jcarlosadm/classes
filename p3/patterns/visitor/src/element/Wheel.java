package element;

import visitor.ICarElementVisitor;

public class Wheel implements ICarElement {

    private String name;
    
    public Wheel(String name) {
        this.name = name;
    }
    
    public String getName(){
        return this.name;
    }
    
    @Override
    public void accept(ICarElementVisitor visitor) {
        visitor.visit(this);
    }

}
