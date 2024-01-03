#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int pesoMamifero = 0, pesoAve = 0, pesoReptil = 0, pesoAnfibio = 0;
    int numMamiferos = 0, numAves = 0, numReptiles = 0, numAnfibios = 0;
    int opcClasificacion;
    cout << "ARCA DE NOE" << endl;
    cout << "Ingrese el peso que soporta el ARCA: ";
    int pesoArca;
    cin >> pesoArca;
    int ppesoArca = pesoArca * 0.9;
    
	do{
        cout << "Seleccione la clasificación a llevar:" << endl;
        cout << "1. Mamíferos" << endl;
        cout << "2. Aves" << endl;
        cout << "3. Reptiles" << endl;
        cout << "4. Anfibios" << endl;
        cout << "0. Navegar" << endl;
        cin >> opcClasificacion;

        switch (opcClasificacion) {
        	case 1: {
        		int opcMamifero;
        		do {
        			cout << "\nMamíferos" << endl;
					cout << "Seleccione el animalito a llevar" << endl;
                    cout << "1. Elefante   - 100KG" << endl;
                    cout << "2. Chimpance  - 50KG" << endl;
                    cout << "3. Coati      - 30KG" << endl;
                    cout << "4. Nutria     - 10KG" << endl;
                    cout << "5. Mapache    - 5KG" << endl;
                    cout << "0. Para volver a la clasificación" << endl;
                    cin >> opcMamifero;
                    
                    if (opcMamifero == 0) {
                    	
                        cout << "Regresando..." << endl;
                        
                        } else {
                            int Elefante = 0, Chimpance = 0, Coati = 0, Nutria = 0, Mapache  = 0;
                            int auxElefante = 0, auxChimpance = 0, auxCoati = 0, auxNutria = 0, auxMapache  = 0;

                            switch (opcMamifero) {
                                case 1:
                                    if (auxElefante > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Elefante = 100 * 2;
                                        if ((pesoMamifero + Elefante) > pesoArca || pesoMamifero > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxElefante == 0) {
                                                cout << "Se ha seleccionado Elefante M1" << endl;
                                                numMamiferos += 2;
                                                pesoMamifero += Elefante;
                                                auxElefante += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 2:
                                    if (auxChimpance > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Chimpance = 50 * 2;
                                        if ((pesoMamifero + Chimpance) > pesoArca || pesoMamifero > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxChimpance == 0) {
                                                cout << "Se ha seleccionado Chimpance" << endl;
                                                numMamiferos += 2;
                                                pesoMamifero += Chimpance;
                                                auxChimpance += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 3:
                                    if (auxCoati > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Coati = 30 * 2;
                                        if ((pesoMamifero + Coati) > pesoArca || pesoMamifero > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxCoati == 0) {
                                                cout << "Se ha seleccionado Coati" << endl;
                                                numMamiferos += 2;
                                                pesoMamifero += Coati;
                                                auxCoati += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 4:
                                    if (auxNutria > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Nutria = 10 * 2;
                                        if ((pesoMamifero + Nutria) > pesoArca || pesoMamifero > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxNutria == 0) {
                                                cout << "Se ha seleccionado Nutria" << endl;
                                                numMamiferos += 2;
                                                pesoMamifero += Nutria;
                                                auxNutria += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 5:
                                    if (auxMapache  > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Mapache  = 5 * 2;
                                        if ((pesoMamifero + Mapache) > pesoArca || pesoMamifero > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxMapache  == 0) {
                                                cout << "Se ha seleccionado Mapache " << endl;
                                                numMamiferos += 2;
                                                pesoMamifero += Mapache;
                                                auxMapache  += 1;
                                                break;
                                            }
                                        }
                                    }

                                default:
                                    cout << "Opción no válida" << endl;
                            }
                        }
                    } while (opcMamifero != 0);
                    break;
                }

                case 2: {
                    int opcAve;
                    do {
                        cout << "\nAves" << endl;
                        cout << "Seleccione el animalito a llevar" << endl;
                        cout << "1. Avestruz           - 145KG" << endl;  
                        cout << "2. Albatroz_errante   - 16KG" << endl;  
                        cout << "3. Aguila_calva       - 6KG" << endl;  
                        cout << "4. Alcon_peregrino    - 2kg" << endl;  
                        cout << "5. Colibri            - 0.20kg" << endl;  
                        cout << "0. Para volver a la clasificación" << endl;
                        cin >> opcAve;

                        if (opcAve == 0) {
                            cout << "Regresando..." << endl;
                        } else {
                            int Avestruz = 0, Albatroz_errante = 0, Aguila_calva = 0, Alcon_peregrino = 0, Colibri = 0;
                            int auxAvestruz = 0, auxAlbatroz_errante = 0, auxAguila_calva = 0, auxAlcon_peregrino = 0, auxColibri = 0;

                            switch (opcAve) {
                                case 1:
                                	if (auxAvestruz > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Avestruz = 145 * 2;
                                        if ((pesoAve + Avestruz) > pesoArca || pesoAve > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxAvestruz == 0) {
                                                cout << "Se ha seleccionado Avestruz" << endl;
                                                numAves += 2;
                                                pesoAve += Avestruz;
                                                auxAvestruz += 1;
                                                break;
                                            }
                                        }
                                    }
                                    
                                
                                case 2:
                                    if (auxAlbatroz_errante > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Albatroz_errante = 16 * 2;
                                        if ((pesoAve + Albatroz_errante) > pesoArca || pesoAve > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxAlbatroz_errante == 0) {
                                                cout << "Se ha seleccionado Albatroz_errante" << endl;
                                                numAves += 2;
                                                pesoAve += Albatroz_errante;
                                                auxAlbatroz_errante += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 3:
                                    if (auxAguila_calva > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Aguila_calva = 6 * 2;
                                        if ((pesoAve + Aguila_calva) > pesoArca || pesoAve > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxAguila_calva == 0) {
                                                cout << "Se ha seleccionado Aguila_calva" << endl;
                                                numAves += 2;
                                                pesoAve += Aguila_calva;
                                                auxAguila_calva += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 4:
                                   if (auxAlcon_peregrino > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Alcon_peregrino = 2 * 2;
                                        if ((pesoAve + Alcon_peregrino) > pesoArca || pesoAve > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxAlcon_peregrino == 0) {
                                                cout << "Se ha seleccionado Alcon_peregrino" << endl;
                                                numAves += 2;
                                                pesoAve += Alcon_peregrino;
                                                auxAlcon_peregrino += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 5:
                                	if (auxColibri > 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                        
									} else {
										Colibri = 0.20 * 2;
										if ((pesoAve + Colibri) > pesoArca || pesoAve > pesoArca) {
											cout << "Ya no hay espacio en el arca" << endl;
										} else {
											if (auxColibri == 0) {
												
												cout << "Se ha seleccionado Colibri" << endl;
												numAves += 2;
												pesoAve += Colibri;
												auxColibri += 1;
												break;
                                            }
                                        }
                                    }

                                default:
                                    cout << "Opción no válida" << endl;
                            }
                        }
                    } while (opcAve != 0);
                    break;
                }

                case 3: {
                    int opcReptil;
                    do {
                        cout << "\nReptiles" << endl;
                        cout << "Seleccione el animalito a llevar" << endl;
                        cout << "1. Tortuga_laud        - 900KG" << endl;  
                        cout << "2. Caiman_negro        - 200KG" << endl; 
                        cout << "3. Varano_de_comodo    - 70KG" << endl;  
                        cout << "4. Caiman_de_anteojos  - 40KG" << endl; 
                        cout << "5. Iguana_Verde        - 10kg" << endl;  
                        cout << "0. Para volver a la clasificación" << endl;
                        cin >> opcReptil;

                        if (opcReptil == 0) {
                            cout << "Regresando..." << endl;
                        } else {
                            int Tortuga_laud = 0, Caiman_negro = 0, Varano_de_comodo = 0, Caiman_de_anteojos = 0, Iguana_Verde = 0;
                            int auxTortuga_laud = 0, auxCaiman_negro = 0, auxVarano_de_comodo = 0, auxCaiman_de_anteojos = 0, auxIguana_Verde = 0;

                            switch (opcReptil) {
                                case 1:
                                	if (auxTortuga_laud> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Tortuga_laud = 900 * 2;
                                        if ((pesoReptil + Tortuga_laud) > pesoArca || pesoReptil > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxTortuga_laud == 0) {
                                                cout << "Se ha seleccionado Tortuga_laud" << endl;
                                                numReptiles += 2;
                                                pesoReptil += Tortuga_laud;
                                                auxTortuga_laud += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 2:
                                	if (auxCaiman_negro> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Caiman_negro = 200 * 2;
                                        if ((pesoReptil + Caiman_negro) > pesoArca || pesoReptil > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxCaiman_negro == 0) {
                                                cout << "Se ha seleccionado Caiman_negro" << endl;
                                                numReptiles += 2;
                                                pesoReptil += Caiman_negro;
                                                auxCaiman_negro += 1;
                                                break;
                                            }
                                        }
                                    }
            
                                case 3:
                                	if (auxVarano_de_comodo> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Varano_de_comodo = 70 * 2;
                                        if ((pesoReptil + Varano_de_comodo) > pesoArca || pesoReptil > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxVarano_de_comodo == 0) {
                                                cout << "Se ha seleccionado Varano_de_comodo" << endl;
                                                numReptiles += 2;
                                                pesoReptil += Varano_de_comodo;
                                                auxVarano_de_comodo += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 4:
                                	if (auxCaiman_de_anteojos> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Caiman_de_anteojos = 40 * 2;
                                        if ((pesoReptil + Caiman_de_anteojos) > pesoArca || pesoReptil > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxCaiman_de_anteojos == 0) {
                                                cout << "Se ha seleccionado Caiman_de_anteojos" << endl;
                                                numReptiles += 2;
                                                pesoReptil += Caiman_de_anteojos;
                                                auxCaiman_de_anteojos += 1;
                                                break;
                                            }
                                        }
                                    }
                                    
                                case 5:
                                	if (auxIguana_Verde> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Iguana_Verde = 10 * 2;
                                        if ((pesoReptil + Iguana_Verde) > pesoArca || pesoReptil > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxIguana_Verde == 0) {
                                                cout << "Se ha seleccionado Iguana_Verde" << endl;
                                                numReptiles += 2;
                                                pesoReptil += Iguana_Verde;
                                                auxIguana_Verde += 1;
                                                break;
                                            }
                                        }
                                    }

                                default:
                                    cout << "Opción no válida" << endl;
                            }
                        }
                    } while (opcReptil != 0);
                    break;
                }

                case 4: {
                    int opcAnfibio;
                    do {
                        cout << "\nAnfibios" << endl;
                        cout << "Seleccione el animalito a llevar" << endl;
                        cout << "1. Salamandra_China     - 64KG" << endl;  
                        cout << "2. Salamandra_de_Japon  - 25KG" << endl;  
                        cout << "3. Sapo_Gigante         - 3KG" << endl;  
                        cout << "4. Rana_toro            - 1KG" << endl;  
                        cout << "5. Ajolote              - 0.3KG" << endl;  
                        cout << "0. Para volver a la clasificación" << endl;
                        cin >> opcAnfibio;

                        if (opcAnfibio == 0) {
                            cout << "Regresando..." << endl;
                        } else {
                            int Salamandra_China = 0, Salamandra_de_Japon = 0, Sapo_Gigante = 0, Rana_toro = 0, Ajolote = 0;
                            int auxSalamandra_China = 0, auxSalamandra_de_Japon = 0, auxSapo_Gigante = 0, auxRana_toro = 0, auxAjolote = 0;

                            switch (opcAnfibio) {
                                case 1:
                                	if (auxSalamandra_China> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Salamandra_China = 64 * 2;
                                        if ((pesoAnfibio + Salamandra_China) > pesoArca || pesoAnfibio > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxSalamandra_China == 0) {
                                                cout << "Se ha seleccionado Salamandra_China" << endl;
                                                numAnfibios += 2;
                                                pesoAnfibio += Salamandra_China;
                                                auxSalamandra_China += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 2:
                                    if (auxSalamandra_de_Japon> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Salamandra_de_Japon = 25 * 2;
                                        if ((pesoAnfibio + Salamandra_de_Japon) > pesoArca || pesoAnfibio > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxSalamandra_de_Japon == 0) {
                                                cout << "Se ha seleccionado Salamandra_de_Japon" << endl;
                                                numAnfibios += 2;
                                                pesoAnfibio += Salamandra_de_Japon;
                                                auxSalamandra_de_Japon += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 3:
                                	if (auxSapo_Gigante> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Sapo_Gigante = 3 * 2;
                                        if ((pesoAnfibio + Sapo_Gigante) > pesoArca || pesoAnfibio > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (auxSapo_Gigante == 0) {
                                                cout << "Se ha seleccionado Sapo_Gigante" << endl;
                                                numAnfibios += 2;
                                                pesoAnfibio += Sapo_Gigante;
                                                auxSapo_Gigante += 1;
                                                break;
                                            }
                                        }
                                    }

                                case 4:
                                	if (auxRana_toro> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Rana_toro = 1 * 2;
                                        if ((pesoAnfibio + Rana_toro) > pesoArca || pesoAnfibio > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (Rana_toro == 0) {
                                                cout << "Se ha seleccionado Rana_toro" << endl;
                                                numAnfibios += 2;
                                                pesoAnfibio += Rana_toro;
                                                auxRana_toro += 1;
                                                break;
                                            }
                                        }
                                    }
                                    
                                case 5:
                                	if (auxAjolote> 0) {
                                        cout << "Solo puedes llevar una pareja de animalitos" << endl;
                                    } else {
                                        Ajolote = 0.3 * 2;
                                        if ((pesoAnfibio + Ajolote) > pesoArca || pesoAnfibio > pesoArca) {
                                            cout << "Ya no hay espacio en el arca" << endl;
                                        } else {
                                            if (Ajolote == 0) {
                                                cout << "Se ha seleccionado Ajolote" << endl;
                                                numAnfibios += 2;
                                                pesoAnfibio += Ajolote;
                                                auxAjolote += 1;
                                                break;
                                            }
                                        }
                                    }
                                   
                                default:
                                    cout << "Opción no válida" << endl;
                            }
                        }
                    } while (opcAnfibio != 0);
                    break;
                }

                case 0:
                    if (pesoMamifero >= ppesoArca || pesoAve >= ppesoArca || pesoReptil >= ppesoArca || pesoAnfibio >= ppesoArca) {
                        cout << "El peso libre del arca es: ";
                        int pesolibre = pesoArca - pesoMamifero - pesoReptil - pesoAnfibio - pesoAve;
                        if (pesolibre < 0) {
                            cout << " 0 kg" << endl;
                        } else {
                            cout << pesolibre << " 0 kg" << endl;
                        }

                        cout << "El peso de mamíferos es: " << pesoMamifero << endl;
                        cout << "El número de machos es: " << round(numMamiferos / 2.0) << endl;
                        cout << "El número de hembras es: " << round(numMamiferos / 2.0) << endl;
                        cout <<"\n";
                        cout << "El peso de Aves es: " << pesoAve << endl;
                        cout << "El número de machos es: " << round(numAves / 2.0) << endl;
                        cout << "El número de hembras es: " << round(numAves / 2.0) << endl;
                        cout <<"\n";
                        cout << "El peso de Reptiles es: " << pesoReptil << endl;
                        cout << "El número de machos es: " << round(numReptiles / 2.0) << endl;
                        cout << "El número de hembras es: " << round(numReptiles / 2.0) << endl;
                        cout <<"\n";
                        cout << "El peso de Anfibios es: " << pesoAnfibio << endl;
                        cout << "El número de machos es: " << round(numAnfibios / 2.0) << endl;
                        cout << "El número de hembras es: " << round(numAnfibios / 2.0) << endl;
                    } else {
                        cout << "El arca no puede navegar, debe completar al menos el 90% del peso" << endl;
                    }
                    break;

                default:
                    cout << "No hay esa opción" << endl;
        }
    } while (opcClasificacion != 0);

    return 0;
}
