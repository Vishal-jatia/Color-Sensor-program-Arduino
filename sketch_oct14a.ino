int redPin=11;
int greenPin=10;
int bluePin=6;

int s2=7;
int s3=8;
int outPin=4;
int rColurStrength;
int bColurStrength;
int gColurStrength;
unsigned int pulseWidth;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);

pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(outPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);

  pulseWidth=pulseIn(outPin,LOW);

  rColurStrength=(pulseWidth/399)-1;
  rColurStrength=(255-rColurStrength);



  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);

  pulseWidth=pulseIn(outPin,LOW);

  gColurStrength=(pulseWidth/399)-1;
  gColurStrength=(255-gColurStrength);


  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);

  pulseWidth=pulseIn(outPin,LOW);

  bColurStrength=(pulseWidth/399)-1;
  bColurStrength=(255-bColurStrength);

  Serial.print(rColurStrength);
  Serial.print("   ,   ");
  Serial.print(gColurStrength);
  Serial.print("   ,   ");
  Serial.println(bColurStrength);
  Serial.println("");
  
  
  if(rColurStrength>gColurStrength && rColurStrength>bColurStrength){
    
    if(gColurStrength>bColurStrength){
      rColurStrength=255;
      gColurStrength=gColurStrength/2.5;
      bColurStrength=0;
   }else{
    rColurStrength=255;
    bColurStrength=bColurStrength/20;
    gColurStrength=0;
      }
  }
  if(gColurStrength>rColurStrength && gColurStrength>bColurStrength){
    if(rColurStrength>bColurStrength){
      gColurStrength=255;
      rColurStrength=rColurStrength/2.5;
      bColurStrength=0;
       
   }else{
    
    gColurStrength=255;
    bColurStrength=bColurStrength/2.5;
    rColurStrength=0;
      }
  }
  if(bColurStrength>rColurStrength && bColurStrength>gColurStrength){
    if(rColurStrength>gColurStrength){
       bColurStrength=255;
       rColurStrength=rColurStrength/2.5;
       gColurStrength=0;
   }else{
    
    bColurStrength=255;
    gColurStrength=gColurStrength/20;
    rColurStrength=0;
    }
  }

 
  rColurStrength=rColurStrength*2;
  bColurStrength=bColurStrength*0.5;
  gColurStrength=gColurStrength*1;
  analogWrite(redPin,rColurStrength);
  analogWrite(greenPin,gColurStrength);
  analogWrite(bluePin,bColurStrength);


  delay(500);
}
