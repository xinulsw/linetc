.. _kompilator-cpp:

Kompilator C/C++
################

W systemie **Linux** potrzebne narzędzia są zazwyczaj obecne, ale w razie potrzeby wystarczy
doinstalować pakiet ``gcc`` odpowiednim menedżerem pakietów, np.:

.. code-block:: bash

    ~$ sudo apt-get install gcc


W **MS Windows** instalujemy minimalistyczne środowisko deweloperskie
dostarczające wolne narzędzia :term:`GNU Compiler Collection`, czyli `MinGw`_. W tym
celu pobieramy instalator `mingw-get-setup.exe <http://sourceforge.net/projects/mingw/files/Installer>`_
i uruchamiamy.

.. figure:: ../img/mingw01.jpg

W oknie wyboru pakietów zaznaczamy widoczne poniżej paczki, w tym przede wszystkim
``mingw32-gcc-g++``, a następnie wybieramy polecenie *Installation/Apply*.

.. figure:: ../img/mingw02.jpg

Po pobraniu i rozpakowaniu wskazanych narzędzi oraz zakończeniu instalatora (*Close*)
trzeba dodać do ścieżki systemowej położenie kompilatora i linkera;
dzięki temu będzie można korzystać z tych i innych narzędzi bezpośrednio
z Geany lub okienka konsoli tekstowej. W oknie "Uruchamianie" (:kbd:`WIN+R`)
wpisujemy polecenie wywołujące okno "Zmienne środowiskowe" – można je również
uruchomić z okna właściwości komputera:

.. figure:: ../img/mingw03.jpg
.. figure:: ../img/mingw04.jpg

Klikamy przycisk *Nowa* i tworzymy nową zmienną użytkownika zgodnie z podanym
zrzutem:

.. figure:: ../img/mingw05.jpg
.. figure:: ../img/mingw06.jpg

.. tip::

    Powyżej przedstawiliśmy instalację narzędzi :term:`MinGw` z konta zwykłego
    użytkownika. Można w razie potrzeby czynności te wykonać również z konta administratora,
    co pozwoli udostępnić narzędzia wszystkim użytkownikom. Podobnie
    ścieżkę do kompilatora itd. można dopisać do zmiennej systemowej ``PATH``,
    dzięki czemu wszyscy użytkownicy będą mogli wywoływać narzędzia bez
    podawania pełnej ich lokalizacji.

Materiały
=========

1. `MinGw`_

.. _MinGw: http://www.mingw.org/

