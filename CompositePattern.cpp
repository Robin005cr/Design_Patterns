/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : CompositePattern.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <numeric>
#include <stdexcept>

// ---- Component ----
class HomeComponent
{
public:
    virtual ~HomeComponent() = default;

    virtual std::string getName() const = 0;
    virtual double getPowerConsumption() const = 0; // in watts
    virtual void turnOffAllDevices() = 0;
    virtual void print(int depth = 0) const = 0;

    // Composite-only operations. Default behavior for leaves.
    virtual void add(std::shared_ptr<HomeComponent> child)
    {
        throw std::logic_error(getName() + " cannot have children");
    }
    virtual void remove(const std::shared_ptr<HomeComponent> &child)
    {
        throw std::logic_error(getName() + " cannot have children");
    }
};

// ---- Leaf ----
class Room : public HomeComponent
{
    std::string name_;
    double devicePower_; // simplistic: total wattage of devices in this room
    bool devicesOn_ = true;

public:
    Room(std::string name, double devicePower)
        : name_(std::move(name)), devicePower_(devicePower) {}

    std::string getName() const override { return name_; }

    double getPowerConsumption() const override
    {
        return devicesOn_ ? devicePower_ : 0.0;
    }

    void turnOffAllDevices() override { devicesOn_ = false; }

    void print(int depth = 0) const override
    {
        std::cout << std::string(depth * 2, ' ')
                  << "- Room: " << name_
                  << " (" << getPowerConsumption() << "W)\n";
    }
};

// ---- Composite ----
class Floor : public HomeComponent
{
    std::string name_;
    std::vector<std::shared_ptr<HomeComponent>> children_;

public:
    explicit Floor(std::string name) : name_(std::move(name)) {}

    std::string getName() const override { return name_; }

    void add(std::shared_ptr<HomeComponent> child) override
    {
        children_.push_back(std::move(child));
    }

    void remove(const std::shared_ptr<HomeComponent> &child) override
    {
        children_.erase(
            std::remove(children_.begin(), children_.end(), child),
            children_.end());
    }

    double getPowerConsumption() const override
    {
        double total = 0.0;
        for (const auto &c : children_)
            total += c->getPowerConsumption();
        return total;
    }

    void turnOffAllDevices() override
    {
        for (auto &c : children_)
            c->turnOffAllDevices();
    }

    void print(int depth = 0) const override
    {
        std::cout << std::string(depth * 2, ' ')
                  << "+ Floor: " << name_
                  << " (" << getPowerConsumption() << "W total)\n";
        for (const auto &c : children_)
            c->print(depth + 1);
    }
};

// Home is structurally identical to Floor — still worth a distinct type
// for semantic clarity and any home-only behavior later (e.g. security mode).
class Home : public Floor
{
public:
    explicit Home(std::string name) : Floor(std::move(name)) {}
};

// ---- Client ----
class SmartHomeController
{
    std::shared_ptr<HomeComponent> root_;

public:
    explicit SmartHomeController(std::shared_ptr<HomeComponent> root)
        : root_(std::move(root)) {}

    void reportUsage() const
    {
        std::cout << "Total power draw: "
                  << root_->getPowerConsumption() << "W\n";
    }

    void nightMode()
    {
        std::cout << "Turning off all devices for the night...\n";
        root_->turnOffAllDevices();
    }

    void printTree() const { root_->print(); }
};

int main()
{
    auto livingRoom = std::make_shared<Room>("Living Room", 250.0);
    auto kitchen = std::make_shared<Room>("Kitchen", 400.0);
    auto bedroom = std::make_shared<Room>("Bedroom", 100.0);

    auto groundFloor = std::make_shared<Floor>("Ground Floor");
    groundFloor->add(livingRoom);
    groundFloor->add(kitchen);

    auto firstFloor = std::make_shared<Floor>("First Floor");
    firstFloor->add(bedroom);

    auto home = std::make_shared<Home>("My Home");
    home->add(groundFloor);
    home->add(firstFloor);

    SmartHomeController controller(home);
    controller.printTree();
    controller.reportUsage();
    controller.nightMode();
    controller.reportUsage();
}