Narzędzia
###################

Poniżej przedstawiamy zestaw przykładowych narzędzi do programowania, tworzenia
skryptów i dokumentacji, stron WWW itp. zadań.

Geany
*************

`Geany`_ to proste i lekkie środowisko IDE dostępne na licencji
`GNU General Public Licence <http://pl.wikipedia.org/wiki/GNU_General_Public_License>`_.
Geany oferuje kolorowanie składni dla najpopularniejszych języków,
m.in. C, C++, C#, Java, PHP, HTML, Python, Perl i Pascal,
wsparcie dla kodowania w ponad 50 standardach, dopełnianie poleceń, mechanizmy automatycznego zamykanie tagów dla HTML\XML,
auto-wcięć, pracy na kartach i wiele, wiele więcej. Podczas pisania kodu przydatny okazuje się brudnopis,
pozwalający tworzyć dowolne notatki, a także możliwość kompilacji plików źródłowych
bezpośrednio z poziomu programu.

Instalacja
===============

W systemie **Linux** korzystamy z dedykowanego menedżera pakietów, np. w Xubuntu
(i innych debianopochodnych) lub Archu wystarczy wpisać w terminalu:

.. code-block:: bash

    ~$ sudo apt-get install geany geany-plugins
    ~# pacman -S geany geany-plugins

.. note::
    Przykłady poleceń będziemy podawali dla systemów opartych na Debianie (Ubuntu
    i pochodne, Mint), które wykorzystyują menedżer oprogramowania ``apt``; oraz
    dla systemów opartych na Arch Linuksie (Arch, Bridge, Manjaro) i korzystających
    z menedżera ``pacman``.

W **MS Windows** ściągamy i instalujemy `pełną wersję binarną Geany <http://www.geany.org/Download/Releases>`_
przeznaczoną dla tych systemów. *Pełna* oznacza tutaj, ze zawiera biblioteki
GTK wykorzystywane przez program. Podczas standardowej instalacji można
zmienić katalog docelowy, np. na ``C:\Geany``.

.. figure:: img/geany1.jpg

Zanim rozpoczniemy pracę w edytorze, warto dostosować kilka ustawień.

W menu `Narzędzia/Menedżer wtyczek` zaznaczamy pozycję "Addons" (dostępna
po zainstalowaniu wtyczek), a następnie "Przeglądarka plików".
Zanim wyjdziemy z okna naciskamy przycisk "Preferencje" i na zakładce
"Przeglądarka plików" zaznaczamy opcję "Podążanie za ścieżką do bieżącego pliku".
Dzięki temu w panelu bocznym w zakładce "Pliki" zobaczymy listę katalogów i plików,
które łatwo możemy otwierać.

.. figure:: img/geany2.jpg
.. figure:: img/geany3.jpg

W menu `Edycja/Preferencje` :kbd:`CTRL+ALT+P` w zakładce `Edytor/Wcięcia` jako
"Typ" wcięć wybieramy opcję "spacje".

.. figure:: img/geany4.jpg

Warto zapamiętać i stosować kilka użytecznych skrótów. Jeśli kodujemy w C/C++: :kbd:`F8` – uruchamia
linker, :kbd:`F9` – buduje plik wykonawczy. Klawisz :kbd:`F5` uruchamia
z kolei pliki wykonywalne, skrypty Pythona lub otwiera strony HTML w przeglądarce.
Wcięcia wstawiają się automatycznie lub poprzez naciśnięcie klawisza :kbd:`TAB`.
Jeżeli chcemy wciąć od razu cały blok kodu, zaznaczamy go i również używamy
:kbd:`TAB` lub :kbd:`CTRL+I`, zmniejszenie wcięcia uzyskamy naciskając :kbd:`CTRL+U`.

.. figure:: img/geany5.jpg

Środowisko Geany nie zawiera narzędzi potrzebnych do kompilowania czy wykonywania
programów pisanych w różnych językach. Wymagane narzędzia musimy doinstalować osobno.

Kompilator C/C++
*********************

W systemie **Linux** wystarczy zazwyczaj wydać jedno polecenie wykorzystujące
używany w danej dystrybucji menedżer pakietów, np.:

.. code-block:: bash

    ~$ sudo apt-get install gcc
    ~# pacman -S gcc

W **MS Windows** instalujemy minimalistyczne środowisko deweloperskie
dostarczające wolne narzędzia :term:`GNU Compiler Collection`, czyli `MinGw`_. W tym
celu pobieramy instalator `mingw-get-setup.exe <http://sourceforge.net/projects/mingw/files/Installer>`_
i uruchamiamy.

.. figure:: img/mingw01.jpg

W oknie wyboru pakietów zaznaczamy widoczne poniżej paczki, w tym przede wszystkim
``mingw32-gcc-g++``, a następnie wybieramy polecenie *Installation/Apply*.

.. figure:: img/mingw02.jpg

Po pobraniu i rozpakowaniu wskazanych narzędzi oraz zakończeniu instalatora (*Close*)
trzeba dodać do ścieżki systemowej położenie kompilatora i linkera;
dzięki temu będzie można korzystać z tych i innych narzędzi bezpośrednio
z Geany lub okienka konsoli tekstowej. W oknie "Uruchamianie" (:kbd:`WIN+R`)
wpisujemy polecenie wywołujące okno "Zmienne środowiskowe" – można je również
uruchomić z okna właściwości komputera:

