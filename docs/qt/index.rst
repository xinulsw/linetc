Biblioteka Qt
###################

.. _biblioteka-qt:

:term:`Qt` to zestaw bibliotek przeznaczonych dla języka C++, QML i Java,
który znakomicie ułatwia tworzenie graficznego interfejsu użytkownika.
Zawiera również klasy udostępniające obsługę m.in. multimediów , sieci
czy baz danych.

System i środowisko IDE
************************

Bilioteka :term:`Qt` jest przenośna z założenia, więc programować z jej wykorzystaniem
można w wielu systemach i środowiskach. My proponujemy system Linux,
np. dystrybucję :term:`Debian` (v. Jessie) lub :term:`Xubuntu 14.04`.
Instalacja wymaganych narzędzi sprowadza się do wydania prostych poleceń
w terminalu:

.. code-block:: bash

    ~$ sudo apt-get update
    ~$ sudo apt-get install qtcreator qt5-qmake qt5-default qt4-qtconfig

Pierwsze polecenie zaktualizuje repoytoria, czyli wersje dostępnego oprogramowania;
drugie zainstaluje dedykowane :term:`środowisko IDE`, które pozwala projektować
interfejs graficzny, bardzo ułatwia edycję kodu, pozwala budować, uruchamiać
i debugować różne wersje tworzonych aplikacji.

Qt5 w systemie Windows
======================

Instalacja jest bardzo prosta. Pobieramy `Qt Online Installer for Windows <https://www.qt.io/download-open-source/>`_
i uruchamiamy. Następnie przeprowadzamy standardową instalację z domyślnymi
ustawieniami, podając w razie potrzeby hasło administratora.

.. figure:: img/qtwin01.jpg

.. figure:: img/qtwin02.jpg

Wygląd i działanie aplikacji :term:`Qt Creator` w systemie Linux i Windows są
takie same.

.. figure:: img/qtcreator.png

Materiały
**************

1. `Biblioteka Qt`_
2. `Qt Creator`_

.. _Biblioteka Qt: https://qt-project.org/
.. _Qt Creator: http://pl.wikipedia.org/wiki/Qt_Creator

Pojęcia
===========

.. glossary::

    Qt
        zestaw bibliotek programistycznych ułatwiających tworzenie aplikacji
        z interfejsem graficznym w językach C++, QML i Java.

    środowisko IDE
        zintegrowane środowisko programistyczne (ang. Integrated Development Environment, IDE),
        składające się z jednej lub wielu aplikacji, umożliwiające tworzenie,
        testowanie, budowanie i uruchamianie kodu.

    Qt Creator
        wieloplatformowe :term:`środowisko IDE` dla aplikacji pisanych
        w językach C++, JavaScript i QML.
        Zawiera m.in. `debugger <http://pl.wikipedia.org/wiki/Debugger>`_
        i edytor GUI (graficznego interfejsu użytkownika).

    Debian
        jedna z najstarszych i wiądących dystrybucji Linuksa, umożliwia
        elastyczną konfigurację systemu i dostosowanie go do własnych potrzeb.
        Jak większość dystrybucji, umożliwia wybór wielu środowisk graficznych,
        np. XFCE lub Gnome.

    Xubuntu 14.04
        odmiana jednej z najpopularniejszych dystrybucji Linuksa, Ubuntu,
        dostarczana z klasycznym, lekkim i konfigurowlanym środowiskiem
        graficznym XFCE.

    środowisko graficzne
        w systemach linuksowych zestaw oprogramowania tworzący GUI, czyli graficzny
        interfejs użytkownika, często zawiera domyślny wybór aplikacji przeznaczonych
        do wykonywania typowych zadań. Najpopularnijesze środowiska to `XFCE`_,
        `Gnome`_, `KDE`_, `LXDE`_, `Cinnamon`_, `Mate`_.

.. _Debian: https://www.debian.org/index.pl.html
.. _Ubuntu: http://ubuntu.pl
.. _Xubuntu: http://xubuntu.org/
.. _Gnome: http://pl.wikipedia.org/wiki/GNOME
.. _KDE: http://pl.wikipedia.org/wiki/KDE
.. _LXDE: http://pl.wikipedia.org/wiki/LXDE
.. _Cinnamon: http://en.wikipedia.org/wiki/Cinnamon_%28software%29
.. _Mate: http://pl.wikipedia.org/wiki/MATE
.. _XFCE: http://www.xfce.org/

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
