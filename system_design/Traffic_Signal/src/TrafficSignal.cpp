#include "TrafficSignal.hpp"
#include <iostream>

TrafficSignal::TrafficSignal(std::string signalId, int greenDuration, int yellowDuration, int redDuration)
    : signalId(signalId), currentColor(SignalColor::RED),
      greenDuration(greenDuration), yellowDuration(yellowDuration), redDuration(redDuration),
      isWorking(true)
{
    reset();
}

std::string TrafficSignal::getSignalId() const { return signalId; }
SignalColor TrafficSignal::getCurrentColor() const { return currentColor; }
int TrafficSignal::getTimeRemaining() const { return timeRemaining; }
bool TrafficSignal::isOperational() const { return isWorking; }

void TrafficSignal::setDurations(int green, int yellow, int red)
{
    greenDuration = green;
    yellowDuration = yellow;
    redDuration = red;
    reset();
}

void TrafficSignal::updateSignal(int timeElapsed)
{
    if (!isWorking)
        return;

    timeRemaining -= timeElapsed;
    if (timeRemaining <= 0)
    {
        switchColor();
    }
}

void TrafficSignal::switchColor()
{
    switch (currentColor)
    {
    case SignalColor::RED:
        currentColor = SignalColor::GREEN;
        timeRemaining = greenDuration;
        break;
    case SignalColor::GREEN:
        currentColor = SignalColor::YELLOW;
        timeRemaining = yellowDuration;
        break;
    case SignalColor::YELLOW:
        currentColor = SignalColor::RED;
        timeRemaining = redDuration;
        break;
    }
}

void TrafficSignal::setWorking(bool status)
{
    isWorking = status;
}

void TrafficSignal::reset()
{
    currentColor = SignalColor::RED;
    timeRemaining = redDuration;
}

void TrafficSignal::displayStatus() const
{
    std::cout << "Signal " << signalId << ": ";
    std::cout << "Color = ";
    switch (currentColor)
    {
    case SignalColor::RED:
        std::cout << "RED";
        break;
    case SignalColor::YELLOW:
        std::cout << "YELLOW";
        break;
    case SignalColor::GREEN:
        std::cout << "GREEN";
        break;
    }
    std::cout << ", Time Remaining: " << timeRemaining << "s";
    std::cout << ", Status: " << (isWorking ? "Working" : "Not Working") << std::endl;
}