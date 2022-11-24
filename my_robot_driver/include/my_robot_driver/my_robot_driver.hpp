#ifndef MY_DRIVER_HPP
#define MY_DRIVER_HPP

#define SUCCEEDED 1
#define FAILED 0 
const int DXL_MOTOR_ID_LEFT = 1; // ID of left motor
const int DXL_MOTOR_ID_RIGHT = 2; 
double torque = 20.0;

class Robot_Driver 
{
public:
    Robot_Driver() {
        position_command_ = 0.0;
        position_state_ = 0.0;

    }

    void init() {
        // Init communication with hardware
        left_wheel_id_(DXL_MOTOR_ID_LEFT);
        right_wheel_id_(DXL_MOTOR_ID_RIGHT);
        
    }

    double readPosition() {
        // Read data (state) from hardware
        // For simulation purpose, as we don't have hardware, 
        // we just "loop back" the command into the position
        position_state_ = position_command_;
        return position_state_;
    }

    int left_wheel_id_(int left_motor_ID)
    {
        if(left_motor_ID)
        {
            return SUCCEEDED;
        }
        return FAILED;
    }

    int right_wheel_id_(int right_motor_ID)
    {
        if(right_motor_ID)
        {
            return SUCCEEDED;
        }
        return FAILED;
    }

    void writePosition(double cmd) {
        // Write data (command) to hardware
        position_command_ = cmd;
    }

    double getTorque()
    {
        if (DXL_MOTOR_ID_LEFT && DXL_MOTOR_ID_RIGHT)
        return torque;
    }

private:
    double position_command_;
    double position_state_;
};

#endif