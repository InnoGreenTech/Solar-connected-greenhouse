
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
                           page +=F("<nav> <ul id='menu'><li><a href='index.html'> Accueil </a></li><li><a href='firmware'> Update </a></li</ul></nav>");
                          
                           page +=F("<div id='page'>");
                           
                           page +=F("<header><h1>Solar greenhouse</h1></header>");

                           page +=F("<div id='corp'>");
                                 page +=F("<section id='datedujour'><h2>");
                                 page +=NTP.getDateStr();
                                 page +=F("</h2><h3>");
                                 page +=NTP.getTimeStr();
                                 page +=F("</h3>");
                                 page +=F("<Table><tr><td>Serveur:</td><td></td><td>");
                                 page +=ip_server;
                                 page +=F("</td></tr><tr><td>Port serveur:</td><td></td><td>");
                                 page +=port_server;
                                 page +=F("</td></tr><tr><td>Adresse MAC:</td><td></td><td>");
                                 page +=local_mac;
                                 page +=F("</td></tr><tr><td>Version:</td><td></td><td>");
                                 page +=version_module;
                                 page +=F("</td></tr></tr></Table></section>");
      
                                 page +=F("<section id='greenhouse'><h2> Greenhouse </h2><table><tr><td>Température:</td><td></td><td>");
                                 page +=temperature_greenhouse;
                                 page +=F(" °c</tr><tr><td>Humidité:</td><td></td><td>");
                                 page +=humidity_greenhouse;
                                 page +=F(" %</td></tr><tr><td>CO2:</td><td></td><td>");
                                 page +=co2_greenhouse;
                                 page +=F(" ppm</td></tr><tr><td>Luminosite:</td><td></td><td>");    
                                 page +=luminosity_greenhouse;
                                 page +=F(" lux</td></tr><tr><td>Humidité sol:</td><td></td><td>");
                                 page +=moisture_greenhouse;
                                 page +=F(" %</td></tr><tr><td>Température sol:</td><td></td><td>");
                                 page +=temperature_soil_greenhouse;
                                 page +=F(" °C</td></tr><tr><td>Température eau:</td><td></td><td>");
                                 page +=temperature_water_greenhouse;
                                 page +=F(" °C</td></tr></table></section>");   
                                       
                                 page +=F("<section id='garden'><h2> Garden </h2><table><tr><td>Température:</td><td></td><td>");
                                 page +=temperature_out;
                                 page +=F(" °C</td></tr><tr><td>Humidité:</td><td></td><td>");
                                 page +=humidity_out;
                                 page +=F(" %</td></tr><tr><td>Température sol:</td><td></td><td>");
                                 page +=temperature_soil_garden;
                                 page +=F(" °C</td></tr><tr><td>Humidité sol:</td><td></td><td>");
                                 page +=moisture_garden;
                                 page +=F(" %</td></tr></table></section>");
                           
                                 page +=F("<section id='compost'><h2> Compost  </h2><table><tr><td>Température:</td><td></td><td>");
                                 page +=average_v_battery;
                                 page +=F(" V</td></tr><tr><td>Courant battery:</td><td></td><td>");
                                 page +=average_a_battery;
                                 page +=F(" A</td></tr><tr><td>Courant load:</td><td></td><td>");
                                 page +=average_a_load;
                                 page +=F(" A</td></tr><tr><td>Température compost:</td><td></td><td>");
                                 page +=temperature_compost;
                                 page +=F(" °C</td></tr><tr><td>Humidité compost:</td><td></td><td>");
                                 page +=humidity_compost;                           
                                 page +=F("  %</td></tr></table></section>");

                                 page +=F("<section id='sent'><h2> Envoi des données  </h2><table><tr><td>Périodicité actuelle ");
                                 page +=period;
                                 page +=F(" secondes</td><td></td><td><form method='get'><input type='hidden' name='envoi' value='1'/><input type='submit' value='envoi'/>");                      
                                 page +=F("</form></td></tr></table></section>");
                                 
                           page +=F("</div>");
                           
                           page +=F("<footer><table><tr><td><a href='http://innogreentech.fr'>InnoGreenTech  </a></td><td></td><td><a href='mailto: info@innogreentech.fr'> Contactez moi</a></td></tr></table></footer>");
                           page +=F("</body></html>");                 
                           return page;
                          }
