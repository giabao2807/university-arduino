#include <AFMotor.h>
 
AF_DCMotor motor(2, MOTOR12_64KHZ); // tạo động cơ #2, 64KHz pwm  
 
void setup() {  
    
    Serial.begin(9600);           // mở cổng Serial monitor 9600 bps 
    
    Serial.println("Hello my racing");     
    
    motor.setSpeed(255);     // chọn tốc độ maximum 255`/255
 
}  
 
void loop() {  
 
    Serial.println("tien");     
    
    motor.run(FORWARD);      // động cơ tiến 
    
    delay(1000);    
    
//    Serial.println("lui");  
//    
//    motor.run(BACKWARD);     // động cơ lùi  
//    
//    delay(1000);     
//    
//    Serial.println("tack");  
//    
//    motor.run(RELEASE);      //   dừng động cơ
//    
//    delay(1000);
 
}
