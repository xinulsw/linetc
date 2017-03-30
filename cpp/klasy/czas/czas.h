#ifndef CZAS_H
#define CZAS_H

class Czas {
	public:
		Czas(int = 0, int = 0, int = 0); //konstruktor
		void ustawCzas( int, int, int );	//ustawia godz., min, i sek.
		void drukujWojskowy();				//wyświetla czas w formacie wojskowym
		void drukujStandard();				//wyświetla czas w formacie standardowym
			
	private:
		int godz;	//0-23
		int min;		//0-59
		int sek;		//0-59
		/* add your private declarations */
};

#endif /* CZAS_H */
