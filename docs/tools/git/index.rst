.. _git:

Git
###

`Git <http://pl.wikipedia.org/wiki/Git_%28oprogramowanie%29>`_ Source Code Mirror
– to rozproszony system wersjonowania kodów źródłowych napisany
przez `Linusa Torvaldsa <http://pl.wikipedia.org/wiki/Linus_Torvalds>`_,
twórcę `jądra Linux <http://pl.wikipedia.org/wiki/Linux_%28j%C4%85dro%29>`_.
Skrót SCM bywa również rozwijany jako *software configuration management*,
co oznacza "zarządzanie konfiguracją oprogramowania". Gita można używać
do rozwijania zarówno małych, jak i dużych projektów (np. Arch Linux, GIMP, jQuery).

Konto
=======

Przede wszystkim wchodzimy na stronę  `<https://github.com/>`_. Następnie zakładamy konto podając:
nazwę użytkownika, email i hasło. Możemy też postępować wg poniższych instrukcji:

*   Krok 1 – `założenie konta <https://help.github.com/articles/signing-up-for-a-new-github-account/>`_;
    podajemy nazwę użytkownika, adres email i hasło, jako typ konta wybieramy *free*.
*   Krok 2 – `weryfikacja adresu e-mail <https://help.github.com/articles/verifying-your-email-address/>`_
*   Krok 3 – `zakładamy repozytorium <https://help.github.com/articles/create-a-repo/>`_ dla projektu,
    wybieramy typ *Public* (publiczne)


.. tip::

    Podczas tworzenia repozytorium można zaznaczyć opcję *Initialize this repository with a README*
    (utwórz początkowy plik README), o ile nie utworzylismy wcześniej repozytorium lokalnego (zob. poniżej),
    które zamierzamy połaczyć ze zdalnym.

Klient Gita
================

Treść projektu można dodawać do repozytorium centralnego w serwisie *github.com*
za pomocą przeglądarki. Częściej jednak pracujemy w repozytorium lokalnym,
obsługiwanym za pomocą jakiegoś programu.

Ze względu na szybkość działania polecamy środowisko **Linux**. Instalacja
podstawowego klienta tekstowego w systemach opartych na Debianie (Ubuntu, Linux Mint itd.)
i opartych na Arch Linuksie (np. Manjaro, Antergos) sprowadza się
do użycia odpowiedniego menedżera pakietów:

.. code-block:: bash

    ~$ sudo apt-get install git
    lub w Archu:
    ~# pacman -S git

W systemach **Windows** tego samego klienta tekstowego pobieramy ze strony `<http://git-scm.com/download/win>`_
i instalujemy wybierając domyślne opcje.

Po opanowaniu podstaw Gita można oczywiście zainstalować programy
z graficznym interfejsem użytkownika np.: `SmartGit <http://www.syntevo.com/smartgit/>`_
lub obsługiwać repozytorium z poziomu edytora kodu, np. Sublime Text 3 czy PyCharm.


Klonowanie repozytorium
=======================

Pierwszym sposobem utworzenia lokalnego repozytorium jest klonowanie.
Możemy klonować założone przez siebie repozytoria lub istniejące (wtedy tworzymy tzw. forki).
Czynność sprowadza się do wydania polecenia w terminalu:

.. code-block:: bash

    ~$ git clone https://github.com/nazwa_użytkownika/nazwa_repozytorium.git [nazwa_katalogu]

Najważniejszy jest argument `Git URL`, czyli schematyczny adres repozytorium,
który możemy pobrać na stronie repozytorium klikając przycisk "Clone or download":


.. figure:: git_clone.jpg


W rezultacie w bieżącym katalogu utworzony zostanie katalog o nazwie repozytorium
lub o nazwie podanej w opcjonalnym argumencie `[nazwa_katalogu]`.


Nowe repozytorium
=================

Repozytorium lokalne możemy utworzyć od podstaw, a później dopiero połączyć go ze zdalnym.
Wydajemy polecenia:

.. code-block:: bash

    ~$ mkdir mojprojekt; cd mojprojekt
    ~/mojprojekt$ git init
    ~/mojprojekt$ echo "Moje pierwsze repozytorium" > README.md
    ~/mojprojekt$ git status
    ~/mojprojekt$ git add README.md
    ~/mojprojekt$ git commit -m "Dodanie opisu projektu"


.. figure:: git_init.jpg


- na początku tworzymy katalog dla projektu i wchodzimy do niego;
- ``git init`` tworzy repozytorium w ukrytym katalogu :file:`.git`;
- ``echo`` tworzy plik :file:`README.md` zawierający opis projektu (oczywiście można to zrobić w dowolnym edytorze);
- ``git status`` – pokazuje status plików;
- ``git add nazwa_pliku`` – przenosi plik do "poczekalni";
- ``git commit -m "komentarz"`` – zatwierdza zaminy w repozytorium.

