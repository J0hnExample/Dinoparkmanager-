/////////////////////////////////////ProSaurier v.1.0////////////////////////////////////
/////////////////////////////////Dino Park Manager Software//////////////////////////////
///////////////////////Autor: Sascha Athmer 	10.01.2016			/////////////////////


//Bibliotheken

#include "lib.h" 				//keine standart Bibliothek
#define F_SAVE "./zoo.db"		//Definition für Speicherdatei

// Deklarationsbereich für die einzelnen Funktionen *Prototypen*

// Struckturen

typedef struct					//Strucktur zur verwaltung der Tier Eigenschaften
{
	char tierart[64];
	char epoche[64];
	int	exemplare;
	char bemerkungen[64];
	int number;
}
dino;


// Funktionen für die Darstellung des Menus

void layout(int Xpos1, int Ypos1);	// Layout Funktion

void menu(int Xpos, int Ypos);		// Hauptmenu

//Funktionen um Tierarten einzugeben
void tierneu(int Xpos, int Ypos);		// Menu Neues Tier

int tiereingabe(void);				// Funktion mehrere Tierarten eingeben
int tiereinzeleingabe(void);			// Funktion eine Tierart hinzufügen
dino artin(void);					// Funktion zur eingabe neuer Arten

// Tierart löschen
void tierweg(int Xpos, int Ypos);		// Menu Tier entfernen
void erase(void);					// Funktion zum löschen
// Tierarten Darstellen
void tierliste(int Xpos, int Ypos);	// Menu Tierarten auflisten
void anzeige(void);					// Listet die Tierarten auf
void artout(dino x);				// Layoutfunktion zur Auflistung

void tiersortier(int Xpos, int Ypos);	// Menu Tiere sortieren
void sortier(void);					// Alphabetische sortierung

void tiersuche(int Xpos, int Ypos);	// Menu Tiere suchen
int serch(void);					// Suchfunktion

// Technische Funktionen

void mess(char ZKette[] );		// Rückmeldung über ausgewähltes Menu

char eingabe(char t);			//Eingabefunktion für die Menuauswahl

// Speichern und Auslesen
void save(void);				//Speichern der Daten

void readdat(void);				//Auslesen der Datei
// Globale Variablen

dino liste[5];						// Variable zur aufnahme von 5 Tierarten
int anzahl = 0;					// Anzahl der Tierarten im Programms
int Xglopos = 8;					//globale Layout Variablen
int Yglopos = 3;
// Start des Programms main Funktion

int main(void)
{

	cls(); // Säubert den Bildschirm

	readdat();	// Speicher auslesen

	// Deklarationsbereich für die main Variablen

	char Antwort; 	// Variable für die Menuauswahl
	char t;		// Variable zur übernahme des return werts aus der Eingabe Funktion

	// Fußgesteuerte Schleife für die Menuauswahl
	do
	{
		// Funktionsaufruf und Definition der enthaltenen Variablen
		layout(10,2);	//Aufruf der layout Funktion
		menu(10,8); 	//Aufruf der Hauptmenu Funktion


		Antwort = eingabe(t); // Übergabe des return wertes aus der eingabe Funktion in die Antwort Variable

		// Die Verschiedenen Auswahlmöglichkeiten des Hauptmenu

		switch(Antwort)
		{
			case '1':	//bestätigung um neues Tier hinzuzufügen
				cls();
				tierneu(10,8);
				break;

			case '2':	//bestätigung um vorhandenes Tier zu entfernen
				cls();
				mess("Vorhandene Tierart entfernen wurde gewählt");
				tierweg(10,8);
				break;

			case '3': 	//bestätigung alle vorhandenen Tiere auflisten
				cls();
				mess("Vorhandene Tierart auflisten wurde gewählt");
				tierliste(10,8);
				break;

			case '4':	//bestätigung vorhandene Tiere sortieren
				cls();
				mess("Vorhandene Tiere sortieren wurde gewählt");
				tiersortier(10,8);
				break;

			case '5':	//bestätigung ein Tier suchen
				cls();
				mess("Tier suchen wurde gewählt");
				tiersuche(10,8);
				break;

			case 'x':	//bestätigung Menu verlassen
				cls();
				save();
				mess("Das programm wurde verlassen\n\n\n\n ");
				break;

			default :	//bestätigung falsche Eingabe
				mess("Falsche Eingabe bitte Menupunkt 1-5 wählen oder x für verlassen");

		}

	}
	while(Antwort != 'x'); // Fuß der Schleife beendet bei x die schleife

	return 0;
}
////////////////////////////////////// Funktionsbereich ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

