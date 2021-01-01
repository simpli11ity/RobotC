const tSensors lightSensor = (tSensors) S4;

// count and display columns
void columns()
{
	int cond = 1;
	int col = 0;
	while(cond == 1)
	{

		while(SensorValue(lightSensor) >= 46) //while on WHITE
	 		{
				setMotorSync(motorB, motorC, 0, 50);
				nMotorEncoder[motorC]=0;
	 		}
	 	if(nMotorEncoder(motorB) < 15)
	 		{
	 			cond = 0;
	 		}

	 	while(SensorValue(lightSensor) < 46) // while on BLACK
	 		{
	 			setMotorSync(motorB, motorC, 0, 50);
	 			nMotorEncoder(motorB) = 0;
	 		}

	 		if(nMotorEncoder[motorC]>50) //its on double black
	 		{
	 				col=col+2;
	 		}
	 		else
	 		{
					col++;
	 		}
	}

	setMotorSync(motorB, motorC, 0, -50);
	wait1Msec(550);
	setMotorSync(motorB, motorC, 50, 50);
	wait1Msec(750);

	col = col - 2;


	displayBigStringAt(0, 31, "%d", col);
	wait1Msec(10000);

}