Tak utworzone repozytorium można połączyć i zsynchronizować ze zdalnym, które jednak musi zostać
wcześniej utworzone w serwisie GitHub.

Podstawy Gita
=====================

.. note::

    Wszystkie poniższe polecenia wydajemy w głównym katalogu projektu.
    Warto poczytać polską wersję 1 `podręcznika Git SCM <http://git-scm.com/book/pl/v1/>`_.
    Dostępna jest również `wersja 2 podręcznika Git <http://git-scm.com/book/en/v2/>`_, ale tylko w j. angielskim.

Codzienną pracę projektem warto rozpocząć od zsynchronizowania wersji lokalnej
z ewentualnymi zmiananami zapisanymi na serwerze:

.. code-block:: bash

    ~$ git pull

Bardzo często będziemy korzystać z polecenia:

.. code-block:: bash

    ~$ git status

– które informuje nas o tym, jakie pliki zostały dodane do poczekalni, ale są nieśledzone
(ang. *Untracked files*), jakie zostały zmienione, ale nie zostały zatwierdzone
(ang. *Changes not staged for commit*), a jakie czekają na zatwierdzenie
(ang. *Changes to be committed*). Komunikat *On branch master* informuje,
że pracujemy na głównej gałęzi (ang. master branch) projektu.

Zarówno nieśledzone, jak i niezatwierdzone pliki, które chcemy umieścić w projekcie,
dodajemy poleceniem:

.. code-block:: bash

    ~$ git add ścieżka/nazwa_pliku

Można używać znaków specjalnych, np. ``git add *.jpg``. Jeżeli mamy rozbudowaną
strukturę katalogów w projekcie, przydatne jest polecenie dodające
nowe zmiany hurtowo i rekursywnie:

.. code-block:: bash

    ~$ find . -name "*.rst" -exec git add {} \;

Po dodaniu wszystkich nowych plików i zmian do poczekalni, trzeba je zatwierdzić:

.. code-block:: bash

    ~$ git commit -m "Opis zmian ..."

Jeżeli pominiemy opcjonalny przełącznik ``-m`` otwarty zostanie edytor, w którym
opisujemy dokonywane zmiany.

Zatwierdzone zmiany prześlemy na serwer wydając polecenie:

.. code-block:: bash

    ~$ git push

– które poprosi nas o podanie nazwy użytkownika (adres email) i hasła, a następnie
prześle informacje na serwer.

Powyższy porządek komend jest typowy dla sesji z gitem.

.. note::

    Wskazówka: nie należy usuwać plików/katalogów lub zmieniać ich nazw w katalogu
    projektu za pomocą narzędzi systemowych, np. menedżera plików, ponieważ
    Git nie będzie nic o tym wiedział i zasypie nas wieloma komunikatami
    podczas sesji. Zamiast tego używamy poniższych poleceń:

.. code-block:: bash

    ~$ git rm plik
    ~$ git rm -rf katalog
    ~$ git mv stara_nazwa nowa_nazwa

ReStructuredText i Sphinx
***************************

Git dobrze nadaje się do prowadzenia projektów nie tylko typowo programistycznych,
ale również dokumentacyjnych i szkoleniowych, a więc zawierających nie tylko kod,
ale przede wszystkim instrukcje, poradniki, scenariusze, itp.

W katalogu naszego projektu zakładamy katalog podrzędny o nazwie np. ``docs``,
w którym tworzyć będziemy naszą dokumentację.

.. code-block:: bash

    ~/nazwa_projektu$ mkdir docs

Dokumenty zapisywane będą w formacie `reStructuredText <http://pl.wikipedia.org/wiki/ReStructuredText>`_,
czyli za pomocą tekstowego języka znaczników, w plikach z rozszerzeniem ``.rst``.
Zawartość tych plików może być później przetworzona do postaci formatów
docelowych, takich jak HTML, PDF czy LaTeX. Zadanie to realizowane będzie
przez narzędzie `Sphinx <http://sphinx-doc.org/>`_ napisane w Pythonie
i służące m.in. do tworzenia dokumentacji tego języka.

Instalacja Sphinksa
=======================

Przede wszystkim potrzebujemy interpretera Pythona i narzędzia instalacji
modułów dodatkowych ``pip`` – zobacz w sekcji `Interpreter Pythona`_.
Następnie wydajemy polecenia:

.. code-block:: bash

    ~$ sudo apt-get install mercurial
    ~$ sudo pip install sphinx_rtd_theme hg+https://bitbucket.org/birkenfeld/sphinx#sphinx

    W Archu:
    ~# pacman -S mercurial
    ~# pip install sphinx_rtd_theme hg+https://bitbucket.org/birkenfeld/sphinx#sphinx