// 	Funktion für das Programmlayout

void layout(int Xpos1, int Ypos1)
{
	// Layout und Überschrift des Programms

	gotoXY(Xpos1+4,Ypos1++);		printf("**** ProSaurier V.1.0 - Dino Park Manager Software 2017 ****\n\n");
	gotoXY(Xpos1,Ypos1++);
	gotoXY(Xpos1+14,Ypos1++); 	printf("64K RAM SYSTEM 389911 BASIC cordS FREE");
	gotoXY(Xpos1,Ypos1++);
	gotoXY(Xpos1,Ypos1++);		printf("By Sascha Mertens");
	gotoXY(Xpos1++,Ypos1+14);	printf("Wählen Sie einen Menupunkt (Zahl) (x) für Beenden");

}
// Menu Funktion darstellung und Layout der Menueinträge

void menu(int Xpos, int Ypos)
{
	// Darstellung und formatierung der einzelnen Hauptmenu Punkte

	gotoXY(Xpos-8,Ypos++);	printf("        Hauptmenu");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(1) - Neue Tierart hinzufügen");
	gotoXY(Xpos,Ypos++);	printf("(2) - Vorhandene Tierart löschen");
	gotoXY(Xpos,Ypos++);	printf("(3) - Alle Tierarten auflisten");
	gotoXY(Xpos,Ypos++);	printf("(4) - Tierarten sortieren");
	gotoXY(Xpos,Ypos++);	printf("(5) - Eine Tierart suchen");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(x) - Beenden");
	gotoXY(Xpos-1,Ypos+4);

}

// Funktion für die Ausgabe der Rückmeldung zum gewählten Menu Punkt

void mess(char ZKette[])
{
	char t;
	//Räumt die Zeile zur Rückmeldungsausgabe auf
	gotoXY(2,20);
	printf("                                                                  ");
	//Ruft Rüchmeldung nach Auswahl auf
	gotoXY(2,20);
	printf("%s", ZKette);

}

// Funktion zur abfrage der User Eingabe und rückgabe der Eingabe an die main Funktion

char eingabe(char t)
{
	t = getch();  	// Definition von t als User Eingabe

	return t;	// Rückgabe der User Eingabe an die main Funktion bzw. untermenu Funktionen

}
////////////////////Hier beginnen die Funktionen für die einzelnen Menu Unterpunkte ///////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// Menupunkt neues Tier hinzufügen
void tierneu(int Xpos, int Ypos)
{
	// Funktionsaufruf und Definition der enthaltenen Variablen
	layout(10,2);	//Aufruf der layout Funktion


	// Menu Variablen
	char Antwort; 	// Variable für die Menuauswahl
	char t;		// Variable zur übernahme des return werts aus der Eingabe Funktion

	// Darstellung und formatierung der einzelnen Menu Punkte


	gotoXY(Xpos-8,Ypos++);	printf("        Hier können neue Tierarten dem Park hinzugefügt werden");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(1) - Mehrere Tierarten hinzufügen - Aktuell %i", anzahl);
	gotoXY(Xpos,Ypos++);	printf("(2) - Eine einzelne Tierart hinzufügen");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(x) - Zurück zum Hauptmenu");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("Anzahl Tierarten: %i\n", anzahl);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos-1,Ypos+4);

	// Übergabe des return wertes aus der eingabe Funktion in die Antwort Variable


	do
	{
		Antwort = eingabe(t);	//Übergabe der Eingabe Variable an die Antwort Variable

		switch(Antwort)
		{			//bestätigung um neues Tier hinzuzufügen
			case '1':
				mess("Neue Tierart hinzufügen gewählt");
				Xglopos = 8;			//Reset für Globale Variablen
				Yglopos = 3;			//
				tiereingabe();
				anzeige();
				break;
			case '2':
				mess("Einzelne Tierart Hinzufügen gewählt");
				tiereinzeleingabe();
				anzeige();
				break;
			case 'x':
				cls();
				mess("Das Menu wurde verlassen\n ");
				break;
			default:
				mess("#############################################################\n####Falsche eingabe! Tierart eingeben 1 oder x für zurück#####\n##############################################################");
				break;

		}



	}
	while(Antwort != 'x'); // Fuß der Schleife beendet bei x die schleife

}
//Neues Tier eingeben von Teil 2///////////////////////////////////////////////
int tiereingabe(void)
{
		//Index Variablen für Array Eingabe
		int i=0;
		dino m;			//Zuweisung einer Übergabe Variable für die Strucktur
		char Antwort;


		//Start der Eingabe
		do
		{
			//Übergabe der Eingaben an das Array
			i = anzahl;
			m = artin();
			liste[i] = m;
			anzahl++;

			gotoXY(8,21); printf("#####################I %i Tier(e) eingegeben I########################", anzahl);
			if (anzahl >= 5)
		 	{
				mess("###### Maximale Anzahl Tierarten eingegeben [x] für Zurück ######");
			}
			else
			{
				mess("Möchten sie weitere Tiere hinzufügen? (Esc = nein, Anykey = Weiter");
			}


			Antwort = getch();
			//Zählung der Array einträge für spätere Darstellungen
			i++;


			// Verhinderung überzähliger Array Einträge
			if (anzahl == 5)
			{
				Antwort = 27;
			}


		} while( Antwort != 27 ); //Beendet die Eingabe mit Esc

		//Aufruf der Auflistungsfunktion und wiederholung für die einzelnen Einträge
		cls();
		gotoXY(8,1);	printf("Eingegebene Tierarten %i	[1] für neu eingeben [x] für Zurück", anzahl);

		for (i = 0; i < anzahl; i++)
		{
			artout(liste[i]);
		}
}

