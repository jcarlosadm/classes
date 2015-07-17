package factory;

import product.Button;
import product.Label;
import product.WinButton;
import product.WinLabel;

public class WinFactory implements GUIFactory {

    @Override
    public Button createButton() {
        return new WinButton();
    }

    @Override
    public Label createLabel() {
        return new WinLabel();
    }

}
