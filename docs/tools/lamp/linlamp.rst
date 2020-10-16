Linux LAMP
===================

Alternatywą dla instalowania środowiska typu XAMPP jest zainstalowanie serwera Apache2,
bazy danych MariaDB i interpretera PHP przy użyciu dedykowanych pakietów.
W dystrybucjach Debian i pochodnych (Ubuntu, Linux Mint itd.) wydajemy polecenie typu:

Apache i PHP
------------

.. code-block:: bash

    ~$ sudo apt-get install apache2 php7.0 php7.0-gd php7.0-sqlite3 php7.0-curl libapache2-mod-php7.0

.. caution::

  Nazwy pakietów dla każdej dystrybujcji mogą różnić się od podanych.
  Właściwe nazwy można sprawdzić (w systemach opartych na Debianie)
  wydając w terminalu polecenie: ``apt-get search php | grep php``.

Podstawowa konfiguracja sprowadza się do uaktywnienia odpowiednich modułów:

.. code-block:: bash

    ~$ sudo a2enmod userdir rewrite
    ~$ sudo systemctl restart apache2

– i odblokowania możliwości wykonywania skryptów w katalogach domowych
użytkowników poprzez zakomentowanie następujących linii z pliku
``/etc/apache2/mods-available/php7.0.conf`` (Debian i pochodne):

.. code-block:: bash

    # To re-enable PHP in user directories comment the following lines
    # (from <IfModule ...> to </IfModule>.) Do NOT set it to On as it
    # prevents .htaccess files from disabling it.
    #<IfModule mod_userdir.c>
    #    <Directory /home/*/public_html>
    #        php_admin_flag engine Off
    #    </Directory>
    #</IfModule>

Tworzone serwisy WWW umieszczamy w podkatalogu ``public_html`` katalogu domowego.
Wywołujemy je wpisując w przeglądarce adres: ``127.0.0.1/~użytkownik`` lub
``127.0.0.1/~użytkownik/serwis`` – gdzie:

- ``użytkownik`` – oznacza nazwę zalogowanego użytkownika,
- ``serwis`` – oznacza nazwę katalogu, w którym umieściliśmy pliki danego serwisu WWW.

.. note::

   Domyślnie serwer szuka w podanej ścieżce plików ``index.php`` lub ``index.html``.

MariaDB
-------

[todo]