// Eine Tierart hinzufügen ///////////////Teil 2////////////////////////////////
int tiereinzeleingabe(void)
{
		//Index Variablen für Array Eingabe
		int i=0;
		dino m;			//Zuweisung einer Übergabe Variable für die Strucktur
		char Antwort;

		int controll = 0;	//Kontrollvariable zur einmaligen Ausführun
		//Start der Eingabe
		do
		{
			//Übergabe der Eingaben an das Array
			i = anzahl;
			m = artin();
			liste[i] = m;
			anzahl++;

			gotoXY(8,18); printf("Weiter mit Eingabe");


			Antwort = getch();
			//Zählung der Array einträge für spätere Darstellungen
			i++;
			controll++;


			// Verhinderung überzähliger Array Einträge
			if (anzahl == 5)
			{
				Antwort = 27;
			}


		} while( controll != 1 ); //Beendet die Eingabe mit Esc

		//Aufruf der Auflistungsfunktion und wiederholung für die einzelnen Einträge
		cls();
		gotoXY(8,1);	printf("Eingegebene Tierarten %i	[1] für neu eingeben [x] für Zurück", anzahl);

		for (i = 0; i < anzahl; i++)
		{
			artout(liste[i]);
		}
}

// Eingaberoutine für neue Art /////////////// Teil 2 ///////////////////////////
dino artin(void)
{
	// Layout und Screenbereinigung
	cls();
	layout(10,2);


	dino q;		// Übergabeparameter für Eingabe

	// Eingaben der einzelnen Eigenschaften
	gotoXY(8,6); printf("Art eingeben z.B. Trex:            ");
	scanf("%s", q.tierart);
	gotoXY(8,7); printf("Epoche eingeben z.B. Kreidezeit:   ");
	scanf("%s", q.epoche);
	gotoXY(8,8); printf("Anzahl Exemplare:                  ");
	scanf("%i", &q.exemplare);
	gotoXY(8,9); printf("Bemerkungen z.B. Mutter, Krank:    ");
	scanf("%s", q.bemerkungen);


	kbclr();
	return q;
}

