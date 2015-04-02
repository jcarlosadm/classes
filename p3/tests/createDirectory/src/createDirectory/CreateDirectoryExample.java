package createDirectory;

import java.io.File;

public class CreateDirectoryExample
{
    public static void main(String[] args)
    {   
    File file = new File("Directory1");
    if (!file.exists()) {
        if (file.mkdir()) {
            System.out.println("Directory is created!");
        } else {
            System.out.println("Failed to create directory!");
        }
    }else{
        System.out.println("directory exists!");
    }
 
    File files = new File("Directory2/Sub2/Sub-Sub2");
    if (!files.exists()) {
        if (files.mkdirs()) {
            System.out.println("Multiple directories are created!");
        } else {
            System.out.println("Failed to create multiple directories!");
        }
    }else{
        System.out.println("directorys exists!");
    }
 
    }
}
