.. _sqlite3:

Baza SQLite3
############

Domyślnie Django korzysta z bazy SQLite, która przechowywana jest w jednym pliku :file:`db.sqlite3`
w katalogu aplikacji.
Warto zobaczyć, jak wygląda. Potrzebny będzie jednak interpreter, który w razie
potrzeby doinstalujemy poleceniem ``apt-get install sqlite3``. Następnie
W terminalu wydajemy polecenie ``python manage.py dbshell``,
które uruchamia interpreter bazy. Następnie możemy wylistować utworzone tabele
poleceniem ``.tables``. Możemy również zobaczyć jakie instrukcje SQL-a
zostały użyte do utworzenia naszej tabeli: ``.schema czat_wiadomosc``.
Z interpretera wychodzimy poleceniem ``.quit``.

.. figure:: img/czat03ter.png