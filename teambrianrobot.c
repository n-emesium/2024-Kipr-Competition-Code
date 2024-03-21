#include <kipr/wombat.h>

int main()
{
    create_connect();
    enable_servos();
    set_servo_position(0, 28);
    set_servo_position(1, 5);
    set_servo_position(2, 159);
    msleep(100);
    
    msleep(2000);
    
    set_create_distance(0);
    while(get_create_distance() < 490){
    create_drive_direct(300, 290);
    }
    create_stop();
    
    int s0;		//servo 0
    for(s0 = 150; s0 < 227; s0 += 5){
        set_servo_position(0, s0);
        msleep(5);
    }
    
    int s1;		//servo 1
    for(s1 = 375; s1 < 1356; s1 += 5){
        set_servo_position(1, s1);
        msleep(5);
    }
    
    set_create_distance(0);
    while(get_create_distance() < 115){
    create_drive_direct(190, 200);
    }
    create_stop();
    
    msleep(2000);
    
    
    
    create_disconnect();
    return 0;
}
