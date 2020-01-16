
void indexRoot(){
              if ( server.hasArg("envoi")) 
              {      
                send_data();
              } 
               server.send ( 200, "text/html", indexPage() );   // envoi de la page
                }
  




String indexPage(){
                    String page =F("<!DOCTYPE html> <html lang=fr-FR><head><meta charset='utf-8'><link rel='stylesheet'type='text/css'href='style.css'><title>Solar Greenhouse</title></head>");
                           page +=F("<body>");
                           page +=F("<nav> <ul id='menu'><li><a href='index.html'> Accueil </a></li><li><a href='firmware'> Update </a></li></ul></nav>");
                          
                           page +=F("<div id='page'>");
                           
                           page +=F("<header><h1>Solar greenhouse</h1></header>");

                           page +=F("<div id='corp'>");
                                 page +=F("<section id='datedujour'><h2>");
                                 page +=NTP.getDateStr();
                                 page +=F("</h2><h3>");
                                 page +=NTP.getTimeStr();
                                 page +=F("</h3>");
                                 page +=F("<Table><tr><td>Serveur:</td><td>");
                                 page +=ip_server;
                                 page +=F("</td></tr><tr><td>Port serveur:</td><td>");
                                 page +=port_server;
                                 page +=F("</td></tr><tr><td>Adresse MAC:</td><td>");
                                 page +=local_mac;
                                 page +=F("</td></tr><tr><td>Version</td><td>");
                                 page +=version_module;
                                 page +=F("</td></tr></tr></Table></section>");
      
                                 page +=F("<section id='greenhouse'><h2> Greenhouse </h2><ul><li>Température: ");
                                 page +=temperature_greenhouse;
                                 page +=F(" °c</li><li> Humidité:");
                                 page +=humidity_greenhouse;
                                 page +=F(" %</li><li> CO2:");
                                 page +=co2_greenhouse;
                                 page +=F(" ppm</li><li> Luminosite:");    
                                 page +=luminosity_greenhouse;
                                 page +=F(" lux</li><li> Humidité sol:");
                                 page +=moisture_greenhouse;
                                 page +=F(" %</li><li> Température sol:");
                                 page +=temperature_soil_greenhouse;
                                 page +=F(" °C</li><li> Température eau:");
                                 page +=temperature_water_greenhouse;
                                 page +=F(" °C</li></ul></section>");   
                                       
                                 page +=F("<section id='garden'><h2> Garden </h2><ul><li>Température: ");
                                 page +=temperature_out;
                                 page +=F(" °c</li><li> Humidité: ");
                                 page +=humidity_out;
                                 page +=F(" %</li><li> Température sol: ");
                                 page +=temperature_soil_garden;
                                 page +=F(" °C</li><li> Humidité sol:");
                                 page +=moisture_garden;
                                 page +=F(" %</li></ul></section>");
                           
                                 page +=F("<section id='compost'><h2> Compost  </h2><ul><li>Température: ");
                                 page +=average_v_battery;
                                 page +=F(" Volts</li><li>Courant battery: ");
                                 page +=average_a_battery;
                                 page +=F(" Ampéres</li><li>Courant load: ");
                                 page +=average_a_load;
                                 page +=F(" Ampéres</li><li> Température compost: ");
                                 page +=temperature_compost;
                                 page +=F(" °C</li><li> Humidité compost: ");
                                 page +=humidity_compost;                           
                                 page +=F("  %</li></ul></section>");

                                 page +=F("<section id='sent'><h2> Envoi données  </h2><ul><li>Périodicité actuelle ");
                                 page +=period;
                                 page +=F(" secondes</li><li><form method='get'><input type='hidden' name='envoi' value='1'/><input type='submit' value='envoi'/>");                      
                                 page +=F("</form></li></ul></section>");
                                 
                           page +=F("</div>");
                           
                           page +=F("<footer><a href='http://innogreentech.fr'>InnoGreenTech  </a><a href='mailto: info@innogreentech.fr'>Contactez moi</a></footer>");
                           page +=F("</body></html>");                 
                           return page;
                          }
