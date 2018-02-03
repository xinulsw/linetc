.. _lwamp:

Serwer WWW
###########

Jeżeli chcemy tworzyć i testować aplikacje sieciowe wykorzystujące bazy danych
za pomocą języków skryptowych, np. PHP czy Python, potrzebujemy środowiska testowego,
na które składa się :term:`serwer WWW`, :term:`interpreter` języka skryptowego i :term:`system bazodanowy`.
Zestawy takiego oprogramowania określa się skrótami `WAMP <http://pl.wikipedia.org/wiki/WAMP>`_ lub `LAMP <http://pl.wikipedia.org/wiki/LAMP>`_ w zależności
od wykorzystywanego systemu operacyjnego: W – Windows, L – Linux.
Pozostałe litery rozwija się najczęściej jako:

* A – `Apache <http://pl.wikipedia.org/wiki/Apache_%28serwer%29>`_;
* M – `MySQL <http://pl.wikipedia.org/wiki/MySQL>`_, w linuksach raczej `MariaDB <http://pl.wikipedia.org/wiki/MariaDB>`_;
* P – `PHP <http://pl.wikipedia.org/wiki/PHP>`_, `Perl <http://pl.wikipedia.org/wiki/Perl>`_ lub `Python <http://pl.wikipedia.org/wiki/Python>`_.

Wymienionego oprogramowanie to najpopularniejsze, ale nie jedyne rozwiązania.
Dostępnych jest wiele innych, równie dobrych serwerów czy baz danych.
Warto też wiedzieć, że instalacja i konfiguracja kompletu wymienionych programów nie jest zazwyczaj
konieczna. Np. jeżeli tworzymy aplikacje sieciowe w Pythonie wystarcza dedykowana
biblioteka (np. Flask) lub :term:`framework` (np. Django), które zapewniają
serwer HTTP i obsługę wbudowanej bazy SQLite.


Linux
===================

W systemie Debian i pochodnych (Ubuntu, Linux Mint itd.) lub na Arch Linuksie
można zainstalować serwer Apache2 i interpreter PHP za pomocą dedykowanych
menedżerów pakietów, czyli odpowiednio:

.. code-block:: bash

    ~$ sudo apt-get install apache2 php7.0 php7.0-gd php7.0-sqlite3 php7.0-curl libapache2-mod-php7.0
    ~# pacman -S apache php php-gd php-sqlite php-curl libapache-mod-php7

.. caution::
  Nazwy pakietów dla dystrybujcji opartych na Debianie (Ubuntu itd.) różnią się od podanych.
  Właściwe nazwy można sprawdzić wydając w terminalu polecenie: ``apt-get search php | grep php``.

Podstawowa konfiguracja sprowadza się do uaktywnienia odpowiednich modułów:

.. code-block:: bash

    ~$ sudo a2enmod userdir rewrite
    ~$ sudo service apache2 restart

    ~# a2enmod userdir rewrite
    ~# systemctl restart httpd

– i odblokowania możliwości wykonywania skryptów w katalogach domowych
użytkowników poprzez zakomentowanie następujących linii z pliku
``/etc/apache2/mods-available/php7.0.conf`` (Debian) lub ``/etc/httpd/mods-available/php7.conf``
(Arch):

.. code-block:: bash

    # To re-enable PHP in user directories comment the following lines
    # (from <IfModule ...> to </IfModule>.) Do NOT set it to On as it
    # prevents .htaccess files from disabling it.
    #<IfModule mod_userdir.c>
    #    <Directory /home/*/public_html>
    #        php_admin_flag engine Off
    #    </Directory>
    #</IfModule>

Tworzone strony umieszczamy w podkatalogu ``public_html`` katalogu domowego.
Wywołujemy je wpisując w przeglądarce adres: ``127.0.0.1/~użytkownik`` –
powinny zostać zwrócone pliki ``index.php`` lub ``index.html``, o ile istnieją.
Jeżeli mamy kilka projektów, umieszczamy je w podkatalogach, np.
``public_html/projekt1`` i wywołujemy: ``127.0.0.1/~użytkownik/projekt1``.


UwAmp w Windows
===================

W systemie Microsoftu najłatwiej skorzystać z gotowego zestawu WAMP.
Proponujemy `UwAmp <http://www.uwamp.com/en/>`_. Po wejściu na stronę klikamy *Download*,
a następnie link o nazwie **Download Exe/Install**.

.. figure:: img/uwamp01.jpg


.. caution::
  Do poprawnego działania Apache'a wymagana jest biblioteka Microsoftu Visual
  `C++ 2012 Redistributable (VC++ 11.0) <https://www.microsoft.com/en-us/download/details.aspx?id=30679>`_
  **w wersji 32-bitowej (x86)**, z kolei do PHP 7 musimy zainstalować
  `Visual C++ 2015 Redistributable <https://www.microsoft.com/en-us/download/details.aspx?id=48145>`_.

Pobieramy wymienione wyżej biblioteki i instalujemy je na początku.

.. figure:: img/vcredist2012.jpg

.. figure:: img/vcredist2015.jpg


Następnie uruchamiamy instalację UwAmpa. Jako miejsce instalacji wybieramy główny katalog
wybranego dysku, *C:*, *D:* itp.:

.. figure:: img/uwamp02.jpg

Po zainstalowaniu i uruchomieniu aplikacji *UwAmp* zapora systemowa może poprosić
o odblokowanie portów serwera www i bazy danych. Godzimy się, wybierając opcję dla
sieci prywatnych i domowych.

.. figure:: img/uwamp04_mysqld.jpg

.. figure:: img/uwamp05_apache.jpg

Serwerami i narzędziami zarządzamy za pomocą wygodnego okna:

.. figure:: img/uwamp06.jpg

.. note::
  Korzystając z powyższego okna wybierz wersję PHP 7.

Serwery www (Apache2) i bazy danych (MySQL) startowane są automatycznie. Jeżeli nie korzystamy
z serwera MySQL, możemy go zatrzymać klikając niebieską strzałkę obok przycisku "Stop" i wybierając
go listy. Do obsługi baz SQLite dołączono bardzo wygodny interfejs graficzny *SQLite Browser*.

Strony czy projekty umieszczamy w katalogu ``www`` folderu, w którym zainstalowaliśmy UwAmpa,
np. w ``C:\\UwAmp\www``. W przeglądarce wpisujemy adres ``localhost`` lub ``localhost/podkatalog``,
jeżeli strony umieściliśmy w jakimś podkatalogu.

.. figure:: img/uwamp07.jpg
