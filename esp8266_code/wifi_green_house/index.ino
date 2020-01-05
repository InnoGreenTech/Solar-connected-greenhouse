
void indexRoot(){
              if ( server.hasArg("envoi")) 
              {      
                send_data();
              } 
               server.send ( 200, "text/html", indexPage() );   // envoi de la page
                }
  




String indexPage(){
                    String page =F("<!DOCTYPE html> <html lang=fr-FR><head><meta charset='utf-8'><link rel='stylesheet'type='text/css'href='style.css'><title>Capteur Maison</title></head>");
                           page +=F("<body>");
                           page +=F("<nav> <ul id='menu'><li><a href='index.html'> Accueil </a></li><li><a href='reglage.html'> Réglages </a></li><li><a href='mail.html'> Mails </a> </li></ul></nav>");
                          
                           page +=F("<div id='page'>");
                           
                           page +=F("<header><h1>Centrale maison</h1></header>");

                           page +=F("<div id='contenu'>");
                                 page +=F("<section id='datedujour'><h2>");
                                 page +=NTP.getDateStr();
                                 page +=F("</h2><h3>");
                                 page +=NTP.getTimeStr();
                                 page +=F("</h3>");
                                 page +=F("<ul><li>Serveur: ");
                                 page +=ip_server;
                                 page +=F("</li><li> Port serveur: ");
                                 page +=port_server;
                                 page +=F("</li><li> Adresse MAC: ");
                                 page +=local_mac;
                                 page +=F("</li><li> Version: ");
                                 page +=version_module;
                                 page +=F("</li></ul></section>");
      
                                 page +=F("<section id='outdoor'><h2> Greenhouse </h2><ul><li>Température: ");
                                 page +=temperature_greenhouse;
                                 page +=F(" °c</li><li> Humidité:");
                                 page +=humidity_greenhouse;
                                 page +=F(" %</li></ul></section>");
      
                                 
                                 page +=F("<section id='indoor'><h2> Garden </h2><ul><li>Température: ");
                                 page +=temperature_out;
                                 page +=F(" °c</li><li> Humidité: ");
                                 page +=humidity_out;
                                 page +=F(" %</li><li> Température: ");
                                 page +=temperature_soil_garden;
                                 page +=F(" °C</li></ul></section>");
                           
                                 page +=F("<section id='energie'><h2> Compost  </h2><ul><li>Température: ");
                                 page +=v_battery;
                                 page +=F(" Volts</li><li>Courant battery: ");
                                 page +=a_battery;
                                 page +=F(" Ampéres</li><li>Courant load: ");
                                 page +=a_load;
                                 page +=F(" Ampéres</li><li> Température compost: ");
                                 page +=temperature_compost;
                                 page +=F(" °C</li><li> Humidité compost ");
                                 page +=humidity_compost;                           
                                 page +=F("  %</li></ul></section>");

                                 page +=F("<section id='sent'><h2> Envoi données  </h2><ul><li>Périodicité actuelle ");
                                 page +=period;
                                 page +=F(" secondes</li><li><form method='get'><input type='hidden' name='envoi' value='1'/><input type='submit' value='envoi'/>");                      
                                 page +=F("</form></li></ul></section>");
                                 
                           page +=F("</div>");
                           
                           page +=F("<footer><a href='http://www.lepal.com'>InnoGreenTech</a><a href='mailto: fabricebaudin@outlook.fr'>Contactez moi</a></footer>");
                           page +=F("/div></body></html>");                 
                           return page;
                          }
