class RiderInterface
{
public:
    virtual void bookRide() = 0;
    virtual void rateDriver() = 0;
    virtual ~RiderInterface() = default;
};

class DriverInterface
{
public:
    virtual void acceptRide() = 0;
    virtual void trackEarnings() = 0;
    virtual void ratePassenger() = 0;
    virtual ~DriverInterface() = default;
};

class Rider : public RiderInterface
{
public:
    void bookRide() override { /* yes */ }
    void rateDriver() override { /* yes */ }
};

class Driver : public DriverInterface
{
public:
    void acceptRide() override { /* yes */ }
    void trackEarnings() override { /* yes */ }
    void ratePassenger() override { /* yes */ }
};
