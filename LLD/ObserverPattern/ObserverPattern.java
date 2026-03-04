package ObserverPattern;

import java.util.*;

// observer interface
interface Subscriber {
    void update(String videoTitle);
}

// concrete observer -- Email
class EmailSubscriber implements Subscriber {
    private String email;

    public EmailSubscriber(String email) {
        this.email = email;
    }

    @Override
    public void update(String videoTitle) {
        System.out.println("Email notification sent to " + email + " : New video uploaded -- " + videoTitle);
    }
}

// concrete observer -- in app
class InAppSubscriber implements Subscriber {
    private String userName;

    public InAppSubscriber(String userName) {
        this.userName = userName;
    }

    @Override
    public void update(String videoTitle) {
        System.out.println("In App notification sent to " + userName + " : New video uploaded -- " + videoTitle);
    }
}

// subject interface
interface Channel {
    void subscribe(Subscriber subscriber);

    void unsubscribe(Subscriber subscriber);

    void sendNotification(String videoTitle);
}

// concrete subject -- Youtube channel
class YoutubeChannel implements Channel {
    private String channelName;
    private List<Subscriber> subscribers = new ArrayList<>();

    public YoutubeChannel(String channelName) {
        this.channelName = channelName;
    }

    @Override
    public void subscribe(Subscriber subscriber) {
        subscribers.add(subscriber);
    }

    @Override
    public void unsubscribe(Subscriber subscriber) {
        subscribers.remove(subscriber);
    }

    @Override
    public void sendNotification(String videoTitle) {
        for (Subscriber subscriber : subscribers) {
            subscriber.update(videoTitle);
        }
    }

    public void uploadVideo(String videoTitle) {
        System.out.println(channelName + " uploaded new video -- " + videoTitle);
        sendNotification(videoTitle);
    }
}

class ObserverPattern {
    public static void main(String[] args) {
        YoutubeChannel tuf = new YoutubeChannel("take you forward");

        tuf.subscribe(new InAppSubscriber("nilava"));
        tuf.subscribe(new InAppSubscriber("panda"));
        tuf.subscribe(new EmailSubscriber("nilavastnd@gmail.com"));

        tuf.uploadVideo("observer-pattern");
    }
}