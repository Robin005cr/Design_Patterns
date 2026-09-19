/*
 * project   : https://github.com/Robin005cr/Design_Patterns
 * file name : FallbackPattern.cpp
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
#include <iostream>
#include <stdexcept>

struct WheelData
{
    float wheelSpeed;
};

struct IMUInclination
{
    float pitch;
};

class Slip_Rollback_Detector
{
public:
    bool detect()
    {
        try
        {
            // Priority 1: Wheel data
            WheelData wheelData = getWheelData();

            std::cout << "Using WheelData\n";

            return detectUsingWheelData(wheelData);
        }
        catch (const std::exception &e)
        {
            std::cout << "WheelData unavailable: "
                      << e.what() << '\n';

            try
            {
                // Fallback: IMU inclination
                IMUInclination imuData = getIMUInclination();

                std::cout << "Using IMU Inclination as fallback\n";

                return detectUsingIMU(imuData);
            }
            catch (const std::exception &e)
            {
                std::cout << "IMU data unavailable: "
                          << e.what() << '\n';

                // No valid data source
                return false;
            }
        }
    }

private:
    WheelData getWheelData()
    {
        // Simulate wheel data failure
        throw std::runtime_error("Wheel sensor data timeout");
    }

    IMUInclination getIMUInclination()
    {
        // Simulate valid IMU data
        return {5.5f};
    }

    bool detectUsingWheelData(const WheelData &data)
    {
        // Example logic
        return data.wheelSpeed < 0.5f;
    }

    bool detectUsingIMU(const IMUInclination &data)
    {
        // Example rollback detection using vehicle pitch
        return data.pitch > 5.0f;
    }
};

int main()
{
    Slip_Rollback_Detector detector;

    bool rollback = detector.detect();

    if (rollback)
        std::cout << "Rollback detected\n";
    else
        std::cout << "No rollback detected\n";

    return 0;
}