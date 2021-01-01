const tSensors lightSensor = (tSensors) S4;
// Count rows

void rows()
{
	int cond = 1;
	int row = 0;

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
	 				row=row+2;
	 		}
	 		else
	 		{
					row++;
	 		}
	}

	setMotorSync(motorB, motorC, 0, -50);
	wait1Msec(550);
	setMotorSync(motorB, motorC, 50, 50);
	wait1Msec(750);

	setMotorSync(motorB, motorC, 0, 0);
	wait1Msec(750);


	row = row - 2;

	displayBigStringAt(10, 31, "Rows");
	displayBigStringAt(0, 31, "%d", row);
	wait1Msec(10000);

}
