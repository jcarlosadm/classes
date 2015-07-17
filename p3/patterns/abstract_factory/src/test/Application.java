package test;

import factory.GUIFactory;
import product.Button;
import product.Label;

public class Application {
    public Application(GUIFactory factory) {
        Button button = factory.createButton();
        Label label = factory.createLabel();
        button.paint();
        label.paint();
    }
}
