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

1. Pobieramy obraz *iso* systemu: `porteus322.iso <https://drive.google.com/open?id=0B1zG9cfNyT7WWHl0OUp1bVlQMUU>`_ [17.01.2017].

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

1. Wybieramy *Start/System/Porteus Setings Centre*, podajemy hasło roota (tj. "toor") i klikamy ikonę dyskietki.

.. figure:: img/psc01.png

.. figure:: img/psc02.png


2. Klikamy ikonę *Porteus Save Changes* i wybieramy opcję "I want to create a new save file" przyciskiem *Create*.

.. figure:: img/savefile_01.png


3. W polu "Location" kilkamy ikonę folderu i wskazujemy napęd USB.
W komputerach z jednym dyskiem twardym będzie to nazwa "sdb1". Jeżeli mamy wątpliwości, możemy uruchomić *Start/System/Porteus system info*, kliknąć *Porteus/Boot_info* i sprawdzić wpis "# Booting device".

.. figure:: img/psi.png


4. W polu "Savefile name" wpisujemy nazwę pliku: ``porteussave.dat``. Rozmiar zostawiamy domyślny lub podajemy większy, np. 768 lub 1024 MB. Na koniec klikamy "OK".

.. figure:: img/savefile_02.png


5. Po zapisaniu pliku powracamy do okna "Porteus Settings Centre", w którym wybieramy *Edit porteus.cfg*. Plik ten znajduje się w katalogu :file:`/boot/syslinux` na pendrajwie i definiuje opcje startowe systemu. Odszukujemy pierwszy wpis ``changes=/porteus`` i zmieniamy na ``changes=/porteussave.dat`` zgodnie z podaną wcześniej nazwą pliku zapisu.

.. figure:: img/porteus_cfg.png


Na koniec **ponownie uruchomiamy system**!


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
3. :file:`03-fonts-ms-ubu.xzm` – zestaw dodatkowych czcionek;
4. :file:`04-devel.xzm` – podstawowe narzędzia deweloperskie (kompilatory);
5. :file:`05-qt5-5.6.1-x86_64-1ponce.xzm` – biblioteka Qt 5.6;
6. :file:`06-python2.7.11-stuff.xzm` – Python 2.7.11, IPython, QtConsole, Matplotlib, PyGame, Terminator, Turtle, PyQt 5.6;
7. :file:`10-geany-1.28-x86_64-1gv.xzm` – Geany, programistyczne IDE;
8. :file:`11-palemoon-27.0.3-x86_64-1.xzm` – przeglądarka Palemoon 27.x
9. :file:`12-git-2.9.0-x86_64-1.xzm` – system kontroli wersji `Git <https://pl.wikipedia.org/wiki/Git_(oprogramowanie)>`_;
10. :file:`15-keepassx-2.0.3-x86_64-1alien.xzm` – menedżer haseł;
11. :file:`50-infinality-fonts.xzm` – poprawione wyświetlanie czcionek;
12. :file:`90-tools.xzm` – narzędzia ``lxrandr`` (zarządzanie ekranami) i ``xmag`` [**Atualizacja 21.01.2017**];
13. :file:`95-sublime_text_3.xzm` – zaawansowany edytor programistyczny SublimeText 3;
14. :file:`99-home-guest.xzm` – prekonfiguracja środowiska XFCE [**Atualizacja 21.01.2017**].

W katalogu :file:`porteus/optional`:

* :file:`python3.5.2-stuff.xzm` – Python 3.5, IPython, QtConsole, Matplotlib, PyGame, Turtle, PyQt 5.6 ();


Dodatkowe moduły
----------------

`Moduły opcjonalne <https://drive.google.com/open?id=0B1zG9cfNyT7WbzRYa2NiM0tZNUU>`_ do pobrania:

* :file:`libreoffice-5.2.3.3-x86_64.xzm` – spolszczony pakiet biurowy LibreOffice;
* :file:`sqlitestudio3.1.1.xzm` – menedżer baz danych SQLite;
* :file:`etherpad-lite-1.5.7.xzm` – notatnik uruchamiany w przeglądarce umożliwiający współpracę nad dokumentami;


Zarządzanie modułami
--------------------

Moduły z katalogu :file:`optional` mogą być (de)aktywowane na żądanie.
Służy do tego *Menedżer modułów*. W menu podręcznym modułów (po kliknięciu
ich prawym klawiszem) znajdziesz również polecenia "Activate" i "Deactivate".

.. figure:: img/menedzer_modulow.png


Wskazówki
=========

 Jeżeli tworzymy lub ściągamy i zapisujemy wiele plików, warto sprawdzać ilość dostępnego miejsca w pliku zapisu:

.. code-block:: bash

    ~$ du -sh /mnt/live/memory/changes (poda ilość zajętego miejsca)
    ~$ df -h /mnt/live/memory/changes (poda ilość wolnego miejsca)

W przypadku wyczerpywania się wolnego miejsca w pliku zapisu możemy zwiększyć jego rozmiar wybierając:

* start systemu w trybie "Always Fresh mode";
* następnie *Start/System/Porteus save file manager* i "I want to resize a save file":

.. figure:: img/resf.png


.. attention::

    Tworzony jest nowy plik zapisu w podanej lokalizacji zawierający dotychczasowe zmiany.
    Nowym plikiem trzeba nadpisać dotychczasowy!


Metryka
-------

:Autor: Robert Bednarz (ecg@ecg.vot.pl)

:Utworzony: |date| o |time|

.. |date| date::
.. |time| date:: %H:%M

.. raw:: html

    <style>
        div.code_no { text-align: right; background: #e3e3e3; padding: 6px 12px; }
        div.highlight, div.highlight-python { margin-top: 0px; }
    </style>
