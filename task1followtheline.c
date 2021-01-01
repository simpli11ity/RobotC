const tSensors lightSensor = (tSensors) S4;
const tSensors touchSensor = (tSensors) S1;

task main()
{
	while(SensorValue(touchSensor) == 0)
	{
			while((SensorValue(lightSensor) < 55 && SensorValue(touchSensor) == 0))
			{
				motor[motorB] = 0;
				motor[motorC] = 40;
			}
			while((SensorValue(lightSensor) > 55 && SensorValue(touchSensor) == 0))
			{
				motor[motorB] = 40;
				motor[motorC] = 0;
			}
	}
		motor[motorB]  = 0;
		motor[motorC]  = 0;
}
