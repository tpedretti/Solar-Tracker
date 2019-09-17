#include <Arduino.h>
#include <Servo.h>

Servo horizontal; //horizontal servo
int servoh = 90; //stand horizontal servo

Servo vertical; //vertical servo 
int servov = 180; //stand vertical servo

//LDR pin connections
//name = analogpin;
int ldrlt = A2; //LDR top left
int ldrrt = A3; //LDR top rigt
int ldrld = A0; //LDR down left
int ldrrd = A1; //ldr down rigt

void setup() 
{
  Serial.begin(9600);
  horizontal.attach(7); 
  vertical.attach(4);  
  vertical.write(servov);
}

void loop() 
{
	int lt = analogRead(ldrlt); // top left Photoresistor 
	int rt = analogRead(ldrrt); // top right Photoresistor 
	int ld = analogRead(ldrld); // down left Photoresistor 
	int rd = analogRead(ldrrd); // down rigt Photoresistor 

	int avt = (lt + rt) / 2; // average value top
	int avd = (ld + rd) / 2; // average value down
	int avl = (lt + ld) / 2; // average value left
	int avr = (rt + rd) / 2; // average value right

	int dvert = abs(avt - avd); // check the diffirence of up and down
	int dhoriz = abs(avl - avr);// check the diffirence og left and rigt

	int tol = 20;

	Serial.print("Top Left PR: ");
	Serial.print(lt);
	Serial.print("	|	");
	Serial.print("Top Right PR: ");
	Serial.println(rt);

	Serial.print("Bot Left PR: ");
	Serial.print(ld);
	Serial.print("	|	");
	Serial.print("Bot Right PR: ");
	Serial.println(rd);

	Serial.print("Top Avg:     ");
	Serial.print(avt);
	Serial.print("	|	");
	Serial.print("Bot Avg:     ");
	Serial.println(avd);

	Serial.print("Right Avg:   ");
	Serial.print(avl);
	Serial.print("	|	");
	Serial.print("Left  Avg:   ");
	Serial.println(avr);

	Serial.print("Diff Up&Down: ");
	Serial.print(dvert);
	Serial.print("	|	");
	Serial.print("Diff Le&Rig: ");
	Serial.println(dhoriz);

	Serial.print("\nServov: ");
	Serial.println(vertical.read());

	/*if(dvert > tol)
	{
		if(avt > avd)
		{
			servov--;
			if(servov < 60)
			{
				servov = 60;
			}
		}
		else if(avd > avt)
		{
			servov++;
			if(servov > 180)
			{
				servov = 180;
			}
		}

		vertical.write(servov);
	}

	if(dvert > tol)
	{
		if(avl > avr)
		{
			servoh--;
			if(servoh < 0)
			{
				servoh = 0;
			}
		}
		else if(avr > avl)
		{
			servoh++;
			if(servoh > 180)
			{
				servoh = 180;
			}
		}

		horizontal.write(servoh);
	}*/

	delay(10000);
}