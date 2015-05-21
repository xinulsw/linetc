Puppy Linux
###################

.. _puppy:

Praktycznie wszystkie dystrybucje Linuksa można bez problemu nagrać na pendrajwa
i uruchamiać komputer przy jego użyciu. Jednak nie wszystkie obsługują tzw.
tryb persystencji, który pozwala na zachhowywanie wprowadzonych zmian, tzn.
konfiguracji, tworzonych dokumentów czy doinstalowanego oprogramowania.

Jedną ze specjalnie zaprojektowanych do tego celu dystrybucji jest
`Puppy Linux <http://puppylinux.org/main/Overview%20and%20Getting%20Started.htm>`_.
Odmiana ta tworzona jest na bazie systemu Slackware lub Ubuntu.
Oferuje różne środowiska graficzne. Domyślnym jest połączenie
menedżera okien `JVM <http://www.joewing.net/projects/jwm/>`_ z pulpitem
`ROX Desktop <http://rox.sourceforge.net/desktop/>`_ i menedżerem
plików `ROX-Filer <http://rox.sourceforge.net/desktop/ROX-Filer>`_.

Do naszych zastosowań wybraliśmy odmianę `LxPup <http://lx-pup.weebly.com/downloads.html>`_ 
zawierającą domyślne środowisko `LXDE <http://pl.wikipedia.org/wiki/LXDE>`_.
*LxPupTahr* jest wersją systemu `Puppy Linux 6.0.2 tahrpup CE <http://www.murga-linux.com/puppy/viewtopic.php?t=96178>`_
opartą na systemie Ubuntu Tahr 14.04 LTS. Nic nie stoi na przeszkodzie,
żeby wypróbować wzorzec z pulpitem JVM/ROX. Wystarczy pobrać plik
`tahr-6.0.2_PAE.iso <http://ftp.nluug.nl/ftp/pub/os/Linux/distr/puppylinux/puppy-tahr/iso/tahrpup%20-6.0-CE/>`_
(ok. 201 MB). W wersji tej łatwo doinstalować również środowisko `XFCE <http://www.xfce.org/?lang=pl>`_.

.. figure:: linimg/lxpup.png
   :alt: Pulpit LxPup

   Pulpit LxPup ze środowiskiem LXDE

.. figure:: linimg/puptahr_jvm.png
   :alt: Pulpit JVM

   Pulpit PupThar ze środowiskiem JVM/ROX

.. figure:: linimg/puptahr_xfce.png
   :alt: Pulpit XFCE

   Pulpit PupTahr ze środowiskiem XFCE

Nazwa pliku zapisu (persystencji) w systemie *TahrPup* zaczyna się zawsze
od ``tahrsave-``. Przykładowy plik udostępniamy udostępniamy w serwisie
`Copy.com <https://copy.com/9WzmbHVn8T8UxsSN>`_ pod nazwą :file:`tahrsave-xfce.2fs`.
Zawiera on wstępną konfigurację oraz następujące dostosowania:

* zaktualizowane listy oprogramowania;
* zaktualizowaną i spolszczoną domyślną przeglądarkę `Pale Moon <https://www.palemoon.org/>_`
  (otwartoźrodłówa, oparta na Firefoksie);
* fonty Droid, Ubuntu oraz podstawowe z Windows;
* pakiety python-pip, python-virtualenv oraz bibliotekę pygame;
* skonfigurowane mini środowisko programistyczne IDE – Geany.
* skonfigurowane elementy interfejsu JVM/ROX oraz XFCE

Po pobraniu należy wgrać go do głównego katalogu pendrajwa.

Pulpit JVM/ROX uruchomić można przy użyciu narzędzia *WM Switcher*
– przełączanie menedżerów okien.

.. attention::

    Na pendrajwie nie może znajdować się żaden inny plik o nazwie rozpoczynającej
    się od ``tahrsave-``.

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
