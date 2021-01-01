const tSensors lightSensor = (tSensors) S4;
const tSensors touchSensor = (tSensors) S1;
//gets the threshold value
int threshold_value();

//changes the direction of robot back to start
void return_to_start(void);

//writes to array
void map(int cellscolour);
//counts number of columns
void columns();
//counts number of rows
void rows(void);
//gets the cells colour
int cellcolour(int threshold1);
//moves backward
void shortmovebackward(void);
//maps each line
void mappingimproved();
//return the distance from start to the edge of map
int thestartingdistance(void);
//turns right
void turnright(void);
//turns left
void turnleft(void);
void shortmoveforward();
void ToFile();

//4 because its starting off facing the edge
int direction=4;

task main()
{
	int distance;
	int thresholdvalue;
	thresholdvalue=threshold_value();
	wait1Msec(3000);
	distance=thestartingdistance();
	shortmovebackward();
	turnleft();
	rows();
	ToFile();
	turnleft();
	columns();
	shortmovebackward();
	turnright();
	mappingimproved();


	return_to_start();
}

//moves it back set distance
void shortmovebackward(void)
{
int i = 0;
//moves robot back a set distance
moveMotorTarget(motorB, 200, -50);
moveMotorTarget(motorC, 200, -50);
wait1Msec(5000);
}

//checking THE CELLS COLOUR
int cellcolour(int threshold1)
{
	//checks if its white or black
	if(SensorValue(lightSensor) > threshold1)
	{		//return white
			return 0;
	}
	else
	{
			//returns black
			return 1;
	}
}



//counting the number of rows
void rows()
{
	int cond = 1;
	int row = 0;
	//reseting the motor encoders
	nMotorEncoder[motorC]=0;
	nMotorEncoder[motorB]=0;
	//while true loop
	while(cond == 1)
	{

		while(SensorValue(lightSensor) >= 46) //while on WHITE
	 		{
	 			//drive forward
				setMotorSync(motorB, motorC, 0, 50);
				//set it back to 0, so it can count
				nMotorEncoder[motorC]=0;
	 		}
	 		//if it detects the white space
	 		if(nMotorEncoder(motorB) < 15)
	 		{
	 			cond = 0;
	 		}
			// while on BLACK
	 		while(SensorValue(lightSensor) < 46)
	 		{
	 			setMotorSync(motorB, motorC, 0, 50);
	 			nMotorEncoder(motorB) = 0;
	 		}

	 		//its on double black
	 		if(nMotorEncoder[motorC]>50)
	 		{
	 				row=row+2;
	 		}
	 		else
	 		{
					row++;
	 		}
	}
	//reversing half a square
	setMotorSync(motorB, motorC, 0, -50);
	wait1Msec(550);

	//stopping the motor
	setMotorSync(motorB, motorC, 0, 0);
	wait1Msec(750);

	//-2 from rows, it counts the border
	row = row - 2;

	//displaying the rows
	displayBigStringAt(10, 31, "Rows");
	displayBigStringAt(0, 31, "%d", row);
	wait1Msec(1000);

}



