package element;

import visitor.ICarElementVisitor;

public interface ICarElement {
    void accept(ICarElementVisitor visitor);
}
