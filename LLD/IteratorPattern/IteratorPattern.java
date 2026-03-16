package IteratorPattern;

import java.util.*;

// ========== Video class representing a single video ==========
class Video {
    String title;

    public Video(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

// ========== Iterator interface (defines traversal contract) ==========
interface PlaylistIterator {
    boolean hasNext(); // Checks if more elements are left

    Video next(); // Returns the next element
}

// ========== Concrete Iterator class ==========
// Implements the actual logic for traversing the Playlist
class ForwardPlaylistIterator implements PlaylistIterator {
    private final List<Video> videos;
    private int position;

    // Constructor takes the list to iterate on
    public ForwardPlaylistIterator(List<Video> videos) {
        this.videos = videos;
        position = 0;
    }

    // Check if more videos are left to iterate
    @Override
    public boolean hasNext() {
        return position < videos.size();
    }

    // Return the next video in sequence
    @Override
    public Video next() {
        return hasNext() ? videos.get(position++) : null;
    }
}

// ========== Concrete Iterator class ==========
// Implements the actual logic for traversing the Playlist in reverse
// order
class ReversePlaylistIterator implements PlaylistIterator {
    private final List<Video> videos;
    private int position;

    public ReversePlaylistIterator(List<Video> videos) {
        this.videos = videos;
        position = videos.size() - 1;
    }

    @Override
    public boolean hasNext() {
        return position >= 0;
    }

    @Override
    public Video next() {
        return hasNext() ? videos.get(position--) : null;
    }
}

// ========== Concrete Iterator class ==========
// Implements the actual logic for traversing the Playlist in random
// order
class RandomPlaylistIterator implements PlaylistIterator {
    private final List<Video> shuffledVideos;
    private int position;

    public RandomPlaylistIterator(List<Video> videos) {
        shuffledVideos = new ArrayList<>(videos);
        Collections.shuffle(shuffledVideos);
        position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < shuffledVideos.size();
    }

    @Override
    public Video next() {
        return hasNext() ? shuffledVideos.get(position++) : null;
    }
}

// ================ Playlist interface ================
// (acts as a contract for collections that are iterable)
interface Playlist {
    // Method to return an iterator for the collection
    PlaylistIterator createForwardIterator();

    // Method to return an reverse order iterator
    PlaylistIterator createReverseIterator();

    // Method to return an random order iterator
    PlaylistIterator createRandomIterator();
}

// ========== YouTubePlaylist class (Aggregate) ==========
// Implements Playlist to guarantee it provides an iterator
class YoutubePlaylist implements Playlist {
    private final List<Video> videos = new ArrayList<>();

    // Method to add video to playlist
    public void addVideo(Video video) {
        videos.add(video);
    }

    // Instead of exposing the list, return an forward iterator
    @Override
    public PlaylistIterator createForwardIterator() {
        return new ForwardPlaylistIterator(videos);
    }

    // Instead of exposing the list, return an reverse iterator
    @Override
    public PlaylistIterator createReverseIterator() {
        return new ReversePlaylistIterator(videos);
    }

    // Instead of exposing the list, return an random iterator
    @Override
    public PlaylistIterator createRandomIterator() {
        return new RandomPlaylistIterator(videos);
    }
}

// ========== Main method (Client code) ==========
public class IteratorPattern {
    public static void main(String[] args) {
        // Create a playlist and add videos to it
        YoutubePlaylist playlist = new YoutubePlaylist();
        playlist.addVideo(new Video("LLD tutorial"));
        playlist.addVideo(new Video("System design basics"));
        playlist.addVideo(new Video("Iterator pattern video"));
        playlist.addVideo(new Video("Singleton Pattern video"));

        System.out.println("Forward Order:");
        // Client simply asks for an iterator — no access to internal data structure
        PlaylistIterator iterator = playlist.createForwardIterator();

        // Iterate through the playlist using the provided interface
        while (iterator.hasNext()) {
            System.out.println(iterator.next().getTitle());
        }

        System.out.println("\nReverse Order:");
        PlaylistIterator reverseIterator = playlist.createReverseIterator();
        while (reverseIterator.hasNext()) {
            System.out.println(reverseIterator.next().getTitle());
        }

        System.out.println("\nRandom Order:");
        PlaylistIterator randomIterator = playlist.createRandomIterator();
        while (randomIterator.hasNext()) {
            System.out.println(randomIterator.next().getTitle());
        }
    }
}

/*
 * Client
 * |
 * v
 * PlaylistIterator
 * |
 * v
 * ForwardPlaylistIterator
 * |
 * v
 * YoutubePlaylist
 * |
 * v
 * List<Video>
 */