void columns()
{
	int cond = 1;
	int col = 0;
	while(cond == 1)
	{
			//while on WHITE
			while(SensorValue(lightSensor) > 46)
	 		{
	 			//move forward
				setMotorSync(motorB, motorC, 0, 50);
				//set encoder to 0
				nMotorEncoder[motorC]=0;
	 		}
	 		//if it detects the white space
	 		if(nMotorEncoder(motorB) < 15)
	 		{
	 			cond = 0;
	 		}
			// while on BLACK
	 		while(SensorValue(lightSensor) < 46)
	 		{
	 			setMotorSync(motorB, motorC, 0, 50);
	 			nMotorEncoder(motorB) = 0;
	 		}
			//its on double black
	 		if(nMotorEncoder[motorC]>50)
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
	//its counting the two black lines at the edge because its going too fast oh well
	col = col - 2;

	//display it
	displayBigStringAt(0, 31, "%d", col);
	wait1Msec(1000);

}




//gettting the threshold
int threshold_value()
{
	//variables
	int lightvalue, darkvalue, thresholdvalue, sumvalue;

	//while touch is isnt pressed
	while(SensorValue(touchSensor)==0)
	{
			displayBigStringAt(0, 31, "read light now");
	}

	//get the value from sensor
	lightvalue=SensorValue(lightSensor);
	wait1Msec(500);
	//while touch is isnt pressed
	while(SensorValue(touchSensor)==0)
	{
		displayBigStringAt(0, 31, "read dark now");
	}
	//getting the dark value
	darkvalue=SensorValue(lightSensor);
	//getting threshold
	sumvalue= lightvalue + darkvalue;
	thresholdvalue = sumvalue/2;
	//returning it to main
	return(thresholdvalue);
}

//CREATING THE ARRAY
void map(int cellscolour)
{

	int row=0;
	int col=0;
	int mmap[9][7];
	//incrementing it each time a new square is mapped
	if(direction == 1)
	{
			mmap[col][row+1]=cellscolour;
	}
	else if (direction == 2)
	{
			mmap[col+1][row]=cellscolour;
	}
	else if (direction == 3)
	{
			mmap[col][row-1]=cellscolour;
	}
	else
	{
			mmap[col][row-1]=cellscolour;
	}
}






//RETURNING THE ROBOT TO FACE THE START

void return_to_start()
{
	if(direction == 4)
	{
		direction--;
		turnleft();
			//turn righto your facing the starting position again
	}
	else
	{
			while(direction !=3)
			{
					//turn right function
					direction++;
			}

	}
}



void turnright()
{
			//turns robot right
			setMotorSyncTime(motorB, motorC, -50, 680, 50);
			sleep (1000);
			//adds one to the direction
			direction++;
}


void turnleft()
{
			//turns it left
			setMotorSyncTime(motorC, motorB, -50, 680, 50);
			sleep (1500);
			//takes one away from direction
			direction--;
}


void mappingimproved()
{
	int cond = 1;
	int cell;
	int col = 0;

			while(cond == 1)
			{

				while(SensorValue(lightSensor) > 46) //while on WHITE
	 			{
	 				//driv forward
					setMotorSync(motorB, motorC, 0, 50);
					nMotorEncoder[motorC]=0;
				}//end the while


				//cell = 0 because its on white
				cell=0;
				//send this to the array
				map(cell);

				//if the gap is less than 15 it detects the small white space
		 		if(nMotorEncoder(motorB) < 15)
	 			{
	 				//breaks from loop
	 				cond = 0;
	 			}//end if

	 			while(SensorValue(lightSensor) < 46) // while on BLACK
	 			{
	 				setMotorSync(motorB, motorC, 0, 50);
	 				//set b back to 0 to count white
	 				nMotorEncoder(motorB) = 0;
				}//end while

	 			if(nMotorEncoder[motorC]>50) //its on double black
	 			{

					//cell is 1
					cell=1;
					//send the colour of the cell to map
					map(cell);
				}//end if

				//if it goes onto a second black square approx
				else if(nMotorEncoder[motorC]>100)
				{
					cell=1;
					//send the colour of the cell to map
					map(cell);
				}//end else if

				else
				{
					//if theres more than 2 black sqaures
					cell=1;
					map(cell);
				}//end else
		}//end while condition



	//displays number of colomns
	displayBigStringAt(0, 31, "%d", col);
	wait1Msec(10000);

}



//Returning to the start of the map from the edge
int thestartingdistance(void)
{
	int cond = 1;
	int distance;
	//set encoder to 0
	nMotorEncoder(motorC)=0;
	//loop forever
	while(cond == 1)
	{

			while(SensorValue(lightSensor) >= 46) //while on WHITE
	 		{
				setMotorSync(motorB, motorC, 0, 50);
	 		}
	 		//detecting white space
	 		if(nMotorEncoder(motorB) < 15)
	 		{
	 			cond = 0;
	 		}

		 	while(SensorValue(lightSensor) < 46) // while on BLACK
	 		{
	 			setMotorSync(motorB, motorC, 0, 50);
	 			nMotorEncoder(motorB) = 0;
	 		}
	}
	distance=getMotorEncoder(motorC);
	return(distance);
}

void shortmoveforward(void)
{
moveMotorTarget(motorB, 200, 50);
moveMotorTarget(motorC, 200, 50);
wait1Msec(5000);
}


//writing to file
void ToFile()
{
	char *mmap= "mmap";
  long fileHandle;
	fileHandle = fileOpenWrite(mmap);
	int row;
	int col;
	int white;
	int black;

	fileHandle = fileOpenWrite(mmap);

 	writeDebugStreamLine("Total amount of rows: %d\n", row);
 	writeDebugStreamLine("Total amount of columns: %d \n", col);
 	writeDebugStreamLine("Total amount of white Squares: %d \n", white);
 	writeDebugStreamLine("Total amount of black Squares: %d \n", black);

  fileClose(fileHandle);
}
