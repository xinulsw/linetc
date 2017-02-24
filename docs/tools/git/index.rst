Git
###

`Git <http://pl.wikipedia.org/wiki/Git_%28oprogramowanie%29>`_ Source Code Mirror
– to rozproszony system wersjonowania kodów źródłowych napisany
przez `Linusa Torvaldsa <http://pl.wikipedia.org/wiki/Linus_Torvalds>`_,
twórcę `jądra Linux <http://pl.wikipedia.org/wiki/Linux_%28j%C4%85dro%29>`_.
Skrót SCM bywa również rozwijany jako *software configuration management*,
co oznacza "zarządzanie konfiguracją oprogramowania". Gita można używać
do rozwijania zarówno małych, jak i dużych projektów (np. Arch Linux, GIMP, jQuery).

Konto i repozytorium
====================

Przede wszystkim wchodzimy na stronę  `<https://github.com/>`_ i zakładamy konto podając:
nazwę użytkownika, email i hasło. Następnie dodajemy pierwsze puste repozytorium.
Możemy postępować wg poniższych instrukcji:

*   Krok 1 – `założenie konta <https://help.github.com/articles/signing-up-for-a-new-github-account/>`_;
    podajemy nazwę użytkownika, adres email i hasło, jako typ konta wybieramy *free*.
*   Krok 2 – `weryfikacja adresu e-mail <https://help.github.com/articles/verifying-your-email-address/>`_
*   Krok 3 – `zakładamy repozytorium <https://help.github.com/articles/create-a-repo/>`_ dla projektu,
    wybieramy typ *Public* (publiczne)

.. figure:: img/git_repo01.jpg

.. figure:: img/git_repo02.jpg

.. figure:: img/git_repo03.jpg


Klient i konfiguracja
=====================

Treściami projektu można zarządzać bezpośrednio w serwisie *GitHub*
za pomocą przeglądarki. Częściej jednak pracujemy w repozytorium lokalnym,
obsługiwanym za pomocą jakiegoś programu. Podstawowym jest klient tekstowy
obsługiwany w termianlu.

W **Linuksie** instalacja sprowadza się do użycia odpowiedniego menedżera pakietów:

.. code-block:: bash

    w Debianie (Ubuntu, Mint):
    ~$ sudo apt-get install git
    w Archu (Manjaro, Antergos):
    ~# pacman -S git

W **Windows** tego samego klienta tekstowego pobieramy ze strony
`<http://git-scm.com/download/win>`_ i instalujemy wybierając domyślne opcje.


.. note::

    Po zrozumieniu podstaw Gita można oczywiście zainstalować programy
    z interfejsem graficznym, np.: `SmartGit <http://www.syntevo.com/smartgit/>`_,
    lub obsługiwać repozytorium z poziomu edytora kodu,
    np. Sublime Text 3 czy PyCharm.


**Podstawowa konfiguracja**: w terminalu wydajemy polecenia:

.. code-block:: bash

    ~$ git config --global user.name "nazwa_użytkownika";
    ~$ git config --global user.email email_użytkownika;
    ~$ git config --list

Podana nazwa użytkownika i email będą wykorzystywane do podpisywania wprowadzanych
w projekcie zmian.

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
    ~/mojprojekt$ git status
    ~/mojprojekt$ git commit -m "Dodanie opisu projektu"


.. figure:: img/git_init.jpg


- na początku tworzymy katalog dla projektu i wchodzimy do niego;
- ``git init`` inicjuje repozytorium w ukrytym katalogu :file:`.git`;
- ``echo`` tworzy plik :file:`README.md` z opisem projektu
  (można to zrobić w dowolnym edytorze);
- ``git status`` – pokazuje status plików;
- ``git add nazwa_pliku`` – przenosi plik do "poczekalni";
- ``git commit -m "komentarz"`` – zatwierdza zmiany w repozytorium, tworząc tzw. migawkę.

Pliki (katalogi) projektu mogą znajdować się w trzech przestrzeniach
określanych jako:

* katalog roboczy (ang. *working directory*);
* poczekalnia (ang. staging area);
* repozytorium (katalog .git).

.. figure:: img/areas.png


Podczas pracy nad projektem stan pliku zależy od przestrzeni, w której się znajduje,
i określany jest jako:

* nieśledzony (ang. *untracked*) – nowe pliki w katalogu roboczym;
  polecenie ``git add`` rozpoczyna ich śledzenie;
* śledzony (ang. *tracked*):
  * niezmieniony (ang. *unmodified*) w katalogu roboczym;
  * zmieniony (ang. *modified*) w katalogu roboczym;
  * czekający na zatwierdzenie (ang. *staged*) – dodane do poczekalni poleceniem ``git add``;

.. figure:: img/lifecycle.png

Polecenie ``git commit`` zatwierdza aktualną zawartość poczekalni w migawce
(ang. *snapshot*), która trafia do repozytorium.


Master i origin
===============

Repozytorium lokalne można połączyć i zsynchronizować ze zdalnym. Podczas tworzenia
pustego repozytorium w serwisie GitHub podane są polecenia, które należy skopiować
i wykonać w terminalu:

