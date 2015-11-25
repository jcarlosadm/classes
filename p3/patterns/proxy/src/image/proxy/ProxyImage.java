package image.proxy;

import image.Image;
import image.RealImage;

public class ProxyImage implements Image {

    private RealImage realImage;
    private String filename;
    
    public ProxyImage(String filename) {
        this.filename = filename;
    }
    
    @Override
    public void display() {
        if (this.realImage == null) {
            this.realImage = new RealImage(this.filename);
        }
        
        this.realImage.display();
    }

}
