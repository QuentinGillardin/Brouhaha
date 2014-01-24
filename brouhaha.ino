//Version V1
//24 janvier 2014
//Auteur & Co-Auteur
//Quentin Gillardin & César Théard


const int rpin1 = 10;
const int gpin1 = 11;
const int bpin1 = 12;
const int rpin2 = 7;
const int gpin2 = 8;
const int bpin2 = 9;
const int rpin3 = 4;
const int gpin3 = 5;
const int bpin3 = 6;
const int rpin4 = 3;
const int gpin4 = 22;
const int bpin4 = 24;
const int rpin5 = 26;
const int gpin5 = 28;
const int bpin5 = 30;
const int rpin6 = 32;
const int gpin6 = 34;
const int bpin6 = 36;
const int v1 = 38;
const int v2 = 40;
const int v3 = 42;
const int v4 = 44;
const int v5 = 46;
const int v6 = 48;

int niveau = 0;

void setup()  {
  pinMode(rpin1, OUTPUT);
  pinMode(rpin2, OUTPUT);
  pinMode(rpin3, OUTPUT);
  pinMode(rpin4, OUTPUT);
  pinMode(rpin5, OUTPUT);
  pinMode(rpin6, OUTPUT);
  pinMode(gpin1, OUTPUT);
  pinMode(gpin2, OUTPUT);
  pinMode(gpin3, OUTPUT);
  pinMode(gpin4, OUTPUT);
  pinMode(gpin5, OUTPUT);
  pinMode(gpin6, OUTPUT);
  pinMode(bpin1, OUTPUT);
  pinMode(bpin2, OUTPUT);
  pinMode(bpin3, OUTPUT);
  pinMode(bpin4, OUTPUT);
  pinMode(bpin5, OUTPUT);
  pinMode(bpin5, OUTPUT);
  pinMode(bpin6, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(v3, OUTPUT);
  pinMode(v4, OUTPUT);
  pinMode(v5, OUTPUT);
  pinMode(v6, OUTPUT);
  
  Serial.begin(9600);


  
  bienvenue();
  delay(1000);

  
}

void loop(){
  if(Serial.available()){
  niveau = detectionNiveau();
  }
  if(niveau == 1 ){
    allumerNiveau1();
  }  
  
  //allumer première couronne
  if(niveau == 2){
    allumerNiveau2();
  }
  
  //allumer seconde couronne
  if(niveau == 3){
    allumerNiveau3();          
  }
  
}

  
  


//Lecture et gestion des informations venant du dispositif du projet décibel (cf readme)
int recupererValeur(){
  char buffer[5];
  if(Serial.read()==':'){
    Serial.readBytesUntil('.',buffer,5);
  }
    return (buffer[0]-48)*100 + (buffer[1]-48)*10 + (buffer[2]-48);
}

int detectionNiveau(){
  int value = recupererValeur();
  if( value <=60){
    return 1;
  }
  if(value <=80 && value >60){
   return 2;
  }
  if(value > 80){
    return 3;
  }
}

//Gestion des états de la matrice de LED
void allumerNiveau1(){
  digitalWrite(rpin1, HIGH);
  digitalWrite(rpin2, HIGH);
  digitalWrite(rpin3, HIGH);
  digitalWrite(rpin4, HIGH);
  digitalWrite(rpin5, HIGH);
  digitalWrite(rpin6, HIGH);
  digitalWrite(gpin1, LOW);
  digitalWrite(gpin2, LOW);
  digitalWrite(gpin2, LOW);
  digitalWrite(gpin3, LOW);
  digitalWrite(gpin4, LOW);
  digitalWrite(gpin5, LOW);
  digitalWrite(gpin6, LOW);
  digitalWrite(bpin1, HIGH);
  digitalWrite(bpin2, HIGH);
  digitalWrite(bpin3, HIGH);
  digitalWrite(bpin4, HIGH);
  digitalWrite(bpin5, HIGH);
  digitalWrite(bpin6, HIGH);
  
  digitalWrite(v1, LOW);
  digitalWrite(v2, LOW);
  digitalWrite(v3, LOW);
  digitalWrite(v4, LOW);
  digitalWrite(v5, LOW);
  digitalWrite(v6, HIGH); 
}

void allumerNiveau2(){
  digitalWrite(rpin1, HIGH);
  digitalWrite(rpin2, HIGH);
  digitalWrite(rpin3, HIGH);
  digitalWrite(rpin4, HIGH);
  digitalWrite(rpin5, HIGH);
  digitalWrite(rpin6, HIGH);
  digitalWrite(gpin1, HIGH);
  digitalWrite(gpin2, HIGH);
  digitalWrite(gpin2, HIGH);
  digitalWrite(gpin3, HIGH);
  digitalWrite(gpin4, HIGH);
  digitalWrite(gpin5, HIGH);
  digitalWrite(gpin6, HIGH);
  digitalWrite(bpin1, LOW);
  digitalWrite(bpin2, LOW);
  digitalWrite(bpin3, LOW);
  digitalWrite(bpin4, LOW);
  digitalWrite(bpin5, LOW);
  digitalWrite(bpin6, LOW);
  
  digitalWrite(v1, LOW);
  digitalWrite(v2, LOW);
  digitalWrite(v3, LOW);
  digitalWrite(v4, HIGH);
  digitalWrite(v5, HIGH);
  digitalWrite(v6, HIGH);
}

void allumerNiveau3(){
  digitalWrite(rpin1, LOW);
  digitalWrite(rpin2, LOW);
  digitalWrite(rpin3, LOW);
  digitalWrite(rpin4, LOW);
  digitalWrite(rpin5, LOW);
  digitalWrite(rpin6, LOW);
  digitalWrite(gpin1, HIGH);
  digitalWrite(gpin2, HIGH);
  digitalWrite(gpin2, HIGH);
  digitalWrite(gpin3, HIGH);
  digitalWrite(gpin4, HIGH);
  digitalWrite(gpin5, HIGH);
  digitalWrite(gpin6, HIGH);
  digitalWrite(bpin1, HIGH);
  digitalWrite(bpin2, HIGH);
  digitalWrite(bpin3, HIGH);
  digitalWrite(bpin4, HIGH);
  digitalWrite(bpin5, HIGH);
  digitalWrite(bpin6, HIGH);

  digitalWrite(v1, HIGH);
  digitalWrite(v2, HIGH);
  digitalWrite(v3, HIGH);
  digitalWrite(v4, HIGH);
  digitalWrite(v5, HIGH);
  digitalWrite(v6, HIGH);
}

void allumerCouronne1(){
  digitalWrite(rpin1, HIGH);
  digitalWrite(rpin2, HIGH);
  digitalWrite(rpin3, HIGH);
  digitalWrite(rpin4, LOW);
  digitalWrite(rpin5, LOW);
  digitalWrite(rpin6, HIGH);
  digitalWrite(gpin1, HIGH);
  digitalWrite(gpin2, HIGH);
  digitalWrite(gpin3, HIGH);
  digitalWrite(gpin4, LOW);
  digitalWrite(gpin5, LOW);
  digitalWrite(gpin6, HIGH);
  digitalWrite(bpin1, HIGH);
  digitalWrite(bpin2, HIGH);
  digitalWrite(bpin3, HIGH);
  digitalWrite(bpin4, LOW);
  digitalWrite(bpin5, LOW);
  digitalWrite(bpin6, HIGH);

  digitalWrite(v1, HIGH);
  digitalWrite(v2, HIGH);
  digitalWrite(v3, HIGH);
  digitalWrite(v4, HIGH);
  digitalWrite(v5, HIGH);
  digitalWrite(v6, HIGH);
}

void allumerCouronne2(){
  digitalWrite(rpin1, LOW);
  digitalWrite(rpin2, LOW);
  digitalWrite(rpin3, LOW);
  digitalWrite(rpin4, HIGH);
  digitalWrite(rpin5, HIGH);
  digitalWrite(rpin6, HIGH);
  digitalWrite(gpin1, LOW);
  digitalWrite(gpin2, LOW);
  digitalWrite(gpin2, LOW);
  digitalWrite(gpin3, HIGH);
  digitalWrite(gpin4, HIGH);
  digitalWrite(gpin5, HIGH);
  digitalWrite(gpin6, HIGH);
  digitalWrite(bpin1, LOW);
  digitalWrite(bpin2, LOW);
  digitalWrite(bpin3, LOW);
  digitalWrite(bpin4, HIGH);
  digitalWrite(bpin5, HIGH);
  digitalWrite(bpin6, HIGH);

  digitalWrite(v1, HIGH);
  digitalWrite(v2, HIGH);
  digitalWrite(v3, HIGH);
  digitalWrite(v4, HIGH);
  digitalWrite(v5, HIGH);
  digitalWrite(v6, HIGH);
}
  
  

void eteindreAll(){
  digitalWrite(rpin1, LOW);
  digitalWrite(rpin2, LOW);
  digitalWrite(rpin3, LOW);
  digitalWrite(rpin4, LOW);
  digitalWrite(rpin5, LOW);
  digitalWrite(rpin6, LOW);
  digitalWrite(gpin1, LOW);
  digitalWrite(gpin2, LOW);
  digitalWrite(gpin2, LOW);
  digitalWrite(gpin3, LOW);
  digitalWrite(gpin4, LOW);
  digitalWrite(gpin5, LOW);
  digitalWrite(gpin6, LOW);
  digitalWrite(bpin1, LOW);
  digitalWrite(bpin2, LOW);
  digitalWrite(bpin3, LOW);
  digitalWrite(bpin4, LOW);
  digitalWrite(bpin5, LOW);
  digitalWrite(bpin6, LOW);
  
  digitalWrite(v1, LOW);
  digitalWrite(v2, LOW);
  digitalWrite(v3, LOW);
  digitalWrite(v4, LOW);
  digitalWrite(v5, LOW);
  digitalWrite(v6, LOW);
}
  
void bienvenue(){
  allumerNiveau1();
  delay(1000);
  allumerNiveau2();
  delay(1000);
  allumerNiveau3();
  delay(2000);
  
  eteindreAll();
  delay(200);
  allumerNiveau3();
  delay(200);
  eteindreAll();
  delay(200);
  allumerNiveau3();
  delay(200);
  eteindreAll();
  delay(200);
  allumerNiveau3();
  delay(200);
  
  eteindreAll();
}
