package adapter;

import mediaplayer.MediaPlayer;

public class AudioPlayer implements MediaPlayer {

    private MediaAdapter mediaAdapter;

    @Override
    public void play(String audioType, String filename) {
        if (audioType.equalsIgnoreCase("mp3")) {
            System.out.println("Playing mp3 file. Name: " + filename);
        } else if (audioType.equalsIgnoreCase("vlc") || audioType.equalsIgnoreCase("mp4")) {
            this.mediaAdapter = new MediaAdapter(audioType);
            this.mediaAdapter.play(audioType, filename);
        } else {
            System.out.println("Invalid Media. " + audioType + " format not supported");
        }
    }

}