.. code-block:: bash

    ~/mojprojekt$ git remote add origin https://github.com/nazwa_konta/mojprojekt.git
    ~/mojprojekt$ git push -u origin master

* ``git remote`` – dodaje zdalne repozytorium określone przez *Git URL* do lokalnego;
* ``git push`` – synchronizuje zawartość aktualnej lokalnej gałęzi ``master`` z repozytorium zdalnym o domyślnej nazwie ``origin``.


.. figure:: img/git_remote.jpg


W wyniku powyższych operacji lokalna gałąź *master* zaczyna śledzić zdalną
o takiej samej nazwie.

**Sprawdź** klikając w przeglądarce nazwę repozytorium, czy jego zawartość
odpowiada lokalnemu.


Klonowanie repozytorium
=======================

.. warning::

    Jeżeli wykonujesz scenariusz od początku i sprawdziłeś, że zawartość zdalnego
    repozytorium na GitHubie odpowiada lokalnemu, usuń teraz lokalny katalog
    :file:`mojprojekt`, np. za pomocą poleceń:

    .. code-block:: language

        ~$ rm -rf ~/mojprojekt

Repozytorium lokalne utworzymy również przez klonowanie. Możemy klonować założone
przez siebie na GitHubie repozytoria lub istniejące publiczne (wtedy tworzymy tzw. forki).
Sprowadza się to do wydania polecenia w terminalu:

.. code-block:: bash

    ~$ git clone https://github.com/nazwa_użytkownika/nazwa_repozytorium.git [nazwa_katalogu]

Najważniejszy jest argument `Git URL`, czyli schematyczny adres repozytorium,
który możemy pobrać na stronie repozytorium klikając przycisk "Clone or download":

.. figure:: img/git_clone.jpg


W rezultacie w bieżącym katalogu utworzony zostanie katalog o nazwie repozytorium
lub o nazwie podanej w opcjonalnym argumencie `[nazwa_katalogu]`.


Praca z repozytorium
=====================

**Zmiany w repozytorium zdalnym**

Jak zostało powiedziane wcześniej, zmiany można wprowadzać za pomocą interfejsu
serwisu GitHub. Spróbujmy tak zrobić.

* Zmień treść zawartą w pliku :file:`README.md`: kliknij jego nazwę, a następnie ikonę
  edycji w prawym górnym rogu obok przycisku "History". Dopisz coś, przewiń w dół,
  wpisz opis zmiany i zatwierdź klikając "Commit changes".

* Utwórz nowy plik :file:`pierwszy.txt` klikając przycisk "Create new file" w głównym
  widoku repozytorium. Wpisz coś i zatwierdź zmiany.


**Pobranie zmian z repozytorium zdalnego**

Ponieważ dokonaliśmy zmian w repozytorium zdalnym, repozytorium lokalne jest nieaktualne.
Sytuacja taka może być częsta, zwłaszcza gdy projekt rozwijany jest zespołowo.
Dlatego codzienną pracę warto rozpoczynać od zsynchronizowania wersji lokalnej
z ewentualnymi zmiananami zapisanymi na serwerze:

.. code-block:: bash

    ~$ git pull [origin] [master]

Opcjonalne argumenty określają nazwy repozytorium zdalnego i lokalnej gałęzi.
Ewentualny komunikat "Already up-to-date." oznacza brak zmian na serwerze zdalnym.

**Zmiany lokalne**

Praca w repozytorium lokalnym jest najwygodniejsza. Zmieńmy więc treść pliku :file:`README.md`,
dodajmy katalog :file:`doc`, a w nim pliki :file:`index.rst` i :file:`slownik.txt` z dowolną
treścią:

.. code-block:: bash

    ~/mojprojekt$ echo "Zmiana lokalna" >> README.md
    ~/mojprojekt$ mkdir doc
    ~/mojprojekt$ echo "Dokumenty" >> doc/index.rst
    ~/mojprojekt$ echo "Słownik" >> doc/slownik.txt
    ~/mojprojekt$ git diff
    ~/mojprojekt$ git add --all
    ~/mojprojekt$ git diff -staged

* ``git diff`` – pokazuje różnice między katalogiem roboczym a poczekalnią, ale bez plików nieśledzonych;
* ``git add --all`` – dodaje do poczekalni wszystkie zmiany z katalogu roboczego;
* ``git diff --staged`` – pokaże zmiany między poczekalnią a ostatnią migawką projektu.

.. tip::

    Podczas dodawania plików do poczekalni można używać symboli wieloznaczych i nazw katalogów,
    np. ``git add '*.txt'`` lub ``git add doc``. Można też korzystać z poleceń powłoki, np.:
    ``find . -name "*.rst" -exec git add {} \;``

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

.. tip::

    Jeżeli zaznaczymy opcję *Initialize this repository with a README*, utworzony
    zostanie plik, w którym umieszcza się opis projektu. Na potrzeby tego scenariusza
    pomijamy

     o ile nie utworzylismy wcześniej repozytorium lokalnego z takim plikiem, które zamierzamy połaczyć ze zdalnym.

1. `Strona projektu Git`_

.. _Strona projektu Git: http://git-scm.com/
