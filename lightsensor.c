const tSensors lightSensor = (tSensors) S4;

task main()
{
	motor[motorB] = 50;
	motor[motorC] = 50;

	while(SensorValue(lightSensor) > 40)
		{
			motor[motorB] = 50;
			motor[motorC] = 50;
		}
	motor[motorB] = -50;
	motor[motorC] = -50;
	wait1Msec(1000);

}
