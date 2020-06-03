int ledRed = D3;
int ledGreen = D4;
int ledBlue = D5;
bool ledRedStatus = false;
bool ledGreenStatus = false;
bool ledBlueStatus = false;
int ledOnDelay = 150;

void setup() {

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);

}

int toggleLights(String inputString) 
{
    if (inputString == "red") 
    {
        if (!ledRedStatus)
        {
            digitalWrite(ledRed, HIGH);
            digitalWrite(ledBlue, LOW);
            digitalWrite(ledGreen, LOW);
            ledRedStatus = true;
        }
        else 
        {
            digitalWrite(ledRed, LOW);
            ledRedStatus = false;
        }
        return 1;
    }
    else if (inputString == "green")
    {
        if (!ledGreenStatus)
        {
            digitalWrite(ledGreen, HIGH);
            digitalWrite(ledRed, LOW);
            digitalWrite(ledBlue, LOW);
            ledGreenStatus = true;
        }
        else 
        {
            digitalWrite(ledGreen, LOW);
            ledGreenStatus = false;
        }
        return 2;
    } 
    else if (inputString == "blue")
    {
        if (!ledBlueStatus)
        {
            digitalWrite(ledBlue, HIGH); 
            digitalWrite(ledGreen, LOW);
            digitalWrite(ledRed, LOW);
            ledBlueStatus = true;
        }
        else 
        {
            digitalWrite(ledBlue, LOW);
            ledBlueStatus = false;
        }
        return 3;
    }
}


void loop() {
    
    Particle.function("toggleLights", toggleLights);
    
}