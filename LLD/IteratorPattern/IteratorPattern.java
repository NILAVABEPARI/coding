package IteratorPattern;
import java.util.*;

class Video {
    String title;
    public Video(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

interface Playlist {
    PlaylistIterator createIterator();
}

class YoutubePlaylist implements Playlist{
    private List<Video> videos = new ArrayList<>();

    public void addVideo(Video video) {
        videos.add(video);
    }

    @Override
    public PlaylistIterator createIterator() {
        return new YoutubePlaylistIterator(videos);
    }
}

interface PlaylistIterator {
    boolean hasNext();
    Video next();
}

class YoutubePlaylistIterator implements PlaylistIterator {
    private List<Video> videos;
    private int position;

    public YoutubePlaylistIterator(List<Video> videos) {
        this.videos = videos;
        position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < videos.size();
    }

    @Override
    public Video next() {
        return hasNext() ? videos.get(position++) : null;
    }
}

public class IteratorPattern {
    public static void main(String[] args) {
        YoutubePlaylist playlist = new YoutubePlaylist();
        playlist.addVideo(new Video("LLD tutorial"));
        playlist.addVideo(new Video("System design basics"));

        PlaylistIterator iterator = playlist.createIterator();

        while(iterator.hasNext()) {
            System.out.println(iterator.next().getTitle());
        }
    }
}
