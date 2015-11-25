package image;

public class RealImage implements Image {

    private String filename;
    
    public RealImage(String filename) {
        this.filename = filename;
        this.loadFromDisk(filename);
    }
    
    @Override
    public void display() {
        System.out.println("Displaying "+this.filename);
    }
    
    private void loadFromDisk(String filename){
        System.out.println("Loading "+filename);
    }

}
