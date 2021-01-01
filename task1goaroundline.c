const tSensors lightSensor = (tSensors) S4;
const tSensors ultrasonic = (tSensors) S3;

task main()
{
	while(SensorValue(ultrasonic) > 15 )
	{
			while((SensorValue(lightSensor) < 55 && SensorValue(ultrasonic) >15 ))
			{
				motor[motorB] = 0;
				motor[motorC] = 40;
			}
			while((SensorValue(lightSensor) > 55 && SensorValue(ultrasonic) >15 ))
			{
				motor[motorB] = 40;
				motor[motorC] = 0;
			}
	}


	setMotorSyncTime(motorB, motorC, -50, 680, 50);
	sleep (1500);

	setMotorSyncTime(motorB, motorC, 0,500, 100);
	sleep (1500);

	setMotorSyncTime(motorB, motorC, 50, 680, 50);
	sleep (1500);

	setMotorSyncTime(motorB, motorC, 0, 1000, 100);
	sleep (1500);

	setMotorSyncTime(motorB, motorC, 50, 680, 50);
	sleep (1500);


	while(SensorValue(lightSensor) >55)
	{
	motor[motorB]  = 20;
	motor[motorC]  = 20;

	}


	if(SensorValue(lightSensor) < 55)
	{
	setMotorSyncTime(motorB, motorC, -50, 680, 50);
	sleep (1500);
	}
	else
	{
		setMotorSyncTime(motorB, motorC, -50, 680, 50);
		sleep (1500);
	}

		while(SensorValue(ultrasonic) >5 )
	{

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
	}
}
