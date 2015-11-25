package adapter;

import mediaplayer.AdvancedMediaPlayer;
import mediaplayer.MediaPlayer;
import mediaplayer.Mp4Player;
import mediaplayer.VlcPlayer;

public class MediaAdapter implements MediaPlayer {

    private AdvancedMediaPlayer advancedMediaPlayer;

    public MediaAdapter(String audioType) {
        if (audioType.equalsIgnoreCase("vlc")) {
            this.advancedMediaPlayer = new VlcPlayer();
        } else if (audioType.equalsIgnoreCase("mp4")) {
            this.advancedMediaPlayer = new Mp4Player();
        }
    }

    @Override
    public void play(String audioType, String filename) {
        if (audioType.equalsIgnoreCase("vlc")) {
            this.advancedMediaPlayer.playVlc(filename);
        } else if (audioType.equalsIgnoreCase("mp4")){
            this.advancedMediaPlayer.playMp4(filename);
        }
    }

}