.. figure:: img/mingw03.jpg
.. figure:: img/mingw04.jpg

Klikamy przycisk *Nowa* i tworzymy nową zmienną użytkownika zgodnie z podanym
zrzutem:

.. figure:: img/mingw05.jpg
.. figure:: img/mingw06.jpg

.. tip::

    Powyżej przedstawiliśmy instalację narzędzi :term:`MinGw` z konta zwykłego
    użytkownika. Można w razie potrzeby czynności te wykonać również z konta administratora,
    co pozwoli udostępnić narzędzia wszystkim użytkownikom. Podobnie
    ścieżkę do kompilatora itd. można dopisać do zmiennej systemowej ``PATH``,
    dzięki czemu wszyscy użytkownicy będą mogli wywoływać narzędzia bez
    podawania pełnej ich lokalizacji.

Interpreter Pythona
*********************

W systemach **Linux** Python jest szeroko stosowany i dostępny jest w ramach
standardowej instalacji większości dystrybucji i to zarówno w wersji 2.x,
jak i 3.x. Dla formalności polecenia instalacyjne to:

.. code-block:: bash

    ~$ sudo apt-get install python2 python3
    ~# pacman -S python python2

.. note::

    Warto zauważyć, że w dystrybucjach opartych na Debianie polecenie ``python``
    jest dowiązaniem do wersji 2.x, a paczki nazywają się odpowiednio ``python2-...``
    lub ``python3-...``. W Arch Linuksie i pochodnych nazwa ``python`` domyślnie
    wskazuje wersję 3.x (!), podobnie nazwy pakietów dodatkowych. Wersja i paczki
    z liniii 2.x mają w nazwie ``python2``.

Polecić natomiast można doinstalowanie rozszerzonej konsoli:

.. code-block:: bash

    ~$ sudo apt-get install ipython2 ipython3
    ~# pacman -S python ipython2

W **MS Windows** najprościej zainstalować Pythona przy użyciu skryptu konsoli PowerShell
dostępnej w wersjach *Professional* (oznaczoną niebieską ikoną i niebieskiem tłem):

.. code-block:: posh

    (new-object System.Net.WebClient).DownloadFile("https://www.python.org/ftp/python/2.7.8/python-2.7.8.msi", "$pwd\python-2.7.8.msi")
    msiexec /i python-2.7.8.msi TARGETDIR=C:\Python27
    [Environment]::SetEnvironmentVariable("Path", "$env:Path;C:\Python27\;C:\Python27\Scripts\", "User")
    (new-object System.Net.WebClient).DownloadFile("https://raw.github.com/pypa/pip/master/contrib/get-pip.py", "$pwd\get-pip.py")
    C:\Python27\python.exe get-pip.py virtualenv

Jeżeli w naszej wersji Windows nie ma PowerShella, ściągamy `interpreter Pythona`_
i instalujemy ręcznie, pamiętając o zaznaczeniu opcji "Add Python.exe to Path".

.. _interpreter Pythona: https://www.python.org/downloads/

.. figure:: img/python01.jpg

Następnie instalujemy program ``pip`` do zarządzania dodatkowymi bibliotekami za pomocą polecenia:

.. code-block:: bash

    python -c "exec('try: from urllib2 import urlopen \nexcept: from urllib.request import urlopen');f=urlopen('https://raw.github.com/pypa/pip/master/contrib/get-pip.py').read();exec(f)"

Aby uruchamiać skrypty bezpośrednio z poziomu Geany lub konsoli tekstowej bez
podawania pełnej ścieżki warto ją dodać do zmiennej użytkownika lub systemu
o nazwie ``PATH``, tak jak pokazano wyżej dla narzędzi *MinGw*.
Na potrzeby pojedynczej sesji odpowiedni efekt osiągniemy wydając polecenie
w konsoli:

.. code-block:: bat

    set PATH=%PATH%;c:\Python27\;c:\Python27\Scripts\

Inne
******************

Instalację bilioteki :term:`Qt` i środowiska IDE :term:`Qt Creator` omówiono
w osobnym :ref:`dokumencie <biblioteka-qt>`.

Materiały
**************

1. `Geany`_
2. `MinGw`_
3. `Python`_

.. _Geany: http://www.geany.org/
.. _MinGw: http://www.mingw.org/
.. _Python: https://www.python.org/

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

    MinGw
        ang. *Minimalist GNU for Windows*; minimalistyczne środowisko
        dostarczające narzędzia GNU (linker, kompilator itd.) pozwalające
        na kompilację natywnych plików wykonywalnych dla Windows
        z kodu pisanego w C/C++.

    GNU Compiler Collection
        zestaw kompilatorów do różnych języków programowania rozwijany
        w ramach projektu GNU i udostępniany na licencji GPL oraz LGPL.
        Zob. hasło w `Wikipedii <http://pl.wikipedia.org/wiki/GNU_Compiler_Collection>`__.

    GPL
        ang. GNU General Public License – licencja wolnego i otwartego
        oprogramowania stworzona w 1989 roku przez Richarda Stallmana
        i Ebena Moglena na potrzeby Projektu GNU. Ostatnia wersja, trzecia,
        opublikowana została 29 czerwca 2007 r.
        Zob. hasło w `Wikipedii <http://pl.wikipedia.org/wiki/GNU_General_Public_License>`__.

    Debian Jessie
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
