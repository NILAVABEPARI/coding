#include <bits/stdc++.h>
using namespace std;

class rectangle
{
protected:
    int height, width;

public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getArea()
    {
        return height * width;
    }
};

class square : public rectangle
{
public:
    void setWidth(int w) override
    {
        width = w;
        height = w;
    }

    void setHeight(int h) override
    {
        width = h;
        height = h;
    }
};

void printArea(rectangle *r)
{
    r->setWidth(5);
    r->setHeight(10);
    cout << r->getArea() << endl;
}

int main()
{
    rectangle *r = new square();
    printArea(r);
    delete r;
    return 0;
}

#include <iostream>
using namespace std;

// Notification class
class Notification
{
public:
    // method implementing send notification functionality
    virtual void sendNotification()
    {
        cout << "Notification sent" << endl;
    }

    // virtual destructor to ensure proper cleanup in polymorphic base class
    virtual ~Notification() {}
};

// Subclass of Notification class for Email Notification
class EmailNotification : public Notification
{
public:
    void sendNotification() override
    {
        cout << "Email Notification sent" << endl;
    }
};

// Subclass of Notification class for Text Notification
class TextNotification : public Notification
{
public:
    void sendNotification() override
    {
        cout << "Text Notification sent" << endl;
    }
};

// Main class
int main()
{
    /* Replaced the Notification class object
    with one of its subclass' objects */
    Notification *notification = new EmailNotification();

    // Working code on the notification object
    notification->sendNotification();

    delete notification;
    return 0;
}
