package mediaplayer;

public class Mp4Player implements AdvancedMediaPlayer {

    @Override
    public void playVlc(String filename) {
    }

    @Override
    public void playMp4(String filename) {
        System.out.println("Playing mp4 file. Name: " + filename);
    }

}
