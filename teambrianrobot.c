//Andrii and Brian

//We are using the create robot to put the equipment in the lava tubes

//Other robot will flip the switch to drop the equipment

#include <kipr/wombat.h>


int main()

{

    create_connect();

    enable_servos();

    shut_down_in(119);


    //reset servos

    set_servo_position(0, 28);

    set_servo_position(1, 5);

    set_servo_position(2, 159);

    msleep(100);

    

    msleep(2000);

    

    //drive foward distance 490

    set_create_distance(0);

    while(get_create_distance() < 490){

    create_drive_direct(300, 290);

    }

    create_stop();

    


    int s0; //servo 0

    for(s0 = 150; s0 < 227; s0 += 5){

        set_servo_position(0, s0);

        msleep(5);

    }

    

    int s1; //servo 1

    for(s1 = 375; s1 < 1356; s1 += 5){

        set_servo_position(1, s1);

        msleep(5);

    }

    





    //Drive foward distance 115 to the space dock

    set_create_distance(0);

    while(get_create_distance() < 115){

    create_drive_direct(180, 200);

    }

    create_stop();

    

    //new code

    msleep(9000); //wait for lever to be switched open

    

    //Drive foward distance 1150 to the lava tubes

    set_create_distance(0);

    while(get_create_distance() < 1150){

     create_drive_direct(207, 200);

    }

    create_stop();


    //allign the two servos that control the arm

    msleep(1000);

    set_servo_position(0, 200);

    set_servo_position(1, 1225);

    msleep(500);


    //open the trapdoor, then wait for equipment to fall

    //then close it to hold the other equipment

    set_servo_position(2, 2047);

    msleep(2500);

    set_servo_position(2, 850);


    //Drive backwards a little bit

    set_create_distance(0);

    while(get_create_distance() > -85){

    create_drive_direct(-100, -100);

    }

    create_stop();


    //open trapdoor

    set_servo_position(2, 2047);

    msleep(1500);

    





    //Drive foward a little bit

    set_create_distance(0);

    while(get_create_distance() < 25){

     create_drive_direct(100, 100);

    }

    create_stop();

    

    create_disconnect();

    return 0;

}
