import processing.serial.*;

Serial port; // le port serial
String serial;
float val;
int bval;
float val2;
int bval2;
PImage F;
int end = 10;
int count=0;
String sb ;

int[] sensorValues;
float tps;
void setup(){
  size(900,900);
  frameRate(30);
  
  
  port = new Serial(this, "COM3", 9600);

  F = loadImage("Pied2.jpg");
  
  
}

void draw(){
  noCursor();
  tps = millis();
   if ( tps < 4000) {
    background(100);
    textSize(24);
    fill(255);
    textAlign(CENTER);
    text("ADOPTER UNE POSE LA PLUS NATUREL POSSIBLE", 900/2, 700/2);
  }
  else{
     background(F); 
  
  while(port.available() > 0){
    
      
    sb = port.readStringUntil(end);
    
    
      if(sb != null){
    if(count%2 == 1){
      println("pied droit");
      print(sb);
      println("kg");
  
        val = float(sb);
        bval = int(val);
      }
    
     else{
          println("pied gauche");
          print(sb);
          println("kg");
          val2 = float(sb);
          bval2 = int(val2);
        }
    
     count ++; 
  }
 }
  
 
  fill(bval2*200, 0, 0);
   
  ellipse(170*2, 750, 120+bval2*10, 120+bval2*50);
  fill(bval*200, 0, 0);

  ellipse(280*2, 750, 120+bval*10, 120+bval*50);
  }
}
