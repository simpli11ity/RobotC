const tSensors lightSensor = (tSensors) S4;
const tSensors ultrasonic = (tSensors) S3;
#define forward_power 30

#define turn_power 50

task main()
{
	//initialise variable forever
	int i=0;
	//while loop to continue forever
	while(i==0)
	{
			//while ultrasonic sensor doesnt sense distance greater than 15
			while(SensorValue(ultrasonic) > 15 )
			{
					//while light sensor is less han 55% and ultrasonic is greater than 15
					while((SensorValue(lightSensor) < 55 && SensorValue(ultrasonic) >15 ))
					{
							//TURNS LEFT
							motor[motorB] = 0;
							motor[motorC] = 40;
					}
					while((SensorValue(lightSensor) > 55 && SensorValue(ultrasonic) >15 ))
					{
							//tuns left
							motor[motorB] = 40;
							motor[motorC] = 0;
					}//end while
			}//end while

			//turns right angle
			setMotorSyncTime(motorB, motorC, -50, 680, 50);
			sleep (1500);


			//turns in arch until hits black line
			while(SensorValue(lightSensor) >55)
			{
					motor[motorC] = forward_power; //Start forward
					motor[motorB] = turn_power;
			}

			//when it hits the black line
			if(SensorValue(lightSensor) < 55)
			{
					//turn left
					setMotorSyncTime(motorB, motorC, -50, 680, 50);
					sleep (1500);
			}
			else
			{
					//tun left
					setMotorSyncTime(motorB, motorC, -50, 680, 50);
					sleep (1500);
			}
			//runs while ultrasonic senses distance is greate than 20
			while(SensorValue(ultrasonic) >20 )
			{
					//follows line
					while(SensorValue(lightSensor) > 55 )
					{
							motor[motorB] = 0;
							motor[motorC] = 20;
					}
					while(SensorValue(lightSensor) <55 )
					{
							motor[motorB] = 20;
							motor[motorC] = 0;
					}
			}//when disance  less than 20 it breaks fom while and returns to the start
	}//end while
}//end main
