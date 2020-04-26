/*******************************************
 * Gestion de la leccture de l'écran tactil*
 ******************************************/

void tactil(){

    digitalWrite(13, HIGH);
    TSPoint   p = ts.getPoint();//Lecture de la position d'appui
    digitalWrite(13, LOW);
   
    pinMode(XM, OUTPUT);//Remise en mode output des pin pour le LCD
    pinMode(YP, OUTPUT);//Remise en mode output des pin pour le LCD
 
     //test de l'écran
 if (p.z> 100&&!bitRead(flag,PUSH_BUTTON)){
          y=map(p.x,TS_MAXX,TS_MINX,tft.height(),0); //mise à l'échelle de la valeur en x
          x=map(p.y,TS_MAXY,TS_MINY,tft.width(),0); // mise à l'échelle de la valeur en Y
          bitSet(flag,PUSH_BUTTON); // blocage de la lecture
          z=p.z;
          button_delay=millis();
          //Serial.println(p.z);Serial.println(x);Serial.println( y);

                    }
 if (millis()>(button_delay+BUTTON_DELAY))
          {
          bitClear(flag,PUSH_BUTTON); //filtre d'appui
          }
 
   
}
