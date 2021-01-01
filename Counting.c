const tSensors lightSensor = (tSensors) S4;
const tSensors ultrasonic = (tSensors) S3;

task main()
{
	int counter = 0; //Initialising variables
	int lastseen = 1; //Lastseen 1 is light, 0 is dark
	int lightvalue, darkvalue, thresholdvalue, sumvalue;

	//Calculating threshold value
	lightvalue=100; //Value of white background
	darkvalue = 12; //Value of lines
	sumvalue = lightvalue + darkvalue; //Needed to calculate thresholdvalue
	thresholdvalue = sumvalue/2; //Calculating thresholdvalue

	lastseen=0;
			while (SensorValue(ultrasonic) >15) //Stops movement and declares how many lines when ultrasonic is triggered
			{
					if (SensorValue(lightSensor) > thresholdvalue) //Reads for the thresholds of the lines
					{
							motor[motorC]=50; //Going forward
							motor[motorB]=50;
							if (lastseen == 1) //If robot was on light last
							{
									counter = counter + 1; //Counts line
									lastseen = 0; //Marks it going on to black
							}
					}
				else
				{
						lastseen = 1; //Marks it going on to white
				}
			}

	displayBigStringAt(0, 32, "%d", counter); //Displays number of lines
	motor[motorC] = 0; //Stops movement
	motor[motorB] = 0;
	wait1Msec(10000); //Allows time to read
}
