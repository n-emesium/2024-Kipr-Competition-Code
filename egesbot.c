//Ege Fuat Eskisar

//Create Robot 

void drive(int distance); //drives straight for a set distance; 
void follow_line(); //follows line until it hits the digital sensor;

int main () {
shut_down_in(119);
create_connect();
//Digital Lever is Port 0;
//Servo Port 3 is Arm
//Servo Port 0 is Claw
enable_servos();




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
	while (get_create_rbump == 0 && get_create_lbump == 0 && digital(0) == 0) { //check bounds
		if (get_create_lcliff_amt() < val) {
			create_drive_direct(0.5 * vel, vel);	
		} else {
			create_drive_direct(vel, 0.5 * vel);
		}
	}
	create_stop();
}
