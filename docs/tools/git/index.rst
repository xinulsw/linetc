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


.. figure:: img/git_clone.jpg


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


.. figure:: img/git_init.jpg


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


Materiały
=========

1. `Strona projektu Git`_

.. _Strona projektu Git: http://git-scm.com/
