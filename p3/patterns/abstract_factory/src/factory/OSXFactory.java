package factory;

import product.Button;
import product.Label;
import product.OSXButton;
import product.OSXLabel;

public class OSXFactory implements GUIFactory {

    @Override
    public Button createButton() {
        return new OSXButton();
    }

    @Override
    public Label createLabel() {
        return new OSXLabel();
    }

}