// Menupunkt Tier entfernen
void tierweg(int Xpos, int Ypos)
{
	// Funktionsaufruf und Definition der enthaltenen Variablen
	layout(10,2);	//Aufruf der layout Funktion


	// Menu Variablen
	char Antwort; 	// Variable für die Menuauswahl
	char t;		// Variable zur übernahme des return werts aus der Eingabe Funktion

	// Darstellung und formatierung der einzelnen Menu Punkte


	gotoXY(Xpos-8,Ypos++);	printf("        Hier konnen Tiere aus dem Park entfernt werden");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(1) - Tier entfernen");
	gotoXY(Xpos,Ypos++);	printf("(x) - Zurück zum Hauptmenu");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos-1,Ypos+4);

	// Übergabe des return wertes aus der eingabe Funktion in die Antwort Variable


	do
	{
		Antwort = eingabe(t);	//Übergabe der Eingabe Variable an die Antwort Variable

		switch(Antwort)
		{			//bestätigung um neues Tier hinzuzufügen
			case '1':
				mess("Tier löschen wurde Gewählt");
				erase();
				break;
			case 'x':
				cls();
				mess("Das Menu wurde verlassen\n ");
				break;
			default:
				mess("Falsche Eingabe bitte Menupunkt 1 oder x für zurück");
				break;

		}



	}
	while(Antwort != 'x'); // Fuß der Schleife beendet bei x die schleife





}
// Funktion zum löschen
void erase(void)
{
	int numb;	//Auswahlvariable
	int j;	//Steuerungsvariable
	cls();
	gotoXY(10,8);  printf("\nNummer des zu löschenden Tieres Eingeben\n");
	scanf("%d", &numb);

	numb--;	// Auswahlvariable


	for (j=numb; j<anzahl-1; j++)
	{
		liste[j] = liste[j+1];
	}
	anzahl--;
	anzeige();
}
// Menupunkt auswahl Tiere auflisten
void tierliste(int Xpos, int Ypos)
{
	// Funktionsaufruf und Definition der enthaltenen Variablen
	layout(10,2);	//Aufruf der layout Funktion


	// Menu Variablen
	char Antwort; 	// Variable für die Menuauswahl
	char t;		// Variable zur übernahme des return werts aus der Eingabe Funktion

	// Darstellung und formatierung der einzelnen Menu Punkte


	gotoXY(Xpos-8,Ypos++);	printf("        Hier konnen Tierarten aus dem Park aufgelistet werden");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(1) - Tiere auflisten");
	gotoXY(Xpos,Ypos++);	printf("(x) - Zurück zum Hauptmenu");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos-1,Ypos+4);

	// Übergabe des return wertes aus der eingabe Funktion in die Antwort Variable


	do
	{
		Antwort = eingabe(t);	//Übergabe der Eingabe Variable an die Antwort Variable

		switch(Antwort)
		{			//bestätigung um neues Tier hinzuzufügen
			case '1':
				mess("Hier könnten Tiere aufgelistet werden");
				anzeige();
				break;
			case 'x':
				cls();
				mess("Das Menu wurde verlassen\n ");
				break;
			default:
				mess("#############################################################\n####Falsche eingabe! Auflistung 1 oder x für zurück#####\n##############################################################");
				break;

		}



	}
	while(Antwort != 'x'); // Fuß der Schleife beendet bei x die schleife


}
// Funktion zur Auflistung der Tierarten ruft Funktion artout() auf /////Teil 2 /////
void anzeige(void)
{
	//Index Variablen
	int i=0;
	//Reset der globalen layout Variablen
	Yglopos = 3;
	Xglopos = 8;
	// Aufruf der Auflistungsfunktion und wiederholung für die einzelnen Einträge
	cls();
	gotoXY(8,1);	printf("Eingegebene Tierarten %i	[x] für Zurück", anzahl);

	for (i = 0; i < anzahl; i++)
	{
		artout(liste[i]);
	}
}
// Layout Funktion zur Auflistung der Tierarten /////////// Teil 2 /////////////
void artout(dino x)
{
	gotoXY(Xglopos,Yglopos++); 		printf("Tierart:     %s", x.tierart);
	gotoXY(Xglopos,Yglopos++);		printf("Exemplare:   %i", x.exemplare);
	gotoXY(Xglopos,Yglopos++);		printf("Epoche:      %s", x.epoche);
	gotoXY(Xglopos,Yglopos++);		printf("Bemerkungen: %s", x.bemerkungen);
}

