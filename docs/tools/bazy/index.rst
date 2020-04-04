.. _bazy-danych:

Baza SQLite
###########

W wielu projektach nie ma potrzeby wykorzystywania dużych i skomplikowanych systemów zarządzania
bazami danych takich jak MySQL, MariaDB czy PostgreSQL. Lepiej skorzystać
z prostszej `bazy SQLite <https://www.sqlite.org/>`_, która ma jednak duże możliwości.
Do zarządzania bazami danych SQLite'a, które przechowywane są w pojednyczych plikach,
wykorzystuje się **interepreter** działający w terminalu.

Linux
=====

Do instalacji możemy użyć polecenia:

.. code-block:: bash

    ~$ sudo apt-get install sqlite3

Narzędzie uruchamiany komendą ``sqlite3``. Podstawowe polecenia:

.. code-block:: bash

    ~$ sqlite3 baza.db // otwarcie pliku z bazą
    ~$ sqlite3 baza.db < schemat.sql // utworzenie bazy na podstawie pliku .sql
    sqlite> .tables // lista tabel
    sqlite> .help // lista poleceń interpretera
    sqlite> .schema tabela // pokazuje klauzulę CREATE dla podanej tabeli
    sqlite> .quit // wyjście z interpretera

Windows
=======

Ze strony `SQLite3 Download Page <https://www.sqlite.org/download.html>`_
z sekcji *Precompiled Binaries for Windows* pobieramy archiwum *sqlite-tools-win32-(...).zip*.
Następnie należy je rozpakować najlepiej do katalogu będącego w ścieżce systemowej.
Interpreter uruchamiamy albo poleceniem ``sqlite3`` albo podwójnym kliknięciem.

Narzędzia GUI
=============

Bardzo dobrym narzędziem z interfejsem graficznym jest polski program `SQLiteStudio <http://sqlitestudio.pl/>`_.
Najnowsze wersje pobierzemy ze strony `repozytorium <https://github.com/pawelsalawa/sqlitestudio/releases>`_
programu w serwisie Github.

W systemie Linux pobieramy pierwszy plik o nazwie ``InstallSQLiteStudio-3.2.1``.
Nadajemy mu uprawnnienia wykonywalności w menedżerze plików lub w terminalu:

.. code-block:: bash

    ~/Pobrane$ chmod a+x InstallSQLiteStudio-3.2.1

W systemie Windows pobieramy plik ``InstallSQLiteStudio-3.2.1.exe``.

Instalatory uruchamiamy podwójnym kliknięciem i postępujemy wg instrukcji. Po zainstalowaniu program
uruchamiamy poleceniem ``sqlitestudio``.

.. figure:: ../img/sqlitestudio.png

Inne programy obsługujące bazę SQLite3 to np. angielskojęzyczne `DB Browser for SQLite <http://sqlitebrowser.org/>`_
i `DBeaver Community Edition <https://dbeaver.io/>`_.

Materiały
=========

1. `Interpreter SQLite3`_

.. _Interpreter SQLite3: https://www.sqlite.org/cli.html
