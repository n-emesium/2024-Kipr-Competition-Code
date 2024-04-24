#include <kipr/wombat.h>

//Ege Fuat Eskisar

//Create Robot

void drive(int distance); //drives straight for a set distance;
void follow_line(); //follows line until it hits the digital sensor;
void open_claw();
void close_claw();
void move_arm(int n);
void turn(int n);
void reset_servos();
void track_color(int channel, int object_no);
int main () {
//shut_down_in(1);
create_connect();
    enable_servos();
   
    /*
    reset_servos();
    create_drive_direct(100,100);
    msleep(1000);
    */
   
   
   
    //Digital Lever is Port 0;
//Servo Port 3 is Arm
//Servo Port 0 is Claw
   
    /*turn(30);
    drive(830);
    turn(-80);
    move_arm(2000);
    turn(-10);
    camera_open();*/
   
    //drive(500);
   
   
    track_color(0,0);
   
    /*
    open_claw();
    //move a little here
    //drive(arbitrarily small number);
    close_claw();
    */
   
    camera_close();
   
disable_servos();
create_disconnect();
return 0;
}

void drive(int distance) {
set_create_distance(0);
while (get_create_distance() < distance) {
create_drive_direct(200,200);
}
create_stop();
}

void follow_line() {
const int vel = 250;
int val = get_create_rcliff_amt(); //base sensor value;
while (get_create_rbump() == 0 && get_create_lbump() == 0 && digital(0) == 0) { //check bounds
if (get_create_lcliff_amt() < val) {
create_drive_direct(0.25 * vel, vel);
} else {
create_drive_direct(vel, 0.25 * vel);
}
}
create_stop();
}
//servo port 0 is for the claw value;
//0 is for open
//1000 is for closed
//command name: set_servo_position(#servo port, #position coordinate);
void open_claw() {
    set_servo_position(0,0);
    msleep(1000);
}


void close_claw () {
    set_servo_position(0,900);
    msleep(1000);
}

void move_arm(int n) {
    set_servo_position(3,n);
    msleep(1000);
}

void turn(int n) {
    set_create_total_angle(0);
    if (n > 0) { //turn right
        while (get_create_total_angle() > -n) {  
        create_drive_direct(100,-100);
        }
        create_stop();
    } else { //turn left
        while (get_create_total_angle() < -n) {
            create_drive_direct(-100,100);
        }
        create_stop();
    }
}

void reset_servos() {
    set_servo_position(0,700);
    msleep(1000);
    set_servo_position(3,0);
    msleep(1000);
}

void track_color(int channel, int object_no) {
    while (analog(0) < 2000) {
        //run camera_update() to get the new position each time
       
        camera_update();
        int x = get_object_center_x(channel,object_no);
        if (get_object_count(channel) > 0) {
            if (x > 80) {
                //turn right
                create_drive_direct(100,70);
            } else {
              //turn left
                create_drive_direct(70,100);
            }
        } else {
          turn(360);  
        }
    }
    create_stop();
}