.. note::

    Instalacja klienta systemu kontroli wersji `Mercurial <http://pl.wikipedia.org/wiki/Mercurial>`_
    wynika z tego, że korzysta z niego projekt Sphinx. Instalacja tematu ``sphinx_rtd_theme``
    jest opcjonalna, domyślny temat wygląda tak, jak w `dokumentacji Pythona <https://docs.python.org/2.7/whatsnew/2.7.html>`_.

Teraz możemy przejść do konfiguracji Sphinksa, która sprowadza się do wygenerowania
pliku z ustawieniami o nazwie ``conf.py``. W głównym katalogu tworzonej dokumentacji,
czyli ``docs``, wydajemy polecenie:

.. code-block:: bash

    ~$ sphinx-quickstart

Na większość pytań kreatora odpowiadamy naciśnięciem :kbd:`Enter`, przyjmując ustawienia
domyślne. Zwrócić uwagę należy na:

* ``Project name:`` – wpisujemy nazwę naszego projektu;
* ``Author name(s):`` – wpisujemy autora;
* ``Project version:`` – podajemy wersję, np. 1;
* ``Project release:`` – podajemy wydanie, np. 0;
* ``Project langiage [en]:`` – określamy język jako ``pl``;
* ``Please indicate... Sphinx extensions:`` – odpowiadając ``y`` dołączamy rozszerzenia, można włączyć:
  ``autodoc``, ``doctest``, ``pngmath`` i ``viewcode`` – przydają się w dokumentacji Pythona.
  Zobacz: `lista rozszerzeń Sphinksa <http://sphinx-doc.org/latest/extensions.html>`_;
* ``Create Makefile?`` – odpowiadamy ``y``, dzięki czemu budowanie dokumentacji sprowadzi się do wydania
  polecenia ``make html``.

Po skonfigurowaniu Sphinksa w katalogu ``docs`` powinny znaleźć się pliki: ``conf.py, Makefile, make.bat``
i ``index.rst``, a także katalogi ``_build, _static, _templates``.

Jeżeli chcemy używać tematu *sphinx_rtd_theme* na końcu pliku ``conf.py`` dopisujemy::

    try:
        import sphinx_rtd_theme
        html_theme = "sphinx_rtd_theme"
        html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]
    except:
        pass

Tworzenie dokumentacji
========================

Na początku warto dostosować plik główny, czyli ``index.rst``.
Jest on naszą "stroną główną", zawiera m. in. dyrektywę tworzącą
spis treści:

.. code-block:: rst

    Welcome to Projekt ILO's documentation!
    =======================================

    Contents:

    .. toctree::
       :maxdepth: 2

       Serwis eCG <http://ecg.vot.pl/>
       cwiczenia/index
       programowanie/index


    Indices and tables
    ==================

    * :ref:`genindex`
    * :ref:`modindex`
    * :ref:`search`

Jak widać domyślne komunikaty są w języku angielskim, należy więc je spolszczyć
zmieniąjąc treść według uznania. Dyrektywa ``.. toctree::`` generuje spis
treści na podstawie wskazanych plików. W powyższym listingu dodano dwa
przykładowe wpisy wskazujące pliki ``index.rst`` umieszczone we wskazanych
podkatalogach. Sphinx odczytuje nagłówki z tych plików i umieszcza w spisie.
Domyślnie sczytywane są dwa poziomy zagnieżdżenia (``:maxdepth: 2``).
Gdybyśmy chcieli mieć numerację, dodalibyśmy opcję: ``:numbered:``.
Pokazano również, jak dodawać stałe linki w spisie (``Serwis eCG ...``).

Z sekcji indeksów (``Indices ...``) można usunąć wszystkie spisy lub
zostawić wybrane, np. ``genindex`` udostępnia indeks zdefiniowanych terminów
i pojęć.

Dokumenty w katalogu ``docs`` warto kategoryzować i umieszczać w osobnych
katalogach. Nazwy plików mogą być dowolne, chociaż dobrze jest przyjąć jakąś
przejrzystą konwencję. Poszczególne pliki należy traktować jako kolejne
strony w wersji HTML.

Podstawy reST
==================

Żeby zrozumieć proste w gruncie rzeczy zasady formatowania reST najlepiej
podglądać kod gotowych stron! Wystarczy w nagłówku kliknąć link *View page source*,
skopiować, wkleić i wypełnić własną treścią. Zacznij od strony, którą czytasz...

Jeżeli chcesz rozumieć, czytaj dalej. Podstawowe zasady są następujące:

