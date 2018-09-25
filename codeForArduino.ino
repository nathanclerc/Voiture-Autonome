
long cpt = 0;
boolean choix=true;


// fonction d'initialisation de la carte
void setup(){
  // contenu de l'initialisation
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}


// fonction principale, elle se répète (s’exécute) à l'infini
void loop(){
  
  // contenu de votre programme
  if (analogRead(A1)<1000 && analogRead(A2)<1000){
    avance();
    cpt = millis();
  }
  else if (analogRead(A1)>1000 && analogRead(A2)>1000){
   if(choix==true){
      while (analogRead(A1)>1000 && analogRead(A2)>1000){
        gauche();
        choix=false;
        if(millis() - cpt > 5000){
          arret();
        }
      }
    }
    else{
      while (analogRead(A1)>1000 && analogRead(A2)>1000){
        droite();
        choix=true;
        if(millis() - cpt > 5000){
          arret();
        }
      }
    }
  }
  else if (analogRead(A1)>1000){
    gauche();
    cpt = millis();
  }
  else if (analogRead(A2)>1000){
    droite();
    cpt = millis();
  }

}

void droite(){
   digitalWrite(10, HIGH);
   digitalWrite(11, LOW);
   digitalWrite(12, LOW);
   digitalWrite(13, HIGH);
}

void gauche(){
   digitalWrite(10, LOW);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
}

void avance(){
   digitalWrite(10, HIGH);
   digitalWrite(11, LOW);
   digitalWrite(12, HIGH);
   digitalWrite(13, LOW);
}

void arret(){
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
   digitalWrite(12, LOW);
   digitalWrite(13, LOW);
}
