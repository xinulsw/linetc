.. _porteus:

Porteus
###################

Porteus jest odmianą Linuksa typu *live* zoptymalizowaną do uruchamiania z nośników wymiennych,
np. kluczy USB. System błyskawicznie się uruchamia i pozwala na zachowanie wprowadzanych zmian,
tj. konfiguracji, oprogramowania czy dokumentów użytkownika. Oparty jest na najstarszej
dystrybucji Linuksa o nazwie `Slackware <https://pl.wikipedia.org/wiki/Slackware>`_.
Przygotowaliśmy 64-bitową spolszczoną wersję ze środowiskiem graficznym `XFCE <https://pl.wikipedia.org/wiki/Xfce>`_, która bardzo dobrze nadaje się m. in. do nauki programowania.


.. figure:: img/porteus322.png

   Porteus 3.2.2 XFCE 64-bit


.. contents:: Spis treści
    :backlinks: none


Klucz USB
=========

Przygotowanie pendrajwa z systemem jest bardzo proste:

1. Pobieramy obraz *iso* systemu: `porteus322.iso <https://drive.google.com/open?id=0B1zG9cfNyT7WWHl0OUp1bVlQMUU>`_ [26.01.2017].

2. Przygotowujemy pustego pendrajwa o pojemności min. 2GB. Im szybszy, tym lepszy!

**W systemie Windows**:

3. Do nagrania Porteusa na pendrajwa polecamy program `Rufus <https://rufus.akeo.ie/?locale=pl_PL>`_. Pobierz, uruchom, wskaż plik *iso* i nagraj.

.. figure:: img/rufus_porteus01.jpg


4. Jeżeli Rufus nie zadziała, rozpakowujemy zawartość obrazu na pendrajwa, np. za pomocą menedżera archiwów `7zip <http://www.7-zip.org/>`_.

5. Wchodzimy do katalogu :file:`boot` na pendrajwie(!) i uruchamiamy plik ``Porteus-installer-for-Windows``, upewniamy się, że wyświetlona została litera wskazująca na pendrajwa i potwierdzamy.

.. figure:: img/porteus_usb_install_windows.jpg


**W systemie Linux**:

3. Montujemy pobrany obraz z uprawnieniami administratora (roota) do katalogu :file:`/mnt/loop`:

.. code-block:: bash

    ~$ sudo mkdir /mnt/loop
    ~S sudo mount -o loop /path/to/Porteus-XFCE-v3.2.2-x86_64.iso /mnt/loop

4. Wkładamy klucz USB, który powinien zostać wykryty jako partycja :file:`/dev/sdb1` lub :file:`/dev/sdc1` i zamontowany w katalogu :file:`/media/nazwa_użytkownika/etykieta_klucza`. Sprawdzimy to poleceniem ``mount|grep "sdb"`` lub otwierając menedżer plików.

5. Kopiujemy zawartość zamontowanego obrazu na pendrajwa za pomocą polecenia (lub menedżera plików):

