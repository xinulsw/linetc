Problemy
#############

Jeśli nie da się uruchomić komputera za pomocą przygotowanego klucza, przeczytaj
poniższe wskazówki.

1. Za pomocą narzędzia `HP-USB-Disk-Storage-Format-Tool <http://www.dobreprogramy.pl/HP-USB-Disk-Storage-Format-Tool,Program,Windows,27581.html>`_
   możesz sformatować pendrajwa, a następnie nagrać jeszcze raz obraz *(Lx)PupTahr*.

.. figure:: linimg/hpformat.jpg

2. Jeżeli nie możesz uruchomić pendrajwa na starszyn sprzęcie, powiedzmy
   sprzed 2005 r., spróbuj wwybrać "Opcje formatowania" w programie *Rufus*,
   a następnie zaznacz "Dodaj łatkę dla starych biosów":

.. figure:: linimg/rufus02.jpg

3. Zainstaluj narzędzie `Linux Live USB Creator <http://www.linuxliveusb.com/en/download>`_,
   sformatuj pendrajwa za pomocą *HP-USB-Disk-Storage-Format-Tool* i użyj *LLUC*
   do nagrania obrazu *(Lx)PupTahr*:

.. figure:: linimg/lluc_lxpup.jpg

4. Wymień pendrajw na inny.

5. Niektóre starsze maszyny stacjonarne wymagają, aby po podłączeniu pendrajwa
   wejść do biosu (zazwyczaj klawisz :kbd:`F1`, :kbd:`F2` lub :kbd:`DEL`);
   jeżeli pendrajw pojawi się na liście dysków twardych(!), ustaw go jako
   pierwszy napęd, z którego uruchamia się system. Później restart i może
   pójdzie...

6. Zmień maszynę ;-)

Inne narzędzia:
==================

.. tip::

    Część narzędzi udostępnia serwis ``dobreprogramy.pl``, niestety sugeruje
    użycie dodatkowej aplikacji do pobierania, ukrytej pod przycieskiem "Pobierz program".
    Sugerujemy używanie przycisku "Linki bezpośrednie" i wybór
    odpowiedniej wersji (32-/64-bitowej), jeżeli jest dostępna.

* `USB Image Tool <http://www.dobreprogramy.pl/USB-Image-Tool,Program,Windows,39717.html>`_
  – narzędzie do robienia obrazów dysków USB i nagrywania ich napędy.

.. figure:: linimg/usbimgtool.jpg

* `Image USB <http://osforensics.com/tools/write-usb-images.html>`_
   – świetny program do tworzenia obrazów napędów USB i nagrywania ich
   na wiele napędów jednocześnie.

.. figure:: linimg/imageusb.jpg

* `Bootice <http://www.dobreprogramy.pl/BOOTICE,Program,Windows,47749.html>`_ –
  opcjonalne narzędzie do różnych operacji na dyskach. Za jego pomocą można
  np. utworzyć, a następnie odtworzyć kopię MBR pendrajwa.

.. figure:: linimg/bootice01.jpg
.. figure:: linimg/bootice02.jpg
.. figure:: linimg/bootice03.jpg

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
