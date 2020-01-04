void second_buttons_design(){
     for (int a=0;a <2;a++)    
     { 
      int b=a*100+6*a+60;
      two_buttons[a].initButton(&tft,b,195,100,30,WHITE,BROWN,GREEN,second_buttons[a],1);
      two_buttons[a].drawButton();
     }
    tft.setCursor(10,215);
    tft.print F("InnoGreenTech info@innogreentech.fr");
}

void greenhouse_buttons_design(){
     unsigned int back_color=0;
     unsigned int text_color=0;
     for (int a=0;a <6;a++)    
     { 
      if (bitRead(forced_greenhouse,a)){back_color=RED;text_color=YELLOW;}
      else if (bitRead(desactive_greenhouse,a)){back_color=YELLOW;text_color=RED;}
      else if (bitRead(output_greenhouse,a)){back_color=GREEN;text_color=RED;}
      else{back_color=BROWN;text_color=CYAN;}
      int b=a*30+6*a+30;
      six_buttons[a].initButton(&tft,270,b,70,30,WHITE,back_color,text_color,greenhouse_buttons[a],1);
      six_buttons[a].drawButton();
     }
}

void garden_buttons_design(){
     unsigned int back_color=0;
     unsigned int text_color=0;
     for (int a=0;a <6;a++)    
     { 
      if (bitRead(forced_garden,a)){back_color=RED;text_color=YELLOW;}
      else if (bitRead(desactive_garden,a)){back_color=YELLOW;text_color=RED;}
      else if (bitRead(output_garden,a)){back_color=GREEN;text_color=RED;}
      else{back_color=BROWN;text_color=CYAN;}     
      int b=a*30+6*a+30;
      six_buttons[a].initButton(&tft,270,b,70,30,WHITE,back_color,text_color,garden_buttons[a],1);
      six_buttons[a].drawButton();
     }
}

void main_buttons_design(){
  for (int a=0;a <4;a++)     // Création des boutons sur l'écran d'accueil
    { 
      int b=a*70+6*a+45;
      four_buttons[a].initButton(&tft,b,200,70,30,WHITE,BROWN,GREEN,main_buttons[a],1);
      four_buttons[a].drawButton();
    }

  tft.setCursor(100,225);
  tft.print F("InnoGreenTech info@innogreentech.fr");
}


void setting_buttons_design(){
  for (int a=0;a <4;a++)     // Création des boutons sur l'écran d'accueil
    { 
      int b=a*70+6*a+45;
      four_buttons[a].initButton(&tft,b,200,70,30,WHITE,BROWN,GREEN,setting_buttons[a],1);
      four_buttons[a].drawButton();
    }

  tft.setCursor(100,225);
  tft.print F("InnoGreenTech info@innogreentech.fr");
}


void choice_buttons_design(){
  for (int a=0;a <2;a++)     // Création des boutons sur l'écran d'accueil
    { 
      int b=a*50+70;
      two_buttons[a].initButton(&tft,275,b,70,30,WHITE,BROWN,GREEN,choice_buttons[a],1);
      two_buttons[a].drawButton();
    }

}
