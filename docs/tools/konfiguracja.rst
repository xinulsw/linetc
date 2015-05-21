Konfiguracja
################

Jeżeli nie chcesz używać udostępnionych przez nas plików zapisu,
możesz sam skonfigurować swój system. Poniżej wskazówki.
    
Ustawienia wstępne
*******************

Okno *QuickSetup ustawienia pierwszego uruchamiania* konfigurujemy
wg zrzutu i klikamy "Ok", dalej potwierdzamy konieczność doinstalowania
pakietu językowego, a w trzecim oknie klikamy "Exit" – bo niczego
jeszcze nie doinstalowaliśmy.

.. figure:: linimg/quicksetup01.png
.. figure:: linimg/quicksetup02.png
.. figure:: linimg/quicksetup03.png

Internet
*********

Uruchamia się *Internet kreator połączenia*, jeśli jesteśmy podpięci do
sieci kablem i dostajemy parametry przez DHCP, powinniśmy zobaczyć komunikat
"Congratulations, you are connected". W przeciwnym razie klikamy "Wired or wireless LAN",
w następnym oknie wybieramy na początek narzędzie "Simple Network Setup".
Po jego uruchomieniu powinniśmy zobaczyć listę wykrytych interfejsów,
z której wybieramy *wlan0* dla połączenia bezprzewodowego. Następnie
w razie potrzeby wskazujemy odpowiednią sieć, metodę zabezpieczeń
i podajemy hasło.

.. figure:: linimg/internet01.png
.. figure:: linimg/internet02.png
.. figure:: linimg/internet03.png
.. figure:: linimg/internet04.png
.. figure:: linimg/internet05.png

Jeżeli uzyskamy połączenie, w oknie "Network Connection Wizard" zobaczymy
aktywne interfejsy. Sugerujemy kliknąć "Cancel", a w ostatnim oknie
informacyjnym "Ok". Na koniec zamykamy okno *Welcome* kreatora.

.. figure:: linimg/internet06.png
.. figure:: linimg/internet07.png

Przeglądarka WWW
*****************

Uaktualnioanie i polonizacja interfejsu omówiona została w dokumnecie
głównym, poniżej konfiguracja dodatkowa.

Wybieramy "Edycja/Preferencje", aby skonfigurować stronę domyślną,
i katalog pobieranych plików, np. :file:`root/Pobrane` (trzeba go utworzyć),
wreszcie opcje śledzenia i historii. Te ostatnie ustawienia wpływają na rozmiar wolnego
miejsca w pliku zapisu.

.. figure:: linimg/palemoon08.png
.. figure:: linimg/palemoon09.png
.. figure:: linimg/palemoon10.png

Na koniec można zainstalować blocker reklam wybierając odpowiedni dodatek,
np. AdBlockEdge, albo korzystając z narzędzia *Pup-Advert-Blocker* (Start/Internet/),
w którym wybieramy serwis "Mvps.org" i klikamy ikonę koła zębatego.
Ściągnięta lista zawierająca adresy IP oraz nazwy serwerów reklamowych
zostanie dodana do pliku :file:`/etc/hosts` i przekierowana na adres
lokalny, co uniemożliwi jakąkolwiek z nimi komunikację ;-)

Plik zapisu
************

Podczas pierwszego zamknięcia system prosi o utworzenie pliku `zapisu <http://puppylinux.org/wikka/SaveFile>`_
(ang. *savefile*), w którym zapisywane będą wprowadzane przez nas zmiany:
konfiguracja, instalacja programów, utworzone dokumenty.

Klikamy więc "Zapisz", następnie "administrator",
wybieramy partycję oznaczającą pendrajwa. W konfiguracjach z 1 dyskiem twardym
będzie ona oznaczona najczęsciej `sdb1` (kierujemy się rozmiarem i typem plików: vfat).

.. figure:: linimg/pupsave01.png
.. figure:: linimg/pupsave02.png
.. figure:: linimg/pupsave03.png

Następnie wybieramy ewentualnie szyfrowanie i system plików. Sugerujemy
`ext2` – najszybszy. Minimalny rozmiar to 512MB, zalecany 768MB.

.. figure:: linimg/pupsave04.png
.. figure:: linimg/pupsave05.png
.. figure:: linimg/pupsave06.png

Opcjonalnie rozszerzamy domyślną nazwę i potwierdzamy zapis.

.. figure:: linimg/pupsave07.png
.. figure:: linimg/pupsave08.png

Na końcu może pojawić się pytanie o przetłumaczenie informacji rozruchowych,
wybieramy "Yes" i potwierdzamy kolejny komunikat. Gdyby pytanie to pojawiło się
następnym razem, wybierzmy "No".

.. figure:: linimg/pupsave09.png

Czcionki
*********

Czcionki *ttf* wystarczy wgrać do katalogu :file:`/usr/share/fonts/default/TTF`.
Można użyć narzędzia *Manager fontów* (Start/Desktop/Desktop).

.. raw:: html

    <hr />

:Autor: Robert Bednarz (ecg@ecg.vot.pl)

:Utworzony: |date| o |time|

.. |date| date::
.. |time| date:: %H:%M

.. raw:: html

    <style>
        div.code_no { text-align: right; background: #e3e3e3; padding: 6px 12px; }
        div.highlight, div.highlight-python { margin-top: 0px; }
    </style>
