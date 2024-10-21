#include <iostream>
#include <string>
int emailACK = 0, smsACK = 0;
// OrderNotifier interface
class OrderNotifier
{
public:
    virtual ~OrderNotifier() = default;
    virtual void notify(const std::string& message) const = 0;
};

// Concrete Strategy for Email Notification
class EmailNotifier : public OrderNotifier
{
public:
    void notify(const std::string& message) const override
    {
        std::cout << "Sending Email: " << message << std::endl;
        emailACK = 1;
    }
};

// Concrete Strategy for SMS Notification
class SMSNotifier : public OrderNotifier
{
public:
    void notify(const std::string& message) const override
    {
        std::cout << "Sending SMS: " << message << std::endl;
        smsACK = 1;
    }
};

// Concrete Strategy for WhatsApp Notification
class WhatsAppNotifier : public OrderNotifier
{
public:
    void notify(const std::string& message) const override
    {
        std::cout << "Sending WhatsApp message: " << message << std::endl;
    }
};

// Context class
class Order
{
private:
    OrderNotifier* notifier;
    std::string message;

public:
    Order(const std::string& message)
        : notifier(nullptr), message(message) {}

    ~Order() {
        delete notifier;
    }

    void setNotifier(OrderNotifier* newNotifier)
    {
        delete notifier;
        notifier = newNotifier;
    }

    void notifyCustomer() const {
        if (notifier)
            notifier->notify(message);
    }
};

int main()
{
    int sendTimer = 5;
    // Create an Order with EmailNotifier
    Order order1("Your order has been placed.");
    order1.setNotifier(new EmailNotifier());
    order1.notifyCustomer();

    if (!emailACK)
    {
        // Change the notification method to SMSNotifier
        order1.setNotifier(new SMSNotifier());
        order1.notifyCustomer();
    }

    if (sendTimer > 4)
    {
        // Change the notification method to WhatsAppNotifier
        order1.setNotifier(new WhatsAppNotifier());
        order1.notifyCustomer();
    }


    return 0;
}
