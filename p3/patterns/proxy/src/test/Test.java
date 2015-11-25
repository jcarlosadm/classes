package test;

import image.Image;
import image.proxy.ProxyImage;

public class Test {
    public static void main(String[] args) {
        Image image = new ProxyImage("test.jpg");
        
        image.display();
        System.out.println("");
        
        image.display();
    }
}
