#include "my_robot_driver/my_robot_driver.hpp"
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/float64.hpp"

using std::placeholders:: _1;
using namespace std::chrono_literals;
class MotorDriver : public rclcpp::Node
{
    public:
        MotorDriver() : Node("Motor_Driver")
        {

            motor.init();
            Motor_Subscriber_ = this->create_subscription<example_interfaces::msg::Float64>(
            "/position_command", 10, std::bind(&MotorDriver::Subscriber_callback, this, std::placeholders::_1));
            Motor_Publisher_ = this->create_publisher<example_interfaces::msg::Float64>("/position_state", 10);
            number_timer_ = this->create_wall_timer(100ms,
                                                std::bind(&MotorDriver::Publisher_callback, this));

        }
    private:

        rclcpp::Publisher<example_interfaces::msg::Float64>::SharedPtr Motor_Publisher_;
        rclcpp::Subscription<example_interfaces::msg::Float64>::SharedPtr Motor_Subscriber_;
        rclcpp::TimerBase::SharedPtr number_timer_;
        Robot_Driver motor;
        void Subscriber_callback(const example_interfaces::msg::Float64::SharedPtr msg)
        {
            double pose = msg->data;
            RCLCPP_INFO(this->get_logger(), "Subscriber callback: %lf", pose);
            motor.writePosition (pose);

        }
        void Publisher_callback()
        {
            auto msg = example_interfaces::msg::Float64();
            
            msg.data = motor.readPosition();
            Motor_Publisher_ ->publish(msg);
            RCLCPP_INFO(this->get_logger(), "Publisher callback: %lf", msg.data);
        }


        // void Motor_Publisher_()
        // {
        //     auto msg = example_interfaces::msg::Float64();
        //     msg.data = motor->readPosition();
        //     Motor_Publisher_->publish(msg);

        // }
    
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MotorDriver>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
