// Implementor Interface
interface VideoQuality {
    void load(String title);
}

// Concrete Implementor
class SDQuality implements VideoQuality {
    @Override
    public void load(String title) {
        System.out.println("Streaming " + title + " in SD Quality");
    }
}

// Concrete Implementor
class HDQuality implements VideoQuality {
    @Override
    public void load(String title) {
        System.out.println("Streaming " + title + " in HD Quality");
    }
}

// Concrete Implementor
class UHDQuality implements VideoQuality {
    @Override
    public void load(String title) {
        System.out.println("Streaming " + title + " in UHD Quality");
    }
}

// Abstraction
abstract class VideoPlayer {
    protected VideoQuality quality;

    public VideoPlayer(VideoQuality quality) {
        this.quality = quality;
    }

    public abstract void play(String title);
}

// Refined Abstraction
class WebPlayer extends VideoPlayer {
    public WebPlayer(VideoQuality quality) {
        super(quality);
    }

    @Override
    public void play(String title) {
        System.out.println("Web Platform");
        quality.load(title);
    }
}

// Refined Abstraction
class MobilePlayer extends VideoPlayer {
    public MobilePlayer(VideoQuality quality) {
        super(quality);
    }

    @Override
    public void play(String title) {
        System.out.println("Mobile Platform");
        quality.load(title);
    }
}

public class BridgePattern {
    public static void main(String[] args) {
        VideoPlayer player1 = new WebPlayer(new HDQuality());
        player1.play("Interstellar");

        VideoPlayer player2 = new MobilePlayer(new UHDQuality());
        player2.play("Inception");

        VideoPlayer player3 = new WebPlayer(new SDQuality());
        player3.play("Titanic");

    }
}