.. code-block:: bash

    ~$ cp -r /mnt/loop/* /media/nazwa_użytkownika/etykieta_klucza

6. Wchodzimy do katalogu :file:`boot` na pendrajwie(!) i wydajemy polecenie z uprawnieniami roota:

.. code-block:: bash

    /media/nazwa_użytkownika/etykieta_klucza$ sudo bash Porteus-installer-for-Linux.com

– upewniamy się, że wyświetlona została partycja klucza USB (np. :file:`/dev/sdb1`), wpisujemy *ok* i potwierdzamy.

.. figure:: img/porteus_usb_install_linux.jpg


Pierwsze uruchomienie
=====================

Po włożeniu pendrajwa do gniazda USB podczas uruchamiania systemu należy nacisnąć klawisz
wywołujący *Boot menu*. Zazwyczaj jest to któryś z klawiszy funkcyjnych, np.: :kbd:`F12`.
Czasem trzeba wywołać BIOS i dopiero wtedy wybrać wpis typu *USB Device* oznaczający
naszego pendrajwa.

Po pierwszym uruchomieniu, **należy stworzyć plik zapisu**, w którym przechowywane będą wszystkie zmiany.

1. Wybieramy *Start/System/Porteus Setings Centre*, podajemy hasło roota (tj. "toor") i klikamy ikonę dyskietki (1).

2. Klikamy ikonę *Porteus Save Changes* (2) i wybieramy opcję "I want to create a new save file" przyciskiem *Create*.

.. figure:: img/psc02.png

3. W polu "Location" kilkamy ikonę folderu i wskazujemy napęd USB, zazwyczaj "sdb1" lub "sdc1".
   (Po wybraniu nazwy napędu powinniśmy widzieć na nim katalog :file:`porteus`).

4. W polu "Savefile name" wpisujemy nazwę pliku: ``porteussave.dat``. Rozmiar zostawiamy domyślny lub podajemy większy, np. 768 lub 1024 MB. Na koniec klikamy "OK" i czekamy na utworzenie pliku.

.. figure:: img/savefile_02.png


5. Nastęþnie w oknie "Porteus Settings Centre" wybieramy *Edit porteus.cfg* (3). Zamieniamy pierwszy wpis ``changes=/porteus`` na ``changes=/porteussave.dat`` (zgodnie z nazwą utworzonego pliku zapisu).

.. figure:: img/porteus_cfg.png


6. Na koniec **ponownie uruchomiamy system**!


Moduły
=======

Porteus ma budowę modularną, składa się ze skompresowanych paczek w formacie *xzm*, zawierających system plików `SquashFS <https://pl.wikipedia.org/wiki/SquashFS>`_. Na kluczu USB (płycie CD) znajduje się katalog :file:`porteus` zawierający wszystkie moduły w podkatalogach:

* :file:`base` – moduły systemu bazowego,
* :file:`modules` – tu umieszczamy moduły ładowane automatycznie podczas startu,
* :file:`optional` – oprogramowanie dodatkowe, ładowane na żądanie.


.. attention::

    Moduły są aktualizowane, aby usunąć ewentualne błędy lub dodać funkcjonalności:

    * `Lista zmian <https://drive.google.com/open?id=0B1zG9cfNyT7WUms4TnNkX3ZOa2s>`_ »»»
    * `Pobierz moduły <https://drive.google.com/open?id=0B1zG9cfNyT7WSTlWWWdTdzRBQnc>`_ »»»


Obraz iso, katalog :file:`potrteus/modules`, zawiera:

1. :file:`01-glibc-i18n-x86_64-1jay.xzm` – podstawa spolszczenia;
2. :file:`02-pl-locales.xzm` – spolszczenie;
3. :file:`03-fonts-msubuinf.xzm` – zestaw dodatkowych czcionek;
4. :file:`04-devel.xzm` – podstawowe narzędzia deweloperskie (kompilatory);
5. :file:`05-python2.7.11.xzm` – Python 2.7.11, IPython, QtConsole, Matplotlib, PyGame, Terminator, Turtle, PyQt 5.6;
6. :file:`10-qt5-5.6.1-x86_64-1ponce.xzm` – biblioteka Qt 5.6;
7. :file:`12-palemoon-27.0.3-x86_64-1.xzm` – przeglądarka Palemoon 27.x
8. :file:`15-flashplayer-plugin-24.0.0.194.xzm` – wtyczka Flash Player;
9. :file:`20-git-2.9.0-x86_64-1.xzm` – system kontroli wersji `Git <https://pl.wikipedia.org/wiki/Git_(oprogramowanie)>`_;
10. :file:`25-keepassx-2.0.3-x86_64-1alien.xzm` – menedżer haseł;
11. :file:`90-tools.xzm` – narzędzia ``lxrandr`` (zarządzanie ekranami) i ``xmag`` [**Atualizacja 21.01.2017**];
11. :file:`91-geany-1.28-x86_64-1gv.xzm` – Geany, programistyczne IDE;
13. :file:`95-sublime_text_3.xzm` – zaawansowany edytor programistyczny SublimeText 3;
14. :file:`99-home-guest.xzm` – prekonfiguracja środowiska XFCE [**Atualizacja 21.01.2017**].

W katalogu :file:`porteus/optional`:

* :file:`python3.5.2-stuff.xzm` – Python 3.5, IPython, QtConsole, Matplotlib, PyGame, Turtle, PyQt 5.6 ();


Dodatkowe moduły
----------------

`Moduły opcjonalne <https://drive.google.com/open?id=0B1zG9cfNyT7WbzRYa2NiM0tZNUU>`_ do pobrania:

* :file:`libreoffice-5.2.3.3-x86_64.xzm` – spolszczony pakiet biurowy LibreOffice;
* :file:`sqlitestudio3.1.1.xzm` – menedżer baz danych SQLite;
* :file:`etherpad-lite-1.5.7.xzm` – notatnik uruchamiany w przeglądarce umożliwiający współpracę nad dokumentami, polecenia: ``sudo /etc/rc.d/rc.etherpad-lite start``, ``sudo /etc/rc.d/rc.etherpad-lite stop``;
* :file:`vsftpd-3.0.3.xzm` – serwer FTP, polecenia: ``sudo rc.ftp start``, ``sudo rc.ftp stop``
* :file:`gimp-2.8.18.xzm` – zaawansowany edytor graficzny;
* :file:`ghostscript-9.19.xzm` – narzędzia do przetwarzania języka PostScript i fomatu PDF;
* :file:`sylpheed-3.5.1.xzm` – klient pocztowy z filtrem spamu;
* :file:`xnview-0.8.4.xzm` – wielofunkcyjny menedżer plików graficznych;
* :file:`faenza-icon-1.3.xzm` – zestaw ikon Faenza;
* :file:`firefox-52.0b1.xzm` – przeglądarka WWW Firefox;
* :file:`qt-creator-4.2.0.xzm` – lekkie środowisko programistyczne dla biblioteki Qt5.
* :file:`kivy-1.9.1.xzm` – międzyplatformowy framework do projektowania aplikacji wykorzystujących naturalny interfejs użytkownika, w tym aplikacji mobilnych.


Zarządzanie modułami
--------------------

Moduły z katalogu :file:`optional` mogą być (de)aktywowane na żądanie.
Służy do tego *Menedżer modułów*. W menu podręcznym modułów (po kliknięciu
ich prawym klawiszem) znajdziesz również polecenia "Activate" i "Deactivate".

.. figure:: img/menedzer_modulow.png


Wskazówki
=========

1. Jeżeli tworzymy lub ściągamy i zapisujemy wiele plików, warto sprawdzać ilość dostępnego miejsca w pliku zapisu:

.. code-block:: bash

    ~$ du -sh /mnt/live/memory/changes (poda ilość zajętego miejsca)
    ~$ df -h /mnt/live/memory/changes (poda ilość wolnego miejsca)

2. Narzędzie *Start/System/Porteus system info* gromadzi w jednym miejscu informacje nt. komputera,
   w tym również o miejscu instalacji: *Porteus/Boot_info*.

.. figure:: img/psi.png


3. W przypadku wyczerpywania się wolnego miejsca w pliku zapisu możemy zwiększyć jego rozmiar wybierając:

* start systemu w trybie "Always Fresh mode";
* następnie *Start/System/Porteus save file manager* i "I want to resize a save file":

.. figure:: img/resf.png


.. attention::

    Tworzony jest nowy plik zapisu w podanej lokalizacji zawierający dotychczasowe zmiany.
    Nowym plikiem trzeba nadpisać dotychczasowy!


4. Plik zapisu można przenosić między różnymi pendrajwami. Można go archiwizować i przeglądać w dowolnym
   systemie opartym na Linuksie. W tym celu montujemy plik z uprawnieniami roota np. do katalogu :file:`/mnt`:

.. code-block:: bash

    ~$ sudo mount -o loop ścieżka_do_pliku/porteussave.dat /mnt


5. Jeżeli masz problem z ustawieniem jasności ekranu laptopa, spróbuj polecenia z opcjonalnym argumentem:

.. code-block:: bash

    ~$ setbright.sh 190

