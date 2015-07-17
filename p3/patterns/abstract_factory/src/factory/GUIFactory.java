package factory;

import product.Button;
import product.Label;

public interface GUIFactory {
    Button createButton();
    Label createLabel();
}