// Menupunkt Tiere Sortieren //////////// Teil 2 ///////////////////////////////
void tiersortier(int Xpos, int Ypos)
{
	// Funktionsaufruf und Definition der enthaltenen Variablen
	layout(10,2);	//Aufruf der layout Funktion


	// Menu Variablen
	char Antwort; 	// Variable für die Menuauswahl
	char t;		// Variable zur übernahme des return werts aus der Eingabe Funktion

	// Darstellung und formatierung der einzelnen Menu Punkte


	gotoXY(Xpos-8,Ypos++);	printf("        Hier können Tierarten nach Alphabet sortiert werden");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(1) - Tiere sortieren und Anzeigen");
	gotoXY(Xpos,Ypos++);	printf("(x) - Zurück zum Hauptmenu");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos-1,Ypos+4);

	// Übergabe des return wertes aus der eingabe Funktion in die Antwort Variable


	do
	{
		Antwort = eingabe(t);	//Übergabe der Eingabe Variable an die Antwort Variable

		switch(Antwort)
		{			//bestätigung um neues Tier hinzuzufügen
			case '1':
				mess("Tierearten nach Alphabet sortieren");
				sortier();
				break;
			case 'x':
				cls();
				mess("Das Menu wurde verlassen\n ");
				break;
			default:
				mess("#############################################################\n####Falsche eingabe! Auflistung 1 oder x für zurück#####\n##############################################################");
				break;

		}



	}
	while(Antwort != 'x'); // Fuß der Schleife beendet bei x die schleife





}
// Sortierung der eingetragenen Tiere nach Alphabet //////////////////Teil 2 ////
void sortier(void)
{
	//Steuerungsvariablen für die Sortierung
	int j;
	int sort;

	do
	{
		sort = 0;
		for(j = 0; j < anzahl-1; j++)
	     {
			//strcmp vergleicht die ASCII werte der beiden Eintragungen
	     	if(strcmp(liste[j].tierart, liste[j+1].tierart) > 0)
	     	{
				//Legt eine Temporäre Strucktur zur Übergabe an und
				//übergibt die Eintragungen
	          	dino temp = liste[j];
	          	liste[j] = liste[j+1];
	          	liste[j+1] = temp;
				sort = 1;
	     	}
	     }
	}
     while (sort);		//Führt die Schleife so lange aus bis nichts mehr übergeben wurde (0)
	anzeige();
	gotoXY(40,3); printf("Liste wurde nach Alphabet sortiert");
}
// Menupunkt Tier Suchen
void tiersuche(int Xpos, int Ypos)
{
	// Funktionsaufruf und Definition der enthaltenen Variablen
	layout(10,2);	//Aufruf der layout Funktion


	// Menu Variablen
	char Antwort; 	// Variable für die Menuauswahl
	char t;		// Variable zur übernahme des return werts aus der Eingabe Funktion

	// Darstellung und formatierung der einzelnen Menu Punkte


	gotoXY(Xpos-8,Ypos++);	printf("        Hier können Tiere gesucht werden");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);	printf("(1) - Tier suchen");
	gotoXY(Xpos,Ypos++);	printf("(x) - Zurück zum Hauptmenu");
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos,Ypos++);
	gotoXY(Xpos-1,Ypos+4);

	// Übergabe des return wertes aus der eingabe Funktion in die Antwort Variable


	do
	{
		Antwort = eingabe(t);	//Übergabe der Eingabe Variable an die Antwort Variable

		switch(Antwort)
		{			//bestätigung um neues Tier hinzuzufügen
			case '1':
				mess("Hier könnte ein Tier gesucht werden");
				serch();
				break;
			case 'x':
				cls();
				mess("Das Menu wurde verlassen\n ");
				break;
			default:
				mess("Falsche Eingabe bitte Menupunkt 1 oder x für zurück");
				break;

		}



	}
	while(Antwort != 'x'); // Fuß der Schleife beendet bei x die schleife



}
////////77777777777///////////////Funktionen Teil3/////////////////////////////////////

// Funktion zur Suche
int serch(void)
{
	char Muster[64];	// Eingabe Suche
	int j;			// Steuerungsvariable
	int found = 0;		// Kontrollvariable

	// Layout und Design

	cls();
	layout(10,2);

	gotoXY(8,10); printf("\nGesuchte Tierart eingeben:\n");

	gets(Muster);		//Eingabe der Suche

	// Suchablauf

	for (j = 0; j < anzahl; j++)
	{
		if (strcmp(Muster, liste[j].tierart) ==0)	// Vergleich der Strings Muster und Tierart
		{
			Xglopos = 20;						// globale Layout Variablen Reset
			Yglopos = 13;
			artout(liste[j]);					// Ausgabe Ergebniss
			found = 1;						//
		}
	}
	if (found == 0)							// Bei fehlender Übereinstimmung
	{
		printf("\n****** Es gab keinen Treffer ******\n");
	}
}

// Speicherfunktion
void save(void)
{
	// Reservierung Adressbereich / öffnen der Datei
	FILE *h = fopen (F_SAVE, "w");

	// Schreiben der Arrayeinträge
	fwrite (&liste, sizeof(dino), anzahl, h);

	// Schließen und Speichern der Datei mit Arrayinhalt
	fclose(h);
}
// Auslesefunktion
void readdat(void)
{
	dino m;						// Dummystrucktur
	int controll = 1;				// Kontrollvariable für Arrayeintrag überprüfung
	FILE *h = fopen (F_SAVE, "a+");	// fopen a+ = lesen/erstellen Reservierung und übergabe an h

	// Lesen der Arrayeinträge
	do
	{
		fread (&m, sizeof(dino), 1, h);
		if (feof(h))					// Prüft Arrayinhalt
		{
			controll=0;
		}
		else
		{
			liste[anzahl] = m;			// Überträgt inhalt in Arrayliste
			anzahl++;
		}
	} while(controll);

	// Schließen der Datei mit Arrayinhalt
	fclose(h);

	//return m;
}




/*************************************** ENDE ********************************************/

//10.01.2016 Sascha Mertens