- Wcięcia są ważne!
- Akapity itp. oddzielamy pustym wierszem.
- \*pochylenie\*, \*\*pogrubienie\*\*
- \`\`przykład kodu\`\`

Nagłówki
---------------

Kolejne poziomy nagłówków tworzymy poprzez podkreślanie ich sekwencjami znaków:

.. code-block:: rst

    Część 1
    ##############

    Rozdział 2
    **************

    Sekcja 3
    ==============

    Podsekcja 4
    --------------

    Podpodsekcja 5
    ^^^^^^^^^^^^^^

    Akapit 6
    """"""""""""""

Wybór znaków nie jest narzucony, ale najlepiej trzymać się jednej konwencji,
np. powyższej.

Dyrektywy
---------------

Ogólna postać dyrektyw to:

.. code-block:: rst

    .. <nazwa>:: <argumenty>
        :<opcja>: <wartość>

        treść

Użyteczne dyrektywy:

- ``.. image:: ścieżka/plik.jpg`` – pozwala wstawić obrazek
- ``.. figure:: ścieżka/plik.jpg`` – pozwala wstawić obrazek z etykietą
- ``.. note::`` – warte zauważenia
- ``.. tip::`` – wskazówka
- ``.. warning::`` – ostrzeżenie
- ``.. highlight:: cpp`` – formatuj kod jako *cpp* (lub ``python``, ``bash``, ``html`` itd.)
- ``.. literalinclude:: ścieżka/test.cpp`` – wstaw kod z podanego pliku
- ``.. code block:: cpp`` – treść poniżej to kod w *cpp* (lub ``python``, ``bash``, ``html`` itd.)
- ``.. raw:: html`` – interpretuj treść poniżej jako HTML
- ``.. include:: ścieżka/plik.rst`` – wstaw treść z innego pliku

Listy
---------------

Aby uzyskać listę wypunktowaną lub numerowaną stosujemy:

.. code-block:: rst

    * punkt
    * punkt drugi zawiera
      dwie linie

    1. punkt 1
    2. punkt 2

    #. automatyczne numerowanie
    #. automatyczne numerowanie


Linki
----------------

- ```Nagłówek`_`` – link do nagłówka w bieżącym dokumencie
- ``.. _Strona Pythona: http:\\www.python.org`` – definicja linku,
  ```Strona Pythona`_`` – wstawienie linku
- ```Strona Pythona <http:\\www.python.org>`_`` – tak też można
- ``.. _nazwa-linku:`` – definicja linku w dokumentacji,
  ``:ref:`zobacz tutaj <nazwa-linku>``` – wstawienie linku

.. tip::

    Powtórzmy, najlepszą metodą poznania składni reST jest przeglądanie
    źródeł gotowych plików.

Budowanie dokumentacji
=======================

W katalogu głównym dokumentacji, czyli ``docs`` wydajemy polecenie:

.. code-block:: bash

    ~/projekt/docs$ make html

W terminalu zobaczymy komunikaty, niektóre z nich będą informacją o błędach
w formatowaniu, które musimy usunąć. Gotowa wersja zostanie umieszczona
w katalogu ``_build/html``. Możemy go wgrać do sieci, możemy spakować i udostępnić
– po otwarciu pliku ``index.html`` w przeglądarce zobaczymy efekt naszej pracy.

Od czasu do czasu, zwłaszcza po wielu zmianach położenia plików i katalogów,
budowanie dokumentacji warto poprzedzić usunięciem poprzedniej wersji HTML:

.. code-block:: bash

    ~/projekt/docs$ make clean

Dokumentacja online
======================

Projekty hostowane w serwisie `GitHub <https://github.com/>`_ łatwo podpiąć
do serwisu `Read the Docs <https://readthedocs.org/>`_, który umożliwia
automatyczne generowanie wersji HTML, PDF, a nawet Epub (chociaż przy wykorzystaniu stabilnej,
a nie testowej wersji Sphinksa) i udostępnianie jej online.

W tym celu trzeba założyć konto na stronie
`Read the Docs – Sign Up <https://readthedocs.org/accounts/signup/>`_.
Po zalogowaniu importujemy projekt z GitHuba (ang. Import a Project –
Import from GitHub) i po potwierdzeniu domyślnych opcji możemy
cieszyć wersją online dostępną pod adresem typu: http://nazwa_projektu.readthedocs.org.
Wersję PDF ściągniemy po zalogowaniu, wejściu na stronę projektu, wybraniu
zakładki *Downloads* i linku *latest PDF*.

.. figure:: img/rtfd.jpg

Materiały

1. `Strona projektu Git`_
2. `First Steps with Sphinx`_
3. `Wprowadzenie do składni Sphinx reST`_
4. `Docutils`_
5. `Składnia reST & Sphinx`_

.. _Strona projektu Git: http://git-scm.com/
.. _First Steps with Sphinx: http://sphinx-doc.org/tutorial.html
.. _Wprowadzenie do składni Sphinx reST: http://sphinx-doc.org/rest.html
.. _Docutils: http://docutils.sourceforge.net/
.. _Składnia reST & Sphinx: http://thomas-cokelaer.info/tutorials/sphinx/rest_syntax.html