# IR2117 - Robot Programming and Simulation

This repository contains a collection of practical exercises developed as part of the **IR2117 - Robot Programming and Simulation** course, a compulsory subject from the 2nd year of the **Bachelor’s Degree in Robotic Intelligence** at Universitat Jaume I.

The course focuses on the fundamentals of **robot middleware** and **simulation tools**, with a strong emphasis on the Robot Operating System (**ROS**) and simulators like **Gazebo** and **Webots**.

## 🔧 Technologies Used

- **ROS 1 (Noetic)**
- **Gazebo**
- **Webots**
- **Turtlesim**
- **C++ / Python**

## 📚 Learning Objectives

Through these exercises, I gained hands-on experience in:
- Robot control and motion planning
- Parameterization and time-based control
- Obstacle detection and avoidance
- Developing ROS services and actions
- Using simulation environments to test robot behaviors
- Integrating teleoperation and autonomous behaviors

---

## 🧪 Main Exercises

### 1. **Square Challenge**
Implemented square path execution using:
- **Turtlesim** and **Gazebo**
- ROS parameters and time-controlled movement
- Both basic and parameterized versions

### 2. **Wandering Challenge**
- Obstacle detection and teleoperation in:
  - Gazebo
  - Webots (via a single launch file)
  - TurtleBot 3 in simulation
- Full pipeline for autonomous wandering behavior and avoidance

### 3. **ROS Services – Olympic Rings**
Developed a service-based architecture to draw the Olympic rings in `turtlesim`:
- Created a `rings` node publishing on `/turtle1/cmd_vel`
- Used parameters for circle radius
- Integrated `setpen`, `teleport_absolute`, and `teleport_relative` services
- Drew five colored circles using a loop

### 4. **ROS Actions – Olympic Rings**
Built on the previous exercise with a ROS action interface:
- Defined a custom `rings` action in the `olympic_interfaces` package
- Created `rings_action_server` and `rings_action_client` nodes
- Reused drawing logic from the service-based version
- Implemented real-time feedback and success acknowledgment

---

## 🧠 Skills Demonstrated

- Proficiency in ROS core concepts: nodes, topics, services, actions, parameters
- Autonomous and reactive robot behaviors in simulation
- Structured and modular ROS package development
- Use of simulators for prototyping and testing robotic systems

## 📘 References
The development of these exercises was supported by materials from the following books:
- *Programming Robots with ROS* – Quigley, Gerkey, Smart
- *ROS Robotics Projects* – Lentin Joseph
- *Robot Operating System Cookbook* – Kumar Bipin
- *A Concise Introduction to Robot Programming with ROS2* – Martín-Rico

## 👨‍🏫 Instructor
- Enric Cervera Mateu [![GitHub](https://img.shields.io/badge/GitHub-ecervera-black?logo=github)](https://github.com/ecervera)

- Jorge Sales [![GitHub](https://img.shields.io/badge/GitHub-jorgesales-black?logo=github)](https://github.com/jorgesales)

---

## 🧾 Course Summary
> “This subject presents a series of fundamental tools to design and integrate robotic systems through middleware like ROS and simulation tools like Gazebo and Webots.”

---

Feel free to explore each folder for source code and simulation files related to the specific exercises!

