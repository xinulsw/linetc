.. _porteus:

Porteus
###################

Porteus jest odmianą Linuksa typu *live* zoptymalizowaną do uruchamiania z nośników wymiennych,
np. kluczy USB. Efekty pracy potrafi zapisywać w specjalnym pliku lub na wskazanej partycji.
Oparty jest na najstarszej dystrybucji Linuksa o nazwie `Slackware <https://pl.wikipedia.org/wiki/Slackware>`_.

.. contents:: Spis treści
    :backlinks: none


Pobieranie i nagrywanie
=======================

1. Pobieramy obraz iso 64-bitowej wersji ze środowiskiem graficznym `XFCE <https://pl.wikipedia.org/wiki/Xfce>`_: `Porteus-XFCE-v3.2.2-x86_64.iso <http://dl.porteus.org/x86_64/Porteus-v3.2.2/Porteus-XFCE-v3.2.2-x86_64.iso>`_.

2. Przygotowujemy pustego pendrajwa o pojemności min. 2GB. Im szybszy, tym lepszy!


**W systemie Linux**:

3. Montujemy pobrany obraz z uprawnieniami administratora (roota) do katalogu :file:`/mnt/loop`:

.. code-block:: bash

    ~$ sudo mkdir /mnt/loop
    ~S sudo mount -o loop /path/to/Porteus-XFCE-v3.2.2-x86_64.iso /mnt/loop

4. Wkładamy klucz USB, który powinien zostać wykryty jako partycja :file:`/dev/sdb1` lub :file:`/dev/sdc1` i zamontowany w katalogu :file:`/media/nazwa_użytkownika/etykieta_klucza`. Sprawdzimy to poleceniem ``mount|grep "sdb"`` lub otwierając menedżer plików.

5. Kopiujemy zawartość zamontowanego obrazu na pendrajwa:

.. code-block:: bash

    ~$ cp -r /mnt/loop/* /media/nazwa_użytkownika/etykieta_klucza

– lub za pomocą menedżera plików.

6. Wchodzimy do katalogu :file:`boot` na pendrajwie(!) i wydajemy polecenie z uprawnieniami roota:

.. code-block:: bash

    /media/nazwa_użytkownika/etykieta_klucza$ sudo bash Porteus-installer-for-Linux.com

– upewniamy się, że wyświetlona została partycja klucza USB (np. :file:`/dev/sdb1`), wpisujemy *ok* i potwierdzamy.

.. figure:: img/porteus_usb_install_linux.jpg


**W systemie Windows**:

3. Do nagrania Porteusa na pendrajwa możemy wykorzystać program `Rufus <https://rufus.akeo.ie/?locale=pl_PL>`_.

4. Jeżeli Rufus nie zadziała, rozpakowujemy zawartość obrazu na pendrajwa, np. za pomocą menedżera archiwów `7zip <http://www.7-zip.org/>`_.

5. Wchodzimy do katalogu :file:`boot` na pendrajwie(!) i uruchamiamy plik ``Porteus-installer-for-Windows``, upewniamy się, że wyświetlona została litera wskazująca na pendrajwa i potwierdzamy.

.. figure:: img/porteus_usb_install_windows.jpg


Budowa
======

Porteus ma budowę modularną, słada się z paczek zawierających system plików SquashFS. Na kluczu USB (płycie CD) znajduje się katalog :file:`porteus` zawierający wszystkie moduły w podkatalogach:

* :file:`base` – moduły systemu bazowego,
* :file:`modules` – tu umieszczamy moduły ładowane automatycznie podczas startu,
* :file:`optional` – oprogramowanie dodatkowe, ładowane na żądanie.

[todo]

Dodatkowe moduły, które udostępniamy, umieszczamy w katalogu modules, jeśli mają być ładowane automatycznie, lub w katalogu optional, jeśli chcemy je ładować w miarę potrzeb. Wtedy wykorzystujemy program "Aktywuj moduł opcjonalny".
Pierwsze uruchomienie

System błyskawicznie się uruchamia i pozwala na zachowanie wprowadzanych zmian, tj. konfiguracji, oprogramowania czy dokumentów użytkownika. W tym celu należy utworzyć specjalny plik zapisu.

Wybieramy Start/System/Porteus Setings Centre, podajemy hasło roota (administratora), czyli toor, i klikamy ikonę dyskietki.

Porteus Settings Center

Klikamy ikonę Porteus Save Changes i wybieramy opcję "I want to create a new save file" przycieskiem Create.

W polu "Location" kilkamy ikonę folderu i wskazujemy napęd USB. W komputerach z jednym dyskiem twardym będzie to nazwa "sdb1". Jeżeli mamy wątpliwości, możemy uruchomić Start/System/Porteus system info, kliknąć Porteus/Boot_info i sprawdzić wpis "# Booting device".

Wybór napędu sdb1

W polu "Savefile name" wpisujemy nazwę pliku, np. "porteussave.dat", rozmiar zostawiamy domyślny. Na koniec klikamy "OK".

Savefile manager

Po zapisaniu pliku powracamy do okna "Porteus Settings Centre", w którym wybieramy Edit porteus.cfg. Plik ten znajduje się w katalogu /boot/syslinux i definiuje opcje startowe systemu. Odszukujemy pierwszy wpis "changes=/porteus" i zmieniamy na changes=/porteussave.dat zgodnie z podaną wcześniej nazwą pliku zapisu.

porteus.cfg

Po ponownym uruchomieniu systemu wszystkie zmiany będą zapisywane. Jeżeli tworzymy lub ściągamy i zapisujemy wiele plików, warto sprawdzać ilość dostępnego miejsca w pliku zapisu:

    du -sh /mnt/live/memory/changes - poda ilość zajętego miejsca;
    df -h /mnt/live/memory/changes - poda ilość wolnego miejsca.

W przypadku wyczerpywania się wolnego miejsca w pliku zapisu możemy zwiększyć jego rozmiar wybierając:

    start systemu w trybie "Always Fresh mode",
    następnie Start/System/Porteus Settings Centre/Porteus changes i opcję "Porteus Save Changes",
    później "I want to resize a save file":

Resize existing file

Uwaga: tworzony jest nowy plik zapisu w podanej lokalizacji zawierający dotychczasowe zmiany. Jeżeli zaznaczymy usunięcie dotychczasowego pliku, nowy trzeba przenieść w dotychczasowe miejsce lub zmienić ścieżkę w pliku "porteus.cfg".
Moduły

    Moduły można (de)aktywować dwukrotnym kliknięciem.
    Domyślną przeglądarką jest Palemoon, zawarta w module /porteus/base/04-palemoon.xzm. Jeżeli chcesz Firefoksa, pobierz moduł 04-firefox.xzm stworzony przez twórców Porteusa i zastąp nim Palemoona.
    Niektóre moduły wymagają innych, zobacz niżej.
    Dodaliśmy moduły pycharm-2016.1.xzm i wymagane środowisko Javy jdk-8u66.xzm. Oba moduły można pobrać, wgrać do katalogu /porteus/optional i przetestować. Uwaga: aktywuj moduły dwukrotnym kliknięciem i nie ładuj Javy w wersji 7 z modułu openjre-7u95.xzm.



Metryka
========

:Autor: Robert Bednarz (ecg@ecg.vot.pl)

:Utworzony: |date| o |time|

.. |date| date::
.. |time| date:: %H:%M

.. raw:: html

    <style>
        div.code_no { text-align: right; background: #e3e3e3; padding: 6px 12px; }
        div.highlight, div.highlight-python { margin-top: 0px; }
    </style>
